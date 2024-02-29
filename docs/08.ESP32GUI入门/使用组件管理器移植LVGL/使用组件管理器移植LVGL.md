
### 说明：

1. 本文档由DuRuofu撰写，由DuRuofu负责解释及执行。
2. 本文记录使用使用组件管理器移植LVGL。

### 修订历史：

|  文档名称  |  版本  |  作者  |      时间      |   备注   |
| ---- | ---- | ------------ | ------ |
| 使用组件管理器移植LVGL |v1.0.0| DuRuofu | 2024-02-29 | 首次建立 |

<div STYLE="page-break-after: always;"></div>

# 使用组件管理器移植LVGL

![](attachments/Pasted%20image%2020240219001357.png)


一个字：香啊！

## 二、组件管理器怎么用

下面展示一个使用组件管理器移植LVGL点亮屏幕的示例：

### 2.1 硬件参数及接线

我们使用的开发板是：[ESP32圆形TFT屏幕开发板](https://item.taobao.com/item.htm?abbucket=18&id=739585951026&ns=1&spm=a21n57.1.0.0.7128523cmbToGt)

![](attachments/Pasted%20image%2020240219002722.png)

屏幕驱动IC为：GC9A01

屏幕尺寸为：240 X 240

屏幕接线如图：

![](attachments/Pasted%20image%2020240219002935.png)


### 2.2 新建工程

新建工程：，命名为：`lvgl_componen`

![](attachments/Pasted%20image%2020240219084903.png)

![](attachments/Pasted%20image%2020240219085149.png)


### 2.3 引入依赖

打开乐鑫维护的lvgl组件支持页面： [esp_lvgl_port](https://components.espressif.com/components/espressif/esp_lvgl_port?language=en)（并不需要直接下载lvgl）


![](attachments/Pasted%20image%2020240219090147.png)


输入命令添加依赖   `idf.py add-dependency "espressif/esp_lvgl_port^1.4.0"`  (这里使用8.3.11版本)

![](attachments/Pasted%20image%2020240219090334.png)

添加后如下图所示：

![](attachments/Pasted%20image%2020240219090346.png)

编译工程，会发现自动生成了 `managed_components`文件夹，替我们下载好了esp_lvgl_port 和lvgl两个组件

![](attachments/Pasted%20image%2020240219090431.png)

我们并没引入lvgl，问什么会下载呢，其实是esp_lvgl_port 内部有通过组件管理器引入了lvgl组件。

![](attachments/Pasted%20image%2020240219090700.png)

除此之外，我们还需要引入GC9A01这个屏幕IC的驱动程序，乐鑫已经替我们准备好了:  [esp_lcd_gc9a01](https://components.espressif.com/components/espressif/esp_lcd_gc9a01?language=en)


![](attachments/Pasted%20image%2020240219091339.png)

同样引入依赖编译即可。

### 2.4 编写代码调用组件，点亮屏幕

>关于如何使用spi点亮led 屏幕可以参考历程：esp-idf-v5.1.2/examples/peripherals/lcd/spi_lcd_touch


### 2.5 修改项目配置

#### 1.修改分区表

``` csv
# Name,   Type, SubType, Offset,  Size, Flags
# Note: if you have increased the bootloader size, make sure to update the offsets to avoid overlap
nvs,      data, nvs,        0x10000,   0x6000,
phy_init, data, phy,               ,   0x1000,
factory,  app,  factory,           ,   0x2c0000,
```

将上面的内容保存为 `partitions.csv` 保存到项目根目录，并修改配置使用自定义分区表

![](attachments/Pasted%20image%2020240219111110.png)

flash 调整到4MB

![](attachments/Pasted%20image%2020240219111316.png)




# 参考链接