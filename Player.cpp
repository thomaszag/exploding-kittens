#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_name = "Meep";
}
Player::Player(string name, vector<Card> hand, bool lost)
{
	m_name = name;
	m_hand = hand;
	m_lost = lost;
}

Card Player::PlayCard(int choice)
{
	int type = -1, sizeHand;
	string desc;
	Card cardTemp(type, desc);
	
	sizeHand = m_hand.size() - 1;
	if ((choice < 0) || (choice > sizeHand))
	{
		cout << "Choice is not valid" << endl;
		return cardTemp;
	}
	else
	{
		cardTemp = m_hand[choice];
		m_hand.erase(m_hand.begin() + choice);
		return cardTemp;
	}
}

Card Player::LoseCard(int cardIndex)
{
	int type = -1;
	string desc;
	Card cardTemp(type, desc);
	cardTemp = m_hand[cardIndex];
	m_hand.erase(m_hand.begin() + cardIndex);


	
	return cardTemp;
}

bool Player::HasCards()
{
	int sizeHand;
	sizeHand = m_hand.size();
	if (sizeHand == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::HasLost()
{
	if (m_lost == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Player::HasExtraTurn()
{
	if (m_extraTurn == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Player::AddToHand(Card card)
{
	m_hand.push_back(card);
	return 0;
}

string Player::GetName()
{
	return m_name;
}

void Player::DisplayHand()
{
	int sizeHand, type;
	sizeHand = m_hand.size();
	string desc;


	for (int i = 0; i < sizeHand; i++)
	{
		type = m_hand[i].GetType();
		switch (type) {
			
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
		cout << i << ". " << desc << m_hand[i].GetDesc() << endl;
	}
}

int Player::GetNumberOfCards()
{
	int sizeHand;
	sizeHand = m_hand.size();
	return sizeHand;
}

Card Player::ReturnBomb()
{
	int type = 0, size;
	string desc;
	Card bomb(type, desc);
	
	size = (m_hand.size() - 1);
	bomb = m_hand[size];
	m_hand.pop_back();
	return bomb;
}

void Player::SetLost(bool lost)
{
	m_lost = lost;
}

void Player::SetExtraTurn(bool turn)
{
	m_extraTurn = turn;
}
