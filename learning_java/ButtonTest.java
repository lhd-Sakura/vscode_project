import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ButtonTest extends JFrame{
    private JButton plainButton, fancyButton;
    public ButtonTest()
    {
        super("JButton�ĳ������");

        Container container = getContentPane();
        container.setLayout(new FlowLayout());

        //����button
        plainButton = new JButton("�ı���ť");
        container.add(plainButton);
        //Icon����ͼ��
        // Icon bug1 = new ImageIcon(getClass().getResource("1.jpg"));
        // Icon bug2 = new ImageIcon(getClass().getResource("2.jpg"));
        Icon bug1 = new ImageIcon("C:/Users/Administrator/Desktop/�����/1.jpg");
        Icon bug2 = new ImageIcon("C:/Users/Administrator/Desktop/�����/2.jpg");

        //����Ĭ��ͼ��
        fancyButton = new JButton("�ı�ͼ��ť",bug1);
        //��������ڸð�ť���ǣ���ʾbug2
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
            JOptionPane.showMessageDialog(ButtonTest.this, "�㰴�µ��ǣ�"+event.getActionCommand());
        }
        
    }



}
