import java.util.Scanner;

public class Addition {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        //声明三个整型变量
        int firstNumber;
        int secondNumber;
        int sum;
         System.out.println("输入第一个数");
         firstNumber = input.nextInt();
         System.out.println("输入第二个数");
         secondNumber = input.nextInt();

        sum = firstNumber + secondNumber;
        System.out.println("相加后的结果为：");
        System.out.println(sum);
    }
    
}