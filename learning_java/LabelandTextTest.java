import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class LabelandTextTest extends JFrame {
    private JTextField textField1,textField2,textField3;
    private JTextArea textArea1,textArea2; 
    private JPasswordField passwordField;
    private JButton copyButton;

    public LabelandTextTest()
    {
        super("JTextField,JPasswordField 和 JTextArea的使用");
        Container container = getContentPane();
        container.setLayout(new FlowLayout());

        JLabel label1 = new JLabel("用户名：");
        container.add(label1);

        textField1 = new JTextField(10);
        container.add(textField1);
        container.add(new JLabel("口令："));
        passwordField = new JPasswordField(10);
        container.add(passwordField);
        Icon bug = new ImageIcon("C:/Users/Administrator/Desktop/表情包/2.jpg");
        JLabel label2 = new JLabel("照片：",bug,SwingConstants.LEFT);

        //设置label的文本相对于图片的位置：水平方向居中对齐，垂直方向在图片的底部
        label2.setHorizontalTextPosition(SwingConstants.LEFT);
        label2.setVerticalTextPosition(SwingConstants.BOTTOM);
        container.add(label2);

        setSize(500,400);
        setVisible(true);
        setLocation(100,100);

    }


    public static void main(String[] args) {
        LabelandTextTest application = new LabelandTextTest();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }



    
}