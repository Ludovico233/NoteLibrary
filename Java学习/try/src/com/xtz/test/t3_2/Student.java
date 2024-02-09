package com.xtz.test.t3_2;
//定义一个学生类Student。要求如下：
//        	属性：姓名，性别，年龄。
//        	静态属性：人数。
//        	方法：自我介绍（输出个人信息）。
//        	构造方法：每增加一个成员，人数+1.
//        	静态方法：输出当前班级人数。
//        定义一个测试类：Test，要求如下：在主程序中，生成多个Student对象，最终输出班级人数，并让每个对象做自我介绍。

public class Student {
    private String name;
    private String sex;
    private int age;
    private static int num = 0;

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", sex='" + sex + '\'' +
                ", age=" + age +
                '}';
    }

    public static String showNum() {
        return "人数：" + num;
    }

    public Student(String name, String sex, int age) {
        this.name = name;
        this.sex = sex;
        this.age = age;
        num++;
    }
}
