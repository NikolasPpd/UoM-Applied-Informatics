public class Card {
    public static final int MIN_CARD_VALUE = 2;
    public static final int MAX_CARD_VALUE = 11;
    public static final int CARD_HEIGHT = 6;
    public static final int CARD_WIDTH = 10;
    private int value;
    private boolean isHidden;

    // Constructors
    public Card(Deck deck) {
        this.value = deck.getRandomCardValue(); // Get random card from deck
        this.isHidden = false;  // Default visibility is "Shown"
    }

    // Give specific card value
    public Card(int value) {
        this.value = value; // Create card with custom value
        this.isHidden = false;  // Default visibility is "Shown"
    }

    // Setup card's visibility
    public Card(Deck deck, boolean isHidden) {
        this.value = deck.getRandomCardValue(); // Get random card from deck
        this.isHidden = isHidden; // Set visibility
    }

    // Setup both card's value and visibility
    public Card(int value, boolean isHidden) {
        this.value = value; // Create card with custom value
        this.isHidden = isHidden; // Set visibility
    }

    // Getter
    public int getValue() {
        return value;
    }
    public boolean getIsHidden() {
        return isHidden;
    }

    // Setter
    public void setValue(int value) {
        this.value = value;
    }
    public void setIsHidden(boolean isHidden) {
        this.isHidden = isHidden;
    }

    // Methods
    // Print cards from list
    public static void printCards(Card[] cards) {
        String lineAscii;

        // Create ASCII art for the cards
        // Construct the cards line by line
        for (int i = 0; i < Card.CARD_HEIGHT; i++) {
            // Clear lineAscii
            lineAscii = "";
            // Construct as many cards as there are in the list
            for (Card card : cards) {
                lineAscii = String.join("", lineAscii, getCardArt(i, card)); // Add card segment
                lineAscii = String.join("", lineAscii, "   "); // Add a space between cards
            }
            System.out.println(lineAscii);
        }
    }

    // Get ASCII line for card
    private static String getCardArt(int row, Card card) {
        // Left and right numbers formatting
        String lDigit;
        String rDigit;

        // If the card is hidden replace the number with "??"
        if (card.isHidden) {
            lDigit = rDigit = "??";
        }
        // Else if the card value is single digit, add a space before it (rDigit) and after it (lDigit) for alignment
        else if (card.getValue() >= 1 && card.getValue() <= 9) {
            lDigit = card.getValue() + " ";
            rDigit = " " + card.getValue();
        }
        // Else don't add any spaces
        else {
            lDigit = rDigit = Integer.toString(card.getValue());
        }

        return switch (row) {
            case 0    -> "┌────────┐";
            case 1    -> "│ " + lDigit + "     │";
            case 2, 3 -> "│        │";
            case 4    -> "│     " + rDigit + " │";
            case 5    -> "└────────┘";
            default -> "";
        };
    }
}
