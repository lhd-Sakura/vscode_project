import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TCPIP extends JFrame implements MouseListener,MouseMotionListener {
    private JTextField textField1;
    private JTextArea textArea1;
    private JButton sendButton;
    private JLabel lable1;


    public TCPIP(){

        super("TCP/IPͨѶ");
        //���ò���
        Container container = getContentPane();
        container.setLayout(null);

        //����button
        sendButton = new JButton("����");
        container.add(sendButton);
        sendButton.setBounds(630,400,100,50);
        sendButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event){
                //add action here
            }
        });

        //���öԻ�����
        textArea1 = new JTextArea();
        container.add(new JScrollPane(textArea1));
        textArea1.setBounds(100,300,5,12);
        textArea1.setBackground(Color.BLACK);
        
        setSize(800, 600);
        setLocation(100,100);;
        setVisible(true);
        

        textField1 = new JTextField(10);
        container.add(textField1);
        textField1.setBounds(500,100,10,10);


        lable1 = new JLabel();
        addMouseListener(this);
        addMouseMotionListener(this);
        //���λ�ò���
        container.add(lable1);
        lable1.setBounds(0,0,100,50);
        

    }



    public static void main(String[] args) {
        TCPIP application = new TCPIP();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    
    public void mouseClicked(MouseEvent event){
        lable1.setText("�����"+event.getX()+","+event.getY());

    }

    public void mouseExited(MouseEvent event){
        lable1.setText("����Ƴ�");
    }

    public void mouseEntered(MouseEvent event){
        lable1.setText("���λ��"+event.getX()+","+event.getY());
    }

    public void mouseReleased(MouseEvent event){
        lable1.setText("����ͷ�"+event.getX()+","+event.getY());
    }

    public void mousePressed(MouseEvent event){
        lable1.setText("��갴��"+event.getX()+","+event.getY());
    }

    public void mouseMoved(MouseEvent event){
        lable1.setText("����ƶ�"+event.getX()+","+event.getY());
    }

    public void mouseDragged(MouseEvent event){
        lable1.setText("����϶�"+event.getX()+","+event.getY());
    }


}