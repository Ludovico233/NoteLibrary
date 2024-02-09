package com.xtz.sort.SelectSort;

import java.util.Arrays;

/*
 * 选择排序(O(n^2))
 * 1. 遍历整个数组下标
 * 2. 遍历 i + 1 到 最后，找到其中最小的值放到 i 这个位置
 * 总结：每次找最小的值放到前面的位置，就实现了排序
 */
public class Main {
    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        sort1 sort1 = new sort1();
        sort1.selectSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}

class sort1 {
    public void selectSort(int[] arr) {
        if (arr == null || arr.length < 2) {                  //首先把空数组和只有一个元素的数组排除因为不需要排序
            return;
        }
        for (int i = 0; i < arr.length - 1; i++) {            //循环遍历每一个数
            int minNum = i;                                   //设定最小下标为i
            for (int j = i + 1; j < arr.length; j++) {        //遍历  从 i + 1 开始到 最后，找出后面有没有比当前下标对应的数还小的数
                minNum = arr[j] < arr[minNum] ? j : minNum;   //有就更新minNum
            }
            swap(arr, i, minNum);                             //将最小的数和当前的数换位置
        }
    }

    public void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}