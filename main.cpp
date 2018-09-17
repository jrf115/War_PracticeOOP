/*
   Object Oriented Programming: War
   Author.  John Fahringer
            jrf115@zips.uakron.edu
   Version. 1.01 9/12/2018
   Purpose: This program is supposed to serve as an implementation of the card game "War".
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "war_card.hpp"
using std::cout;
using std::endl;

int main()
{
    // Introduce players
    bool playerA_Status = true;
    bool playerB_Status = true;
    Standard_card playerA_Card; // Represents player A's drawn card
    Standard_card playerB_Card; // Represents player B's drawn card
    Deck playerA_Deck;
    Deck playerB_Deck;
    // Create Deck
    Deck cards;
    populuateDeck(cards);
    // Shuffle Deck
    Deck::iterator start;
    start = (cards).begin();
    Deck::iterator finish;
    finish = (cards).end();
    std::random_shuffle(start, finish);
    // Split Cards equally between players
    split(playerA_Card, playerB_Deck, cards);

    // Game Psuedo Code
    // Initiate Game (Loop which ends when a player runs out of cards)
        // Start off with revealing top cards. When both players place down their initial cards...
        // If player 1 has a higher ranked card, he takes his and player 2's cards
        // Else if player 2 has a higher ranked card, he takes his and player 1's cards
        // Else, engage war()...:
            // While both players have cards or up until 3 cards are placed...:
                // place cards.
            // If player 1 has a higher ranked card, he takes his and player 2's cards
            // Else if player 2 has a higher ranked card, he takes his and player 1's cards
            // Else, engage war() (loop again)
        // If a player has no cards, that player has lost
    //

    while (playerA_Status && playerB_Status)
    {
        playerA_Card = playerA_Deck[0];
        playerB_Card = playerA_Deck[0];
        cout << "Player A placed a " << playerA_Card.rank << " of " << playerA_Card.suit << endl;
        cout << "Player B placed a " << playerB_Card.rank << " of " << playerB_Card.suit << endl;
        cout << endl;
        if (compareDifference(playerA_Card, playerB_Card))
        {
            if (playerA_Card.rank < playerB_Card.rank)
                giveCardToPlayer(playerA_Card, playerB_Deck);
            else
                giveCardToPlayer(playerB_Card, playerA_Deck);
        }
        else
        {
            cout << "WAR!!! \n";
            war(playerA_Deck, playerB_Deck);
        }

        if (playerA_Deck.empty())
            playerA_Status = false;
        if (playerB_Deck.empty())
            playerB_Status = false;
    }

    if (playerA_Status)
        cout << "Player A is the winner!" << endl;
    else
        cout << "Player B is the winner!" << endl;
    return 0;
}
