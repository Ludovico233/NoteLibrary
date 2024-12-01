# PostgreSQL
## 入门
```sql
-- 单行注释

/*
多行注释
*/

/*
sql语句中 
	<>:必填字段
	[]:可选字段
*/
```

### 简单查询语句
- 关键字：SELECT
```sql
-- pgsql支持无表查询（from可以不写，不一定查询表）
SELECT version() AS "数据库版本";

-- 查询记录（字段名 = * --> 查询所有字段）
SELECT FROM <字段名> [AS <别名>]  FROM <表名>;

-- 查询不重复项（查询结果去重）
SELECT DISTINCT <字段名> FROM <表名>;

-- 条件查询
-- 提供的运算符：=, !=, <>, >, >=, <, <=, BETWEEN, IN等
SELECT <字段名> FROM <表名> [WHERE <条件>];

/* 模糊查询
通配符：
	%：匹配任意多个字符 (可以是0次)
	_：匹配一个字符
*/
SELECT FROM <字段名> FROM <表名> [LIKE '通配符'];

-- ILIKE: 查询字段不区分大小写
SELECT FROM <字段名> FROM <表名> [ILIKE '通配符'];
```
条件查询时可以用 AND , OR, NOT 等逻辑运算，AND优先级大于OR，括号可以改变优先级 ，比较运算符优先级比逻辑运算符高

### 模糊匹配
- 关键字：LIKE / ILIKE
- 通配符：
	%（百分号）：匹配任意多个字符 (可以是0次)
	\_（下划线）：匹配一个字符
- ESCAPE选项用于指定转义字符
```sql
-- LIKE：查询字段区分大小写
SELECT FROM <字段名> FROM <表名> [LIKE '通配符'];

-- ILIKE: 查询字段不区分大小写
SELECT FROM <字段名> FROM <表名> [ILIKE '通配符'];
```

### 空值
- 空值用NULL表示，代表未知或是缺失数据，是**不确定的** --->  0 = NULL  NULL != NULL 结果：NULL
- SQL标准使用 `IS [NOT] NULL`做空值判断
- pgSQL 还支持 `ISNULL 和 NOTNULL`的方言
- `IS [NOT] DISTINCT FROM`：表示两边是否不同，支持空值比较

### 数据排序显示
- 关键字：ORDER BY
- **默认升序ASC**，可以改为DESC降序
- **NULL** 在排序的时候看作 **无限大**
- NULLS FIRST 或者 NULLS LAST 可以指定空值的位置
```sql
-- 排序字段在查询字段中
SELECT <字段名> FROM <表名> ORDER BY <字段名/字段顺序> [ASC/DESC];

-- 一下两段查询语句等同
SELECT employee_id, first_name, last_name, hire_date, salary 
FROM employees 
ORDER BY first_name ASC, lat_name DESC;


SELECT employee_id, first_name, last_name, hire_date, salary 
FROM employees 
ORDER BY 2, 3 DESC;
```
![[Pasted image 20241127103025.png]]

### 限制返回结果的数量
- 关键字：TOP N
- 标准SQL：FETCH FIRST 10 ROWS ONLY;   ---> 获取前10行记录
- pgsql扩展语法：LIMIT 10
```sql
-- 标准SQL,获取前10行数据
SELECT first_name, last_name,  salary 
FROM employees 
ORDER BY salary
FETCH FIRST 10 ROWS ONLY;

-- pgsql方言
SELECT first_name, last_name, salary 
FROM employees 
ORDER BY salary
LIMIT 10;
```
![[Pasted image 20241126173616.png]]


需求：我们以员工工资来排序，不止是获得前10条记录，按说表中应该还存在和第10条一样的记录两者排名应该是一样的，想要尽可能多的展示出来。
```sql
-- 标准SQL
SELECT first_name, last_name,  salary 
FROM employees 
ORDER BY salary
FETCH FIRST 10 ROWS WITH TIES;
-- 找出和最后一条记录相同的尽可能多的数据
```
![[Pasted image 20241126173710.png]]

