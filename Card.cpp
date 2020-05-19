#include "stdafx.h"
#include "Card.h"

Card::Card()
{
	m_type = -1;
	m_desc = "Kitten Card";
}

Card::Card(int type, string desc)
{
	m_type = type;
	m_desc = desc;
}

int Card::GetType()
{
	return m_type;
}

string Card::GetDesc()
{
	return m_desc;
}

string Card::ToString()
{
	return string();
}