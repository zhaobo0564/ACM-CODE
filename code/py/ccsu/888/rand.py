# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库

for i in range(1, 21): 
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\888\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    str = String.random(1, charset="123456789")
    str += String.random(199999, charset="0123456789")
    test_data.input_write(str)
   
    #test_data.output_gen("std.exe") # 标程编译后的
         
        
     
            
            
                    
        