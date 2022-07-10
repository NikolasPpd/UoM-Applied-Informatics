import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class FindSuspectGUI extends JFrame {
    private JPanel panel;
    private JLabel infoLabel;
    private JTextField nameField;
    private JButton findButton;
    private JButton visualizeButton;

    private FindSuspectGUI gui;

    public FindSuspectGUI(Registry registry) {
        // Set the title of the window
        super("Find Suspect");
        // Reference to this window (FindSuspectGUI)
        // to access it from the SuspectPageGUI window later
        gui = this;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(305, 160);
        setLocationRelativeTo(null);
        setResizable(false);

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
        
        visualizeButton = new JButton("Visualize Network");
        visualizeButton.setBounds(10, 85, 270, 25);
        panel.add(visualizeButton);
        
        // Adding in-line action listeners to the buttons
        findButton.addActionListener(new ActionListener() {
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
                        setVisible(false);
                        new SuspectPageGUI(gui, registry, tempSuspect).setVisible(true);
                    }
                }
            }
        });
        
        visualizeButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		new NetworkGUI(registry).setVisible(true);
        	}
        });

        this.setContentPane(panel);
        this.setVisible(true);
    }
}
