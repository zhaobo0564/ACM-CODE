# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�


#����һ��ͼ���������������������Ŀ����ȵ����ΪP1339
# for i in range(1, 6): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
#     test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
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

        
#     test_data.output_gen("std.exe") # ��̱�����
         
# for i in range(6, 11): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
#     test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
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

        
#     test_data.output_gen("std.exe") # ��̱�����
# for i in range(11, 12): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
#     test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
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

        
#     test_data.output_gen("std.exe") # ��̱�����                
     
# for i in range(12, 14): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
#     test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
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

        
#     test_data.output_gen("std.exe") # ��̱�����                

for i in range(14, 20): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
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

        
    test_data.output_gen("std.exe") # ��̱�����                
         
                    
        