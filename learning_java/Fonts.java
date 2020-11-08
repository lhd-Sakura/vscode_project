import java.awt.*;

import javax.swing.*;

public class Fonts extends JFrame{


    public Fonts()
    {
        super("设置字体");
        setSize(420,125);
        setVisible(true);
        //

    }

    public void paint(Graphics g){
        super.paint(g);
        g.setFont(new Font("楷体",Font.BOLD,20));
        g.drawString("楷体 12 bold.",50,100);
        
    }

    public static void main(String[] args) {
        Fonts application = new Fonts();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
}