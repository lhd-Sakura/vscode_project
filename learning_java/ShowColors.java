import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

public class ShowColors extends JFrame {


    public ShowColors() {
        super("颜色的使用");
        setSize(400,130);
        setVisible(true);
    }
    

    public void paint(Graphics g)
    {
        super.paint(g);
        g.setColor(new Color(255,0,0));
        //g.fillRect(x, y, width, height);
        g.fillRect(25, 50, 100, 20);
        g.drawString("Current RGB:"+g.getColor(), 130, 60);

        g.setColor(new Color(0.0f,1.0f,0.0f));
        g.fillRect(25, 75, 100, 20);
        g.drawString("Current RGB:"+g.getColor(), 130, 85);

        g.setColor(Color.blue);
        g.fillRect(25, 100, 100, 20);
        g.drawString("Current RGB:"+g.getColor(), 130, 110);

    }


    public static void main(String[] args) {
        ShowColors application = new ShowColors();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }

}

