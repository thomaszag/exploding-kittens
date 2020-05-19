#include "stdafx.h"
#include "Game.h"

using namespace std;

//Game Constructor
Game::Game()
{
	int numPlayers = 0;

	cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW" << "\n" << "Welcome to Exploding Kittens" << "\n" <<
		"A Game By Elan Lee, Shane Small, and Matthew Inman" << "\n" << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW"
		<< endl;

	SetNumPlayers(numPlayers);
	PlayGame();


}

//Sets Number of players
void Game::SetNumPlayers(int numPlayers)
{
	cout << "How many players would you like? Choose 2 - 4 players : " << endl;
	cin >> numPlayers;
	while ((numPlayers < 2) || (numPlayers > 4))
	{
		cout << "How many players would you like? Choose 2 - 4 players : " << endl;
		cin >> numPlayers;
	}
	m_numPlayers = numPlayers;

}

//Shuffles Deck
void Game::Shuffle()
{
	int type = 0, maxSize, currVar;
	string desc;
	Card tempCard(type, desc);
	Card newCard(type, desc);
	maxSize = m_deck.size();
	srand(time(NULL));
	
	for (int i = 0; i < maxSize; i++)
	{
		currVar = rand() % maxSize;
		tempCard = m_deck[currVar];
		m_deck[currVar] = m_deck[i];
		m_deck[i] = tempCard;
	}
	
}

//See-The-Future-Card purpose, Sees next three cards in deck.
void Game::Peek()
{
	int type = 0, sizeVec;
	string desc;
	sizeVec = m_deck.size() - 1;
	if (sizeVec < 3)
	{
		cout << "Less than three cards left in deck. " << endl;
	}
	else
	{
		cout << "The types of the next three cards in the deck are: " << endl;
		for (int i = 0; i < PEEK_NUM; i++)
		{
			type = m_deck[sizeVec].GetType();
			switch (type) {
			case 0:
				desc = "Bomb ";
				break;
			case 1:
				desc = "Defuse: ";
				break;
			case 2:
				desc = "Attack: ";
				break;
			case 3:
				desc = "Skip: ";
				break;
			case 4:
				desc = "See-The-Future: ";
				break;
			case 5:
				desc = "Shuffle: ";
				break;
			default:
				desc = "Cat Card";
				break;

				}

			cout << desc << endl;
			sizeVec--;
			}
		}
}

//Draws Card from Deck
Card Game::DrawCard()
{
	int type = 0, sizeVec;
	string desc;
	Card drawnCard(type, desc);

	sizeVec = m_deck.size() - 1;
	drawnCard = m_deck[sizeVec];
    type = m_deck[sizeVec].GetType();

	m_deck.pop_back();
	switch (type) {
    
		//Gets Type of Card
	case 1:
		desc = "Defuse: ";
		break;
	case 2:
		desc = "Attack: ";
		break;
	case 3:
		desc = "Skip: ";
		break;
	case 4:
		desc = "See-The-Future: ";
		break;
	case 5:
		desc = "Shuffle: ";
		break;
	default:
		desc = "";
		break;

	}
	cout << "Drawn Card - " << desc << drawnCard.GetDesc() << endl;
	return drawnCard;

}

//Returns number based on card type.
int Game::HandleCard(int cardType)
{
	int defuse = 1, attack = 2, skip = 3, peek = 4, shuffle  = 5, melonCat = 6, potatoCat = 7, zombieKitty = 8, tacoCat = 9;
	switch (cardType)
	{
	case 1:
		return defuse;
		break;
	case 2:
		return attack;
		break;
	case 3:
		return skip;
		break;
	case 4:
		return peek;
		break;
	case 5:
		return shuffle;
		break;
	case 6:
		return melonCat;
		break;
	case 7:
		return potatoCat;
		break;
	case 8:
		return zombieKitty;
		break;
	case 9:
		return tacoCat;
		break;
	}
	return 0;
}

