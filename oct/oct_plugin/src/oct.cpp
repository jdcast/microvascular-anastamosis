#include <oct_plugin/oct.hpp>
#include <ignition/gazebo/Util.hh>
#include <ignition/plugin/Register.hh>
#include <ignition/gazebo/components/JointVelocityCmd.hh>
#include <ignition/gazebo/components/World.hh>
#include <ignition/gazebo/components/Name.hh>
#include <ignition/gazebo/components/Model.hh>
#include <ignition/gazebo/components/Link.hh>
#include <ignition/gazebo/components/Pose.hh>
#include <ignition/math/Pose3.hh>
#include <ignition/math/Quaternion.hh>

oct_system::oct_system(){
  std::cout << "constructor" << std::endl;
}
oct_system::~oct_system(){}

void oct_system::Configure( const ignition::gazebo::Entity& entity,
			    const std::shared_ptr<const sdf::Element>& sdf,
			    ignition::gazebo::EntityComponentManager& ecm,
			    ignition::gazebo::EventManager& eventmgr ){
  igndbg << "configure";
  igndbg << sdf->ToString("element");

  // I don't think this model parent in the sdf should be needed but the plugin seems to need to be 
  // attached to a model
  towersModel = ignition::gazebo::Model(entity);

  // get tower names from sdf

  if (sdf->HasElement("towerA") ) {
    towerA_name = sdf->Get<std::string>("towerA");
    igndbg << "towerA name: " << towerA_name << std::endl;
  } else {
    ignerr << "oct_plugin requires <towerA> element" << std::endl;
    return;
  }
  
  if (sdf->HasElement("towerB") ) {
    towerB_name = sdf->Get<std::string>("towerB");
    igndbg << "towerB name: " << towerB_name << std::endl;
  } else {
    ignerr << "oct_plugin requires <towerB> element" << std::endl;
    return;
  }
  
  // get tower models

  auto towerAModel = ignition::gazebo::Model(
      ecm.EntityByComponents(ignition::gazebo::components::Name(towerA_name), 
        ignition::gazebo::components::Model()));
  if (!towerAModel.Valid(ecm))
  {
    ignerr << "towerA entity not found" << std::endl;
    return;
  }
  if (towerAModel.Name(ecm) != "")
  {
    igndbg << "towerA model name: " << towerAModel.Name(ecm) << std::endl;
  }
  
  auto towerBModel = ignition::gazebo::Model(
      ecm.EntityByComponents(ignition::gazebo::components::Name(towerB_name), 
        ignition::gazebo::components::Model()));
  if (!towerBModel.Valid(ecm))
  {
    ignerr << "towerB entity not found" << std::endl;
    return;
  }
  if (towerBModel.Name(ecm) != "")
  {
    igndbg << "towerB model name: " << towerBModel.Name(ecm) << std::endl;
  }

  // get tower links 
  
  towerALink = ignition::gazebo::Link(towerAModel.LinkByName(ecm, "cylinder_link"));
  if (!towerALink.Valid(ecm))
  {
    ignerr << "towerA link entity not found" << std::endl;
    return;
  }
  if (towerALink.Name(ecm) != "")
  {
    igndbg << "towerA link name: " << towerALink.Name(ecm).value() << std::endl;
  }
  
  towerBLink = ignition::gazebo::Link(towerBModel.LinkByName(ecm, "cylinder_link"));
  if (!towerBLink.Valid(ecm))
  {
    ignerr << "towerB link entity not found" << std::endl;
    return;
  }
  if (towerBLink.Name(ecm) != "")
  {
    igndbg << "towerB link name: " << towerBLink.Name(ecm).value() << std::endl;
  }
  
  std::vector<std::string> p1Topics;
  if (sdf->HasElement("p1_topic")){
    p1Topics.push_back(sdf->Get<std::string>("p1_topic"));
  }
  p1Topics.push_back("/oct/p1");
  auto p1Topic = ignition::gazebo::validTopic(p1Topics);

  p1Pub = node.Advertise<ignition::msgs::Pose>(p1Topic);
  
  std::vector<std::string> p2Topics;
  if (sdf->HasElement("p2_topic")){
    p2Topics.push_back(sdf->Get<std::string>("p2_topic"));
  }
  p2Topics.push_back("/oct/p2");
  auto p2Topic = ignition::gazebo::validTopic(p2Topics);

  p2Pub = node.Advertise<ignition::msgs::Pose>(p2Topic);

  if (sdf->HasElement("frame_id"))
    sdfFrameId = sdf->Get<std::string>("frame_id");
  
  if (sdf->HasElement("child_frame_id"))
    sdfChildFrameId = sdf->Get<std::string>("child_frame_id");
}

