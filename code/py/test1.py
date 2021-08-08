def cmp(msg):
    return msg['id']

msg = {'name': 'Bob', 'id': 1234}
msg1 = {'name': 'Tom', 'id': 2132}
msg2 = {'name': 'aa', 'id': 1000}
list_a = []
list_a.append(msg)
list_a.append(msg1)
list_a.append(msg2)
print(list_a)
print("")
list_a.sort(key = cmp)
print(list_a)
