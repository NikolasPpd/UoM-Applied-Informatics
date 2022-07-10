import java.util.ArrayList;

public class Registry {
    private final ArrayList<Communication> communications;
    private final ArrayList<Suspect> suspects;

    // Constructor
    public Registry() {
        this.communications = new ArrayList<>();
        this.suspects = new ArrayList<>();
    }

    // Methods
    // Add suspect to the suspects list
    public void addSuspect(Suspect aSuspect) {
        this.suspects.add(aSuspect);
    }

    // Add communication to the communications list
    public void addCommunication(Communication aCommunication) {
        this.communications.add(aCommunication);
        Suspect tempSuspect1 = null;
        Suspect tempSuspect2 = null;
        // Search for the suspects with the phone number 1 and 2
        for (Suspect s : suspects) {
            // Look through every phone number of each suspect
            for (String phoneNumber : s.getPhoneNumbers()) {
                // If current suspect has the phone number 1
                if (phoneNumber.equals(aCommunication.getPhoneNumber1())) {
                    tempSuspect1 = s;
                }
                // Else if current suspect has the phone number 2
                else if (phoneNumber.equals(aCommunication.getPhoneNumber2())) {
                    tempSuspect2 = s;
                }
                // If both phone numbers are found break the loop
                if (tempSuspect1 != null && tempSuspect2 != null) {
                    break;
                }
            }
        }
        // Update the suspects' partners list
        if (tempSuspect1 != null && tempSuspect2 != null) {
            tempSuspect1.addSuspect(tempSuspect2);
            tempSuspect2.addSuspect(tempSuspect1);
        }
    }

    // Get suspect with most partners
    // In case of a tie, return the first suspect
    public Suspect getSuspectWithMostPartners() {
        int max = 0;
        Suspect suspect = null;
        // Loop through each suspect
        for (Suspect s : suspects) {
            // If current suspect has more partners than the current max
            if (s.getPartners().size() > max) {
                // Update max and suspect
                max = s.getPartners().size();
                suspect = s;
            }
        }
        return suspect;
    }

    // Get the longest phone call between two numbers
    public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
        PhoneCall longest = null;
        // Loop through each communication
        for (Communication c : communications) {
            // If communication is phone call (using pattern matching)
            if (c instanceof PhoneCall tempCall) {
                // If the phone call is between the two numbers passed as parameters
                if (c.getPhoneNumber1().equals(number1) && c.getPhoneNumber2().equals(number2)
                    || c.getPhoneNumber1().equals(number2) && c.getPhoneNumber2().equals(number1)) {
                    if (longest == null) {
                        longest = tempCall;
                    } else if (tempCall.getDuration() > longest.getDuration()) {
                        longest = tempCall;
                    }
                }
            }
        }
        return longest;
    }

    // Get messages between two numbers
    public ArrayList<SMS> getMessagesBetween(String number1, String number2) {
        ArrayList<SMS> messages = new ArrayList<>();
        // Loop through each communication
        for (Communication c : communications) {
            // If communication is SMS (using pattern matching)
            if (c instanceof SMS tempMessage) {
                // If the message is between the two numbers passed as parameters
                if (c.getPhoneNumber1().equals(number1) && c.getPhoneNumber2().equals(number2)
                    || c.getPhoneNumber1().equals(number2) && c.getPhoneNumber2().equals(number1)) {
                    // If the message contains the words "Bomb", "Attack", "Explosives" or "Gun" add it to the list
                    if (tempMessage.getMessage().contains("Bomb") || tempMessage.getMessage().contains("Attack")
                        || tempMessage.getMessage().contains("Explosives") || tempMessage.getMessage().contains("Gun")) {
                        messages.add(tempMessage);
                    }
                }
            }
        }
        return messages;
    }
}
