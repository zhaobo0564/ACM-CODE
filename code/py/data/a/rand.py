# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�


# ����һ��ͼ���������������������Ŀ����ȵ����ΪP1339
for i in range(1, 21): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="123456789")
    str += String.random(11499, charset="0123456789")

    test_data.input_writeln(str)
    str = String.random(1, charset="123456789")
    str += String.random(499, charset="0123456789")
    test_data.input_writeln(str)
  #  a = Vector.random(n, [(1000000, 1000000000)])
   # a = sum(a, [])
    #test_data.input_writeln(a)



   
    test_data.output_gen("std.exe") # ��̱�����
         
        
     
            
            
                    
        