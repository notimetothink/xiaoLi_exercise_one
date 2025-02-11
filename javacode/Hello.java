package javacode;

public class Hello {
    public static void main(String[] args) {
        // 基础一到基础五
        // 单行注释
        /**
         * 多行注释
         * 第二行
         */
        // 标识符命名规则：首字符必须是字母或下划线，后续字符可以是字母、数字、下划线
        String teacher = "teacher";
        String Teacher = "teacher";
        String $teacher = "teacher";
        String _teacher = "teacher";
        System.out.print(teacher + Teacher + $teacher + _teacher);
        /*
         * 数据类型
         */
        // 整型
        int age = 25;
        byte b = 127;
        short s = 32767;
        long l = 9223372036854775807L;
        // 浮点型
        float f = 3.14f;
        double d = 3.14159265358979323846;
        // 字符型
        char c = 'A';
        // 布尔型
        boolean flag = true;
        // 字符串型,String不是关键字，是类
        String str = "Hello, world!";
        // 数组
        int[] arr = {1, 2, 3, 4, 5};
        // 引用类型
        // Person person = new Person();
        // person.name = "Tom";
        // person.age = 25;
        /*
         * 整数进制
         */
        // 二进制0b开头
        int binary = 0b1010;
        // 八进制0开头
        int octal = 010;
        // 十六进制0x开头
        int hexadecimal = 0x10;
        System.out.println(binary + " " + octal + " " + hexadecimal);
        /*
         * 浮点数精度
         */
        // float 有限 离散 舍入误差 大约 接近但不等于
        // 最好完全避免使用浮点数进行比较
        // 最好使用BigDecimal类
        /*
         * 字符强转
         */
        // 所有字符本质还是数字
        char a = 'a';
        System.out.println(a);
        System.out.println((int) a); // 97
        char b1 = '中';
        System.out.println(b1);
        System.out.println((int) b1); // 20013
        // Unicode编码
        char c1 = '\u0061';
        System.out.println(c1); // a
        char c2 = '\u4e2d';
        System.out.println(c2); // 中
        /*
         * 转义字符
         */
        // \n 换行
        // \t 制表符
        System.out.println("Hello, world!\n"); // Hello, world!
        System.out.println("Hello\tworld!"); // Hello    world!
        /*
         * 字符串比较
         */
        String sa = new String("Hello, world!");
        String sb = new String("Hello, world!");
        System.out.println(sa == sb); // false
        String sc = "Hello, world!";
        System.out.println(sa == sc); // true
    }
}
