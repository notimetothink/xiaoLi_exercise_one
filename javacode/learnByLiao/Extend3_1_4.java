package javacode.learnByLiao;
// 继承
public class Extend3_1_4 {
    public static void main(String[] args) {
        Student student = new Student("lhc", 14, 100);
        System.out.println(student.hello());
        // 向上转型
        // 把一个子类类型安全地变为父类类型的赋值
        Person p = new Student("Xiao Ming", 15, 95);
        System.out.println(p.name);
    }
}
class Student extends Person {
    protected int score;
    public Student(String name, int age, int score) {
        // 如果父类没有默认的构造方法，子类就必须显式调用super()并给出参数以便让编译器定位到父类的一个合适的构造方法。
        // 即子类不会继承任何父类的构造方法。子类默认的构造方法是编译器自动生成的，不是继承的。
        super(name, age); // 调用父类的构造方法Person(String, int)
        this.score = score;
    }
    public String hello() {
        return "Hello, " + name; // OK!
    }
}
