#include <rclcpp/rclcpp.hpp>

#include <sensor_msgs/msg/joint_state.hpp>

#include <memory>
#include <string>
#include <vector>

std::shared_ptr<rclcpp::Node> node;

void sub_callback(const sensor_msgs::msg::JointState& msg) {
  for (size_t i = 0; i < msg.position.size(); i++) {
    std::cout << "Joint " << i + 1 << ": " << msg.position[i] << std::setw(15);
  }
  std::cout << std::endl;
  rclcpp::shutdown();
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  node = std::make_shared<rclcpp::Node>("joint_trajectory_node");

  std::cout << "node created" << std::endl;

  auto subscription = node->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 1, sub_callback);

  rclcpp::spin(node);
  
  rclcpp::shutdown();

  return 0;
}
