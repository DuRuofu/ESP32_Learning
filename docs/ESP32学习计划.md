 ### 说明：

1. 本文档由DuRuofu撰写，由DuRuofu负责解释及执行。
### 修订历史：

| 文档名称                     | 版本   | 作者    | 时间       | 备注     |
| ---------------------------- | ------ | ------- | ---------- | -------- |
| ESP32学习计划 | v1.0.0 | DuRuofu | 2023-08-28 | 首次建立 |
| ESP32学习计划 | v1.0.1 | DuRuofu | 2023-09-2 | 补充 |
| ESP32学习计划 | v1.1.0 | DuRuofu | 2023-09-13 | 补充 |
# ESP32学习计划

## 一、认知阶段

> 目标：学会安装esp-idf开发环境，并使用其烧录代码，学会工具使用。

### 1. 1  **准备开发环境**：

安装 esp-idf 开发环境，并进行设置。

参考：

>基础搭建：[ESP-IDF环境搭建](https://www.bilibili.com/video/BV1E841177Tu/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)+[官方安装教程](https://docs.espressif.com/projects/esp-idf/zh_CN/v5.1.2/esp32/get-started/index.html#get-started-how-to-get-esp-idf)
>进阶搭建: [linux下ESP32开发环境搭建](https://duruofu.github.io/2024/01/25/4.%E7%A1%AC%E4%BB%B6%E7%9B%B8%E5%85%B3/MCU/ESP32/%E6%90%AD%E5%BB%BAesp-idf%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83/#%E5%9B%9B%E3%80%81-%E9%85%8D%E7%BD%AE%E5%BF%AB%E6%8D%B7%E6%8C%87%E4%BB%A4) +[vscdoe配合虚拟机远程连接开发](https://duruofu.github.io/2024/01/30/4.%E7%A1%AC%E4%BB%B6%E7%9B%B8%E5%85%B3/MCU/ESP32/vscdoe+%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%BC%80%E5%8F%91ESP32/#2-2-%E6%89%8B%E8%BE%93%E5%91%BD%E4%BB%A4%E5%A4%AA%E9%BA%BB%E7%83%A6%E7%9A%84%E9%97%AE%E9%A2%98)

这里提供一个搭建好4.4.6以及5.1.2 版本的虚拟机：[虚拟机-网盘分享](https://www.alipan.com/s/i8yiHDk8nMN) ,提取码：3j9a
虚拟机密码：3.1415926

基于官方提供的示例程序，我们可以了解到最基本的工程结构：

>代码参考：[01.example/sample_project](https://github.com/DuRuofu/ESP32_Learning/tree/master/01.example/sample_project)

### 1.2 点灯程序：

创建一个最简单的程序，点亮板载的LED灯。（使用官方历程）

>视频参考：[ESP-IDF点灯](https://www.bilibili.com/video/BV1nR4y1o7VE/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)
>代码参考：[01.example/blink](https://github.com/DuRuofu/ESP32_Learning/tree/master/01.example/blink)

### 1.3 **Hello World 程序**：
  
  创建一个最简单的程序，如打印 "Hello world!" 到串口。（使用官方历程）
  
> 视频参考：[Hello World 程序](https://www.bilibili.com/video/BV1Rd4y1b7CE/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)
> 代码参考：[01.example/hello_world](https://github.com/DuRuofu/ESP32_Learning/tree/master/01.example/hello_world)

## 二、IDF学习

> 目标：学会安装esp-idf开发环境的项目配置，包括配置菜单，可变参数宏，组件机制。

### 2.1  ESP32工程结构及构建

> 教程参考：[ESP32工程结构及构建](02.IDF开发入门/2.1-ESP32工程结构及构建/ESP32工程结构及构建.md)
> 官方参考：[ESP-IDF编程指南/API指南/构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html)

### 2.2  ESP-IDF项目配置（Menuconfig）

> 教程参考：[ESP-IDF项目配置](02.IDF开发入门/2.2-ESP-IDF项目配置/ESP-IDF项目配置.md)
> 官方参考：[ESP-IDF编程指南/API参考/项目配置](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/kconfig.html)
> 视频参考:   [ESP-IDF自定义菜单](https://www.bilibili.com/video/BV1S44y1D7cf/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)
> 代码参考:  https://github.com/DuRuofu/ESP32_Learning/tree/master/02.idf_basis/blink_menuconfig

### 2.3  ESP-IDF自定义组件（components）


> 教程参考：[ESP-IDF自定义组件](02.IDF开发入门/2.3-ESP-IDF自定义组件/ESP-IDF自定义组件.md)
> 官方参考：[API指南->构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html#component-configuration)
> 视频参考:  [ESP32-IDF中cmake文件管理](https://www.bilibili.com/video/BV1w14y1s7oy/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)
> 代码参考:  https://github.com/DuRuofu/ESP32_Learning/tree/master/02.idf_basis/blink_component
### 2.4  ESP-IDF组件管理器

> 教程参考：[ESP-IDF组件管理器](02.IDF开发入门/2.4-ESP-IDF组件管理器/ESP-IDF组件管理器.md)
> 官方参考：[API指南->构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html#component-configuration)
> 视频参考:  [ESP32-IDF中cmake文件管理](https://www.bilibili.com/video/BV1w14y1s7oy/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)
> 代码参考:  https://github.com/DuRuofu/ESP32_Learning/tree/master/02.idf_basis/button_component

## 三、基础外设学习

### 3.1 GPIO

#### 3.1.1 GPIO输出/输出

> 教程参考：[ESP32外设-GPIO入门](03.ESP32基础外设入门/3.1-ESP32外设-GPIO入门/ESP32外设-GPIO入门.md)
> 官方参考：[GPIO & RTC GPIO](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/gpio.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/gpio

#### 3.1.2 GPIO中断

> 教程参考：[ESP32外设-GPIO入门](03.ESP32基础外设入门/3.1-ESP32外设-GPIO入门/ESP32外设-GPIO入门.md)
> 官方参考：[GPIO & RTC GPIO](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/gpio.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/gpio_exit

### 3.2 UART

> 教程参考：[ESP32外设-UART入门](03.ESP32基础外设入门/3.2-ESP32外设-UART入门/ESP32外设-UART入门.md)
> 官方参考：[外设API->通用异步接收器/发送器 (UART)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/uart.html#uart-api-setting-communication-parameters)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/uart

### 3.3 硬件定时器


> 教程参考：[ESP32外设-硬件定时器入门](03.ESP32基础外设入门/3.3-ESP32外设-硬件定时器入门/ESP32外设-硬件定时器入门.md)
> 官方参考：[通用定时器](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/gptimer.html#id26)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/gptimer

### 3.4 ADC

#### 3.4.1 ADC单次转换

> 教程参考：[ESP32外设-ADC入门](03.ESP32基础外设入门/3.4-ESP32外设-ADC入门/ESP32外设-ADC入门.md)
> 官方参考：[模数转换器 (ADC-单次)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/adc_oneshot.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/adc_oneshot

#### 3.4.2 ADC连续转换

> 教程参考：[ESP32外设-ADC入门](03.ESP32基础外设入门/3.4-ESP32外设-ADC入门/ESP32外设-ADC入门.md)
> 官方参考：[模数转换器 (ADC-连续)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/adc_continuous.html#)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/adc_continuous

### 3.5 DAC

> 教程参考：[ESP32外设-DAC入门](03.ESP32基础外设入门/3.5-ESP32外设-DAC入门/ESP32外设-DAC入门.md)
> 官方参考：[模数转换器 (ADC-连续)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/adc_continuous.html#)
> 代码参考1： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/dac_oneshot
> 代码参考2： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/dac_cosine


### 3.6 LED PWM 

> 教程参考：[ESP32外设-LEDPWM入门](03.ESP32基础外设入门/3.6-ESP32外设-LEDPWM入门/ESP32外设-LEDPWM入门.md)
> 官方参考：[LED PWM 控制器](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/peripherals/ledc.html#led-pwm "永久链接至标题")
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/led_pwm


### 3.7 I2C

> 教程参考：[ESP32外设-I2C入门](03.ESP32基础外设入门/3.7-ESP32外设-I2C入门/ESP32外设-I2C入门.md)
> 官方参考：[I2C 驱动程序](https://docs.espressif.com/projects/esp-idf/zh_CN/release-v5.1/esp32/api-reference/peripherals/i2c.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/03.peripheral/i2c_bh1750

### 3.8 SPI

> 教程参考：
> 官方参考：
> 代码参考： 


## 四、ESP32存储器学习

### 4.1 分区表

> 教程参考：[ESP32存储-分区表入门](04.ESP32存储器入门/4.1-ESP32存储-分区表入门/ESP32存储-分区表入门.md)
> 官方参考：[分区表](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/partition-tables.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/04.storage/partition

### 4.2 非易失性存储 (NVS)

> 教程参考：[ESP32存储-非易失性存储 (NVS)入门](04.ESP32存储器入门/4.2-ESP32存储-非易失性存储%20(NVS)/ESP32存储-非易失性存储%20(NVS)入门.md)
> 官方参考：[分区表](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/partition-tables.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/04.storage/nvs

### 4.3  FAT文件系统

> 教程参考：[ESP32存储-VFS虚拟文件系统入门](04.ESP32存储器入门/4.3-ESP32存储-VFS文件系统/ESP32存储-VFS虚拟文件系统入门.md)
> 官方参考：[FAT 文件系统](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/storage/fatfs.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/04.storage/flash_fatfs


### 4.4 SPIFFS 文件系统

> 教程参考：[ESP32存储-SPIFFS文件系统](04.ESP32存储器入门/4.4-ESP32存储-SPIFFS文件系统入门/ESP32存储-SPIFFS文件系统.md)
> 官方参考：[SPIFFS 文件系统](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/storage/spiffs.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/04.storage/flash_spiffs


## 五、ESP32 WFI学习

### 5.1  WIFI入门

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.2 TCP协议

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.3 UDP协议

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.4 HTTP协议

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.5 webSocket协议

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.6 MQTT协议

> 教程参考：
> 官方参考：
> 代码参考： 
### 5.7 ESP-NOW协议

> 教程参考：
> 官方参考：
> 代码参考： 

### 5.8 WIFI配网


## 六、ESP32 蓝牙学习


## 七、ESP32其他系统API学习

### 7.1 软件定时器

> 教程参考：[ESP32系统API-软件定时器](07.ESP32系统API入门/7.1-软件定时器/ESP32系统API-软件定时器.md)
> 官方参考：[ESP 定时器](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/system/esp_timer.html)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/07.system/esp_timer


### 7.2 控制台终端

> 教程参考：
> 官方参考：[控制台终端](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-reference/system/console.html)
> 代码参考： 


## 八、ESP32FreeRTOS


### 8.1 FreeRTOS基础


### 8.2 ESP32中FreeRTOS启动过程


### 8.3 任务（task）


### 8.4 队列传递数据


### 8.5 定时器&信号量


### 8.6 事件组


### 8.7 任务通知


### 8.8 流数据/消息


## 九、GUI学习


### 9.1 LVGL的移植

#### 9.1.1 以GC9A01为例（SPI）

> 教程参考：[基于ESP-IDF官方组件移植LVGL(GC9A01无触摸)](08.ESP32GUI入门/8.1-使用组件管理器移植LVGL/基于ESP-IDF官方组件移植LVGL(以GC9A01为例)/基于ESP-IDF官方组件移植LVGL(GC9A01无触摸).md)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/08.gui/lvgl_component


#### 9.1.2 以SPD2010(带触摸)为例（QSPI +I2C）

> 教程参考：[基于ESP-IDF官方组件移植LVGL(SPD2010带触摸)](08.ESP32GUI入门/8.1-使用组件管理器移植LVGL/基于ESP-IDF官方组件移植LVGL(SPD2010带触摸)/基于ESP-IDF官方组件移植LVGL(SPD2010带触摸).md)
> 代码参考： https://github.com/DuRuofu/ESP32_Learning/tree/master/08.gui/lvgl_component


## 十、其他外部硬件demo








# 参考链接

- 孤独的二进制：https://space.bilibili.com/1375767826
- Augtons正(单片机)：https://blog.csdn.net/m0_50064262/article/details/120250151
- 乐鑫文档：https://docs.espressif.com/projects/esp-idf/zh_CN/release-v4.4/esp32c3/index.html
- 第九个下弦月：https://space.bilibili.com/34165842?spm_id_from=333.999.0.0
- **Michael_ee**：https://space.bilibili.com/505630520/fans/follow?tagid=529812
