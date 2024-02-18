#开发记录
### 说明：

1. 本文档由DuRuofu撰写，由DuRuofu负责解释及执行。
2. 本文档主要记载一些vscdoe配合虚拟机远程连接开发ESP32的窍门

### 修订历史：

|  文档名称  |  版本  |  作者  |      时间      |   备注   |
| ---- | ---- | ------------ | ------ |
| vscdoe配合虚拟机远程连接开发 |v1.0.0| DuRuofu | 2024-01-29 | 首次建立 |
<div STYLE="page-break-after: always;"></div>
# vscdoe配合虚拟机远程连接开发

## 1. 连接虚拟机开发过程

> 这部分不再赘述，主要依靠Remote -SSH插件，然后编译使用命令行。

![](attachments/Pasted%20image%2020240129230625.png)
网上搜素vscode远程开发即可

## 2. 一些问题的处理

### 2.1 头文件跳转的问题

不使用esp-idf插件的原因是多版本切换不方便，使用命令行能随时多版本切换，但是这样导致我们的代码头文件无法跳转，写代码没有代码提示。

无法跳转：
![](attachments/Pasted%20image%2020240129231028.png)
无有效代码提示：

![](attachments/Pasted%20image%2020240129232435.png)

解决办法：
先编译代码：
![](attachments/Pasted%20image%2020240129231103.png)

然后找到`build`下的`compile_commands.json`文件：

![](attachments/Pasted%20image%2020240129231253.png)

右键复制绝对路径：
![](attachments/Pasted%20image%2020240129231616.png)

然后打开命令面板：

![](attachments/Pasted%20image%2020240129231412.png)

找到这一项：
![](attachments/Pasted%20image%2020240129231444.png)

将绝对路径复制到编译命令：
![](attachments/Pasted%20image%2020240129231711.png)


然后就能正常跳转到源码了

![](attachments/Pasted%20image%2020240129231954.png)

代码提示也有了：

![](attachments/Pasted%20image%2020240129232230.png)


### 2.2 手输命令太麻烦的问题

使用Run Terminal Command插件可视化执行命令：

``` json
    "runTerminalCommand.commands": [
        

        //------------------V4-----------------//
        // 删除
        {
            "command": "get_idf_v4 && idf.py fullclean",
            "auto": true,
            "name": "fullclean",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 配置
        {
            "command": "get_idf_v4 && idf.py menuconfig",
            "auto": true,
            "name": "menuconfig",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 编译
        {
            "command": "get_idf_v4 && idf.py build",
            "auto": true,
            "name": "build",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 查询串口
        {
            "command": "ls /dev/ttyUSB*",
            "auto": true,
            "name": "Query serial port",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        }, 
        // 烧录
        {
            "command": "get_idf_v4 && idf.py -p {clipboard} flash",
            "auto": true,
            "name": "flash",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        //打开监视器
        {
            "command": "get_idf_v4 && idf.py -p {clipboard} monitor",
            "auto": true,
            "name": "monitor",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },   
        //一次性编译烧录和打开监视
        {
            "command": "get_idf_v4 && idf.py -p {clipboard} flash monitor",
            "auto": true,
            "name": "build&flash&monitor",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 擦除
        {
            "command": "get_idf_v4 && idf.py -p {clipboard} erase_flash",
            "auto": true,
            "name": "erase_flash",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },   
        //查询内存剩余
        {
            "command": "get_idf_v4 && idf.py size",
            "auto": true,
            "name": "size",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 设置开发板esp32
        {
            "command": "get_idf_v4 && idf.py fullclean && idf.py set-target esp32",
            "auto": true,
            "name": "set-target esp32",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 设置开发板esp32c3
        {
            "command": "get_idf_v4 && idf.py fullclean && idf.py set-target esp32c3",
            "auto": true,
            "name": "set-target esp32c3",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        // 设置开发板esp32s3
        {
            "command": "get_idf_v4 && idf.py fullclean && idf.py set-target esp32s3",
            "auto": true,
            "name": "set-target esp32s3",
            "preserve": true,
            "group": "ESP-IDF-v4.4.6"
        },
        //------------------V5-----------------//
        // 删除
        {
            "command": "get_idf_v5 && idf.py fullclean",
            "auto": true,
            "name": "fullclean",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 配置
        {
            "command": "get_idf_v5 && idf.py menuconfig",
            "auto": true,
            "name": "menuconfig",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 编译
        {
            "command": "get_idf_v5 && idf.py build",
            "auto": true,
            "name": "build",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 查询串口
        {
            "command": "ls /dev/tty*",
            "auto": true,
            "name": "Query serial port",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        }, 
        // 烧录
        {
            "command": "get_idf_v5 && idf.py -p {clipboard} flash",
            "auto": true,
            "name": "flash",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        //打开监视器
        {
            "command": "get_idf_v5 && idf.py -p {clipboard} monitor",
            "auto": true,
            "name": "monitor",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },   
        //一次性编译烧录和打开监视
        {
            "command": "get_idf_v5 && idf.py -p {clipboard} flash monitor",
            "auto": true,
            "name": "build&flash&monitor",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 擦除
        {
            "command": "get_idf_v5 && idf.py -p {clipboard} erase_flash",
            "auto": true,
            "name": "erase_flash",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },   
        //查询内存剩余
        {
            "command": "get_idf_v5 && idf.py size",
            "auto": true,
            "name": "size",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 设置开发板esp32
        {
            "command": "get_idf_v5 && idf.py fullclean && idf.py set-target esp32",
            "auto": true,
            "name": "set-target esp32",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 设置开发板esp32c3
        {
            "command": "get_idf_v5 && idf.py fullclean && idf.py set-target esp32c3",
            "auto": true,
            "name": "set-target esp32c3",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
        // 设置开发板esp32s3
        {
            "command": "get_idf_v5 && idf.py fullclean && idf.py set-target esp32s3",
            "auto": true,
            "name": "set-target esp32s3",
            "preserve": true,
            "group": "ESP-IDF-v5.1.2"
        },
    ],

```

然后就可以使用命令快捷方式来开发ESP32了，效率提示。

![](attachments/Pasted%20image%2020240130012646.png)
