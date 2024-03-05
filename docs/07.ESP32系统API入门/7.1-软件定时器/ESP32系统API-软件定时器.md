
### 说明：

1. 本文档由DuRuofu撰写，由DuRuofu负责解释及执行。
2. 本文档介绍ESP32的软件定时器。

### 修订历史：

| 文档名称             | 版本     | 作者      | 时间         | 备注   |
| ---------------- | ------ | ------- | ---------- | ---- |
| ESP32系统API-软件定时器 | v1.0.0 | DuRuofu | 2024-03-04 | 首次建立 |

<div STYLE="page-break-after: always;"></div>

# ESP32系统API-软件定时器

## 一、介绍

本节介绍：高分辨率软件定时器（esp_imer），推荐选择esp_timer定时器作为esp32首选软件定时器。

FreeRTOS提供软件计时器，但这些计时器有一些限制:
1. 最大分辨率等于RTOS滴答周期
2. FreeRTOS的定时器回调来自于一个低优先级的任务。

硬件定时器不受限制，但配置复杂，只能设置一个比较值(警报值)，要灵活使用比较麻烦。

esp_timer定时器有两种工作方式：单次模式/周期模式

## 二、esp_timer定时器使用

头文件：

```c
#include "esp_timer.h"
```

#### 一、初始化软件定时器

创建定时器句柄：`esp_timer_handle_t`

创建并配置结构体：

``` c
typedef struct {
    esp_timer_cb_t callback;        //函数在计时器到期的回调函数
    void* arg;                      //传递给回调函数的参数
    esp_timer_dispatch_t dispatch_method; //从任务或ISR调用回调
    const char* name;               //定时名称（字符串）
} esp_timer_create_args_t;
```

使用`esp_timer_create`创建定时器：
```c
esp_err_t esp_timer_create(const esp_timer_create_args_t* create_args, esp_timer_handle_t* out_handle);
```
参数：
`create_args` ：参数，也就是2.1中的变量类型； 
`out_handle`：定时器句柄；
`esp_err_t`：返回值，ESP_OK表示创建成功，其他表示失败。

#### 二、启动软件定时器

##### 启动一个周期定时器

```c
esp_err_t esp_timer_start_periodic(esp_timer_handle_t timer, uint64_t period);
```

`timer` ：定时器句柄； `period`：定时时长，单位是微秒； `esp_err_t`：返回值，ESP_OK表示创建成功，其他表示失败。

##### 启动一个单次定时器

```c
esp_err_t esp_timer_start_once(esp_timer_handle_t timer, uint64_t timeout_us);
```

`timer` ：定时器句柄； `period`：定时时长，单位是微秒； `esp_err_t`：返回值，ESP_OK表示创建成功，其他表示失败。

#### 三、停止和删除软件定时器

##### 停止一个定时器

```javascript
esp_err_t esp_timer_stop(esp_timer_handle_t timer);
```

既可以用于单词定时器、也可以用于周期定时器。 `timer` ：定时器句柄； `esp_err_t`：返回值，ESP_OK表示操作成功，其他表示失败。

##### 删除定时器

```javascript
esp_err_t esp_timer_delete(esp_timer_handle_t timer);
```

`timer` ：定时器句柄； `esp_err_t`：返回值，ESP_OK表示操作成功，其他表示失败。

## 三、使用案例

``` c
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

```

代码中先定义了两个定时器句柄，一个是周期定时器 (`periodic_timer`)，另一个是单次定时器 (`oneshot_timer`)。
然后分别使用 `esp_timer_create` 函数创建这两个定时器，指定了回调函数和名称。
接着使用 `esp_timer_start_periodic` 函数启动周期定时器，设置了定时器的周期为 1 秒。同时使用 `esp_timer_start_once` 函数启动单次定时器，设置了定时器在 5 秒后触发。
在主任务函数中，使用了 `vTaskDelay` 函数延迟了 10 秒，之后停止并删除了这两个定时器。

# 参考链接

1. https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/system/esp_timer.html
