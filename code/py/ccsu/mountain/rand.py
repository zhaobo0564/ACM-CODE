# -*- coding: gbk -*-  
# #!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�

# # for i in range(1, 2): # һ����� 
# #     test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
# #     n = 500
# #     q = 2000000
# #     output = []
# #     query = []
# #     for i in range(1, n + 1):
# #         output.append([i, i])
# #     for i in range(0, q):
# #         x = randint(1, n)
# #         w = randint(20, 10000)
# #         query.append([x, w])
    
    
# #     test_data.input_writeln([n, q])
# #     for i in output:
# #         test_data.input_writeln(i)
# #     for i in query:
# #         test_data.input_writeln(i)
   
# #     test_data.output_gen("std.exe") # ��̱�����
         
# # for i in range(2, 3): # һ����� 
# #     test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
# #     n = 500
# #     q = 2000000
# #     output = []
# #     query = []
# #     for i in range(1, n + 1):
# #         output.append([i, i])
# #     for i in range(0, q):
# #         x = randint(1, 20)
# #         w = randint(1, 200)
# #         query.append([1, w])
    
    
# #     test_data.input_writeln([n, q])
# #     for i in output:
# #         test_data.input_writeln(i)
# #     for i in query:
# #         test_data.input_writeln(i)
   
# #     test_data.output_gen("std.exe") # ��̱�����
            
            
                    
for i in range(3, 4): # һ����� 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = 500
    q = 2000000
    output = []
    query = []
    a = Vector.random(n, [(1, n)])
    b = sum(a, [])
    for j in range(0, n):
        h = randint(1, 100000)
        output.append([b[j], h])
    for j in range(0, q):
        x = randint(1, n)
        w = randint(1, 10000000)
        query.append([x, w])
    
    test_data.input_writeln([n, q])

    for j in output:
        test_data.input_writeln(j)
    for j in query:
        test_data.input_writeln(j)
  
   
    test_data.output_gen("std.exe") # ��̱�����

for i in range(4, 8): # һ����� 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = 500
    q = 2000000
    output = []
    query = []
    a = Vector.random(n, [(1, n)])
    b = sum(a, [])
    
    for j in range(0, 500):
        h = randint(1, 100000)
        output.append([b[j], h])
    
        output.append([b[j], h])
    for j in range(0, q):
        x = randint(1, 200)
        w = randint(1, 1000000)
        query.append([x, w])
    
    test_data.input_writeln([n, q])

    for j in output:
        test_data.input_writeln(j)
    for j in query:
        test_data.input_writeln(j)
   
    test_data.output_gen("std.exe") # ��̱�����

for i in range(8, 9): # һ����� 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = 500
    q = 2000000
    output = []
    query = []
    a = Vector.random(n, [(1, n)])
    b = sum(a, [])
    
    for j in range(0, 200):
        h = randint(1, 1000)
        output.append([b[j], h])
    for j in range(200, 500):
        h = randint(1000, 100000)
        output.append([b[j], h])
    for j in range(0, q):
        x = randint(1, 20)
        w = 0
        op = 0
        if op == 0:
            w = randint(0, 1000)
        else:
            w = randint(10000000, 1000000000)
        query.append([x, w])
    
    test_data.input_writeln([n, q])

    for j in output:
        test_data.input_writeln(j)
    for j in query:
        test_data.input_writeln(j)
   
    test_data.output_gen("std.exe") # ��̱�����
for i in range(9, 10): # һ����� 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��ɽ\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = 500
    q = 2000000
    output = []
    query = []
    a = Vector.random(n, [(1, n)])
    b = sum(a, [])
    
    for j in range(0, 200):
        h = randint(1, 1000)
        output.append([b[j], h])
    for j in range(200, 500):
        h = randint(1000, 100000)
        output.append([b[j], h])
    for j in range(0, q):
        x = randint(1, 20)
        w = 0
        op = 1
        if op == 0:
            w = randint(0, 1000)
        else:
            w = randint(10000000, 1000000000)
        query.append([x, w])
    
    test_data.input_writeln([n, q])

    for j in output:
        test_data.input_writeln(j)
    for j in query:
        test_data.input_writeln(j)
   
    test_data.output_gen("std.exe") # ��̱�����