分页查询
以每次查询10条记录为例：
- 关键字：OFFSET <偏移量> RWS
```sql
-- 标准SQL
SELECT first_name, last_name,  salary 
FROM employees 
ORDER BY salary
OFFSET 10 ROWS    -- 查询偏移量为10，即10-20记录
FETCH FIRST 10 ROWS WITH TIES;

-- pgsql方言
SELECT first_name, last_name,  salary 
FROM employees 
ORDER BY salary
LIMIT 10 OFFSET 10;
```
![[Pasted image 20241127110049.png]]
#### 聚合函数
- 聚合函数会忽略NULL数据行
- 但是`COUNT(*)`除外
- 聚合函数中的DISTINCET 会对数据去重
- `COUNT(*)`聚合函数不允许出现在 WHERE里面

| 函数名          | 说明      |
| ------------ | ------- |
| COUNT（）      | 计数      |
| SUM（）        | 求和      |
| AVG（）        | 求平均     |
| MAX（）        | 求最大     |
| MIN（）        | 求最小     |
| STRING_AGG（） | 字符串聚合函数 |

- 关键字：COUNT
- 聚合函数会忽略NULL数据行
```sql
SELECT COUNT(*), COUNT(manager_id),
COUNT(DISTINCT(manager_id)) -- 去重计数
FROM employees;
```
![[Pasted image 20241126150659.png]]

- 关键字：STRING_AGG
- 字符串拼接函数
```sql
SELECT STRING_AGG(first_name, ';' ORDER BY first_name)
FROM employees;
```
![[Pasted image 20241126173426.png]]

- 关键字：GROUP BY
- 分组查询
```sql
SELECT department_id, count(*)
FROM employees
GROUP BY department_id;
```
![[Pasted image 20241127110337.png]]

```
-- extract 提取函数，提取时间里面的 年
SELECT extract(year from hire_date), count(*)
FROM employees
GROUP BY 1;
```
![[Pasted image 20241127110403.png]]

需求：分组计数完希望，找出数量超过10的组
- 关键字：HAVING
- 对GROUP BY 分组之后的结果进行筛选的函数  - 同WHERE
```sql
-- 错误语法逻辑, COUNT()聚合函数不能出现在WHERE里面
SELECT department_id, COUNT(*)
FROM employees
WHERE COUNT(*) > 10
GROUP BY department_id;
```
![[Pasted image 20241126173300.png]]

```sql
-- 正确语法
SELECT department_id, COUNT(*)
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 10;
```
![[Pasted image 20241126173348.png]]

#### 高级分组
- 关键字：GROUPING SETS(<字段>)
- 括号内可以选择字段进行分组
```sql
-- coalesce(<字段>,'为NULL时显示的信息')
SELECT coalesce(item,'所有产品') AS "产品", coalesce(year,'所有年份') AS "年份",SUM(quantity)
FROM sales
GROUP BY GROUPING SETS ((item, year), (item), (year), ());
```

- 特殊情况：ROLLUP(<字段>)
```sql
SELECT coalesce(item,'所有产品') AS "产品", coalesce(year,'所有年份') AS "年份",SUM(quantity)
FROM sales
GROUP BY ROLLUP(item, year);
-- ROLLUP就是item, year + item + sunm()
-- 相当于分组条件从右向左每次减少一个
```

- 特殊情况：CUBE(<字段>)
```sql
SELECT coalesce(item,'所有产品') AS "产品", coalesce(year,'所有年份') AS "年份",SUM(quantity)
FROM sales
GROUP BY CUBE(item, year);
-- CUBE就是 item，year + item + year + sum()
-- 相当于分组条件排列组合
```

- 关键字：GROUPING(<字段>)
- 显示是否是根据字段做出的分组，1->是，0->不是
- **用于区分是原数据中的空值还是分组产生的空值**
- 如果字段含多个值 例如：GROUPING(item, year)  要是根据两个字段做的汇总会将数值二进制转化  ->   1 1   ->  3
![[Pasted image 20241129212614.png]]


### 多表连接查询
- 内连接查询
- 关键字：`[INNER] JOIN`
- 只会返回两个表同时具有的值的字段，交集
![[Pasted image 20241129213308.png]]

- 左外连接查询    -- 同右外连接
- 关键字：`LEFT/RIGHT [OUTER] JOIN`
- 返回左边全部字段，如果包含右边没有的字段，则值设为空
![[Pasted image 20241129213647.png]]

- 全外连接
- 关键字：`FULL [OUTER] JOIN`
- 左右表数据都有，缺少的值设置为 空
![[Pasted image 20241129213918.png]]

