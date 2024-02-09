package com.xtz.houseRent.view;

import com.xtz.houseRent.domain.House;
import com.xtz.houseRent.service.HouseService;
import com.xtz.houseRent.utils.Utility;

//1. 显示界面
//2. 接收用户输入
//3. 调用HouseService完成对房屋信息的各种操作
public class HouseView {
    public boolean loop = true;//控制显示菜单
    private int key;//接收用户选择的功能
    private char c;
    private HouseService houseService = new HouseService(10);

    //显示界面
    public void mainMenu() {
        do {
            System.out.println("=======房屋出租系统菜单=======");
            System.out.println("|       1.新增房源\t\t|");
            System.out.println("|       2.查找房源\t\t|");
            System.out.println("|       3.删除房源\t\t|");
            System.out.println("|       4.修改房屋信息\t|");
            System.out.println("|       5.房屋列表\t\t|");
            System.out.println("|       6.退   出\t\t|");
            System.out.println("===========================");
            System.out.print("请输入你的选择(1 - 6)：");
            key = Utility.readInt();
            switch (key) {
                case 1:
                    addHouse();
                    break;
                case 2:
                    readHouse();
                    break;
                case 3:
                    delHouse();
                    break;
                case 4:
                    updateHouse();
                    break;
                case 5:
                    listHouses();
                    break;
                case 6:
                    exit();
                    break;
            }
        } while (loop);
    }

    //1.编写 addHouse 显示方法，接收输入，创建house对象，调用add方法
    public void addHouse() {
        System.out.println("======================添加房屋======================");
        System.out.print("姓名:");
        String name = Utility.readString(8);
        System.out.print("电话:");
        String phone = Utility.readString(12);
        System.out.print("地址:");
        String address = Utility.readString(18);
        System.out.print("月租:");
        int rent = Utility.readInt();
        System.out.print("状态(未/已出租):");
        String state = Utility.readString(8);
        House newhouse = new House(0, name, phone, address, rent, state);
        if (houseService.add(newhouse)) {
            System.out.println("===================添加房屋成功===================");
        } else {
            System.out.println("===================添加房屋失败===================");
        }
    }

    //2. 编写 readHouse() 查找方法
    public void readHouse() {
        System.out.println("======================查找房屋======================");
        System.out.print("请输入要查找的Id:");
        int readId = Utility.readInt();
        House house = houseService.readById(readId);
        if (house != null) {
            System.out.println(house);
        } else {
            System.out.println("================并未发现房屋信息=================");
        }
    }

    //3.编写 delHouse() 删除方法,接收输入 id，调用Service的del方法
    public void delHouse() {
        System.out.println("======================删除房屋======================");
        System.out.print("请选项带删除的房屋编号(-1退出):");
        int delId = Utility.readInt();
        if (delId == -1) {
            System.out.println("======================放弃删除======================");
            return;
        }
        System.out.print("请确认是否删除(y/n),请小心选择:");
        c = Utility.readChar();
        do {
            if (c == 'y' || c == 'n') {
                break;
            } else {
                System.out.print("输入错误请重新输入:");
            }
        } while (loop);
        if (c == 'y') {
            if (houseService.del(delId)) {
                System.out.println("======================删除成功======================");
            } else {
                System.out.println("=================编号不存在，删除失败=================");
            }
        } else {
            System.out.println("======================放弃删除======================");
        }
    }

    //4.编写 updateHouse() 修改方法，接收输入id
    public void updateHouse() {
        System.out.println("===================修改房屋信息===================");
        System.out.print("请选择待修改房屋编号(-1退出):");
        int updateId = Utility.readInt();
        if (updateId == -1) {
            System.out.println("你放弃修改房屋信息");
            return;
        }
        House house = houseService.readById(updateId);
        if (house == null) {
            System.out.println("你要修改的房屋信息不存在");
        }
        System.out.print("姓名(" + house.getName() + "):");
        String name = Utility.readString(8, "");
        if (!"".equals(name)) {
            house.setName(name);
        }
        System.out.print("电话(" + house.getPhone() + "):");
        String phone = Utility.readString(12, "");
        if (!"".equals(phone)) {
            house.setPhone(phone);
        }
        System.out.print("地址(" + house.getAddress() + "):");
        String address = Utility.readString(18, "");
        if (!"".equals(address)) {
            house.setAddress(address);
        }
        System.out.print("租金(" + house.getRent() + "):");
        int rent = Utility.readInt(-1);
        if (rent != -1) {
            house.setRent(rent);
        }
        System.out.print("状态(" + house.getState() + "):");
        String state = Utility.readString(8, "");
        if (!"".equals(state)) {
            house.setState(state);
        }
        System.out.println("=================成功修改房屋信息=================");
    }

    //5.编写 listHouses() 显示房屋列表
    public void listHouses() {
        System.out.println("======================房屋列表======================");
        System.out.println("编号\t\t房主\t\t电话\t\t地址\t\t月租\t\t状态(未/已出租)");
        House[] houses = houseService.list();
        for (int i = 0; i < houses.length; i++) {
            if (houses[i] != null) {
                System.out.println(houses[i]);
            }
        }
        System.out.println("==================房屋列表显示完毕==================\n");
    }

    //6.编写 exit() 退出方法
    public void exit() {
        System.out.print("请问是否确认退出(y/n):");
        for (; ; ) {
            c = Utility.readChar();
            if (c == 'y' || c == 'n') {
                break;
            }
            System.out.print("输入错误请重新输入:");
        }
        if (c == 'y') {
            System.out.println("成功退出！");
            loop = false;
        }
    }
}