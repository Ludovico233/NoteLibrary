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
- 回滚之前版本
	- `git log`  查看版本号
	- `git reset --hard 版本号` 回滚到版本号的版本
- 回滚回滚后的版本（已经回滚到之前的版本了，但是后悔了想回再回到之后的版本）
	- `git reflog` 可以显示回滚前的版本号
	- `git reset --hard 版本号` 回滚


![git命令](../statics/img/git命令.png "git命令")


## 3. 分支
---
| 命令                    | 解释                     |
|:----------------------- |:------------------------ |
| git branch              | 查看当前分支             |
| git branch 分支名       | 创建新分支               |
| git checkout 分支名     | 切换分支                 |
| git mege 要合并的分支名 | 合并分支（可能产生冲突） |
| git branch -d 分支名                        | 删除分支                         |


## 4. git工作流
---
工作时至少保留两个分支 --> master（主分支），dev（开发分支）

- master分支
	- 保存线上运行的正式版本（稳定版）
- dev分支
	- 在此分支上做开发，添加性能/修改代码
	- 测试没有问题，可合并到主分支上

![git简单工作流](../statics/img/git简单工作流.png "git简单工作流")

## 5. github
---
github：代码托管仓库之一 （gitlab，gitee....）

1. github最初使用
	- 流程
		- 注册账号
		- 创建仓库
		- 本地代码推送到github仓库
	
	- 命令
		- 给远程仓库起别名(origin)
			- `git remote add origin 远程仓库地址`
		- 向远程推送代码
			- `git push -u origin 分支`
		- 克隆远程仓库代码
			- `git clon 远程仓库地址`（内部已实现 git remote add origin 远程仓库地址）

2. 去到公司拉取到自己本地，继续开发
	- 切换分支到dev
		- `git checkout dev`
	- 将master分支合并到dev分支（仅一次）
		- `git merge master`
	- 修改代码并提交
		- `git add .`
		- `git commit -m xx`
		- `git push origin dev`

3. 回到家要拉取仓库最新版本，继续开发
	- 切换到dev分支，继续开发
		- `git checkout dev`
	- 拉取更新后的代码
		- `git pull origin dev`
	- 继续开发，提交代码
		- `git add .`
		- `git commit -m xx`
		- `git push origin dev`(如果时git push -u xx：表示默认提交到xx地址)

流程：切换到dev(开发)分支，先拉取(pull)代码，再推(push)代码

4. 开发完毕，准备上线
	- 将dev分支合并到master分支，并上线
		- `git checkout master`
		- `git merge dev`
		- `git push origin master`
	- 还要将本地更新后的dev分支推送到github仓库
		- `git checkout dev`
		- `git merge master`
		- `git push origin dev`


```
git pull origin dev   --> 远程仓库拉到工作区
       ||（等于）
git fetch origin dev  --> 远程仓库拉到本地版本库
git merge origin/dev  --> 版本库拉到工作区
```


## 6. rebase(变基)
---
使git记录变得简洁

- 情况一：合并commit记录
	- `git rebase -i 版本号` 从版本号的记录开始 --> 最新记录合并
	- `git rebase -i HEAD~数字`从最新记录开始合并 数字 个记录
	- 修改合并信息 pick -> s
	- 修改提交信息
- 情况二：强行将其他分支记录合并到master分支上，强行插入
	- `git rebase master` ：切换到dev分支时操作
	- `git merge dev`：切换回master分支
	- 
- 情况三：多端修改时，一端忘记push，之后的合并产生分叉的情况
	- `git push` == `git fetch` + `git merge`/ `git rebase 分支名`将分叉解决

附加命令：
```
git log --graph --pretty=fomate:"%h %s"
# --graph 线性显示记录（更加美观）
# ---pretty=fomate:"%h %s" 格式化输出（hash值 和 提交信息）
```

注：如果rebase过程中产生冲突，解决冲突后`git rebase --continue`继续进行变基操作

## 7. beyond compare 快速解决冲突
---
前期准备：
1. 安装beyond compare
2. 在git中配置
	 ```
	 git config --local merge.tool bc3 // 取名 bc3
	 git config --local mergetool.path '路径（bin/bcomp）'
	 git config --local merge tool.keepBackup false   //不用保留源文件
	 // --local 只在本项目有效
	 ```
3. 应用beyond compare 解决冲突
	 `git mergetool`


## 8. 总结
---
| 命令                         | 解释                      |
|:---------------------------- |:------------------------- |
| `git remote add origin 地址` | 添加远程连接（取别名）    |
| `git push origin dev`        | 推送代码                  |
| `git clone 地址`             | 下载代码                  |
| `git pull origin dev`        | 拉取代码  = fetch + merge |
| `git rebase ...`             | 变基，使提交记录简洁      |
| `git log --graph --pretty=format:"%h %s"`                             | 记录图形显示                          |

