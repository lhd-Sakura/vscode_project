import javax.swing.*;

import javafx.scene.input.MouseEvent;

import java.awt.*;
import java.awt.event.*;

public class MouseTracker extends JFrame implements MouseListener,MouseMotionListener {
    private JLable statusBar;

    public MouseTracker(){
        super(" Û±Í“∆∂Ø");
        statusBar = new JLabel("",SwingConstants.CENTER);
        getContentPane().add(statusBar,BorderLayout.SOUTH);
        addMouseListener(this);
        addMouseMotionListener(this);
        setSize(275,100);
        setVisible(true);
    }


    public void mouseClicked(MouseEvent event){


    }


    


}