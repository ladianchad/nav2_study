#ifndef CUSTOM_CONTROLLER__CUSTOM_CONTROLLER_HPP_
#define CUSTOM_CONTROLLER__CUSTOM_CONTROLLER_HPP_

#include <nav2_core/controller.hpp>
#include <nav_msgs/msg/path.hpp>
#include <std_msgs/msg/string.hpp>

namespace custom_controller
{

class CustomController : public nav2_core::Controller
{
public:
  CustomController();

  void configure(
    const rclcpp_lifecycle::LifecycleNode::SharedPtr &parents,
    std::string name, const std::shared_ptr<tf2_ros::Buffer> &tf,
    const std::shared_ptr<nav2_costmap_2d::Costmap2DROS> &) override;

  void cleanup() override;

  void activate() override;

  void deactivate() override;

  void setPlan(const nav_msgs::msg::Path & path) override;

  geometry_msgs::msg::TwistStamped computeVelocityCommands(
    const geometry_msgs::msg::PoseStamped & pose,
    const geometry_msgs::msg::Twist & velocity) override;

private:
  rclcpp_lifecycle::LifecycleNode::SharedPtr node_;
  std::shared_ptr<tf2_ros::Buffer> tf_;
  rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr publisher_;

};

} // namespace custom_controller

#endif
