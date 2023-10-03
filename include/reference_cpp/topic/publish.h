
#pragma once

#ifndef REFERENCE_CPP_TOPIC_PUBLISH_H
#define REFERENCE_CPP_TOPIC_PUBLISH_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class Publish : public rclcpp::Node
{
public:
    /* Constructor */
    Publish();

private:
    /* variable to count */
    int counter_;

    /* SharedPtr handle for publish topic. */
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr ref_pub_;

    /* SharedPtr handle for timer function */
    rclcpp::TimerBase::SharedPtr ref_pub_timer_;

    /* initialize all the publisher */
    void init_pub();

    /* timer callback for publisher */
    void ref_pub_call();
};

#endif