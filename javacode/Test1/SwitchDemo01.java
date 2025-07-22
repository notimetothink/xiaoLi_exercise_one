package javacode.Test1;

public class SwitchDemo01 {
    // switch语句，匹配一个具体的值
    // case穿透 ，如果case没有break，会继续执行下一个case
    public static void main(String[] args) {
        char grade = 'C';
        switch (grade) {
            case 'A':
                System.out.println("优秀");
                break;
            case 'B':
                System.out.println("良好");
                break;
            case 'C':
                System.out.println("及格");
                break;
            case 'D':
                System.out.println("不及格");
                break;
            default:
                System.out.println("差");
                break;
        }
        // while循环
        int i = 0;
        while (i < 10) {
            System.out.println("i = " + i);
            i++;
        }
        // do while循环
        int j = 0;
        do {
            System.out.println("j = " + j);
            j++;

        }while (j < 0);
        // for循环
        for (int k = 0; k < 10; k++) {
            System.out.println("k = " + k);
        }
        // 增强for循环
        int[] arr = {1, 2, 3, 4, 5};
        for (int num : arr) {
            System.out.println("num = " + num);
        }
    }

    public static void printMax(double... nums) {
        if (nums.length == 0) {
            System.out.println("No argument passed");
            return;
        }
        double max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        System.out.println("The max value is " + max);
    }
    // 递归
    // 阶乘
    public static int factorial(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}
