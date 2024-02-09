package com.xtz.homeWork2;

public class Cylinder implements C {
    private double r;
    private double h;
    private String color;

    @Override
    public double area() {
        return 2 * A.PI * r + (2 + h);
    }

    @Override
    public void setColor(String c) {
        this.color = c;
    }
    
    @Override
    public double volume() {
        return A.PI * r * r * h;
    }

    public Cylinder(double r, double h) {
        this.r = r;
        this.h = h;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public double getH() {
        return h;
    }

    public void setH(double h) {
        this.h = h;
    }

    public String getColor() {
        return color;
    }

}
