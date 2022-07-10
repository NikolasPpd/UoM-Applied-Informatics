import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class FindSuspectGUI extends JFrame {
    private JPanel panel;
    private JLabel infoLabel;
    private JTextField nameField;
    private JButton findButton;
    private Registry registry;

    private FindSuspectGUI gui;

    //public SuspectPageGUI susInfoGUI = new SuspectPageGUI();

    public FindSuspectGUI(Registry registry) {
        // Set the title of the window
        super("Find Suspect");
        // Reference to this window to access it from the other window later
        gui = this;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(305, 130);
        setLocationRelativeTo(null);
        setResizable(false);

        this.registry = registry;

        panel = new JPanel();
        panel.setLayout(null);

        infoLabel = new JLabel("Suspect Name:");
        infoLabel.setBounds(10, 10, 100, 25);
        panel.add(infoLabel);

        nameField = new JTextField(20);
        nameField.setBounds(120, 10, 160, 25);
        panel.add(nameField);

        findButton = new JButton("Find");
        findButton.setBounds(10, 50, 270, 25);
        panel.add(findButton);

        ButtonListener listener = new ButtonListener();
        findButton.addActionListener(listener);

        this.setContentPane(panel);
        this.setVisible(true);
    }

    class ButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = nameField.getText();
            if (name.equals("")) {
                JOptionPane.showMessageDialog(null, "Please enter a suspect name.");
            } else {
                Suspect tempSuspect = registry.findSuspect(name);
                if (tempSuspect == null) {
                    JOptionPane.showMessageDialog(null, "Suspect " + name + " not found!");
                }
                else {
                    //JOptionPane.showMessageDialog(null, "Suspect " + name + " found!");
                    setVisible(false);
                    new SuspectPageGUI(gui, registry, tempSuspect).setVisible(true);
                    //susInfoGUI.setVisible(true);
                }
            }
        }
    }
}
