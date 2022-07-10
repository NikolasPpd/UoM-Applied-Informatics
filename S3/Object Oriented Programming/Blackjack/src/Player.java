import java.util.Scanner;

public class Player extends BasePlayer {
    Scanner input = new Scanner(System.in);

    // Constructor
    public Player() {
        super();
        isDealer = false;
    }

    // Methods
    // Perform the first draw
    @Override
    public void firstDraw(Deck deck, int count){
        System.out.println("You get: ");
        // Draw the first two cards and print them
        drawCards(deck, count);
        System.out.println("Your total is: " + this.score);
    }

    // Ask the player if they want to draw another card
    public boolean askDraw() {
        System.out.print("Would you like to \"Hit\" or \"Stay\" (h/s)? ");
        String answer = input.nextLine();
        return answer.equalsIgnoreCase("h");
    }

    // Called when it's the player's turn
    public void Play(Deck deck) {
        while (!finished) {
            if (askDraw()) {
                drawCard(deck);
                checkBust();
            }
            else {
                finished = true;
            }
        }
    }
}
