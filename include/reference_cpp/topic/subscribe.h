#pragma once

#ifndef REFERENCE_CPP_TOPIC_SUBSCRIBE_H
#define REFERENCE_CPP_TOPIC_SUBSCRIBE_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class Subscribe : public rclcpp::Node
{
public:
    Subscribe();

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr ref_sub_;

    void init_sub();
    void ref_sub_callback(const std_msgs::msg::String::SharedPtr msg);

};

#endif