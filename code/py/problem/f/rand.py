# -*- coding: gbk -*- 
from cyaron import * # 引入CYaRon的库

for i in range(10, 21): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    n = randint(500000, 500000)
    q = n
    test_data.input_write(n)
    test_data.input_writeln(q)
    a = Vector.random(n, [(1, 1000000)]) 
    test_data.input_writeln(a)
    tree = Graph.flower(n)
    test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
    for i in range(0, q):
        op = randint(1, 3)
        List = []
        List.append(op)
        if op == 1:
            u = randint(1, 10)
            List.append(u)
        elif op == 2:
            u = randint(1, n)
            v = randint(1, 1000000)
            List.append(1)
            List.append(v)
        else:
            u = randint(1, n)
            v = randint(1, 1000000)
            List.append(1)
            List.append(v)
        #print(List)
        test_data.input_writeln(List)
    

    
    test_data.output_gen("E:\\作业\\题解\\考试\\蓝桥杯选拔赛\\std\\树\\std.exe")
    