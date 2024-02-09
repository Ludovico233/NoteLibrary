package com.xtz.homework1;

public class Cone extends Shape {
    private double h;

    @Override
    public double cubage() {
        return Math.PI * getRadius() * getRadius() * h / 3;
    }

    public Cone(double radius, double h) {
        super(radius);
        this.h = h;
    }
}
