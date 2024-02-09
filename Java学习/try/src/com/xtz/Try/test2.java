package com.xtz.Try;

import java.util.Arrays;

public class test2 {
    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        //process(arr, 0, arr.length - 1);
        //ss(arr);
        //bs(arr);
        //is(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void process(int[] arr, int l, int r) {
        if (l == r) return;
        int m = l + ((r - l) >> 1);
        process(arr, l, m);
        process(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    public static void merge(int[] arr, int l, int m, int r) {
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

    public static void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void ss(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++) {
                min = arr[min] < arr[j] ? min : j;
            }
            swap(arr, i, min);
        }
    }

    public static void bs(int[] arr) {
        for (int i = arr.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
            }
        }

    }

    public static void qs(int[] arr) {
        if (arr.length < 2 || arr == null) return;
        qs(arr, 0, arr.length - 1);
    }

    public static void qs(int[] arr, int l, int r) {
        if (l < r) {
            swap(arr, l + (int) (Math.random() * (r - l + 1)), r);
            int[] p = partition(arr, l, r);
            qs(arr, l, p[0] + 1);
            qs(arr, p[1] - 1, r);
        }
    }

    public static int[] partition(int[] arr, int l, int r) {
        int less = l - 1;
        int more = r;
        while (l < more) {
            if (arr[l] < arr[r]) {
                swap(arr, l++, ++less);
            } else if (arr[l] > arr[r]) {
                swap(arr, l, --more);
            } else {
                l++;
            }
        }
        swap(arr, r, more);
        return new int[]{less + 1, more};
    }
}