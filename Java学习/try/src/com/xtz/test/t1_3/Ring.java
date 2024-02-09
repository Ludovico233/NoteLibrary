package com.xtz.test.t1_3;

//编写一个圆环类 Ring 的Java 程序。圆环类有3 个数据成员,
//        分别是内半径 innerRadius,外半径outerRadius 和颜色color，
//        通过增加一个构造方法Ring(),该构造方法包含三个参数，分别是内半径，外半径和颜色，
//        再通过构造方法，初始化圆环的内半径、外半径和颜色，增加一个get方法，打印输出该圆的内半径，
//        外半径和颜色； 再增加一个返回圆环面积的方法getArea(),用来打印输出圆环的面积。
//        通过定义的构造方法创建具体的圆环实例；对圆环进行初始化。同时调用getArea()实现圆环面积的计算

public class Ring {
    private double innerRadius;
    private double outerRadius;
    private String color;

    public String getArea() {
        return "面积：" + Math.PI * (outerRadius * outerRadius - innerRadius * innerRadius);
    }

    public double getInnerRadius() {
        return innerRadius;
    }

    @Override
    public String toString() {
        return "Ring{" +
                "innerRadius=" + innerRadius +
                ", outerRadius=" + outerRadius +
                ", color='" + color + '\'' +
                '}';
    }

    public Ring(double innerRadius, double outerRadius, String color) {
        this.innerRadius = innerRadius;
        this.outerRadius = outerRadius;
        this.color = color;
    }

    public void setInnerRadius(double innerRadius) {
        this.innerRadius = innerRadius;
    }

    public double getOuterRadius() {
        return outerRadius;
    }

    public void setOuterRadius(double outerRadius) {
        this.outerRadius = outerRadius;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
}
