package com.xtz.test.t3_1;
//编写一个类Book，代表教材：
//（1）具有属性：名称（title）、页数（pageNum）、类型（type）。
//（2）具有方法：detail( )，用来在控制台输出每本教材的名称、页数、类型。
//（3）具有两个带参构造方法：
//     第一个构造方法中，设置教材类型为“计算机”（固定），其余属性的值由参数给定。
//      第二个构造方法中，所有属性的值都由参数给定。
// 编写测试类BookTest进行测试：分别以两种方式完成对两个Book对象的初始化工作，并分别调用它们的detail( )方法，看看输出是否正确。

public class Book {
    private String title;
    private int pageNum;
    private String type;
    
    public String detail() {
        return "Book{" +
                "title='" + title + '\'' +
                ", pageNum=" + pageNum +
                ", type='" + type + '\'' +
                '}';
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getPageNum() {
        return pageNum;
    }

    public void setPageNum(int pageNum) {
        this.pageNum = pageNum;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Book(String title, int pageNum, String type) {
        this.title = title;
        this.pageNum = pageNum;
        this.type = type;
    }

    public Book(String title, int pageNum) {
        this.title = title;
        this.pageNum = pageNum;
        this.type = "计算机";
    }
}
