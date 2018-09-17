#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP

enum Suit
{
    Spades = 1,
    Clubs,
    Diamonds,
    Hearts,
};

enum Rank
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

struct Standard_card
{
    Suit suit;
    Rank rank;
};

using Deck = std::vector<Standard_card>;
using std::cout;
using std::endl;

void populuateDeck(Deck& aDeck);
void fillSuit(Deck& aDeck, int& iter);
void fillRank(Deck& aDeck, int& iter, int cardSuit);
void split(Deck& deckA, Deck& deckB, Deck& deckGame);
bool compareDifference(Standard_card& aCard, Standard_card& bCard);
void giveCardToPlayer(Standard_card& otherPlayersCard, Deck& playerDeck);
void war(Deck& playerA_Deck, Deck& playerB_Deck);
void giveCardsToPlayer(Deck& playerCards, Deck& temp);

/****************
*** Functions ***
****************/

/** Generates deck of 52 cards **/
void populuateDeck(Deck& aDeck)
{
    int iterate = 0; // Our card counter in our deck.
    fillSuit(aDeck, iterate);
}

/** This function will define the Suit for the fillRank to fill up with. **/
/** There are four suits that need filled.                               **/
void fillSuit(Deck& aDeck, int& iter)
{
    fillRank(aDeck, iter, Spades);
    iter = iter + 13;
    fillRank(aDeck, iter, Clubs);
    iter = iter + 13;
    fillRank(aDeck, iter, Diamonds);
    iter = iter + 13;
    fillRank(aDeck, iter, Hearts);
}

/** This function will fill up the suit it is called to fill up **/
void fillRank(Deck& aDeck, int& iter, Suit cardSuit)
{
    if (cardSuit != Hearts && cardSuit != Clubs && cardSuit != Diamonds && cardSuit != Spades)
        std::cout << "Error: 'cardSuit' is invalid.\n";

    int rankCounter = 1; // Used for the enum's property of ints to help us define the rank of each card in the following loop.
    int temp = iter;

    for (;iter < (temp + 14); iter++)   // Each suit has 13 cards. Once you reach the 13th card, focus on the next suit
    {
        aDeck[iter].suit = cardSuit;
        aDeck[iter].rank = static_cast<Rank>(rankCounter);
        rankCounter++;
    }
}

/** Splits cards evenly for each player. Each player will have 26 cards **/
void split(Deck& deckA, Deck& deckB, Deck& deckGame)
{
    for (int i; i < 26; i++)
    {
        deckA.push_back(deckGame[0]); // The vector parameter is always zero since we are erasing the first element afterwards, and erase pushes values left one.
        deckGame.erase(deckGame.begin());
    }
    for (int i; i < 26; i++)
    {
        deckB.push_back(deckGame[0]);
        deckGame.erase(deckGame.begin());
    }
}

/** This function will compare the rank of the cards passed in,  **/
/** and will return true if there is a difference, false if not  **/
bool compareDifference(Standard_card& aCard, Standard_card& bCard)
{
    if (aCard.rank != bCard.rank)
        return true;     // give card to one of the players
    else
        return false;    // and will initiate a call to war
}

/** Gives a single card to specified player **/
void giveCardToPlayer(Standard_card& otherPlayersCard, Deck& playerDeck)
{
    playerDeck.push_back(otherPlayersCard);
}

/** Implements the war mode in the game "War" **/
void war(Deck& playerA_Deck, Deck& playerB_Deck)
{
    Deck playerA_PlayCards;
    Deck playerB_PlayCards;
    Deck::iterator playerA_LastCard;
    Deck::iterator playerB_LastCard;
    while (!playerA_Deck.empty() && !playerB_Deck.empty())
    {    // Each player needs to place down three cards vvv
        for (int i = 0; !playerA_Deck.empty() && !playerB_Deck.empty() && i < 4; i++)
        {
            playerA_PlayCards.push_back(playerA_Deck[i]);
            playerB_PlayCards.push_back(playerB_Deck[i]);
            playerA_Deck.erase(playerA_Deck.begin());
            playerB_Deck.erase(playerB_Deck.begin());
        }
        playerA_LastCard = playerA_PlayCards.end() - 1;  // null - 1 gives us player A's last played card
        playerB_LastCard = playerB_PlayCards.end() - 1;
        cout << "Player A placed a " << playerA_LastCard->rank << " of " << playerA_LastCard->suit << endl;
        cout << "Player B placed a " << playerB_LastCard->rank << " of " << playerB_LastCard->suit << endl;
        cout << endl;
        if (playerA_LastCard->suit > playerB_LastCard->suit)
        {
            giveCardsToPlayer(playerA_Deck, playerB_PlayCards);
            return;
        }
        else if (playerB_LastCard->suit > playerA_LastCard->suit)
        {
            giveCardsToPlayer(playerB_Deck, playerA_PlayCards);
            return;
        }
    }
}

/** This function will give cards to a player's hand **/
void giveCardsToPlayer(Deck& playerCards, Deck& temp)
{   //Deck temp are the cards to "push back"
    Deck::iterator iter;
    for (iter = temp.begin(); iter != temp.end(); iter++)
    {
        playerCards.push_back(*iter);
        temp.erase(iter);
    }
}

#endif // WAR_CARD_HPP