//Plays most game functions
void Game::PlayGame()
{
	int count = 0, type = 0, sizeVec, sizeHand, cardNum, play1 = 0, play2 = 1, play3 = 2, play4 = 3, gameEnd = 0;
	bool lostF = false, lostT = true, extraTurn = true, extraTurnEnd = false;
	string desc, name, player1 = "Player 1", player2 = "Player 2", player3 = "Player 3", player4 = "Player 4";
	vector<Card> handTemp;

	Card cardDraw(type, desc);
	Card cardTemp(type, desc);
	


	LoadDeck();
	Shuffle();
	
	sizeVec = m_deck.size();
	count = sizeVec - 1;
	
	//Checks how many players are players and builds that number accordingly
	if (m_numPlayers > 1)
	{
		//Building Player 1 with deck, name, and lost check
		for (int i = 0; i < INIT_CARDS; i++)
		{
			cardDraw = m_deck[count];		
			handTemp.push_back(cardDraw);
			
			count--;
			m_deck.pop_back();
		}
	
		Player playerOne(player1, handTemp, lostF);
		m_players[play1] = playerOne;
		handTemp.clear();

	   
		//Building Player 2 with deck, name, and lost check
		for (int i = 0; i < INIT_CARDS; i++)
		{
			cardDraw = m_deck[count];
			handTemp.push_back(cardDraw);
			count--;
			m_deck.pop_back();

		}
		
		Player playerTwo(player2, handTemp, lostF);
		m_players[play2] = playerTwo;
		handTemp.clear();
	
	}
	if (m_numPlayers > 2)
	{

		//Building Player 3 with deck, name, and lost check
		for (int i = 0; i < INIT_CARDS; i++)
		{
			cardDraw = m_deck[count];
			handTemp.push_back(cardDraw);
		    count--;
			m_deck.pop_back();
		}
		
		Player playerThree(player3, handTemp, lostF);
		m_players[play3] = playerThree;
		handTemp.clear();
	}

	if (m_numPlayers > 3)
	{
		//Building Player 4 with deck, name, and lost check
		for (int i = 0; i < INIT_CARDS; i++)
		{
			
			cardDraw = m_deck[count];	
			handTemp.push_back(cardDraw);
			count--;
			m_deck.pop_back();

		}
		
		Player playerFour(player4, handTemp, lostF);
		m_players[play4] = playerFour;
		handTemp.clear();
	}

	AddBombCards();
	Shuffle();


	sizeVec = m_deck.size();
	cout << "Shuffling the cards" << "\n" << "Dealing" << "\n" << "Shuffling in the exploding kittens!"
		<< "\n" << "Num cards remaining: " << sizeVec << endl;


	//Plays actual game. Gives three options: View hand, Play card, and Draw card.
	
	int numHandler;
	int choiceA;
	bool attacked;

	while (gameEnd == 0)
	{
		for (int i = 0; i < m_numPlayers; i++)
		{
			int turnEnd = 1, CatermelonCount = 0, PotatoCatCount = 0, ZombieKittyCount = 0, TacoCatCount = 0, pair = 2;
			
			//Checks if player has lost
			if (m_players[i].HasLost() == true)
			{
				turnEnd--;
			}
			
			//Checks for attack, adds extra turn
			if (m_players[i].HasExtraTurn() == true)
			{
				m_players[i].SetExtraTurn(extraTurnEnd);
				turnEnd++;
				
			}

			//Implements turn based game, turn ends when skip is played or card is drawn
			while (turnEnd > 0)
			{
				cout << endl;
				cout << "It is " << m_players[i].GetName() << " 's turn" << "\n" << "What would you like to do: " << "\n" << "1. View Cards " <<
					"\n" << "2. Play A Card " << "\n" << "3. Draw A Card" << endl;

				cin >> choiceA;
				cout << endl;
				while ((choiceA < 1) || (choiceA > 3))
				{
					cout << "It is " << m_players[i].GetName() << " 's turn" << "\n" << "What would you like to do: " << "\n" << "1. View Cards " <<
						"\n" << "2. Play A Card " << "\n" << "3. Draw A Card" << endl;
					cin >> choiceA;
					cout << endl;
				}
				//View Card
				if (choiceA == 1)
				{
					m_players[i].DisplayHand();
				}
				
				//Play a Card
				if (choiceA == 2)
				{
					if (m_players[i].HasCards() == false)
					{
						cout << "You have no cards!!" << endl;
					}
					else
					{
						int choiceB, playerChoice, cardChoice, playerCount = 0, numCards;

						m_players[i].DisplayHand();

						cout << "Select a card to play : " << endl;
						cin >> choiceB;

						cardTemp = m_players[i].PlayCard(choiceB);

						if ((cardTemp.GetType() > -1) && (cardTemp.GetType() < 10))
						{
							numHandler = HandleCard(cardTemp.GetType());
							switch (numHandler)
							{


								//Plays attacks card
							case 2:

								cout << "You attacked" << endl;

								if (i == (m_numPlayers - 1))
								{
									m_players[playerCount].SetExtraTurn(extraTurn);
								}
								else
								{
									m_players[i + 1].SetExtraTurn(extraTurn);
								}
								turnEnd--;
								break;

								//Plays skip card
							case 3:

								cout << "Your turn has been skipped" << endl;
								turnEnd--;
								break;
							case 4:

								Peek();
								break;

							case 5:

								Shuffle();
								break;
								// Cases 6-9 deal with the pair cards. 
							    //Catermelon Pair
							case 6:

								cout << "Cat cards played" << endl;
								CatermelonCount++;
								
								if (CatermelonCount == pair)
								{
									cout << "You played a pair! You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
									for (int j = 0; j < m_numPlayers; j++)
									{
										if (m_players[i].GetName() != m_players[j].GetName())
										{
											cout << j << ". " << " Player " << (j + 1) << endl;

										}

									}
									cin >> playerChoice;
									//Checks if player choice is in bounds
									while ((playerChoice < 0) || (playerChoice > m_numPlayers))
									{
										cout << "You played a pair! You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
										for (int j = 0; j < m_numPlayers; j++)
										{
											if (m_players[i].GetName() != m_players[j].GetName())
											{
												cout << j << ". " << " Player " << (j + 1) << endl;

											}

										}
										cin >> playerChoice;
									}
									//Chooses which card to steal
									if (m_players[playerChoice].GetNumberOfCards() == 0)
									{
										cout << "Player has no cards" << endl;
									}
									else
									{
										numCards = m_players[playerChoice].GetNumberOfCards();
										for (int j = 0; j < numCards; j++)
										{
											cout << "Card" << (j + 1) << endl;
										}
										cin >> cardChoice;

										//Checks if card choice is in bounds
										while ((cardChoice < 1) || (cardChoice > m_players[playerChoice].GetNumberOfCards()))
										{
											cout << "Choose a valid card" << endl;
											numCards = m_players[playerChoice].GetNumberOfCards();
											for (int j = 0; j < numCards; j++)
											{
												cout << "Card" << (j + 1) << endl;
											}
											cin >> cardChoice;
										}
										cardTemp = m_players[playerChoice].LoseCard(cardChoice - 1);
										m_players[i].AddToHand(cardTemp);
									}
								}
								break;
								//Hairy Potato Cat Pair
							case 7:

								cout << "Cat cards played" << endl;
								PotatoCatCount++;
								if (PotatoCatCount == pair)
								{
									cout << "You played a pair! You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
									for (int j = 0; j < m_numPlayers; j++)
									{
										if (m_players[i].GetName() != m_players[j].GetName())
										{
											cout << j << ". " << " Player " << (j + 1) << endl;

										}


									}
									cin >> playerChoice;

									//Checks if player choice is in bounds
									while ((playerChoice < 0) || (playerChoice > m_numPlayers))
									{
										cout << "You played a pair! You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
										for (int j = 0; j < m_numPlayers; j++)
										{
											if (m_players[i].GetName() != m_players[j].GetName())
											{
												cout << j << ". " << " Player " << (j + 1) << endl;

											}

										}
										cin >> playerChoice;
									}
									//Chooses which card to steal
									if (m_players[playerChoice].GetNumberOfCards() == 0)
									{
										cout << "Player has no cards" << endl;
									}
							
									else
									{
										numCards = m_players[playerChoice].GetNumberOfCards();
										for (int j = 0; j < numCards; j++)
										{
											cout << "Card" << (j + 1) << endl;
										}
										cin >> cardChoice;

										//Checks if card choice is in bounds
										while ((cardChoice < 1) || (cardChoice > m_players[playerChoice].GetNumberOfCards()))
										{
											cout << "Choose a valid card" << endl;
											numCards = m_players[playerChoice].GetNumberOfCards();
											for (int j = 0; j < numCards; j++)
											{
												cout << "Card" << (j + 1) << endl;
											}
											cin >> cardChoice;
										}
										cardTemp = m_players[playerChoice].LoseCard(cardChoice - 1);
										m_players[i].AddToHand(cardTemp);
									}
								}
								break;
								//Zombie Kitten Pair
							case 8:

								cout << "Cat cards played" << endl;
								ZombieKittyCount++;
								if (ZombieKittyCount == pair)
								{
									cout << "You played a pair!You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
									for (int j = 0; j < m_numPlayers; j++)
									{
										if (m_players[i].GetName() != m_players[j].GetName())
										{
											cout << j << ". " << " Player " << (j + 1) << endl;

										}


									}

									cin >> playerChoice;
									//Checks if player choice is in bounds
									while ((playerChoice < 0) || (playerChoice > m_numPlayers))
									{
										cout << "You played a pair!You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
										for (int j = 0; j < m_numPlayers; j++)
										{
											if (m_players[i].GetName() != m_players[j].GetName())
											{
												cout << j << ". " << " Player " << (j + 1) << endl;

											}

										}
										cin >> playerChoice;
									}
									//Chooses which card to steal
									if (m_players[playerChoice].GetNumberOfCards() == 0)
									{
										cout << "Player has no cards" << endl;
									}
									else
									{
										numCards = m_players[playerChoice].GetNumberOfCards();
										for (int j = 0; j < numCards; j++)
										{
											cout << "Card" << (j + 1) << endl;
										}
										cin >> cardChoice;

										//Checks if card choice is in bounds
										while ((cardChoice < 1) || (cardChoice > m_players[playerChoice].GetNumberOfCards()))
										{
											cout << "Choose a valid card" << endl;
											numCards = m_players[playerChoice].GetNumberOfCards();
											for (int j = 0; j < numCards; j++)
											{
												cout << "Card" << (j + 1) << endl;
											}
											cin >> cardChoice;
										}
										cardTemp = m_players[playerChoice].LoseCard(cardChoice - 1);
										m_players[i].AddToHand(cardTemp);
									}

								}
								break;
							//Tacocat Pair
							case 9:

								cout << "Cat cards played" << endl;
								TacoCatCount++;
								if (TacoCatCount == pair)
								{
									cout << "You played a pair!You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
									for (int j = 0; j < m_numPlayers; j++)
									{
										if (m_players[i].GetName() != m_players[j].GetName())
										{
											cout << j << ". " << " Player " << (j + 1) << endl;

										}

									}
									cin >> playerChoice;
									//Checks if player choice is in bounds
									while ((playerChoice < 0) || (playerChoice > m_numPlayers))
									{
										cout << "You played a pair!You can now steal a card from another player!" << "\n" << "Select a Player" << endl;
										for (int j = 0; j < m_numPlayers; j++)
										{
											if (m_players[i].GetName() != m_players[j].GetName())
											{
												cout << j << ". " << " Player " << (j + 1) << endl;

											}

										}
										cin >> playerChoice;
									}
									//Chooses which card to steal
									if (m_players[playerChoice].GetNumberOfCards() == 0)
									{
										cout << "Player has no cards" << endl;
									}
									else
									{
										numCards = m_players[playerChoice].GetNumberOfCards();
										for (int j = 0; j < numCards; j++)
										{
											cout << "Card" << (j + 1) << endl;
										}
										cin >> cardChoice;

										//Checks if card choice is in bounds
										while ((cardChoice < 1) || (cardChoice > m_players[playerChoice].GetNumberOfCards()))
										{
											cout << "Choose a valid card" << endl;
											numCards = m_players[playerChoice].GetNumberOfCards();
											for (int j = 0; j < numCards; j++)
											{
												cout << "Card" << (j + 1) << endl;
											}
											cin >> cardChoice;
										}
										cardTemp = m_players[playerChoice].LoseCard(cardChoice - 1);
										m_players[i].AddToHand(cardTemp);
									}
								}
								break;

							}

							m_discard.push_back(cardTemp);
						}

						else
						{
							//cout << "Discard Card Only " << endl;
							m_discard.push_back(cardTemp);
						}
					}
				}

				//Draw a Card
				if (choiceA == 3)
				{
					int cardChoice, cardDefuse, playersLeft = 0;
					cardDraw = DrawCard();
					m_players[i].AddToHand(cardDraw);
					//Checks to see if player drew a bomb card
					if (cardDraw.GetType() == 0)
					{
						cout << "Oh No! You drew Exploding Kitten Card: " << cardDraw.GetDesc() 
							<< " But you have a defuse card! Play it or lose!" << endl;
						
						//Lose if you have no cards
						if (m_players[i].GetNumberOfCards() == 1)
						{
							cout << "You lost" << endl;
							cardDraw = m_players[i].ReturnBomb();
							m_deck.push_back(cardDraw);
							Shuffle();
							m_players[i].SetLost(lostT);
						}
						else
						{
							m_players[i].DisplayHand();
							cin >> cardChoice;

							int maxSize = m_players[i].GetNumberOfCards() - 1;
							while ((cardChoice < 0) || (cardChoice > maxSize))
							{
								cout << "Oh No! You drew Exploding Kitten Card: " << cardDraw.GetDesc()
									<< " But you have a defuse card! Play it or lose!" << endl;

								m_players[i].DisplayHand();
								cin >> cardChoice;
							}

							cardTemp = m_players[i].PlayCard(cardChoice); //Chooses card to defuse bomb
							cardDefuse = HandleCard(cardTemp.GetType());  // Type of card, checks if its a defuse type
							m_discard.push_back(cardTemp);

							//If card is defuse type, returns bomb back into deck and reshuffles
							if (cardDefuse == 1)
							{
								cout << "You have defused the bomb" << endl;
								cardDraw = m_players[i].ReturnBomb();
								m_deck.push_back(cardDraw);
								Shuffle();

							}
							else
							{
								cout << "You lost" << endl;
								cardDraw = m_players[i].ReturnBomb();
								m_deck.push_back(cardDraw);
								Shuffle();
								m_players[i].SetLost(lostT);
								//Checks if game is over
								for (int i = 0; i < m_numPlayers; i++)
								{
									if (m_players[i].HasLost() == false)
									{
										playersLeft++;

									}

								}
								if (playersLeft == 1)
								{
									for (int i = 0; i < m_numPlayers; i++)
									{
										if (m_players[i].HasLost() == false)
										{
											cout << m_players[i].GetName() << " is the winner!!" << endl;
											gameEnd = 1;
											turnEnd--;
											
										}

									}

								}

							}
						}
					}
					sizeVec = m_deck.size();
					if (gameEnd == 0)
					{
						cout << "Num cards remaining: " << sizeVec << endl;
						turnEnd--;
					}
				}
				//end = 1;
			}
		}
	}

}

//Puts cards into deck
int Game::LoadDeck()
{
	string line, desc;
	int type, maxSize, count = 1;
	fstream myFile;
	myFile.open(DECK_NAME);

	while (getline(myFile, line))
	{	
		myFile >> type;
		myFile >> line;
		Card card(type, line);
		card.GetType();
		m_deck.push_back(card);
		

	}
	m_deck.pop_back();
	return 0;
}

//Adds bomb cards after normal cards
int Game::AddBombCards()
{
	string line, desc;
	int type, count = 1;
	fstream myFile;
	myFile.open(BOMB_NAME);

	while (getline(myFile, line))
	{
		myFile >> type;
		myFile >> line;
		Card card(type, line);
		m_deck.push_back(card);

	}
	m_deck.pop_back();
	return 0;
}
