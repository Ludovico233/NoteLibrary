package com.xtz.homeWork2;

public class Main {
    public static void main(String[] args) {
        Cylinder cylinder = new Cylinder(5, 7);
        System.out.println("圆柱体表面积：" + cylinder.area());
        System.out.println("圆柱体体积：" + cylinder.volume());
        cylinder.setColor("black");
        System.out.println("圆柱体颜色：" + cylinder.getColor());
    }
}
