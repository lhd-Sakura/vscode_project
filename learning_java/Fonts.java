import java.awt.*;

import javax.swing.*;

public class Fonts extends JFrame{


    public Fonts()
    {
        super("��������");
        setSize(420,125);
        setVisible(true);
        //

    }

    public void paint(Graphics g){
        super.paint(g);
        g.setFont(new Font("����",Font.BOLD,20));
        g.drawString("���� 12 bold.",50,100);
        
    }

    public static void main(String[] args) {
        Fonts application = new Fonts();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
}