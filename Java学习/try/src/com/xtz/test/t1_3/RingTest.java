package com.xtz.test.t1_3;

public class RingTest {
    public static void main(String[] args) {
        Ring ring = new Ring(3, 5, "red");
        System.out.println(ring);
        ring.setInnerRadius(5);
        ring.setOuterRadius(8);
        ring.setColor("black");
        System.out.println(ring);
    }
}
