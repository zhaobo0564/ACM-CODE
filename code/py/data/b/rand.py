# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�


# ����һ��ͼ���������������������Ŀ����ȵ����ΪP1339
for i in range(15, 21): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������

    n = randint(1**10, 10**14)
   # x = randint(10000, 1000000000)
    test_data.input_write(n)
   # test_data.input_writeln(x)
   # a = Vector.random(n, [(1000000, 1000000000)])
   # a = sum(a, [])
   # test_data.input_writeln(a)
#


   
    test_data.output_gen("std.exe") # ��̱�����
         
        
     
            
            
                    
        