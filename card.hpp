#ifndef CARD_HPP
#define CARD_HPP

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank {
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
    King
};

class Card {
public:
    Card(Suit suit, Rank rank);

    Suit GetSuit() const;
    Rank GetRank() const;

private:
    Suit suit_;
    Rank rank_;
};

#endif 