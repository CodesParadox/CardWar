#include "player.hpp"
// #include "sources/game.hpp"
#include "card.hpp"
using namespace std;
using namespace std;

#include "doctest.h"
using namespace ariel;

TEST(GameTest, DeckIsShuffledRandomly) {
  Player p1("Alice");
  Player p2("Bob");

  Game game(p1,p2);


  vector<Card> initialDeck = game.getDeck();

  // Shuffle the deck
  game.shuffleDeck();

  // Get the shuffled deck
  vector<Card> shuffledDeck = game.getDeck();

  // Check that the shuffled deck is not equal to the initial deck
  EXPECT_NE(initialDeck, shuffledDeck);
}

TEST(GameTest, DeckIsDividedEqually) {
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");

  // Create a new game
  Game game(p1,p2);

  // Get the initial deck
  vector<Card> initialDeck = game.getDeck();

  // Shuffle the deck
  game.shuffleDeck();

  // Divide the deck equally between the two players
  game.divideDeck();

  // Get the piles of each player
  vector<Card> pile1 = p1.getPile();
  vector<Card> pile2 = p2.getPile();

  // Check that each pile has half of the cards in the initial deck
  EXPECT_EQ(pile1.size(), initialDeck.size() / 2);
  EXPECT_EQ(pile2.size(), initialDeck.size() / 2);
}

TEST(PlayerTest, DrawOneCard) {
  // Create a new player with their name
  Player p("Alice");

  // Create a new card
  Card c("Hearts", "Ace");

  // Add the card to the player's pile
  p.addCard(c);

  // Draw one card from the player's pile
  Card drawnCard = p.drawCard();

  // Check that the drawn card is equal to the added card
  EXPECT_EQ(drawnCard, c);
}

TEST(PlayerTest, DrawMultipleCards) {
  // Create a new player with their name
  Player p("Alice");

  // Create a new card
  Card c1("Hearts", "Ace");
  Card c2("Spades", "King");
  Card c3("Diamonds", "Queen");

  // Add the cards to the player's pile
  p.addCard(c1);
  p.addCard(c2);
  p.addCard(c3);

  // Draw two cards from the player's pile
  vector<Card> drawnCards = p.drawCards(2);

  // Check that the drawn cards are equal to the added cards
  EXPECT_EQ(drawnCards[0], c1);
  EXPECT_EQ(drawnCards[1], c2);
}
TEST(GameTest, PlayerWithHighestCardWins) {
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");

  // Create a new game
  Game game(p1,p2);

  // Add cards to the players' piles
  p1.addCard(Card("Hearts", "Ace"));
  p2.addCard(Card("Spades", "King"));

  // Play one turn
  game.playTurn();

  // Check that the player with the highest card wins
  EXPECT_EQ(game.getWinner(), &p1);
}

TEST(GameTest, DrawWithinADraw) {
  Player p1("Alice");
  Player p2("Bob");

  // Create a new game
  Game game(p1,p2);

  // Add cards to the players' piles
  p1.addCard(Card("Hearts", "Ace"));
  p2.addCard(Card("Spades", "Ace"));

  // Play one turn
  game.playTurn();

  // Add cards to the players' piles
  p1.addCard(Card("Hearts", "King"));
  p2.addCard(Card("Spades", "King"));

  // Play one turn
  game.playTurn();

  // Add cards to the players' piles
  p1.addCard(Card("Hearts", "Queen"));
  p2.addCard(Card("Spades", "Queen"));

  // Play one turn
  game.playTurn();

  // Check that there was a draw within a draw and that it counts as two draws
  EXPECT_EQ(game.getNumDraws(), 2);
}
TEST(PlayerTest, DrawFromEmptyPile) {
  // Create a new player with their name
  Player p("Alice");

  // Try to draw a card from an empty pile
  EXPECT_THROW(p.drawCard(), out_of_range);
}

TEST(GameTest, InvalidCardSuit) {
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");

  // Create a new game
  Game game(p1,p2);

  // Add an invalid card to the first player's pile
  p1.addCard(Card("Invalid", "Ace"));

  // Play one turn
  EXPECT_THROW(game.playTurn(), invalid_argument);
}

TEST(PlayerTest, AddCardToFullPile) {
  // Create a new player with their name
  Player p("Alice");

  // Add cards to the player's pile until it is full
  for (int i = 0; i < 52; i++) {
    p.addCard(Card("Hearts", "Ace"));
  }

  // Try to add another card to the full pile
  EXPECT_THROW(p.addCard(Card("Hearts", "King")), out_of_range);
}

TEST(GameTest, InvalidCardRank) {
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");

  // Create a new game
  Game game(p1,p2);

  // Add an invalid card to the first player's pile
  p1.addCard(Card("Hearts", "Invalid"));

  EXPECT_THROW(game.playTurn(), invalid_argument);
}
