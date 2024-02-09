package com.xtz.test.t1_1;

public class Fibonacci {
    private long[] fib;

    public Fibonacci(int num) {
        fib = new long[num];
    }

    public void insertFib() {
        for (int i = 0; i < fib.length; i++) {
            if (fib.length == 1 || fib.length == 2) {
                fib[i] = 1;
            }
            fib[0] = fib[1] = 1;
            if (i > 1) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
        }
    }

    public void printFib() {
        for (int i = 0; i < fib.length; i++) {
            System.out.print("f" + (i + 1) + "=" + fib[i] + "\t\t");
            if ((i + 1) % 5 == 0) {
                System.out.println();
            }
        }
    }
}
