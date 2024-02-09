package com.xtz.homework4;

import java.util.ArrayList;
import java.util.Iterator;

public class Student {
    private String sno;
    private String name;
    private double math;
    private double computer;

    Student(String s,String n,double m,double c){
        this.sno=s;
        this.name=n;
        this.math=m;
        this.computer=c;
    }

    public void print(){
        System.out.println("学号为："+sno);
        System.out.println("姓名为："+name);
        System.out.println("数学成绩为："+math);
        System.out.println("计算机成绩为："+computer);
    }
}
public class PostGraduate extends Student{
    private String teachername;
    private String direction;

    public PostGraduate(String s, String n, double m, double c, String teachername, String direction) {
        super(s, n, m, c);
        this.teachername = teachername;
        this.direction = direction;
    }


    public class Try1 {
    public static void main(String[] args) {
    }
}
