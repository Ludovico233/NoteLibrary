package com.xtz.homework1;

public class Cylinder extends Shape {
    private double h;

    @Override
    public double cubage() {
        return Math.PI * getRadius() * getRadius() * h;
    }

    public Cylinder(double radius, double h) {
        super(radius);
        this.h = h;
    }
}
