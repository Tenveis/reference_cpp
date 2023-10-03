#include "reference_cpp/topic/subscribe.h"

Subscribe::Subscribe() : Node("reference_subscribe")
{
    init_sub();
    RCLCPP_INFO(this->get_logger(), "Subscribe class has been inititalized.");
}

void Subscribe::init_sub()
{
    ref_sub_ = this->create_subscription<std_msgs::msg::String>(
        "ref_chatter", 10,
        std::bind(&Subscribe::ref_sub_callback, this, std::placeholders::_1));
}

void Subscribe::ref_sub_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "received->[ %s ]",msg->data.c_str());
}
