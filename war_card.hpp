#ifndef WAR_CARD_HPP
#define WAR_CARD_HPP
// ^- This is a header guard. It prevents accidental repeated inclusion of a header file
#include <iostream>
#include <deque>
#include <algorithm>
// #pragma once
// Or just write this. It's equivalent to using header guards. Choose this or that.

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

using Deck = std::deque<Standard_card>;

#endif // WAR_CARD_HPP
