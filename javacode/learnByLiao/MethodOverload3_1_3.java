package javacode.learnByLiao;
// 方法重载
public class MethodOverload3_1_3 {
    public static void main(String[] args) {
        String s = "Test string";
        int n1 = s.indexOf('t'); // 根据字符的Unicode码查找
        int n2 = s.indexOf("st"); // 根据字符串查找
        int n3 = s.indexOf("st", 4);  // 根据字符串查找，但指定起始位置
        System.out.println(n1);
        System.out.println(n2);
        System.out.println(n3);
    }
}
