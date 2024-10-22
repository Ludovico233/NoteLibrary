
## 项目开发进度
- 一期：用户验证（短信验证，图片验证，django ModelForm组件） - 3天
- 二期：wiki，文件，问题管理 - 5~7天
- 三期：支付，部署（周末Linux基础） - 2天

## 项目开发
### day01 开发前戏
#### 今日概要
- 虚拟环境（项目环境）
- 搭建项目框架：local_settings
- git实战应用（代码每天提交）
- 通过python and 腾讯sms发送短信

#### 今日详情
1. 虚拟环境 virtualenv
	为每一个重要的项目创建虚拟环境
	1.1 安装  
	`pip install virtualenv`
	1.2 创建虚拟环境
```python
	virtualenv 环境名称（和项目名相同）
	# 注意：创建 [环境名称] 文件夹，放置所有的环境，进入指定路径
```

```python
	假设：目前电脑 py27/py35
	# 如果加入环境变量可以使用这种写法
	virtualenv 环境名称 --python=python3.6
	virtualenv 环境名称 --python=python2.7
	# 没有时
	virtualenv 环境名称 --python=解释器路径（c:\python\python3.6.exe）
```

```python
	1. 打开终端
	2. 安装：virtualenv
	3. 终端重启
	4. 通过cd进入指定目录
	5. 创建虚拟环境 virtualenv 环境名 --python==pythonXX
```

	1.3 目录详情
```
bin(包含解释器)
include（python包相关的东西）
lib（python默认模块）
```

	1.4 激活虚拟环境
```
win:
	cd Scripts 进入虚拟环境 Scripts 目录
	activate
```