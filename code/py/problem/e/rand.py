# -*- coding: gbk -*- 
from cyaron import * # ����CYaRon�Ŀ�

for i in range(6, 21): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="", data_id=i) # ���� heat[1|2|3].in/out �����������
    n = randint(32, 32)    
    test_data.input_writeln(n)
    x = randint(1, 1000000000)
    test_data.input_writeln(x)
    List = Vector.random(n, [1,1000000000])
    List = sum(List, [])
    test_data.input_writeln(List)
    test_data.output_gen("E:\\��ҵ\\���\\����\\���ű�ѡ����\\std\\����\\std.exe")
   