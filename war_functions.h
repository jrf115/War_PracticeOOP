#ifndef WAR_FUNCTIONS_H_INCLUDED
#define WAR_FUNCTIONS_H_INCLUDED

#include "war_card.hpp"

void populuateDeck(Deck& aDeck);
void fillSuit(Deck& aDeck, int iter);
void fillRank(Deck& aDeck, int iter, int cardSuit);
void split(Deck& deckA, Deck& deckB, Deck& deckGame);
bool compareDifference(Standard_card& aCard, Standard_card& bCard);
void giveCardToPlayer(Standard_card& playersCard, Standard_card& otherPlayersCard, Deck& playerDeck);
void war(Deck& playerA_Deck, Deck& playerB_Deck);
void giveCardsToPlayer(Deck& playerCards, Deck& temp, Deck& temp2);

using std::cout;
using std::endl;
using std::deque;

#endif // WAR_FUNCTIONS_H_INCLUDED
