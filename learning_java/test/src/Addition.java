import java.util.Scanner;

public class Addition {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        //�����������ͱ���
        int firstNumber;
        int secondNumber;
        int sum;
         System.out.println("�����һ����");
         firstNumber = input.nextInt();
         System.out.println("����ڶ�����");
         secondNumber = input.nextInt();

        sum = firstNumber + secondNumber;
        System.out.println("��Ӻ�Ľ��Ϊ��");
        System.out.println(sum);
    }
    
}