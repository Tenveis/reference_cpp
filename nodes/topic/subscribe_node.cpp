/*TODO: include header file.
    example: #include "package_name/header_file.h"
*/
#include "reference_cpp/topic/subscribe.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*TODO: add class name */
    auto node = std::make_shared<Subscribe /* here */>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}