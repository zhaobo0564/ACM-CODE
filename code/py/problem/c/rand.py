# -*- coding: gbk -*- 
from cyaron import * # ����CYaRon�Ŀ�

for i in range(1, 5): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
    str = String.random(100, charset="WASD")
    test_data.input_writeln(str)
   
    test_data.output_gen("E:\\��ҵ\\���\\����\\���ű�ѡ����\\std\\����Ϸ\\std.exe")
   