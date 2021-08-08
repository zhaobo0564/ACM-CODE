# -*- coding: gbk -*- 
from cyaron import * # 引入CYaRon的库

for i in range(6, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    n = randint(32, 32)    
    test_data.input_writeln(n)
    x = randint(1, 1000000000)
    test_data.input_writeln(x)
    List = Vector.random(n, [1,1000000000])
    List = sum(List, [])
    test_data.input_writeln(List)
    test_data.output_gen("E:\\作业\\题解\\考试\\蓝桥杯选拔赛\\std\\买东西\\std.exe")
   