- 交叉连接查询  -- **笛卡尔积**
- 关键字：`CROSS JOIN`
- 左右两表进行笛卡尔积
- 数据量大会有性能问题
```postgresql
-- conceat() 构造字符串
-- generate_series() 生成一个数值序列或者时间序列。

SELECT concat(t1, '*', t2, '=', t1*t2)
FROM generate_series(1, 9) t1
CROSS JOIN generate_series(1, 9) t2;
```
![[Pasted image 20241129215208.png]]

- 扩充
- 自然连接查询
- `NATURAL JOIN`
- 自动匹配两个表中所有名称相同的列
```postgresql
SELECT employee_name, department_name 
FROM employees 
NATURAL JOIN departments;
```
- 自连接查询
- 指一个表与它自身进行连接
```postgresql
SELECT e.employee_name AS '员工', m.employee_name AS '经理' 
FROM employees e 
JOIN employees m 
ON e.manager_id = m.employee_id;
```

### 条件表达式
- CASE分支表达式
- 实现分支功能
```postgresql
-- 简单CASE表达式
SELECT COUNT(CASE department_id
				WHEN 10 THEN 1 END) 
				AS dept10_count,
		COUNT(CASE department_id
				WHEN 10 THEN 1 END) 
				AS dept10_count,
		COUNT(CASE department_id
				WHEN 10 THEN 1 END) 
				AS dept10_count,
FROM employees;
```

```postgresql
-- 搜索CASE表达式
SELECT first_name, last_name,
	CASE
	  WHEN salary < 5000 THEN '低收入'
	  WHEN salary between 5000 and 10000 THEN '中等收入'
	  ELSE '高收入'
	END AS '收入'
FROM employees;
```

- 扩充
- NULLIF函数
	-  **概念**
        - `NULLIF`函数用于比较两个表达式的值。如果这两个表达式的值相等，那么函数返回`NULL`；如果两个表达式的值不相等，那么函数返回第一个表达式的值。
    - **语法格式**
        - `NULLIF(expression1, expression2)`，其中`expression1`和`expression2`是要进行比较的两个表达式。
    - **示例**
        - 假设我们有一个员工薪资表，其中包含基本工资（`base_salary`）和奖金（`bonus`）两列。如果奖金为 0，我们可能希望在计算总薪资时将奖金视为`NULL`，这样可以方便后续的统计操作（比如在求平均总薪资时，奖金为 0 的情况和没有奖金的情况可以统一处理）。可以使用`NULLIF`函数来实现：
        ```postgresql
        SELECT base_salary + NULLIF(bonus, 0) AS total_salary 
        FROM employee_salary;
		```
	- 在这个例子中，如果`bonus`列的值为 0，`NULLIF(bonus, 0)`将返回`NULL`，那么`base_salary + NULLIF(bonus, 0)`在计算总薪资时，就会将奖金视为`NULL`，只有当`bonus`不为 0 时，才会将其与基本工资相加。

- COALEASE函数
	-  **概念**
        - `COALESCE`函数用于返回参数列表中的第一个非`NULL`值。它会从左到右依次检查参数列表中的每个值，一旦找到一个非`NULL`值，就返回该值；如果所有参数都是`NULL`，则返回`NULL`。
    - **语法格式**
        - `COALESCE(expression1, expression2,..., expressionN)`，其中`expression1`到`expressionN`是要检查的表达式列表。
    - **示例**
        - 假设我们有一个客户联系信息表，其中包含客户的电话号码（`phone_number`）、电子邮件（`email`）和传真号码（`fax_number`）。我们希望获取一种可以联系到客户的方式，优先使用电话号码，其次是电子邮件，最后是传真号码。可以使用`COALESCE`函数来实现：
		```postgresql
		SELECT COALESCE(phone_number, email, fax_number) AS contact_info
		FROM customer_contact_info;
		```
	- 在这个查询中，`COALESCE`函数会首先检查`phone_number`列是否为`NULL`。如果不是`NULL`，则返回`phone_number`的值作为`contact_info`；如果`phone_number`是`NULL`，则检查`email`列，以此类推。如果所有列都是`NULL`，则`contact_info`列的值为`NULL`。

