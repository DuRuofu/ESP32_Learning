#开发记录
#### 说明：

1. 本文档由杜若甫撰写，由杜若甫负责解释及执行。

#### 修订历史：

|  文档名称  |  版本  |  作者  |      时间      |   备注   |
| :----: | :----: | :------------: | :------: |
| 在linux下搭建esp-idf开发环境 | DuRuofu | 2023-04-29 | 首次建立 |

## 在linux下搭建esp-idf开发环境(v5.1.2)


## 一 、准备工作

### 1. 准备linux的电脑或者虚拟机
   
   我这里使用Ubuntu22.04的虚拟机环境
   
![](attachments/Pasted%20image%2020240125114613.png)

### 2. 下载ESP-IDF包环境

> 这里有两种下载方式：分别针对有魔法和无魔法

#### 1. （有魔法）使用git clone：

   在终端运行命令：
   
```sh
mkdir -p ~/esp
cd ~/esp
git clone -b v5.1.2 --recursive https://github.com/espressif/esp-idf.git
```

#### 2. (无魔法) 手动下载：
   
前往ESP-IDF仓库：https://github.com/espressif/esp-idf/releases/tag/v5.1.2 ，如下：

![](attachments/Pasted%20image%2020240125120321.png)

找到： Download an archive with submodules included 一项

![](attachments/Pasted%20image%2020240125120428.png)

下载并解压到 ~/esp/esp-idf 即可

> 这里也可以安装多个版本，在这个目录，不冲突

## 二、安装依赖

编译 ESP-IDF 需要以下软件包。请根据使用的 Linux 发行版本，选择合适的安装命令。

- Ubuntu 和 Debian:
```sh
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```

- CentOS 7 & 8:
```sh
sudo yum -y update && sudo yum install git wget flex bison gperf python3 python3-setuptools cmake ninja-build ccache dfu-util libusbx
```

- Arch:
```sh
sudo pacman -S --needed gcc git make flex bison gperf python cmake ninja ccache dfu-util libusb
```


## 三、 安装 ESP-IDF 使用的各种工具

这里使用全部安装：

```sh
cd ~/esp/esp-idf
./install.sh all
```

ESP-IDF 工具安装器会下载 Github 发布版本中附带的一些工具，如果访问 Github 较为缓慢，可以设置一个环境变量，从而优先选择 Espressif 的下载服务器进行 Github 资源下载。

```sh
cd ~/esp/esp-idf
export IDF_GITHUB_ASSETS="dl.espressif.com/github_assets"
./install.sh
```


这一步可能会遇到python下载失败的问题：

![](attachments/Pasted%20image%2020240125161324.png)

需要修改镜像源：

Linux下，修改 ~/.pip/pip.conf (没有就创建一个文件夹及文件。文件夹要加“.”，表示是隐藏文件夹)
内容如下：

```ini
[global]
index-url = https://pypi.tuna.tsinghua.edu.cn/simple
[install]
trusted-host=mirrors.aliyun.com
```

> 如果还失败就去修改：~/.config/pip/pip.conf 这个配置文件
##  四、 配置快捷指令

在终端执行`. $HOME/esp/esp-idf/export.sh`  这个脚本，就可以在当前终端使用esp-idf工具

但是每次执行都要先使用这个脚本激活环境不太方便，可以为执行 `export.sh` 创建一个别名

打开`.bashrc` 配置文件
```
nano ~/.bashrc
```

写入配置文件：
![](attachments/Pasted%20image%2020240125164001.png)

我这里安装了两个版本，于是写两条命令
![](attachments/Pasted%20image%2020240125164248.png)

##  五、 测试程序s

打开历程目录下的hello_world程序：

![](attachments/Pasted%20image%2020240125165114.png)


使用`idf.py set-target esp32` 命令选择芯片

使用`idf.py build  `命令编译代码

![](attachments/Pasted%20image%2020240125165709.png)
编译成功

使用 ` idf.py -p PORT 【-b BAUD】 flash `命令烧录（先插好开发板） 

> 在linux下可以这样查看单片机的串口端口：
> 
> 		`cd /dev`
> 		`ls ttyUSB*`
> ![](attachments/Pasted%20image%2020240125170645.png)

但是运行后可能会出现：
![](attachments/Pasted%20image%2020240125171030.png)

这是由于我们的linux用户没有读写串口的权限

可以使用下面的命令添加串口读写权限（也可直接切换root用户）：

```
sudo chmod a+rw /dev/ttyUSB0
```

然后就成功烧录了：
![](attachments/Pasted%20image%2020240125171933.png)

接下来使用`idf.py -p PORT monitor` 来查看串口输出：

![](attachments/Pasted%20image%2020240125172139.png)

到此就完成了一个开发的流程。
##  六 、 常用命令  

自定义：

- 运行idfV4.4.6环境：`get_idf_v4`
- 运行idfV5.1.2环境：`get_idf_v5`

ESP-IDF；
- 清除之前的编译：` idf.py fullclean`           
- 编译:  `idf.py build`          
- 向串口烧录固件: `idf.py  -p  COM8  flash`                
- 打开串口监视器:`idf.py  -p  COM8  monitor`   
-  配置菜单 :`idf.py  menuconfig  `             
- 选择芯片型号：` idf.py set-target esp32 `  不输入参数的话，会列出所有可用型号
- 一次性执行构建、烧录和监视过程：idf.py -p PORT flash monitor
## 参考链接

1. https://www.bilibili.com/video/BV1J14y1n7Ve/?spm_id_from=333.337.search-card.all.click&vd_source=ef5a0ab0106372751602034cdd9ab98e
2. https://blog.csdn.net/ZRongZH/article/details/129237476
3. https://www.bilibili.com/video/BV1Mv4y1U7x9/?spm_id_from=333.999.0.0&vd_source=ef5a0ab0106372751602034cdd9ab98e