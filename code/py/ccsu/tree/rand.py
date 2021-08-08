# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # 引入CYaRon的库
a = []
for i in range(0, 21):
    a.append(2 ** i)



# for i in range(1, 6): #随机
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = 100000
#     output = []
    
#     for j in range(0, n):
        
#         x = randint(0, 15 + i)
        
#         output.append(a[x])
   
#     tree = Graph.tree(n) 
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
#     # str = String.random(1, charset="123456789")
#     # str += String.random(199999, charset="0123456789")
#     # test_data.input_write(str)
   
#    # test_data.output_gen("std.exe") # 标程编译后的
# for i in range(6, 8):  #40%链35菊花
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = 100000
#     output = []
#     for j in range(0, n):
#         op = randint(0, 1)
#         if op == 1:
#             y = randint(0, 20)
#             x = randint(0, y)
#             output.append(a[x])
#         else:
#             x = randint(0, 1000000)
#             output.append(x)
    
   
#     tree = Graph.tree(n, 0.4, 0.35) 
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
#     # str = String.random(1, charset="123456789")
#     # str += String.random(199999, charset="0123456789")
#     # test_data.input_write(str)
   
#    # test_data.output_gen("std.exe") # 标程编译后的
        
for i in range(6, 11): #30%链 60%菊花
    test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
    n = 100000
    output = []
    for j in range(0, n):
        sum = 0
        for k in range(0, 3): 
            x = randint(0, 20)
            sum = sum + (2 ** int(x))
        output.append(sum)
   
    tree = Graph.tree(n, 0.3, 0.6) 
    test_data.input_writeln(n)
    test_data.input_writeln(output)
    test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
    # str = String.random(1, charset="123456789")
    # str += String.random(199999, charset="0123456789")
    # test_data.input_write(str)
   
#     #test_data.output_gen("std.exe") # 标程编译后的
# for i in range(11, 12): #100% 链
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = 100000
#     output = []
#     for j in range(0, n):
#         op = randint(0, 3)
#         if op == 1 or op == 2:
#             y = randint(0, 20)
#             x = randint(0, y)
#             output.append(a[x])
#         else:
#             x = randint(0, 1000000)
#             output.append(x)
   
#     tree = Graph.chain(n)
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
#     # str = String.random(1, charset="123456789")
#     # str += String.random(199999, charset="0123456789")
#     # test_data.input_write(str)
   
#    # test_data.output_gen("std.exe") # 标程编译后的
            
     
# for i in range(12, 14):
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     output = []
#     for j in range(0, n):
#         op = randint(0, 1)
#         if op == 1:
#             y = randint(0, 20)
#             x = randint(0, y)
#             output.append(a[x])
#         else:
#             x = randint(0, 2**20)
#             output.append(x)
   
#     tree = Graph.flower(n)
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
#     # str = String.random(1, charset="123456789")
#     # str += String.random(199999, charset="0123456789")
#     # test_data.input_write(str)
   
#     #test_data.output_gen("std.exe") # 标程编译后的                   
# for i in range(14, 16): #1随机二叉树
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = 100000
#     output = []
#     for j in range(0, n):
#         op = randint(0, 1)
#         if op == 1:
#             y = randint(0, 20)
#             x = randint(0, y)
#             output.append(a[x])
#         else:
#             x = randint(0, 100)
#             output.append(x)
   
#     tree = Graph.binary_tree(n)
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
#     # str = String.random(1, charset="123456789")
#     # str += String.random(199999, charset="0123456789")
#     # test_data.input_write(str)
   
#     #test_data.output_gen("std.exe") # 标程编译后的

# 生成一棵n个节点的二叉树，其中节点有40%的概率是左儿子，35%的概率是右儿子，25%的概率被随机选
# for i in range(16, 17): #1随机二叉树
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     output = Vector.random(n, [(0,10000)], 1)
   
#     tree = Graph.binary_tree(n, 0.4, 0.35)
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
    # str = String.random(1, charset="123456789")
    # str += String.random(199999, charset="0123456789")
    # test_data.input_write(str)
   
   # test_data.output_gen("std.exe") # 标程编译后的
# for i in range(17, 20): #1随机二叉树
#     test_data = IO(file_prefix="E:\\作业\\出题\\2021长沙学院校赛\\异或树\\数据\\", data_id=i) # 生成 heat[1|2|3].in/out 三组测试数据
#     n = randint(100000, 100000)
#     output = []
#     for j in range(0, n):
#         sum = 0
#         for k in range(0, 2): 
#             x = randint(0, 20)
#             sum = sum + (2 ** int(x))
#         output.append(sum)
        

   
#     tree = Graph.tree(n, 0.2, 0.35)
#     test_data.input_writeln(n)
#     test_data.input_writeln(output)
#     test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
 