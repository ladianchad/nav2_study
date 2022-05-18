#include <custom_controller/custom_contorller.hpp>

namespace custom_controller
{
CustomController::CustomController()
: nav2_core::Controller()
{}

void 
CustomController::configure(
  const rclcpp_lifecycle::LifecycleNode::SharedPtr &parents,
  std::string name, const std::shared_ptr<tf2_ros::Buffer> &tf,
  const std::shared_ptr<nav2_costmap_2d::Costmap2DROS> &)
{
  node_ = parents;
  tf_ = tf;
  publisher_ = node_->create_publisher<std_msgs::msg::String>("topic", 10);
}

void 
CustomController::cleanup()
{}

void 
CustomController::activate()
{
  publisher_->on_activate();
}

void 
CustomController::deactivate()
{}

void 
CustomController::setPlan(const nav_msgs::msg::Path & path)
{}

geometry_msgs::msg::TwistStamped 
CustomController::computeVelocityCommands(
  const geometry_msgs::msg::PoseStamped & pose,
  const geometry_msgs::msg::Twist & velocity)
{
  return geometry_msgs::msg::TwistStamped();
}
} // namespace custom_cotroller


#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(custom_cotroller::CustomController, nav2_core::Controller)