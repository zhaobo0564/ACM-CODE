# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�

for i in range(1, 21): 
    test_data = IO(file_prefix="E:\\��ҵ\\����\\2021��ɳѧԺУ��\\888\\����\\", data_id=i) # ���� heat[1|2|3].in/out �����������

    str = String.random(1, charset="123456789")
    str += String.random(199999, charset="0123456789")
    test_data.input_write(str)
   
    #test_data.output_gen("std.exe") # ��̱�����
         
        
     
            
            
                    
        