# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�

for i in range(1, 6): 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��������\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="123456789")
    str += String.random(10, charset="0123456789")
    test_data.input_writeln(str)
   
    test_data.output_gen("std.exe") # ��̱�����
         
for i in range(6, 10): 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��������\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="123456789")
    str += String.random(17, charset="0123456789")
    str += '.'
    str += String.random(1000, charset="0123456789")
    test_data.input_writeln(str)       
    test_data.output_gen("std.exe")
for i in range(10, 15): 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��������\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="9")
    str += String.random(17, charset="9")
    str += '.'
    str += String.random(1000, charset="456789")
    test_data.input_writeln(str)    
    test_data.output_gen("std.exe")
      
for i in range(15, 21): 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\��������\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="12345678")
    str += String.random(17, charset="9")
    str += '.'
    str += String.random(1000, charset="456789")
    test_data.input_writeln(str)                     
    test_data.output_gen("std.exe")