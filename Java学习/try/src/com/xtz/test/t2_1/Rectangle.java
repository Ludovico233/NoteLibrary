package com.xtz.test.t2_1;

//编写一个矩形类Rectangle;将长length与宽width作为矩形类的属性，
//        编写setLength()和setWidth()方法分别实现长和宽的设置，
//        并定义一个成员方法getArea()求此矩形的面积，
//        另外定义一个成员方法getGirth()求此矩形的周长
public class Rectangle {
    private double length;
    private double width;

    public String getArea() {
        return "面积：" + length * width;
    }

    public String getGirth() {
        return "周长：" + 2 * (length + width);
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "length=" + length +
                ", width=" + width +
                '}';
    }


    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
}
