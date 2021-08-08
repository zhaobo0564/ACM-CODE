# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库


# 这是一个图论题的数据生成器，该题目在洛谷的题号为P1339
for i in range(15, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据

    n = randint(1**10, 10**14)
   # x = randint(10000, 1000000000)
    test_data.input_write(n)
   # test_data.input_writeln(x)
   # a = Vector.random(n, [(1000000, 1000000000)])
   # a = sum(a, [])
   # test_data.input_writeln(a)
#


   
    test_data.output_gen("std.exe") # 标程编译后的
         
        
     
            
            
                    
        