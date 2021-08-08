# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库


#这是一个图论题的数据生成器，该题目在洛谷的题号为P1339
# for i in range(1, 6): # 即在[1, 4)范围内循环，也就是从1到3
#     test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     q = randint(100000, 100000)
#     a = Vector.random(n, [1, 99995], 1)
#     b = Vector.random(n, [1, 99995], 1)
#     a = list(sum(a, []))
#     b = list(sum(b, []))
#     test_data.input_writeln([n, q])
#     test_data.input_writeln(a)
#     test_data.input_writeln(b)
#     for i in range(0, q):
#         op = randint(0, 1)
#         if op == 0:
#             l = randint(1, n)
#             r = randint(1, n)
#             if l > r:
#                 temp = l
#                 l = r
#                 r = temp
#             test_data.input_writeln([1, l, r])
#         else:
#             postion = randint(1, n)
#             test_data.input_writeln([2, postion])

        
#     test_data.output_gen("std.exe") # 标程编译后的
         
# for i in range(6, 11): # 即在[1, 4)范围内循环，也就是从1到3
#     test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     q = randint(100000, 100000)
#     a = Vector.random(n, [99990, 99995], 1)
#     b = Vector.random(n, [1, 10], 1)
#     a = list(sum(a, []))
#     b = list(sum(b, []))
#     test_data.input_writeln([n, q])
#     test_data.input_writeln(a)
#     test_data.input_writeln(b)
#     for i in range(0, q):
#         op = randint(0, 1)
#         if op == 0:
#             l = randint(1, n)
#             r = randint(1, n)
#             if l > r:
#                 temp = l
#                 l = r
#                 r = temp
#             test_data.input_writeln([1, l, r])
#         else:
#             postion = randint(1, n)
#             test_data.input_writeln([2, postion])

        
#     test_data.output_gen("std.exe") # 标程编译后的
# for i in range(11, 12): # 即在[1, 4)范围内循环，也就是从1到3
#     test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     q = randint(100000, 100000)
#     a = []
#     b = []
#     for i in range(0, n):
#         a.append(99995)
#         b.append(99995)
#     test_data.input_writeln([n, q])
#     test_data.input_writeln(a)
#     test_data.input_writeln(b)
#     for i in range(0, q):
#         op = 1
#         if op == 0:
#             l = randint(1, n)
#             r = randint(1, n)
#             if l > r:
#                 temp = l
#                 l = r
#                 r = temp
#             test_data.input_writeln([1, l, r])
#         else:
#             postion = randint(1, n)
#             test_data.input_writeln([2, postion])

        
#     test_data.output_gen("std.exe") # 标程编译后的                
     
# for i in range(12, 14): # 即在[1, 4)范围内循环，也就是从1到3
#     test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     q = randint(100000, 100000)
#     a = []
#     b = []
#     for i in range(0, n):
#         a.append(99995)
#         b.append(99995)
#     test_data.input_writeln([n, q])
#     test_data.input_writeln(a)
#     test_data.input_writeln(b)
#     for i in range(0, q):
#         op = 1
#         if op == 0:
#             l = randint(1, n)
#             r = randint(1, n)
#             if l > r:
#                 temp = l
#                 l = r
#                 r = temp
#             test_data.input_writeln([1, l, r])
#         else:
#             postion = randint(1, 10)
#             test_data.input_writeln([2, postion])

        
#     test_data.output_gen("std.exe") # 标程编译后的                

for i in range(14, 20): # 即在[1, 4)范围内循环，也就是从1到3
    test_data = IO(file_prefix="", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    n = randint(100000, 100000)
    q = randint(100000, 100000)
    a = []
    b = []
    for i in range(0, n):
        a.append(99995)
        b.append(0)
    test_data.input_writeln([n, q])
    test_data.input_writeln(a)
    test_data.input_writeln(b)
    for i in range(0, q):
        op = randint(0, 1)
        if op == 0:
            l = randint(1, n)
            r = randint(1, n)
            if l > r:
                temp = l
                l = r
                r = temp
            test_data.input_writeln([1, l, r])
        else:
            postion = randint(1, n)
            test_data.input_writeln([2, postion])

        
    test_data.output_gen("std.exe") # 标程编译后的                
         
                    
        