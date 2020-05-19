# Title: Exploding Kittens

This project uses C++ to create a version of the popular kickstarter game Exploding Kittens. 

## General Details

* Exploding Kittens is a turn-based game that is played between 2 - 4 players.
* Each player has a deck that contains a pleothra of card types that are put face down. 
* Each player takes turns drawing cards until someone draws an Exploding Kitten. 
* On each turn, a player can either view their cards, play a card or draw a card
* A player can place as many cards as they want
* A player's turn ends when they either play a card that ends their turn or they draw a card
* If a player draws an exploding kitten, they are eliminated unless they have a defuse card. The defuse card is
discarded and the exploding kitten card is put back into the deck
* Game ends and a winner is declared once every player is eliminated except the last player 

## Card Types

* Exploding Kitten: A player loses when they draw this card, unless they have a Defuse card in which case the Defuse is discarded and the Exploding Kitten placed back into the deck.
* Defuse: When a Exploding Kitten card is played, this card allows the player to continue playing 
* Skip: The player ends their turn without drawing a card.
* Attack: The player ends their turn(s) without drawing a card and the next player takes two turns.
* See the Future: The player is able to see the top three cards of the deck.
* Shuffle: Allows player to shuffle their deck.
* Cat Cards: Cards without instructions that must be played in matched pairs, and allow the player to take a random card from another player's hand.

(For more expansive card list see deck.txt and bomb.txt)



