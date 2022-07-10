import java.util.ArrayList;

public class Suspect implements Comparable<Suspect> {
    private String name;
    private String codeName;
    private String city;
    private final ArrayList<String> phoneNumbers = new ArrayList<>();
    private final ArrayList<Suspect> partners = new ArrayList<>();

    // Constructor
    public Suspect(String name, String codeName, String city) {
        this.name = name;
        this.codeName = codeName;
        this.city = city;
    }

    // Getters
    public String getName() {
        return this.name;
    }
    public String getCodeName() {
        return this.codeName;
    }
    public String getCity() {
        return this.city;
    }
    public ArrayList<String> getPhoneNumbers() {
        return this.phoneNumbers;
    }
    public ArrayList<Suspect> getPartners() {
        return this.partners;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }
    public void setCodeName(String codeName) {
        this.codeName = codeName;
    }
    public void setCity(String city) {
        this.city = city;
    }

    // Methods
    // Add a phone number to the current suspect's phone numbers list
    public void addNumber(String number) {
        this.phoneNumbers.add(number);
    }

    // Remove a phone number from the current suspect's phone numbers list
    public void removeNumber(String number) {
        this.phoneNumbers.remove(number);
    }

    // Add a suspect to the current suspect's partners list
    public void addSuspect(Suspect suspect) {
        if (!this.partners.contains(suspect)) {
            this.partners.add(suspect);
        }
    }

    // Remove a suspect from the current suspect's partners list
    public void removeSuspect(Suspect suspect) {
        this.partners.remove(suspect);
    }

    // Check if the current suspect is connected to the suspect passed as parameter
    public boolean isConnectedTo(Suspect aSuspect) {
        return this.partners.contains(aSuspect);
    }

    // Get common partners between the current suspect and the suspect passed as parameter
    public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
        ArrayList<Suspect> commonPartners = new ArrayList<>();
        for (Suspect partner : this.partners) {
            if (aSuspect.isConnectedTo(partner)) {
                commonPartners.add(partner);
            }
        }
        return commonPartners;
    }

    // Print partners' names and code names
    public void printPartners() {
        System.out.println("Partners:");
        for (Suspect partner : this.partners) {
            System.out.println(partner.getName() + " (" + partner.getCodeName() + ")");
        }
    }

    // Return a list of suggested suspects
    public ArrayList<Suspect> getSuggestedSuspects() {
        ArrayList<Suspect> suggestedSuspects = new ArrayList<>();
        // Loop through current suspect's partners
        for (Suspect partner : this.partners) {
            // Loop through partner's partners
            for (Suspect partnerPartner : partner.getPartners()) {
                // If partner's partner is not the current suspect, isn't the current suspect's partner already
                // and is not yet in the list of suggested suspects, then add them to the list
                if (partnerPartner != this && !partners.contains(partnerPartner) && !suggestedSuspects.contains(partnerPartner)) {
                    suggestedSuspects.add(partnerPartner);
                }
            }
        }
        return suggestedSuspects;
    }

    // Override compareTo method
    @Override
    public int compareTo(Suspect aSuspect) {
        return this.name.compareTo(aSuspect.getName());
    }
}