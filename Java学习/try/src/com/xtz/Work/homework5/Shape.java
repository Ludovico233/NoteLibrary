package com.xtz.homework1;

public abstract class Shape {
    private double radius;

    public abstract double cubage();

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Shape(double radius) {
        this.radius = radius;
    }
}
