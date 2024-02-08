## 1. 快速入门
---
版本控制流程：创建文件夹 -> 初试化 -> 管理 -> 生成版本

- 创建文件夹
- 在文件夹中右键打开`git bash` 

| 命令 | 解释 |
| :--- | :--- |
| git init | 文件初试化，即：让git管理当前文件夹 |
| git status | 查看git当前 管理/未管理 的文件。绿色(已管理)，红色(未管理) |
| git add file_name | 添加文件被git管理，file_name = . 即：所有文件添加管理 |
| git config --global user.email "邮箱"<br>git config --globle user.name "姓名" | 个人信息配置：邮箱，用户名【仅需开始第一次】 |
| git commit -m '描述信息' | 本地提交，生成一个版本 |
| git log | 查看版本信息 |

## 2. 回滚
---
1. 回滚之前版本
	- `git log`  查看版本号
	- `git reset --hard 版本号` 回滚到版本号的版本
1. 回滚回滚后的版本（已经回滚到之前的版本了，但是后悔了想回再回到之后的版本）
	- `git reflog` 可以显示回滚前的版本号
	- `git reset --hard 版本号` 回滚


![](../statics/img/git命令.png "git命令")

![]()