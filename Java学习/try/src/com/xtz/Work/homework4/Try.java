package com.xtz.homework4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Try {
    @SuppressWarnings({"all"})
    public static void main(String[] args) {
//        List list = new LinkedList();
//        list.add("tom");
//        list.add("jack");
//        list.add("smith");
//        list.add("vennasa");
//        list.add("kristina");
//        Iterator iter = list.iterator();
//        while(iter.hasNext()){
//            Object next = iter.next();
//            System.out.println(next);
//        }


//        for(Object o:list){
//            System.out.println(o);
//        }


//        for (int i = 0; i < list.size(); i++) {
//            System.out.println(list.get(i));
//        }

        List list = new ArrayList();
        list.add(new Book("红楼梦",99,"曹雪芹"));
        list.add(new Book("西游记",90,"吴承恩"));
        list.add(new Book("水浒传",92,"施耐庵"));
        list.add(new Book("三国志",98,"罗贯中"));
        Iterator i = list.iterator();
        while(i.hasNext()){
            Object o = i.next();
            System.out.println(o);
        }
        System.out.println("====================");
        bs(list);
        i = list.iterator();
        while(i.hasNext()){
            Object o = i.next();
            System.out.println(o);
        }

    }

    public static void bs(List list){
        for (int i = list.size() - 1;i > 0; i--){
            for (int j = 0;j < i;j++){
                Book book1 = (Book)list.get(j);
                Book book2 = (Book)list.get(j + 1);
                if (book1.getJg() > book2.getJg()){
                    list.set(j,book2);
                    list.set(j + 1,book1);
                }
            }
        }
    }
}
class Book{
    private String name;
    private double jg;
    private String zz;

    public Book(String name, double jg, String zz) {
        this.name = name;
        this.jg = jg;
        this.zz = zz;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getJg() {
        return jg;
    }

    public void setJg(double jg) {
        this.jg = jg;
    }

    public String getZz() {
        return zz;
    }

    public void setZz(String zz) {
        this.zz = zz;
    }

    @Override
    public String toString() {
        return "名称：" + name +
                "\t价格：" + jg +
                "\t作者：" + zz
                + "\n";
    }
}
