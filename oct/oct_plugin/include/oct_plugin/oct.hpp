#include <ignition/gazebo/System.hh>
#include <ignition/transport/Node.hh>
#include <ignition/gazebo/Link.hh>
#include <ignition/gazebo/Model.hh>
#include <ignition/gazebo/World.hh>

class oct_system:

  public ignition::gazebo::System,
  public ignition::gazebo::ISystemConfigure,
  public ignition::gazebo::ISystemPreUpdate,
  public ignition::gazebo::ISystemPostUpdate {

private:

  ignition::transport::Node node;
  ignition::gazebo::Link towerALink;
  ignition::gazebo::Link towerBLink;
  std::string towerA_name;
  std::string towerB_name;

  /// \brief model holding towers...probably shouldn't be needed
  ignition::gazebo::Model towersModel{ignition::gazebo::kNullEntity};
  
  /// \brief robot positions publishers
  ignition::transport::Node::Publisher p1Pub;
  ignition::transport::Node::Publisher p2Pub;
  
  /// \brief frame_id from sdf.
  std::string sdfFrameId;
  
  /// \brief child_frame_id from sdf.
  std::string sdfChildFrameId;

public:

  oct_system();
  ~oct_system();

  void Configure( const ignition::gazebo::Entity& entity,
		  const std::shared_ptr<const sdf::Element>& sdf,
		  ignition::gazebo::EntityComponentManager& ecm,
		  ignition::gazebo::EventManager& eventmgr ) override;

  void PreUpdate( const ignition::gazebo::UpdateInfo& info,
		  ignition::gazebo::EntityComponentManager& ecm ) override;

  void PostUpdate( const ignition::gazebo::UpdateInfo& info,
		   const ignition::gazebo::EntityComponentManager& ecm ) override;
  
};
