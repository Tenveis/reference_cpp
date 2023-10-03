#include "reference_cpp/topic/publish.h"

Publish::Publish()
    : Node("reference_publish"), counter_(0)
{
    init_pub();
    RCLCPP_INFO(this->get_logger(), "Publish class has been inititalized.");
}

void Publish::init_pub()
{
    ref_pub_ = this->create_publisher<std_msgs::msg::String>("ref_chatter", 10);

    ref_pub_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000),
        std::bind(&Publish::ref_pub_call, this));
}

void Publish::ref_pub_call()
{
    counter_++;
    std_msgs::msg::String msg;
    msg.data = "simple pub: " + std::to_string(counter_);

    ref_pub_->publish(msg);
}
