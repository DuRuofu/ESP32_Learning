#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"

#define ESP_WIFI_AP_SSID DuRuofu_ESP32

void app_main(void)
{
	//----------------准备阶段-------------------
	// Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	//---------------初始化阶段------------------

	ESP_ERROR_CHECK(esp_netif_init());

	// 初始化默认事件循环
	ESP_ERROR_CHECK(esp_event_loop_create_default());

	// *esp_netif_ap 可以用来修改AP设置
	esp_netif_t *esp_netif_ap = esp_netif_create_default_wifi_ap();

	/*Initialize WiFi */
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	// WIFI_INIT_CONFIG_DEFAULT 是一个默认配置的宏
	ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	//---------------配置阶段--------------------
	// 设置为AP模式
	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));

	// AP详细配置
	wifi_config_t wifi_ap_config = {
		.ap = {
			.ssid = ESP_WIFI_AP_SSID,			  // WIFI名称
			.ssid_len = strlen(ESP_WIFI_AP_SSID), // 名称长度
			.channel =1,							  // WIFI信道
			.password = EXAMPLE_ESP_WIFI_AP_PASSWD,
			.max_connection = EXAMPLE_MAX_STA_CONN,
			.authmode = WIFI_AUTH_WPA2_PSK,        // WiFi认证方式
			.pmf_cfg = {
				.required = false,
			},
		},
	};
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_ap_config));
}
