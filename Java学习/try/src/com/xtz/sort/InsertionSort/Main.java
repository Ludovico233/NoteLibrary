package com.xtz.sort.InsertionSort;

import java.util.Arrays;


//插入排序
public class Main {
    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        sort1 sort1 = new sort1();
        sort1.insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}

class sort1 {
    public void insertionSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 1; i < arr.length; i++) {
            for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
                swap(arr, j, j + 1);
            }
        }
    }

    public void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}