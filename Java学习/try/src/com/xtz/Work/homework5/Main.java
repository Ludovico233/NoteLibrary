package com.xtz.homework1;

public class Main {
    public static void main(String[] args) {
        Globe globe = new Globe(5);
        Cylinder cylinder = new Cylinder(5, 7);
        Cone cone = new Cone(5, 7);
        System.out.println("圆的面积：" + globe.cubage());
        System.out.println("圆柱的面积：" + cylinder.cubage());
        System.out.println("圆锥的面积：" + cone.cubage());
    }
}
