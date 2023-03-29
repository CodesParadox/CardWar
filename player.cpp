#include "player.hpp"

Player::Player(std::string name)
    : name_(name) {}

std::string Player::GetName() const {
    return name_;
}

int Player::GetNumCards() const {
    return hand_.size();
}

void Player::AddCard(Card card) {
    hand_.push_back(card);
}

Card Player::GetCardByIndex(int index) const {
    return hand_[index];
}