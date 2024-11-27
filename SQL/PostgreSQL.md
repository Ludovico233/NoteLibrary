
---
## PostgreSQL简介
1. **开源**：用户可以基于任何目的的使用，修改，发布PostgreSQL
2. **先进**：高度兼容SQL标准，支持事务的ACID原则
3. **功能丰富**：基本数据类型，数组，范围类型，JSON，XML，几何类型；完整性约束；索引；复杂查询；先进的查询优化器；分区表；异步；同步；逻辑复制；安全认证；全文检索。
4. **可拓展性**：存储过程（C，Go，Perl，Python，Java等）；FDW；自定义类型和索引；存储引擎；大量衍生产品。
5. **端口**：5432

拓展链接：
	**在线运行SQL**：[SQL Fiddle](https://sqlfiddle.com/)
	**英文文档**：[PostgreSQL 17.2 Documentation](https://www.postgresql.org/docs/17/index.html)
	**中文文档**：[PostgreSQL 15.7 手册](http://www.postgres.cn/docs/current/index.html)


---
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
SELECT employee_id, first_name, last_name, hire_date, selary 
FROM employees 
ORDER BY first_name ASC, lat_name DESC;


SELECT employee_id, first_name, last_name, hire_date, selary 
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
SELECT first_name, last_name,  selary 
FROM employees 
ORDER BY selary
FETCH FIRST 10 ROWS WITH TIES;
-- 找出和最后一条记录相同的尽可能多的数据
```
![[Pasted image 20241126173710.png]]

分页查询
以每次查询10条记录为例：
- 关键字：OFFSET <偏移量> RWS
```sql
-- 标准SQL
SELECT first_name, last_name,  selary 
FROM employees 
ORDER BY selary
OFFSET 10 ROWS    -- 查询偏移量为10，即10-20记录
FETCH FIRST 10 ROWS WITH TIES;

-- pgsql方言
SELECT first_name, last_name,  selary 
FROM employees 
ORDER BY selary
LIMIT 10 OFFSET 10;
```

### 函数

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
SELECT department_name, count(*)
FROM employees
GROUP BY departmen_name;
```

```
-- extract 提取函数，提取时间里面的 年
SELECT extract(year from hire_date), count(*)
FROM employees
GROUP BY 1;
```

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
