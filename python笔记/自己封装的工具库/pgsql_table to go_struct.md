```python
import string  
  
import psycopg2  
  
specialFields = ["id", "app", "ios", "uid"]  
  
  
# 下划线转驼峰  
def snake_to_camel(snake_str):  
if snake_str in specialFields:  
camel = snake_str.upper()  
else:  
camel = string.capwords(snake_str, '_').replace('_', '')  
return camel  
  
  
# pgsql 与 go 数据类型映射表  
mappingTable = {  
"character varying": "string",  
"text": "string",  
"integer": "int64",  
"real": "float64"  
}  
  
db_name = "study"  
user = "study"  
password = "KCEsjzTCwffb"  
host = "111.173.117.11"  
# 通过connect方法，创建连接对象 connconn = psycopg2.connect(database=db_name, user=user, password=password, host=host)  
  
# 获得游标对象  
cursor = conn.cursor()  
  
# 查找所有表名  
sql = "select tablename from pg_tables where schemaname='public'"  
cursor.execute(sql)  
allTable = cursor.fetchall()  
  
# 查找表字段和属性  
table = input("请输入表名：")  
  
sql1 = f"""  
SELECT column_name, data_type, character_maximum_length  
FROM INFORMATION_SCHEMA.COLUMNS  
WHERE table_name = '{table}';  
"""  
cursor.execute(sql1)  
fields = cursor.fetchall()  
  
# 拼接结构体语句  
goStruct = f"type {table[0].upper() + table[1:]}Model struct " + "{\n"  
for field in fields:  
fieldName = snake_to_camel(field[0])  
goStruct += f'\t{fieldName} {mappingTable[field[1]]} `db:"{field[0]}"`\n'  
goStruct += "}"  
print(goStruct)  
  
# 关闭数据库连接  
conn.close()
```