void oct_system::PreUpdate( const ignition::gazebo::UpdateInfo& info,
			    ignition::gazebo::EntityComponentManager& ecm ){
  igndbg << "preupdate" << std::endl;

  if(!ecm.EntityHasComponentType(towerALink.Entity(), ignition::gazebo::components::Pose::typeId))
  {
    igndbg << "Adding WorldPose component to tower A link" << std::endl;
    ecm.CreateComponent(towerALink.Entity(), ignition::gazebo::components::Pose());
  }
  if(!ecm.EntityHasComponentType(towerBLink.Entity(), ignition::gazebo::components::Pose::typeId))
  {
    igndbg << "Adding WorldPose component to tower B link" << std::endl;
    ecm.CreateComponent(towerBLink.Entity(), ignition::gazebo::components::Pose());
  }
}

void oct_system::PostUpdate( const ignition::gazebo::UpdateInfo& info,
			     const ignition::gazebo::EntityComponentManager& ecm ){
  igndbg << "postupdate" << std::endl;
  
  // collect world position of each tower

  ignition::math::Pose3d towerAPose = worldPose(towerALink.Entity(), ecm);
  float Xa = towerAPose.Pos().X();
  float Ya = towerAPose.Pos().Y();

  igndbg << "towerA world position: " << 
    Xa << ", " <<
    Ya << std::endl;
  
  ignition::math::Pose3d towerBPose = worldPose(towerBLink.Entity(), ecm);
  float Xb = towerBPose.Pos().X();
  float Yb = towerBPose.Pos().Y();

  igndbg << "towerB world position: " << 
    Xb << ", " <<  
    Yb << std::endl;

  // collect world position of oct robot
  
  auto octModel = ignition::gazebo::Model(
      ecm.EntityByComponents(ignition::gazebo::components::Name("oct_test")));
  if (!octModel.Valid(ecm))
  {
    ignerr << "oct entity not found" << std::endl;
    return;
  }
  if (octModel.Name(ecm) != "")
  {
    igndbg << "oct model name: " << octModel.Name(ecm) << std::endl;
  }

  ignition::math::Pose3d octPose = worldPose(octModel.Entity(), ecm);
  float Xe = octPose.Pos().X();
  float Ye = octPose.Pos().Y();

  igndbg << "oct world position: " <<
    Xe << ", " << 
    Ye << std::endl;

  // calculate r1 and r2
  // 
  float diffAX = Xe - Xa;
  float diffAY = Ye - Ya;
  float r1 = sqrt((diffAX * diffAX) + (diffAY * diffAY));
  
  float diffBX = Xe - Xb;
  float diffBY = Ye - Yb;
  float r2 = sqrt((diffBX * diffBX) + (diffBY * diffBY));
  
  igndbg << "r1: " << r1 << "; " << "r2: " << r2 << std::endl;

  // separation of circles
  //
  float D = sqrt(pow(Xa - Xb, 2) + pow(Ya - Yb, 2));
  
  igndbg << "D: " << D << std::endl;

  // solve for intersection points of two circles
  // 
  float tolerance = 0.01; // tolerance when testing equality of distances

  float x1 = 0.0;
  float x2 = 0.0; 
  float y1 = 0.0;
  float y2 = 0.0;

  if (((r1 + r2) <= (D + tolerance)) && ((r1 + r2) >= (D - tolerance))) { // in between towers on line connecting two towers' centers
    igndbg << "one solution: in between towers" << std::endl;

    y1 = -1*(r1-r2);
    y2 = y1;

    x1 = 0.0;
    x2 = 0.0;
    
    igndbg << "x1: " << x1 << ", x2: " << x2 << std::endl;
    igndbg << "y1: " << y1 << ", y2: " << y2 << std::endl;
  } else {
    igndbg << "two solutions" << std::endl;

    float F = (-1/(2*(Ya-Yb)));
    float A = F*2*(Xa-Xb);
    float B = F*( (pow(r1,2) - pow(r2,2)) - (pow(Xa,2) - pow(Xb,2)) - (pow(Ya,2) - pow(Yb,2)) );
    float K = B - Ya;

    float a = (1 + pow(A,2)); 
    float b = 2*(A*K - Xa);
    float c = pow(Xa,2) + pow(K,2) - pow(r1,2);
    
    igndbg << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    igndbg << "determinant: " << pow(b,2)-4*a*c << std::endl;

    x1 = (-b + sqrt(pow(b,2) - 4*a*c)) / (2*a);
    x2 = (-b - sqrt(pow(b,2) - 4*a*c)) / (2*a);

    igndbg << "x1: " << x1 << ", x2: " << x2 << std::endl;

    y1 = F*A*x1 + B;
    y2 = F*A*x2 + B;
    
    igndbg << "y1: " << y1 << ", y2: " << y2 << std::endl;
  }
  
  // Construct the p1 and p2 messages and publish them.
  ignition::msgs::Pose p1Msg;
  ignition::msgs::Pose p2Msg;
  
  p1Msg.mutable_position()->set_x(x1);
  p1Msg.mutable_position()->set_y(y1);
  p1Msg.mutable_position()->set_z(0.0);
  
  p2Msg.mutable_position()->set_x(x2);
  p2Msg.mutable_position()->set_y(y2);
  p2Msg.mutable_position()->set_z(0.0);
  
  ignition::math::Quaterniond orientation = ignition::math::Quaterniond::Identity;
  ignition::msgs::Set(p1Msg.mutable_orientation(), orientation);
  
  // Set the time stamp in the header
  p1Msg.mutable_header()->mutable_stamp()->CopyFrom(ignition::gazebo::convert<ignition::msgs::Time>(info.simTime));
  p2Msg.mutable_header()->mutable_stamp()->CopyFrom(ignition::gazebo::convert<ignition::msgs::Time>(info.simTime));
  
  // Set the frame id
  auto frame1 = p1Msg.mutable_header()->add_data();
  frame1->set_key("frame_id");
  if (sdfFrameId.empty())
    {
      frame1->add_value("world");
    }
  else
    {
      frame1->add_value(sdfFrameId);
    }
  
  std::string linkName1 = "p1";
  if (sdfChildFrameId.empty())
    {
    if (linkName1 != "")
      {
        auto childFrame = p1Msg.mutable_header()->add_data();
        childFrame->set_key("child_frame_id");
        childFrame->add_value(linkName1);
      }
    }
  else
  {
    auto childFrame = p1Msg.mutable_header()->add_data();
    childFrame->set_key("child_frame_id");
    childFrame->add_value(sdfChildFrameId);
  }
  
  auto frame2 = p2Msg.mutable_header()->add_data();
  frame2->set_key("frame_id");
  if (sdfFrameId.empty())
    {
      frame2->add_value("world");
    }
  else
    {
      frame2->add_value(sdfFrameId);
    }
  
  std::string linkName2 = "p2";
  if (sdfChildFrameId.empty())
    {
    if (linkName2 != "")
      {
        auto childFrame = p2Msg.mutable_header()->add_data();
        childFrame->set_key("child_frame_id");
        childFrame->add_value(linkName2);
      }
    }
  else
  {
    auto childFrame = p2Msg.mutable_header()->add_data();
    childFrame->set_key("child_frame_id");
    childFrame->add_value(sdfChildFrameId);
  }
  
  // Publish the messages
  p1Pub.Publish(p1Msg);
  p2Pub.Publish(p2Msg);
}

IGNITION_ADD_PLUGIN( oct_system,
		     ignition::gazebo::System,
		     oct_system::ISystemConfigure,
		     oct_system::ISystemPreUpdate,
		     oct_system::ISystemPostUpdate )

