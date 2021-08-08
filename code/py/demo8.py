import pymysql
 

account = {
    'user' : 'root',
    'password' : 'zhaobo123..',
    'host' : '193.112.141.129',
    'database' : 'cf'
}


connect = pymysql.connect(**account)
cursor = connect.cursor(cursor = pymysql.cursors.DictCursor)

   

