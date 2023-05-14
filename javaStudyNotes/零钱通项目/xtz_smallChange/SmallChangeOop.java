package com.xtz_smallChange;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

//该类完成零钱通各个功能
//将各个功能封装成一个方法
public class SmallChangeOop {
    //属性
    String details = "----------------零钱通明细----------------";
    boolean loop = true;
    Scanner scanner = new Scanner(System.in);
    Date date = new Date();
    double money = 0;
    double balance = 0;
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm");//用于日期格式化
    String note;
    String choose;
    int c;//储存选择分支的量

    //方法
    public void mainMenu() {
        do {
            System.out.println("=========零钱通菜单=========");
            System.out.println("|       1. 零钱通明细      |");
            System.out.println("|       2. 收益入账        |");
            System.out.println("|       3. 消费情况        |");
            System.out.println("|       4. 退出程序        |");
            System.out.println("===========================");
            System.out.print("请输入你的选择：");
            c = scanner.nextInt();
            switch (c) {
                case 1:
                    this.detail();
                    break;
                case 2:
                    this.income();
                    break;
                case 3:
                    this.pay();
                    break;
                case 4:
                    this.exit();
                    break;
                default:
                    System.out.println("菜单选择有误，请重新选择");
            }
        } while (loop);
    }

    public void detail() {
        System.out.println(details);
    }

    public void income() {
        System.out.print("收益入账金额：");
        money = scanner.nextDouble();
        if (money <= 0) {
            System.out.println("收益金额需要 > 0");
            return;
        }
        balance += money;
        date = new Date();
        details += "\n收益入帐\t+" + money + "\t" + sdf.format(date) + "\t" + balance;
    }

    public void pay() {
        System.out.print("消费金额：");
        money = scanner.nextDouble();
        if (money <= 0 || money > balance) {
            System.out.println("消费金额 应该在: 1--" + balance);
            return;
        }
        System.out.print("消费说明：");
        note = scanner.next();
        balance -= money;
        date = new Date();
        details += "\n" + note + " \t-" + money + "\t" + sdf.format(date) + "\t" + balance;
    }

    public void exit() {
        System.out.println("你是否要退出？y/n");
        do {
            choose = scanner.next();
            if (choose.equals("y") || choose.equals("n")) {
                return;
            }
            System.out.println("输入错误，请重新输入");
        } while (loop);
        if (choose.equals("y")) {
            loop = false;
        }
    }
}
