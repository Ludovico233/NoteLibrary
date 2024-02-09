package com.xtz.sort.BubbleSort;

import java.util.Arrays;


/*
 * 冒泡排序
 * 1. 遍历  限定范围
 * 2. 遍历  区间范围，大数向后移
 * 总结：每次把大数向后移，让区间内最大多数在最后，然后缩小范围，完成排序
 * */
public class Main {
    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        sort1 sort1 = new sort1();
        sort1.bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}

class sort1 {
    public void bubbleSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = arr.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }
    }

    //最好交换别这么写，这里只是引入位操作
    public void swap(int[] arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}
