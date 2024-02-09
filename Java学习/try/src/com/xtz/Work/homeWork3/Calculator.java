package com.xtz.homeWork3;

public class Calculator implements Compute {
    @Override
    public void computer(double m, double n, char c) {
        switch (c) {
            case '+':
                System.out.println(m + " + " + n + " = " + (m + n));
                break;
            case '-':
                System.out.println(m + " - " + n + " = " + (m - n));
                break;
            case '*':
                System.out.println(m + " * " + n + " = " + (m * n));
                break;
            case '/':
                System.out.println(m + " / " + n + " = " + (m / n));
                break;
        }
    }
}
