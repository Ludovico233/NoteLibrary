# Java概述  
## Java历史  

### 什么是程序  
程序：计算机执行某些操作或解决某些问题而编写的一系列**有序指令的集合**

### Java诞生  
创始人：高司令（甲骨文公司）  
第一代：1995年  
现行用的的最多的是Java8，Java11  

---
## Java技术体系平台  
javaSE（标准版），JavaEE（企业版），JavaME（小型版）  

---
## Java重要特点 
- Java面向对象（oop）
 - Java是健壮的。**强类型机制，异常处理，垃圾的自动收集**是保证。
 - Java是跨平台的。（windows，linux 即：一个编译好的.class文件,可以在多个系统下运行）。**依靠 JVM(Java虚拟机)**
 - Java是解释型的。
 解释性语言：JavaScript，PHP，Java
 编译性语言:c,c++
 区别：**解释性语言，编译后的代码，不能直接被机器执行。编译性语言，编译后，能直接执行**
 - Java开发工具
 notepad++，editplus，sublime text，IDEA，eclipse

---
## Java运行机制和运行过程
- **JVM** Java虚拟机（Jvm Java virtual machine）
Jvm具有指令集并使用不同的储存区域。负责执行指令，管理数据，内存，寄存器，**包含在JDK中**。
对于不同的平台，有不同的虚拟机。
Java虚拟机制屏蔽了底层运行平台的差异，实现“一次编译，到处运行”
- JDK基本介绍
**JDK**（Java development kit **Java开发工具包**）
**JDK = JRE + Java开发工具**（Java，Javac，Javadoc，Javap等）
- **JRE**(Java runtime environment **Java运行环境**)
**JRE = JVM + Java核心类库**

---
## 配置环境变量path
- 我的电脑--属性--高级系统设置--环境变量
- 增加Java home 环境变量，指向JDK安装目录。 
- 编辑path环境变量，增加%Java_HOME%\bin
- 打开DOS命令行，任意目录下敲击Javac，如果出现参数信息，配置成功。

---
## java快速入门
1.哈哈，又是编写hello，world
- public class Hello  **表示hello是一个类，是一个public公有的类，hello{ } 是类的开始和结束。**
- public static void main(String[] args)和c语言一样**main（）是主函数**
```java
public class Hello{
    public static void main(String[] args){
        System.out.println("hello,world");
    }
}
```
2.cmd中编译（javac），生成.class文件。   
3.cmd中运行（Java）。  
**文件有中文时**：在文件-设置文件编码-GBK，重新保存即可。  
4.Java执行流程  
**.Java文件----编译（javac.exe)----.class文件----运行（java.exe）----结果  
.class（字节码文件）装载到对应系统的JVM（虚拟机）执行。**  

---
## Java细节说明
**1.编译后，每一个类都对应一个.class文件。  
2.如果源文件包含一个public类，则文件名必须按该类命名。  
3.一个文件最多只包含一个public类，其他类个数不限，也可以将main方法写在非public类中，然后指定运行非     public类，这样入口的方法就是非public的main方法（每个类里面都可以有一个main函数）**  
##快速学习Java技术   
1.**找到需求**（工作需要，客户要求，技术控）  
2.看**是否能用传统技术解决**（解决不完美或者不能）  
3.引出需要**学习的知识点 **   
4.**学习新技术或者知识点的基本原理和基本语法**（不要考虑细节）  
5.**快速入门（基本程序，增删改查crud）**  
6.**开始研究技术的注意事项，使用西街，使用规范，如何优化**  

---
## Java API 文档  
1.API（application programming intrface , 应用程序编程接口）   
是java提供的基本类库  
**[java api 文档 ](https://www.matools.com/)   
2.java 有丰富的基础类库，api文档用于告诉我们如何使用这些类，以及这些类里包含的方法**   
![](java类.png)
##快捷键   
ctrl + shift + d(复制上一行到下一行)   
ctrl + shift + k(删除本行)   
ctrl + /(注释) 