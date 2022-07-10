public class Communication {
    private String phoneNumber1;
    private String phoneNumber2;
    private int day;
    private int month;
    private int year;

    // Constructor
    public Communication(String phoneNumber1, String phoneNumber2, int day, int month, int year) {
        this.phoneNumber1 = phoneNumber1;
        this.phoneNumber2 = phoneNumber2;
        this.day = day;
        this.month = month;
        this.year = year;
    }

    // Getters
    public String getPhoneNumber1() {
        return phoneNumber1;
    }
    public String getPhoneNumber2() {
        return phoneNumber2;
    }
    public int getDay() {
        return day;
    }
    public int getMonth() {
        return month;
    }
    public int getYear() {
        return year;
    }

    // Setters
    public void setPhoneNumber1(String phoneNumber1) {
        this.phoneNumber1 = phoneNumber1;
    }
    public void setPhoneNumber2(String phoneNumber2) {
        this.phoneNumber2 = phoneNumber2;
    }
    public void setDay(int day) {
        this.day = day;
    }
    public void setMonth(int month) {
        this.month = month;
    }
    public void setYear(int year) {
        this.year = year;
    }

    // Methods
    // Print the phone numbers and date of the communication
    public void printInfo() {
        System.out.println("Between " + phoneNumber1 + " --- " + phoneNumber2);
        System.out.println("on " + year + "/" + month + "/" + day);
    }
}
