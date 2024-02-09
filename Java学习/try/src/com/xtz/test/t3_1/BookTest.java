package com.xtz.test.t3_1;

public class BookTest {
    public static void main(String[] args) {
        Book book = new Book("剑指算法", 300);
        System.out.println(book.detail());
        Book book1 = new Book("传习录", 300, "哲学类");
        System.out.println(book1.detail());
    }
}
