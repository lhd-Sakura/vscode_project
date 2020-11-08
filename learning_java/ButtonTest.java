import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ButtonTest extends JFrame{
    private JButton plainButton, fancyButton;
    public ButtonTest()
    {
        super("JButton的程序设计");

        Container container = getContentPane();
        container.setLayout(new FlowLayout());

        //创建button
        plainButton = new JButton("文本按钮");
        container.add(plainButton);
        //Icon窗口图标
        // Icon bug1 = new ImageIcon(getClass().getResource("1.jpg"));
        // Icon bug2 = new ImageIcon(getClass().getResource("2.jpg"));
        Icon bug1 = new ImageIcon("C:/Users/Administrator/Desktop/表情包/1.jpg");
        Icon bug2 = new ImageIcon("C:/Users/Administrator/Desktop/表情包/2.jpg");

        //设置默认图标
        fancyButton = new JButton("文本图像按钮",bug1);
        //当鼠标置于该按钮上是，显示bug2
        fancyButton.setRolloverIcon(bug2);
        container.add(fancyButton);

        ButtonHandler handler = new ButtonHandler();
        fancyButton.addActionListener(handler);
        plainButton.addActionListener(handler);


        setSize(800,800);
        setVisible(true);
        setLocation(300,100);
    }
    


    public static void main(String[] args) {
        ButtonTest application = new ButtonTest(); 
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private class ButtonHandler implements ActionListener {
        public void actionPerformed(ActionEvent event)
        {
            JOptionPane.showMessageDialog(ButtonTest.this, "你按下的是："+event.getActionCommand());
        }
        
    }



}
