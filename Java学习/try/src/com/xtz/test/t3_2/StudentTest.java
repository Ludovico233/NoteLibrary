package com.xtz.test.t3_2;

public class StudentTest {
    public static void main(String[] args) {
        Student student1 = new Student("jack", "男", 18);
        Student student2 = new Student("simth", "男", 30);
        Student student3 = new Student("susan", "女", 20);
        System.out.println(student1);
        System.out.println(student2);
        System.out.println(student3);
        System.out.println(Student.showNum());
    }
}
