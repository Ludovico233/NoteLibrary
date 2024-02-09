package com.xtz.homework1;

public class Globe extends Shape {
    public Globe(double radius) {
        super(radius);
    }

    @Override
    public double cubage() {
        return (4.0 / 3.0) * Math.PI * getRadius() * getRadius() * getRadius();
    }
}
