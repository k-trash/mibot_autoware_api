#ifndef __LIB_TEST_API__
#define __LIB_TEST_API__

#include <rclcpp/rclcpp.hpp>
#include <autoware_adapi_v1_msgs/srv/initialize_localization.hpp>

namespace mibot_autoware_api{
	class ApiTest : public rclcpp::Node{
		public:
			explicit ApiTest(const rclcpp::NodeOptions& options);
			virtual ~ApiTest(void);
		private:
		rclcpp::Client<autoware_adapi_v1_msgs::srv::InitializeLoalization>::SharedPtr client;
	};
}

#endif