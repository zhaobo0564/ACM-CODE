# -*- coding: gbk -*- 
#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�


# ����һ��ͼ���������������������Ŀ����ȵ����ΪP1339
for i in range(19, 21): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������


    line = Vector.random(2, [(0, 1000)])
    line1 = Vector.random(2, [(0, 1000)])
    line = sum(line, [])
    line1 = sum(line1, [])
    line.sort()
    line1.sort()
    y = Vector.random(2, [(0, 1000)])
    y = sum(y, [])
    for i in line1:
        line.append(i)
    for i in y:
        line.append(i)
    
    test_data.input_writeln(line)
    test_data.output_gen("E:\\��ҵ\\���\\����\\���ű�ѡ����\\std\\�߶�\\std.exe") # ��̱�����
         
        
     
            
            
                    
        