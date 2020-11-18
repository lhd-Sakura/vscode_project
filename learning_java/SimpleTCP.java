import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleTCP extends JFrame {
    private JTextField sourceField, destinationField;
    private JTextArea textArea1;
    private JButton sendButton, confirmButton;

    public SimpleTCP() {
        super("TCP/IP");
        Container container = getContentPane();
        container.setLayout(new FlowLayout());

        Box sbox = Box.createVerticalBox();

        Box box1 = Box.createHorizontalBox();

        box1.add(new JLabel("ԴIP��ַ"));
        sourceField = new JTextField(10);
        box1.add(sourceField);

        box1.add(new JLabel("Ŀ��IP��ַ"));
        destinationField = new JTextField(10);
        box1.add(destinationField);

        confirmButton = new JButton("ȷ��");
        box1.add(confirmButton);
        ButtonHandler handler = new ButtonHandler();
        confirmButton.addActionListener(handler);

        sbox.add(box1);

        Box box2 = Box.createHorizontalBox();

        textArea1 = new JTextArea(10, 20);
        box2.add(new JScrollPane(textArea1));
        sendButton = new JButton("����");
        box2.add(sendButton);

        sbox.add(box2);

        container.add(sbox);
        setSize(500, 300);
        setVisible(true);
        setLocation(100, 100);

    }

    public static void main(String[] args) {
        SimpleTCP application = new SimpleTCP();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    private class ButtonHandler implements ActionListener {
        public void actionPerformed(ActionEvent event) {
            String source = "";
            String destination = "";

            source = sourceField.getText();
            System.out.println("ԴIP��ַ��" + source);

            destination = destinationField.getText();
            System.out.println("Ŀ��IP��ַ��" + destination);

        }
    }
}