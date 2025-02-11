package javacode.scanner;
import java.util.Scanner;

public class Demo01 {
    public static void main(String[] args) {
        // // 创建一个扫描器对象,用于获取键盘录入的数据
        // Scanner scanner = new Scanner(System.in);

        // System.out.println("使用next方式接收：");
        // // 判断用户是否还有输入的数据
        // if (scanner.hasNext()) {
        //     // 使用next方式接收，得不到空格
        //     String str = scanner.next();
        //     System.out.println("输入的是：" + str);
        // }
        // // 关闭扫描器
        // scanner.close();
        /*------------------------------------------------------------------------------------ */
        // Scanner scanner1 = new Scanner(System.in);

        // System.out.println("使用nextLine方式接收：");
        // // 判断用户是否还有输入的数据
        // if (scanner1.hasNextLine()) {
        //     // 使用nextLine方式接收，接收一行数据，可以接收空格
        //     String str1 = scanner1.nextLine();
        //     System.out.println("输入的是：" + str1);
        // }
        // scanner1.close();
        /*-------------------------------------------------------------------------------------- */
        int i = 0;
        float f = 0.0f;
        Scanner scanner2 = new Scanner(System.in);
        System.out.println("请输入整数：");
        if (scanner2.hasNextInt()) {
            i = scanner2.nextInt();
            System.out.println("整数数据是：" + i);
        }else {
            System.out.println("输入的不是整数！");
        }

        System.out.println("请输入小数：");
        if (scanner2.hasNextFloat()) {
            f = scanner2.nextFloat();
            System.out.println("小数数据是：" + f);
        }else {
            System.out.println("输入的不是小数！");
        }
        scanner2.close();
    }
}
