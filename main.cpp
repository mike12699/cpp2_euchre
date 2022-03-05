#include <iostream>
#include <vector>
#include <string>

enum Value { Nine, Ten, Jack, Queen, King, Ace };
enum Suit { Diamonds, Clubs, Hearts, Spades };


struct Card
{
	Value value; 
	Suit suit;
};

int getTrumpColor(const Card& trump)
{
	return trump.suit % 2;
}

float Rank(std::vector<Card>* hand, const Card& trump)
{	
	int points = 0;
			
	int trumpColor = getTrumpColor(trump);

	for (int i = 0; i < hand->size(); i++)
	{
		if (hand->at(i).suit == trump.suit) 
		{
			if (hand->at(i).value == 2)
			{
				points += 25;
			}
			else if (trump.value < 2)
			{
				points += 6 + (2 * hand->at(i).value);
			}
			else
			{
				points += 6 + (2 * hand->at(i).value);
			}
		}
		else
		{
			if ((hand->at(i).value == 2) && (hand->at(i).suit % 2 == trumpColor))
			{
				points += 18;
			}			
			else if ((hand->at(i).value > 1))
			{
				points += 2 * (hand->at(i).value) - 3;
			}
		}
		std::cout << points << " ";
	}	
	return (points/85.0);    
}

int main()
{
	//handles the best ranking cards
	std::vector<Card> best(0);
	best.push_back({ Ace, Spades });
	best.push_back({ King, Spades });
	best.push_back({ Queen, Spades });
	best.push_back({ Jack, Spades });
	best.push_back({ Jack, Clubs });

	//handles the worst ranking cards
	std::vector<Card> worst(0);
	worst.push_back({ Nine, Hearts });
	worst.push_back({ Nine, Diamonds });
	worst.push_back({ Nine, Clubs });
	worst.push_back({ Ten, Hearts });
	worst.push_back({ Ten, Diamonds });

	Card trump = { Nine,Spades };

	float bestRank = Rank(&best, trump) * 100;	
	std::cout << "wins " << bestRank << "% of tricks.\n";

	float worstRank = Rank(&worst, trump) * 100;
	std::cout << "wins " << worstRank << "% of tricks.\n";
	return 0; 
}