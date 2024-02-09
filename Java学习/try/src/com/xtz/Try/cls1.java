package com.xtz.Try;
public class cls1 {
    private String name;
    private String msgtitle;
    private String msg;
    private String time;

    public cls1(String name, String msgtitle, String msg, String time) {
        this.name = name;
        this.msgtitle = msgtitle;
        this.msg = msg;
        this.time = time;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMsgtitle() {
        return msgtitle;
    }

    public void setMsgtitle(String msgtitle) {
        this.msgtitle = msgtitle;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }
}