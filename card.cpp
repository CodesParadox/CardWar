#include "card.hpp"

Card::Card(Suit suit, Rank rank)
    : suit_(suit), rank_(rank) {}

Suit Card::GetSuit() const {
    return suit_;
}

Rank Card::GetRank() const {
    return rank_;
}