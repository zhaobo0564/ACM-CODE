# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(1, 6): 
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\四舍五入\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    str = String.random(1, charset="123456789")
    str += String.random(10, charset="0123456789")
    test_data.input_writeln(str)
   
    test_data.output_gen("std.exe") # 标程编译后的
         
for i in range(6, 10): 
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\四舍五入\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    str = String.random(1, charset="123456789")
    str += String.random(17, charset="0123456789")
    str += '.'
    str += String.random(1000, charset="0123456789")
    test_data.input_writeln(str)       
    test_data.output_gen("std.exe")
for i in range(10, 15): 
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\四舍五入\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    str = String.random(1, charset="9")
    str += String.random(17, charset="9")
    str += '.'
    str += String.random(1000, charset="456789")
    test_data.input_writeln(str)    
    test_data.output_gen("std.exe")
      
for i in range(15, 21): 
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\四舍五入\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    str = String.random(1, charset="12345678")
    str += String.random(17, charset="9")
    str += '.'
    str += String.random(1000, charset="456789")
    test_data.input_writeln(str)                     
    test_data.output_gen("std.exe")