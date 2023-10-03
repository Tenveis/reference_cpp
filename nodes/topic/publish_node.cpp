/*TODO: include header file.
    example: #include "package_name/header_file.h"
*/
#include "reference_cpp/topic/publish.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*TODO: add class name */
    auto node = std::make_shared<Publish /* here */>();
    RCLCPP_INFO(node->get_logger(), "publish_node is created.");
    
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}