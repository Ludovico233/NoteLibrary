1.修改密码 passwd （输入当前密码）—> 新密码 重复新密码 
PS: LINUX 下的所有密码输入都不显示 直接回车 输入状态下的删除键是【ctrl+back<-】

常见的命令
### 1.确定Linux发行版本（centos 、ubuntu、...）
uname -a
### 2.确定端口占用（已经开放了:8000 : 5000）
lsof -i:端口号 （lsof 不加参数 列出所有端口）（ubuntu）
如果lsof无法使用，则使用 netstat -nat（centos用的）
### 3.列出所有进程
`ps aux | less`
# web 服务器
1.php
2.python
3.mysql


# 观察别人屏幕

# 任务1.在 centos 机器上安装 tcpdump

### 参考文章
[(26条消息) Centos 7.x 安装 tcpdump 方法说明。_Dylan.zhou的博客-CSDN博客](https://blog.csdn.net/avla210/article/details/120997348)



1. 扫描端口状态 nmap -A -v - T4  目标
2. masscan -p(端口) 网关  --rate=10000 开放端口的主机信息