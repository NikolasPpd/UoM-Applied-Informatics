import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Print the game title
        System.out.println("╔═════════════════════════════════════════════╗");
        System.out.println("║  Welcome to the simplified Blackjack game!  ║");
        System.out.println("╠═════════════════════════════════════════════╣");
        System.out.println("║    Προσοχή! Υπάρχει κίνδυνος εθισμού και    ║");
        System.out.println("║    απώλειας περιουσίας. Παίξτε υπεύθυνα!    ║");
        System.out.println("╚═════════════════════════════════════════════╝");

        // Loop until the user wants to quit
        while (true) {
            // Create player and dealer objects
            Player player = new Player();
            Dealer dealer = new Dealer();

            // Create deck object
            Deck deck = new Deck();

            // First draw for the player
            player.firstDraw(deck, 2);
            // First draw for the dealer
            dealer.firstDraw(deck, 2);

            // Player's turn
            player.Play(deck);

            // Dealer's turn if the player didn't bust
            if (!player.getIsBust()) {
                System.out.println("\nOK, dealer is playing.");
                System.out.println("His hidden card was:");

                // Print the dealer's hidden card
                {
                    // Create a temporary card array
                    Card[] tempCardArray = new Card[1];
                    // Make the hidden card visible
                    dealer.getHiddenCard().setIsHidden(false);
                    // Insert the hidden card
                    tempCardArray[0] = dealer.getHiddenCard();
                    // Print it
                    Card.printCards(tempCardArray);
                    // After this block, the temp variable is destroyed
                }

                // Dealer's turn
                dealer.Play(deck, player.getScore());

                // Check who won
                // If the dealer busted, the player wins
                if (dealer.getIsBust()) {
                    System.out.println("\nDealer busted! You win!");
                } else {
                    // If the player's hand is higher than the dealer's, the player wins
                    if (player.getScore() > dealer.getScore()) {
                        System.out.println("\nYour hand is higher than the dealer's. You win!");
                    }
                    // Otherwise, the dealer wins
                    else {
                        if (player.getScore() == dealer.getScore()) {
                            System.out.println("\nYour hand is equal to the dealer's. You lose!");
                        }
                        else {
                            System.out.println("\nYour hand is lower than the dealer's. You lose!");
                        }
                    }
                }
            } else {
                // If the player busted, the dealer wins
                System.out.println("\nYou busted! Dealer wins!");
            }

            // Ask the user if he wants to play again
            System.out.print("\nDo you want to play again? (y/n): ");
            String answer = input.nextLine();
            if (answer.equalsIgnoreCase("n")) {
                input.close();
                break;
            }
        }
    }
}
