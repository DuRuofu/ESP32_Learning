### 说明：

1. 本文档由DuRuofu撰写，由DuRuofu负责解释及执行。
### 修订历史：

| 文档名称                     | 版本   | 作者    | 时间       | 备注     |
| ---------------------------- | ------ | ------- | ---------- | -------- |
| 项目组任务安排-ESP32学习计划 | v1.0.0 | DuRuofu | 2023-08-28 | 首次建立 |
| 项目组任务安排-ESP32学习计划 | v1.0.1 | DuRuofu | 2023-09-2 | 补充 |
| 项目组任务安排-ESP32学习计划 | v1.1.0 | DuRuofu | 2023-09-13 | 补充 |
# ESP32学习计划

## 一、认知阶段

- **准备开发环境**：安装 esp-idf 开发环境，并进行设置。
>基础搭建：[ESP-IDF环境搭建](https://www.bilibili.com/video/BV1E841177Tu/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)
>
>进阶搭建: [linux下ESP32开发环境搭建](https://duruofu.github.io/2024/01/25/4.%E7%A1%AC%E4%BB%B6%E7%9B%B8%E5%85%B3/MCU/ESP32/%E6%90%AD%E5%BB%BAesp-idf%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83/#%E5%9B%9B%E3%80%81-%E9%85%8D%E7%BD%AE%E5%BF%AB%E6%8D%B7%E6%8C%87%E4%BB%A4) +[vscdoe配合虚拟机远程连接开发](https://duruofu.github.io/2024/01/30/4.%E7%A1%AC%E4%BB%B6%E7%9B%B8%E5%85%B3/MCU/ESP32/vscdoe+%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%BC%80%E5%8F%91ESP32/#2-2-%E6%89%8B%E8%BE%93%E5%91%BD%E4%BB%A4%E5%A4%AA%E9%BA%BB%E7%83%A6%E7%9A%84%E9%97%AE%E9%A2%98)

- **点灯程序**：创建一个最简单的程序，点亮板载的LED灯。（使用官方历程）
>参考：[ESP-IDF点灯](https://www.bilibili.com/video/BV1nR4y1o7VE/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **Hello World 程序**：创建一个最简单的程序，如打印 "Hello,ESP32!" 到串口。（使用官方历程）
> 参考：[Hello World 程序](https://www.bilibili.com/video/BV1Rd4y1b7CE/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)

## 二、入门阶段
- **GPIO 控制**：使用 GPIO 控制 LED 灯的开关。
>参考：[ESP-IDF点灯](https://www.bilibili.com/video/BV1nR4y1o7VE/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **按钮输入**：使用 GPIO 监测按钮输入，使用按钮控制LED灯的开关。
>参考：[按键读取](https://blog.csdn.net/qq_24550925/article/details/85335516)

- **NVS：** 学习ESP32的NVS非易失性存储，并使用NVS保存开发板LED状态，使得系统复位后LED状态与复位前一致。
>参考:[NVS非易失性存储](https://www.bilibili.com/video/BV1nW4y1g7c5/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **使用 ADC**：学习ESP32的 ADC 的基本原理和使用方法，并且使用ADC读取一节干电池的电压，并且发送到上位机串口。

>参考:[ESP32ADC的使用](https://blog.csdn.net/m0_50064262/article/details/118817032)

- **日志模块**：自行学习ESP32的gebug日志模块，输出不同级别的日志。（极易）

>参考：[esp日志的使用](https://www.bilibili.com/video/BV1KG4y1d7Ed/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)

## 三、基础阶段
- **Wi-Fi 连接**：使用 ESP32 连接到 Wi-Fi 网络，并获取到实时时间。

> 参考：[WIFI基础篇](https://www.bilibili.com/video/BV16G4y1g72w/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)
>
> 参考：[ESP32 WIFI教程一: 开篇介绍](https://www.bilibili.com/video/BV1Dd4y1B7RT/?spm_id_from=333.337.search-card.all.click&vd_source=ef5a0ab0106372751602034cdd9ab98e)
>
> 参考:[ESP32-IDF下WIFI使用以及NTP时间获取](https://www.bilibili.com/video/BV1Ug411s7Ue/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **MQTT 通信**：实现 ESP32 与 MQTT 服务器的通信。（应该在进阶，但是需求度较高，故放在基础里。）

> 参考：[ESP32 WIFI教程二十四: MQTT简介](https://www.bilibili.com/video/BV1gG411u7DG/?spm_id_from=333.788&vd_source=ef5a0ab0106372751602034cdd9ab98e)
> 参考：[零基础入门学用物联网 – MQTT基础篇](http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-tuttorial/mqtt-tutorial/)

- **组件管理：** 学习ESP32的组件管理机制。

> 参考：[API指南->构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html#component-configuration)
>
> 参考：[ESP32-IDF中cmake文件管理(](https://www.bilibili.com/video/BV1w14y1s7oy/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **自定义菜单：** 学习ESP32的自定义宏菜单。

> 参考:[ESP-IDF自定义菜单](https://www.bilibili.com/video/BV1S44y1D7cf/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e)

- **温湿度传感器**：使用ESP的I2C接口实现读取DHT11温湿度传感器。

> 参考：[ESP官方外设驱动组件库](https://github.com/UncleRus/esp-idf-lib)



## 三、进阶阶段

- **FreeRTOS**：使用ESP32创建多线程任务。
- **TCP/UDP通信**：基于wifi完成与上位机的TCP或者UDP通信。
- **蓝牙通信**：使用 ESP32 进行蓝牙通信，完成基本的数据传输和控制功能。
- **LVGL**：在ESP32上移植LVGL，实现图形化界面。
- **OTA 升级**：学习 ESP32 的 OTA（Over The Air）升级机制，实现通过 Wi-Fi 远程更新程序。
- **Web 服务器**：使用 ESP32 实现 Web 服务器，可以在浏览器上访问并控制 ESP32 的各种功能。
# 参考链接

- 孤独的二进制：https://space.bilibili.com/1375767826
- Augtons正(单片机)：https://blog.csdn.net/m0_50064262/article/details/120250151
- 乐鑫文档：https://docs.espressif.com/projects/esp-idf/zh_CN/release-v4.4/esp32c3/index.html
- 第九个下弦月：https://space.bilibili.com/34165842?spm_id_from=333.999.0.0
- **Michael_ee**：https://space.bilibili.com/505630520/fans/follow?tagid=529812
