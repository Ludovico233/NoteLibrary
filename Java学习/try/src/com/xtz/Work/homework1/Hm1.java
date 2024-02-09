package com.xtz.Work.homework1;

import java.util.ArrayList;
import java.util.Iterator;

public class Hm1 {
    public static void main(String[] args) {
        ArrayList a = new ArrayList();
        a.add(4);
        a.add(3);
        a.add(2);
        a.add(1);
        Iterator i = a.iterator();
        while(i.hasNext()){
            Object o = i.next();
            System.out.println(o);
        }
    }
}
