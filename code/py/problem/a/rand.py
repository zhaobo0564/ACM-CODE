# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库


# 这是一个图论题的数据生成器，该题目在洛谷的题号为P1339
for i in range(19, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据


    line = Vector.random(2, [(0, 1000)])
    line1 = Vector.random(2, [(0, 1000)])
    line = sum(line, [])
    line1 = sum(line1, [])
    line.sort()
    line1.sort()
    y = Vector.random(2, [(0, 1000)])
    y = sum(y, [])
    for i in line1:
        line.append(i)
    for i in y:
        line.append(i)
    
    test_data.input_writeln(line)
    test_data.output_gen("E:\\作业\\题解\\考试\\蓝桥杯选拔赛\\std\\线段\\std.exe") # 标程编译后的
         
        
     
            
            
                    
        