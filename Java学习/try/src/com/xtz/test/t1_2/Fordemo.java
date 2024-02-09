package com.xtz.test.t1_2;

public class Fordemo {
    public static void main(String[] args) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print((i + 1) + "*" + (j + 1) + "=" +
                        (i + 1) * (j + 1) + "\t");
            }
            System.out.println();
        }
    }
}