### 常用函数
#### 算术运算符
| 运算符   | 描述            | 示例        | 结果  |
| :---- | :------------ | :--------------- | :------------- |
| +     | 加法            | 2 + 3     | 5   |
| -     | 减法            | 2 - 3     | -1  |
| *     | 乘法            | 2 * 3     | 6   |
| /     | 除法            | 5 / 2     | 2   |
| %     | 模除(取余)        | 5 % 4     | 1   |
| ^     | 求幂(左边底数，右边指数) | 2.0 ^ 3.0 | 8   |
| \|/   | 平方根           | \|/25.0   | 5   |
| \|\|/ | 立方根           | \|\|/27.0 | 3   |
| !     | 阶乘            | 5!        | 120 |
| !!    | 阶乘(前置运算符)     | !!5       | 120 |
| @     | 绝对值           | @-5.0     | 5   |
| &     | 按位与           | 91 & 15   | 11  |
| \|    | 按位或           | 32 \| 3   | 35  |
| #     | 按位异或          | 17 # 5    | 20  |
| ~     | 按位非           | ~1        | -2  |
| <<    | 按位左移          | 1 << 4    | 16  |
| >>    | 按位右移          | 8 >> 2    | 2   |
#### 数学函数
| 函数                   | 描述                       | 示例             | 结果          |
| :------------------- | :----------------------- | :------------- | :---------- |
| abs(dp)              | 计算dp绝对值                  | abs(-100)      | 100         |
| ceil(dp)/ceiling(dp) | 向上取整                     | ceil(-42.8)    | -42         |
| floor(dp)            | 向下取整                     | ceil(-42.8)    | -43         |
| round(dp/dp, s)      | 四舍五入取整/到多少位小数            | round(12.45)   | 12          |
| trunc(dp/dp, s)      | 向0取整/到多少位小数              | trunc(12.8)    | 12          |
| power(a,b)           | 计算a的b次方                  | power(2, 3)    | 8           |
| sqrt(dp)             | 计算dp的平方根                 | sqrt(4)        | 2           |
| cbrt(dp)             | 计算dp的立方根                 | cbrt(27)       | 3.00004     |
| exp(dp)              | 计算以自然常数e为底的真数            | exp(1.0)       | 2.718...    |
| ln(dp)               | 计算以自然常数e为底的对数            | ln(2.718)      | 0.9999...   |
| log(dp)/log10(dp)    | 计算以10为底的对数               | log(100)       | 2           |
| log(b, x)            | 计算以b为底x的对数               | log(2.0, 16.0) | 3           |
| div(y, x)            | 计算y除以x的整数商               | div(9, 4)      | 2           |
| mod(y,x)             | 计算y除以x的余数                | mod(9, 4)      | 1           |
| degrees(dp)          | 将弧度转换为角度                 | degrees(1.57)  | 89.95....   |
| radians(dp)          | 将角度转换成弧度                 | radians(90.0)  | 1.570...    |
| pi()                 | 返回常量Π                    | pi()           | 3.14.159... |
| sign(dp)             | 返回参数的正负号，可能值为-1，0，+1     | sign(-8.4)     | -1          |
| random()             | 生成【0, 1）之间的随机数，类型为double | random()       | 0.07759...  |

#### 字符函数
| 函数                     | 描述                                                 | 示例                          | 结果      |
| :--------------------- | :------------------------------------------------- | :-------------------------- | :------ |
| concat(str,...)        | 用于字符串连接，并忽略NULL参数                                  | concat(22,NULL,33)          | 2233    |
| concat_ws(sep,str,...) | 使用指定分隔符sep连接字符串                                    | concat_ws('and',22,NULL,33) | 22and33 |
| \|\| : 双竖杠             | \|\|也可用于连接字符串                                      |                             |         |
| ascii(string)          | 返回第一个字符ASCII码，对于UTF8则返回Unicode码                    | ascii('x')                  | 120     |
| chr(int)               | 返回编码对应的字符，UTF8参数指定的是Unicode码，参数不能为0，text数据类型不能存空字符 | chr(120)                    | x       |
| bit_length(string)     | 计算字符串比特位                                           | bit_length('计算机')           | 72      |
| length(string)         | 计算字符串字符数                                           | length('计算机')               | 3       |
| octet_length(string)   | 计算字符串字节数                                           | octed_length('计算机')         | 9       |


