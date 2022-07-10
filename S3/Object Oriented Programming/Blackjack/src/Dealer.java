public class Dealer extends BasePlayer{

    // Constructor
    public Dealer() {
        super();
        isDealer = true;
    }

    // Methods
    // Perform the first draw
    @Override
    public void firstDraw(Deck deck, int count){
        firstTurn = true;
        System.out.println("The dealer has: ");
        // Draw the first two cards and print them
        drawCards(deck, count);
    }

    // Ask the dealer if they want to draw another card
    public boolean askDraw(int playerScore) {
        // Wait 2 seconds before replying
        try {
            Thread.sleep(2000);
        }
        catch(InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
        // If score is less than player's score, draw a card
        return score < playerScore;
    }

    // Called when it's the dealer's turn
    public void Play(Deck deck, int playerScore) {
        while (!finished) {
            if (askDraw(playerScore)) {
                drawCard(deck);
                checkBust();
            }
            else {
                System.out.println("The dealer decides to stay.");
                finished = true;
            }
        }
    }
}
