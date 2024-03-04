#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_timer.h"

static const char *TAG = "esp_timer";

static void periodic_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);
}

static void oneshot_timer_callback(void* arg)
{
    int64_t time_since_boot = esp_timer_get_time();
    ESP_LOGI(TAG, "One-shot timer called, time since boot: %lld us", time_since_boot);
}

void app_main(void)
{
	// 定义定时器句柄
	esp_timer_handle_t oneshot_timer ,periodic_timer;

    // 创建一个周期定时器
    const esp_timer_create_args_t periodic_timer_args = {
            .callback = &periodic_timer_callback,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodic"
    };//周期定时器配置
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));

	// 创建一个单次定时器
    const esp_timer_create_args_t oneshot_timer_args = {
            .callback = &oneshot_timer_callback,
            .name = "one-shot"
    };//单次定时器配置
    ESP_ERROR_CHECK(esp_timer_create(&oneshot_timer_args, &oneshot_timer));
    /* Start the timers */
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1000000));//1s回调一次
    ESP_ERROR_CHECK(esp_timer_start_once(oneshot_timer, 5000000));//5s后回调
    ESP_LOGI(TAG, "Started timers, time since boot: %lld us", esp_timer_get_time());


	vTaskDelay(10000 / portTICK_PERIOD_MS);  // 10s后删除定时器
	/* Clean up and finish the example */
    ESP_ERROR_CHECK(esp_timer_stop(periodic_timer));
    ESP_ERROR_CHECK(esp_timer_delete(periodic_timer));
    ESP_ERROR_CHECK(esp_timer_delete(oneshot_timer));
}
