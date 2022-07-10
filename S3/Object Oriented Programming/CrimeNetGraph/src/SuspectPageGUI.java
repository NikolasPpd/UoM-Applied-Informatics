import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.*;

public class SuspectPageGUI extends JFrame {
    private JPanel mainPanel;

    private JPanel suspectPanel;
    private JTextField nameField;
    private JTextField codeNameField;
    private JScrollPane phoneNumbersScrollPane;
    private JTextArea phoneNumbersTextArea;

    private JPanel SMSPanel;
    private JTextField phoneNumberField;
    private JScrollPane SMSScrollPane;
    private JTextArea SMSTextArea;
    private JButton findSMSButton;

    private JPanel partnersPanel;
    private JLabel partnersTitle;
    private JScrollPane partnersScrollPane;
    private JTextArea partnersTextArea;

    private JPanel suggestedPartnersPanel;
    private JLabel suggestedPartnersTitle;
    private JScrollPane suggestedPartnersScrollPane;
    private JTextArea suggestedPartnersTextArea;

    private JPanel returnPanel;
    private JButton returnButton;

    public SuspectPageGUI(FindSuspectGUI homeScreen, Registry registry, Suspect suspect) {
        setTitle("Suspect Page");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(700, 650);
        setLocationRelativeTo(null);
        setResizable(false);

        mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Create suspect panel
        suspectPanel = new JPanel();
        suspectPanel.setBorder(BorderFactory.createTitledBorder("Suspect Info"));
        // Create components for suspect panel
        nameField = new JTextField(suspect.getName(), 16);
        codeNameField = new JTextField(suspect.getCodeName(), 16);
        phoneNumbersTextArea = new JTextArea();
        phoneNumbersScrollPane = new JScrollPane(phoneNumbersTextArea);
        phoneNumbersScrollPane.setPreferredSize(new Dimension(200, 100));
        phoneNumbersTextArea.setEditable(false);
        phoneNumbersTextArea.setLineWrap(true);
        phoneNumbersTextArea.setWrapStyleWord(true);
        // Add components to suspect panel
        suspectPanel.add(nameField);
        suspectPanel.add(codeNameField);
        suspectPanel.add(phoneNumbersScrollPane);

        // Create SMS panel
        SMSPanel = new JPanel();
        SMSPanel.setBorder(BorderFactory.createTitledBorder("Suspect SMS"));
        // Create components for SMS panel
        phoneNumberField = new JTextField("", 16);
        SMSTextArea = new JTextArea("");
        SMSScrollPane = new JScrollPane(SMSTextArea);
        SMSScrollPane.setPreferredSize(new Dimension(300, 100));
        SMSTextArea.setEditable(false);
        SMSTextArea.setLineWrap(true);
        SMSTextArea.setWrapStyleWord(true);
        findSMSButton = new JButton("Find SMS");
        findSMSButton.setSize(200, 30);
        // Add components to SMS panel
        SMSPanel.add(phoneNumberField);
        SMSPanel.add(SMSScrollPane);
        SMSPanel.add(findSMSButton);

        // Create partners panel
        partnersPanel = new JPanel();
        partnersPanel.setBorder(BorderFactory.createTitledBorder("Partners"));
        // Create components for partners panel
        partnersTitle = new JLabel("");
        partnersTextArea = new JTextArea("");
        partnersScrollPane = new JScrollPane(partnersTextArea);
        partnersScrollPane.setPreferredSize(new Dimension(200, 100));
        partnersTextArea.setEditable(false);
        partnersTextArea.setLineWrap(true);
        partnersTextArea.setWrapStyleWord(true);
        // Add components to partners panel
        partnersPanel.add(partnersTitle);
        partnersPanel.add(partnersScrollPane);

        // Create suggested partners panel
        suggestedPartnersPanel = new JPanel();
        suggestedPartnersPanel.setBorder(BorderFactory.createTitledBorder("Suggested Partners"));
        // Create components for suggested partners panel
        suggestedPartnersTitle = new JLabel("");
        suggestedPartnersTextArea = new JTextArea("");
        suggestedPartnersScrollPane = new JScrollPane(suggestedPartnersTextArea);
        suggestedPartnersScrollPane.setPreferredSize(new Dimension(200, 100));
        suggestedPartnersTextArea.setEditable(false);
        suggestedPartnersTextArea.setLineWrap(true);
        suggestedPartnersTextArea.setWrapStyleWord(true);
        // Add components to suggested partners panel
        suggestedPartnersPanel.add(suggestedPartnersTitle);
        suggestedPartnersPanel.add(suggestedPartnersScrollPane);

        // Create return panel
        returnPanel = new JPanel();
        // Create return button
        returnButton = new JButton("Back to Search Screen");
        // Add return button to return panel
        returnPanel.add(returnButton);

        // Add panels to main panel
        mainPanel.add(suspectPanel);
        mainPanel.add(SMSPanel);
        mainPanel.add(partnersPanel);
        mainPanel.add(suggestedPartnersPanel);
        mainPanel.add(returnPanel);

        // Populate text areas
        // Populate phone numbers text area
        for (String phoneNumber : suspect.getPhoneNumbers()) {
            phoneNumbersTextArea.append(phoneNumber + "\n");
        }
        // Populate partners text area
        // Create temp ArrayList to hold partners and sort them alphabetically
        ArrayList<Suspect> tempPartners = new ArrayList<>(suspect.getPartners());
        Collections.sort(tempPartners);
        for (Suspect partner : suspect.getPartners()) {
            partnersTextArea.append(partner.getName() + ", " + partner.getCodeName() + "\n");
        }
        // Clear the temp ArrayList
        tempPartners.clear();
        // Populate suggested partners text area
        tempPartners = new ArrayList<>(suspect.getSuggestedSuspects());
        Collections.sort(tempPartners);
        for (Suspect partner : tempPartners) {
            suggestedPartnersTextArea.append(partner.getName() + ", " + partner.getCodeName() + "\n");
        }

        // Add action listeners to buttons
        findSMSButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String searchPhoneNumber = phoneNumberField.getText();

                // Clear text area
                SMSTextArea.setText("");

                // Loop through current suspect's phone numbers
                for (String phoneNumber : suspect.getPhoneNumbers()) {
                    for (SMS sms : registry.getMessagesBetween(phoneNumber, searchPhoneNumber)) {
                        // Append SMS to text area
                        SMSTextArea.append(sms.getMessage() + "\n");
                    }
                }
            }
        });

        returnButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
                homeScreen.setVisible(true);
            }
        });

        // Add main panel to content pane
        Container contentPane = getContentPane();
        contentPane.add(mainPanel);
    }
}
