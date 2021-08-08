# -*- coding: gbk -*- 
from cyaron import * # 引入CYaRon的库

for i in range(1, 5): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    str = String.random(100, charset="WASD")
    test_data.input_writeln(str)
   
    test_data.output_gen("E:\\作业\\题解\\考试\\蓝桥杯选拔赛\\std\\玩游戏\\std.exe")
   