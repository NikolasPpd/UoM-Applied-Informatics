public class PhoneCall extends Communication {
    private int duration;

    // Constructor
    public PhoneCall(String phoneNumber1, String phoneNumber2, int day, int month, int year, int duration) {
        super(phoneNumber1, phoneNumber2, day, month, year);
        this.duration = duration;
    }

    // Getters
    public int getDuration() {
        return duration;
    }

    // Methods
    // Print the phone call's info
    public void printInfo() {
        System.out.println("This phone call has the following info");
        super.printInfo();
        System.out.println("Duration: " + duration);
    }
}
