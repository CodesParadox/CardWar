#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "card.hpp"

class Player {
public:
    Player(std::string name);

    std::string GetName() const;
    int GetNumCards() const;
    void AddCard(Card card);
    Card GetCardByIndex(int index) const;

private:
    std::string name_;
    std::vector<Card> hand_;
};

#endif // PLAYER_HPP
