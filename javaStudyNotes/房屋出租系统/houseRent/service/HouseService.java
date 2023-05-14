package com.xtz.houseRent.service;

import com.xtz.houseRent.domain.House;
import com.xtz.houseRent.utils.Utility;

//1. 定义House[],保存house对象
//2.响应HouseView的调用
//3.完成对房屋信息的c(create)r(read)u(update)d(delete)
public class HouseService {
    private House[] houses;//存放House对象
    private int houseNums;//记录当前有多少个房屋信息
    private int idCounter = 0;
    private char c;
    private House[] houses2;
    private boolean loop = true;

    public HouseService(int size) {
        houses = new House[size];//指定数组大小
        houses2 = new House[houses.length + 1];
    }

    //readById方法，查找对象
    public House readById(int readId) {
        for (int i = 0; i < houseNums; i++) {
            if (readId == houses[i].getId()) {
                return houses[i];
            }
        }
        return null;
    }

    //add方法，添加新对象，返回boolean
    public boolean add(House newHouse) {
        if (houseNums == houses.length) {
            System.out.print("数组已满，是否继续添加(y/n=):");
            do {
                c = Utility.readChar();
                if (c == 'y') {
                    for (int i = 0; i < houses.length; i++) {
                        houses2[i] = houses[i];
                    }
                    houses2[houses.length] = newHouse;
                    houses = houses2;
                    return true;
                } else if (c == 'n') {
                    return false;
                } else {
                    System.out.println("输入错误请重新输入:");
                }
            } while (loop);
        }
        houses[houseNums++] = newHouse;
        newHouse.setId(++idCounter);
        return true;
    }

    //del方法，删除一个房屋信息
    public boolean del(int delId) {
        int index = -1;
        for (int i = 0; i < houseNums; i++) {
            if (delId == houses[i].getId()) {//要删除的房屋(id),是数组下标为i的元素
                index = i;//index记录下标
            }
        }
        if (index == -1) {//说明delId在数组中不存在
            return false;
        }
        //如果找到，需要怎么删除
        for (int i = index; i < houseNums - 1; i++) {
            houses[i] = houses[i + 1];
        }
        houses[--houseNums] = null;
        return true;
    }

    //显示列表
    public House[] list() {
        return houses;
    }

}
