package javacode;

public class Test {
    // 实例变量
    int y;
    // 类变量
    static int z = 30;
    static final double PI = 3.1415926;
    public static void main(String[] args) {
        /*
         * 类型转换
         */
        // 精度损失
        System.out.println((int) 3.14); // 3
        System.out.println((int) -45.89f); // -45
        // 内存溢出
        int a = 128;
        byte b = (byte) a; // 128
        System.out.println(b); // -128
        /*
         * 
         */
        char c = 'a';
        int d = c+1;
        System.out.println(d); // 98
        System.out.println((char) (d)); // b
        /*
         * 操作比较大的数的时候，注意溢出问题
         */
        // JDK7新特性，数字可以用下划线分隔
        int money = 10_0000_0000;
        System.out.println(money); // 100000000
        int years = 20;
        int total = money * years;
        System.out.println(total); // -1474836480
        long total2 = money * years; // 默认是int，转换之前就计算好溢出了
        System.out.println(total2); // -1474836480
        // 解决方法，先把一个int转换为long，然后乘以另一个int，这样就不会溢出
        long total3 = (long) money * years;
        System.out.println(total3); // 2000000000
        /*
         * 变量类型
         */
        // 局部变量
        int x = 10;
        System.out.println(x); // 10
        // 实例变量
        // 从属于对象,不自行初始化,值为默认值,int类型默认值为0,布尔值默认值为false,引用类型默认值为null
        Test t = new Test();
        t.y = 20; 
        // 类变量
        System.out.println(z); // 30
        /*
         * 运算符
         */
        // a++是先赋值给了b再a自增1，所以b只是3，而++a是先自增再赋值给c，所以c是变成了5
        int a1 = 3;
        int b1 = a1++;
        int c1= ++a1;
        System.out.println(b1); // 3
        System.out.println(c1); // 5
        System.out.println(a1); // 5
        /*
         * 幂运算
         */
        double pow = Math.pow(2,3);
        System.out.println(pow); // 8.0
        /*
         * 位运算
         */
        int A = 60; // 60 = 0011 1100
        int B = 13; // 13 = 0000 1101
        int C = A & B; // 12 = 0000 1100 与运算
        int D = A | B; // 61 = 0011 1101 或运算
        int E = A ^ B; // 49 = 0011 0001 异或运算
        int F = ~A; // -61 = 1100 0011 取反
        int G = A << 2; // 240 = 1111 0000 左移运算 *2
        int H = A >> 2; // 15 = 0000 1111 右移运算 /2
        System.out.println(C); // 12
        System.out.println(D); // 61
        System.out.println(E); // 49
        System.out.println(F); // -61
        System.out.println(G); // 240
        System.out.println(H); // 15
        // 
        int a2 = 10;
        int b2 = 20;
        a2+=b2; // a = a + b
        System.out.println(a2); // 30
        a-=b; // a = a - b
        // 字符串连接符
        String str1 = "hello";
        int str2 = 123;
        String str3 = str1 + " " + str2;
        System.out.println(str3); // hello 123
        int a3 = 10;
        int b3 = 20;
        System.out.println(""+a3+b3); // 1020
        System.out.println(a3+b3+""); // 30
        // 条件运算符
        int x1 = 10;
        int y1 = 20;
        int z1 = (x1 > y1)? x1 : y1;
        System.out.println(z1); // 20
    }
}
