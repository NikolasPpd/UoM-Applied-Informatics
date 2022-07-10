import java.util.ArrayList;
import java.util.HashMap;

public class Deck {
    // Dictionary to store all available cards
    // Key - value pair: card value and card count
    private final HashMap<Integer, Integer> cards = new HashMap<>();
    // ArrayList of available card values
    private final ArrayList<Integer> values = new ArrayList<>();

    // Constructor
    public Deck() {
        // Loop through every card value within range and add 4 to the deck
        for (int i = Card.MIN_CARD_VALUE; i <= Card.MAX_CARD_VALUE; i++) {
            cards.put(i, 4);
            // Add each card value to the values ArrayList
            values.add(i);
        }
    }

    // Return a random card value that is available in the deck.
    public int getRandomCardValue() {
        // If ArrayList is empty (no cards available), return -1
        if (values.isEmpty()) {
            return -1;
        }

        // Get a random ArrayList index
        int randomIndex = getRandomInt(0, values.size() - 1);
        int tempValue = values.get(randomIndex);

        // Update remaining cards count
        cards.put(tempValue, cards.get(tempValue) - 1);

        // Check if specified card has ran out
        if (cards.get(tempValue) == 0) {
            // If so remove the card from available values
            values.remove(randomIndex);
        }

        // Return card value
        return tempValue;
    }

    // Return random integer within range
    private int getRandomInt(int min, int max) {
        return (int)(Math.random() * ((max - min) + 1)) + min;
    }
}
