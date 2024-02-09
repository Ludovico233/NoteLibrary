package com.xtz.sort.All;

public class Main {
    public static void main(String[] args) {

    }

    public static void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    //选择排序
    public static void ss(int[] arr) {
        if (arr == null || arr.length < 2) return;
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++) {
                min = arr[j] < arr[min] ? j : min;
            }
            swap(arr, i, min);
        }
    }

    //冒泡排序
    public static void bs(int[] arr) {
        if (arr == null || arr.length < 2) return;
        for (int i = arr.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }
    }

    //插入排序
    public static void is(int[] arr) {
        if (arr == null || arr.length < 2) return;
        for (int i = 1; i < arr.length; i++) {
            int min = i;
            for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j++) {
                swap(arr, j, j + 1);
            }
        }
    }

    //归并排序
    public static void process(int[] arr, int l, int r) {
        if (arr == null || arr.length < 2) return;
        int m = l + ((r - l) >> 1);
        process(arr, l, m);
        process(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    public static void merge(int[] arr, int l, int m, int r) {
        if (r == l) return;
        int[] help = new int[r - l + 1];
        int i = 0;
        int p1 = l;
        int p2 = m + 1;
        while (p1 <= m && p2 <= r) {
            help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }
        while (p1 <= m) {
            help[i++] = arr[p1++];
        }
        while (p2 <= r) {
            help[i++] = arr[p2++];
        }
        for (int j = 0; j < help.length; j++) {
            arr[l + j] = help[j];
        }
    }
}