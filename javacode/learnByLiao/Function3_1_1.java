package javacode.learnByLiao;

import java.util.Arrays;
// 方法
public class Function3_1_1 {
    public static void main(String[] args) {
        // private field测试
        Person ming = new Person("lhc", 18);
        ming.setName("Xiao Ming"); // 设置name
        ming.setAge(12); // 设置age
        System.out.println(ming.getName() + ", " + ming.getAge());
        // 可变参数测试
        Group group = new Group();
        group.setNames("Xiao Ming");
        System.out.println(Arrays.toString(group.getNames()));
        group.setNames("Xiao Ming", "xiaohong");
        System.out.println(Arrays.toString(group.getNames()));
    }
}
// 可变参数测试
class Group {
    private String[] names;

    public void setNames(String... names) {
        this.names = names;
    }
    public String[] getNames() {
        return names;
    }
}
// private field测试
class Person {
    private String name1 = null;
    // 用protected修饰的字段可以被子类访问
    protected String name;
    protected int age;
    // 构造函数
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return this.age;
    }
    public void setAge(int age) {
        if (age < 0 || age > 100) {
            throw new IllegalArgumentException("invalid age value");
        }
        this.age = age;
    }
}
