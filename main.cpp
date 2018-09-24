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
#include "war_functions.h"

using std::cout;
using std::endl;

int main()
{
    int cumulativeTurns = 0;
    double summation_X_Of_I_min_avg = 0;
    std::vector<int> allTurns(1000);
    /// This loop will simulate multiple instances of the game, while recording
    /// the number turns for each game, and will perform calculations based on those
    /// numbers to find avg number of turns for each game.

    for (int numGames = 0; numGames < 1000; numGames++)
    {
        // Introduce players
        int numTurns = 0;
        bool playerA_Status = true;
        bool playerB_Status = true;
        Standard_card playerA_Card; // Represents player A's drawn card
        Standard_card playerB_Card; // Represents player B's drawn card
        Deck playerA_Deck;
        Deck playerB_Deck;
        // Create Deck
        Deck cards(52);
        populuateDeck(cards);
        // Shuffle Deck
        Deck::iterator start;
        start = (cards).begin();
        Deck::iterator finish;
        finish = (cards).end();
        std::random_shuffle(start, finish);
        // Split Cards equally between players
        split(playerA_Deck, playerB_Deck, cards);
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

        /// Game_Loop
        while (playerA_Status && playerB_Status)
        {
            playerA_Card = playerA_Deck[playerA_Deck.size() - 1];
            playerA_Deck.pop_back();
            playerB_Card = playerB_Deck[playerB_Deck.size() - 1];
            playerB_Deck.pop_back();
            cout << " Test ";
            cout << "Player A placed a " << playerA_Card.rank << " of " << playerA_Card.suit << endl;
            cout << "Player B placed a " << playerB_Card.rank << " of " << playerB_Card.suit << endl;
            cout << endl;
            if (compareDifference(playerA_Card, playerB_Card))
            {
                if (playerA_Card.rank < playerB_Card.rank){
                    giveCardToPlayer(playerA_Card, playerB_Deck);
                    cout << "Player B wins player A's card. " << endl;
                }
                else{
                    giveCardToPlayer(playerB_Card, playerA_Deck);
                    cout << "Player A wins player B's card. " << endl;
                }
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
            numTurns++;
        }
        if (playerA_Status)
            cout << "Player A is the winner!" << endl;
        else
            cout << "Player B is the winner!" << endl;
        /// End of game
        // Calculate for avgs and std dev
        cumulativeTurns += numTurns;
        allTurns.push_back(numTurns);
        cout << "Number of turns played: " << numTurns
        << endl << "------------------------------------\n";
    }

    cout << "FINISHED: \nWith an average number of turns being: " << cumulativeTurns / 999.0 << endl;
    while (!allTurns.empty()) // Calculate summation
    {
        summation_X_Of_I_min_avg += ( (allTurns[allTurns.size() - 1] - (cumulativeTurns / 999) ) ^ 2) ;
        allTurns.pop_back();
    }
    cout << "STandard deviation: " << sqrt(abs(summation_X_Of_I_min_avg / 999));
    return 0;
}
