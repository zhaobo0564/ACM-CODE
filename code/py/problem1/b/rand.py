# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�


#����һ��ͼ���������������������Ŀ����ȵ����ΪP1339
for i in range(1, 21): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = randint(2000, 2000)
    a = Vector.random(n, [1, 1000], 1)
    a = list(sum(a, []))
    test_data.input_writeln(n)
    test_data.input_writeln(a)
    test_data.output_gen("std.exe") # ��̱�����
            
         
                    
        