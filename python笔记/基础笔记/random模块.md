## 基础知识
```python
random.random() # 随机小于1的浮点数  
random.uniform(1, 3 # 随机1-3的浮点数  
random.randint(1, 3) # 随机1-3的整数  
random.randrange(1, 3) # 随机1-3的整数,不包含3  
random.choice([1, 2, 3, 4, 5]) # 随机选择一个  
random.sample([1, 2, 3, 4, 5], 2) # 随机选择2个  
random.shuffle([1, 2, 3, 4, 5]) # 随机打乱顺序
```

---
## 实践

### 题目
- 1.生成一个16位随机密码
- 2.必须包含（字符，数字，大写字母，小写字母）


### 代码
- 方法一，直接想到，存在很大缺陷
```python
str1 = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'  
print(''.join(random.sample(str1, 16)))
```

- 方法二，仍然存在缺陷
```python
def get_random_pwd(length=16):  
	pwd = ''   
	# ASCII码对照（符号，数字，大写字母，小写字母）  
	char_list = [[33, 47], [48, 57], [65, 90], [97, 122]]
	for i in range(length):  
		random_list = random.choice(char_list) # 随机选择一个字符列表  
		# 随机选择一个字符列表中的字符，*random_list解包  
		pwd += chr(random.randint(*random_list)) 
  
	return pwd
```

- 方法三，判断很多，还可能生成不了正确密码，导致重来
```python
def get_random_pwd(length=16):  
	if length < 4:  
		print('密码长度不能小于4位')  
		return ''  
	while True:  
		pwd = ''  
		char_list = [[33, 47], [48, 57], [65, 90], [97, 122]] 
		choice_list = [False for i in range(4)]  
		for i in range(length):  
			random_list = random.choice(char_list)   
			pwd += chr(random.randint(*random_list)) 
		for word in pwd:  
			if 33 <= ord(word) <= 47:  
			choice_list[0] = True  
			elif 48 <= ord(word) <= 57:  
			choice_list[1] = True  
			elif 65 <= ord(word) <= 90:  
			choice_list[2] = True  
			elif 97 <= ord(word) <= 122:  
			choice_list[3] = True  
		if False not in choice_list:  
			return pwd
```

- 方法四，最终成果
```python
def get_random_pwd(length=16):  
	if length < 4:  
		print('密码长度不能小于4位')  
		return ''  
	# 生成四种字符  
	pwd = []  
	char_list = [[33, 47], [48, 57], [65, 90], [97, 122]]  
	four_char = [chr(random.randint(*char_list[0])),  
				 chr(random.randint(*char_list[1])),  
				 chr(random.randint(*char_list[2])),  
				 chr(random.randint(*char_list[3]))]  
	pwd.extend(four_char)  
	# 生成剩余字符  
	for i in range(length - 4):  
		random_list = random.choice(char_list)  
		pwd.append(chr(random.randint(*random_list)))  
	# 打乱顺序  
	random.shuffle(pwd)  
	return ''.join(pwd)
```

