自定义：

- 运行idfV4.4.6环境：`get_idf_v4`
- 运行idfV5.1.2环境：`get_idf_v5`

ESP-IDF:
- 清除之前的编译：` idf.py fullclean`           
- 编译:  `idf.py build`          
- 向串口烧录固件: `idf.py  -p  {PORT}  flash`                
- 打开串口监视器:`idf.py  -p  {PORT}  monitor`   
-  配置菜单 :`idf.py  menuconfig  `             
- 选择芯片型号：` idf.py set-target esp32 `  不输入参数的话，会列出所有可用型号
- 一次性执行构建、烧录和监视过程：`idf.py -p {PORT} flash monitor`

其他:

- 查询可用串口:`ls /dev/ttyUSB*`
