abstract class BasePlayer {
    protected int score;
    protected boolean isBust;
    protected boolean isDealer;
    protected boolean finished;
    protected boolean firstTurn;
    protected Card hiddenCard;

    // Constructor
    public BasePlayer() {
        score = 0;
        finished = false;
        isBust = false;
    }

    // Getters
    public int getScore() {
        return this.score;
    }
    public boolean getIsFinished() {
        return this.finished;
    }
    public boolean getIsDealer() {
        return this.isDealer;
    }
    public Card getHiddenCard() {
        return hiddenCard;
    }
    public boolean getIsBust() {
        return isBust;
    }

    // Setters
    public void setScore(int score) {
        this.score = score;
    }
    public void setFinished(boolean finished) {
        this.finished = finished;
    }
    public void setIsDealer(boolean isDealer) {
        this.isDealer = isDealer;
    }
    public void setHiddenCard(Card hiddenCard) {
        this.hiddenCard = hiddenCard;
    }
    public void setIsBust(boolean isBust) {
        this.isBust = isBust;
    }

    // Methods
    // Perform the first draw
    public abstract void firstDraw(Deck deck, int count);

    // Draw 1 card from the deck and add it to the player's score
    public void drawCard(Deck deck) {
        System.out.println((isDealer ? "Dealer chooses to hit. He" : "You") + " drew: ");
        // Draw card and print it
        drawCards(deck, 1);
        // Print total score
        System.out.println((isDealer ? "His" : "Your") + " total is: " + this.score);
    }

    // Draw multiple cards from the deck and add them to the player's score
    public void drawCards(Deck deck, int count) {
        // Create a new array to hold the drawn cards
        Card[] drawnCards = new Card[count];

        // Add cards to the array and the player's score
        for (int i = 0; i < count; i++) {
            drawnCards[i] = new Card(deck);
            this.score += drawnCards[i].getValue();
        }

        // If the player is the dealer, hide the second card and store its value
        if (isDealer && firstTurn) {
            hiddenCard = drawnCards[count - 1];
            drawnCards[count - 1].setIsHidden(true);
            firstTurn = false;
        }

        // Print the cards
        Card.printCards(drawnCards);
    }

    // Check if the player has busted
    public void checkBust() {
        if (score > 21) {
            finished = true;
            isBust = true;
        }
    }
}
