public class SMS extends Communication {
    private String message;

    // Constructor
    public SMS(String phoneNumber1, String phoneNumber2, int day, int month, int year, String message) {
        super(phoneNumber1, phoneNumber2, day, month, year);
        this.message = message;
    }

    // Getter
    public String getMessage() {
        return message;
    }

    // Methods
    // Print the SMS' info
    public void printInfo() {
        System.out.println("This SMS has the following info");
        super.printInfo();
        System.out.println("Text: " + message);
    }
}
