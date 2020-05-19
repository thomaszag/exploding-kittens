# Title: Exploding Kittens
#### Status: Complete
This project uses C++ to create a version of the popular kickstarter game Exploding Kittens. 



## How to Play

* Exploding Kittens is a turn-based game played between 2 - 4 players.
* Each player has a hand that contains multiple card types that are face down. 
* Each player takes turns drawing cards from the main deck until someone draws an Exploding Kitten. 
* On each turn, a player can either view their cards, play a card, or draw a card.
* A player can place as many cards as they want per turn.
* A player's turn ends when they either play a card that ends their turn or when they draw a card.
* If a player draws an Exploding Kitten, they are eliminated unless they have a defuse card. The defuse 
  card can therefore be played to save the player but is discarded after use. The Exploding Kitten card 
  is put back into the deck.
* The game ends and a winner is declared once every player is eliminated except the last player. 

## Card Types

* Exploding Kitten: A player loses when they draw this card, unless they have a Defuse card in which case the Defuse is discarded, and    the Exploding Kitten is placed back into the deck.
* Defuse: When an Exploding Kitten card is played, this card allows the player to continue playing - saving them from elimination.
* Skip: The player ends their turn without drawing a card.
* Attack: The player ends their turn(s) without drawing a card, and the next player takes two turns.
* See the Future: The player is able to see the top three cards of the main deck.
* Shuffle: Allows player to shuffle the main deck.
* Cat Cards: Cards without instructions that must be played in matched pairs and which allow the player to take a random card from another player's hand.

(For more expansive card list see deck.txt and bomb.txt)



