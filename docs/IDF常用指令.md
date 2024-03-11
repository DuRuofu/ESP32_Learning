自定义：

- 运行idfV4.4.6环境：`get_idf_v4`
- 运行idfV5.1.2环境：`get_idf_v5`

ESP-IDF:
- 创建工程：`idf.py create-project main` 
- 新建组件`idf.py -C components create-component {componentName}`
- 清除之前的编译：` idf.py fullclean`           
- 编译:  `idf.py build`          
- 向串口烧录固件: `idf.py  -p  /dev/ttyUSB0  flash`    （`/dev/ttyUSB0`  为目标串口参数，根据实际填写）            
- 打开串口监视器:`idf.py  -p  /dev/ttyUSB0  monitor`   （`/dev/ttyUSB0`  为目标串口参数，根据实际填写）   
-  配置菜单 :`idf.py  menuconfig  `             
- 选择芯片型号：` idf.py set-target esp32 `  不输入参数的话，会列出所有可用型号
- 一次性执行构建、烧录和监视过程：`idf.py -p /dev/ttyUSB0 flash monitor`  （`/dev/ttyUSB0`  为目标串口参数，根据实际填写）   

- 获取ADC基准值：`espefuse.py -p /dev/ttyUSB0 adc_info`
其他:

- 查询可用串口:`ls /dev/ttyUSB*`
- 添加串口权限(需重启)：`sudo usermod -aG dialout username`


win下添加环境：

`C:\Espressif\frameworks\esp-idf-v5.2.1\export.bat`

`D:\Espressif\frameworks\esp-idf-v5.2.1\export.bat`