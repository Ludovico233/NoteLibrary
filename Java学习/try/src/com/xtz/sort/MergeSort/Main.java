package com.xtz.sort.MergeSort;

import java.util.Arrays;


//归并排序
public class Main {
    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        process(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }

    public static void process(int[] arr, int L, int R) {
        if (L == R) {



            return;
        }
        int mid = L + ((R - L) >> 1);
        process(arr, L, mid);
        process(arr, mid + 1, R);
        merge(arr, L, mid, R);
    }

    public static void merge(int[] arr, int L, int M, int R) {
        // 创建help帮助数组，用于将两个子树合并成顺序数组
        int[] help = new int[R - L + 1];
        // 给help数组使用的下标变量
        int i = 0;
        // 给两个子树首元素标记，并且比大小放入help数组
        int p1 = L;       // 左子树开始
        int p2 = M + 1;   // 右子树开始
        while (p1 <= M && p2 <= R) {
            help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
        }
        // 如果一颗子树添加完成，下列while会中一个
        while (p1 <= M) {
            help[i++] = arr[p1++];
        }
        while (p2 <= R) {
            help[i++] = arr[p2++];
        }
        // 添加回原数组
        for (int j = 0; j < help.length; j++) {
            arr[L + j] = help[j];
        }
    }
}



