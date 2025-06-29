#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <autoware_adapi_v1_msgs/srv/initialize_localization.hpp>

namespace mibot_autoware_api{
	TestApi::TestApi(const rclcpp::Nodeoptions& options) : rclcpp::Node("test_api", options){
		client = this->create_client<autoware_adapi_v1_msgs::srv::InitializeLocalization>()

		autoware_adapi_v1_msgs::srv::Initializelocalization::SharedPtr request;

		request->pose.header.frame_id = "base_link";
		request->pose.header.stamp = this->get_clock()->now();
		request->pose.pose.pose.position.x=90612;
		request->pose.pose.pose.position.y=5735;
		request->pose.pose.pose.position.z=62;
		request->pose.pose.pose.orientation.x = 0;
		request->pose.pose.pose.orientation.y = 0;
		request->pose.pose.pose.orientation.z = 0;
		request->pose.pose.pose.orientation.w = 1;
		request->pose.pose.covariance[0] = 10;
		request->pose.pose.covariance[7] = 10;
		request->pose.pose.covariance[14] = 10;
		request->pose.pose.covariance[35] = 0.1;

		while(!client->wait_for_service(std::chrono::seconds{1})){
			if(!rclcpp::ok()){
				RCLCPP_ERROR(this->get_logger(), "ERROR!");
				return 0;
			}
		}

		client->async_send_request(request);
	}

	TestApi::~TestApi(void){
		;
	}
}

RCLCPP_COMPONENTS_REGISTER_NODE(mibot_autoware_api::TestApi)