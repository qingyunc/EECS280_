// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>
using namespace std;

TEST(test_card_ctor) {
  Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
  ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
  ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

// Add more test cases here
TEST(constrctor) {
  Card KINGHEARTS = Card(Card::RANK_KING, Card::SUIT_HEARTS);
  ASSERT_EQUAL(KINGHEARTS.get_rank(), Card::RANK_KING);
  ASSERT_EQUAL(KINGHEARTS.get_suit(), Card::SUIT_HEARTS);
  ASSERT_EQUAL(KINGHEARTS.get_suit(Card::SUIT_DIAMONDS), Card::SUIT_HEARTS);

  Card THREE_CLUB = Card(Card::RANK_THREE, Card::SUIT_CLUBS);
  ASSERT_EQUAL(THREE_CLUB.get_rank(), Card::RANK_THREE);
  ASSERT_EQUAL(THREE_CLUB.get_suit(), Card::SUIT_CLUBS);
  ASSERT_EQUAL(THREE_CLUB.get_suit(Card::SUIT_SPADES), Card::SUIT_CLUBS);
}

TEST(test_is_face) {
  Card ACE = Card(Card::RANK_KING, Card::SUIT_HEARTS);
  ASSERT_EQUAL(ACE.is_face(), true);
  Card KING = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(KING.is_face(), true);
  Card QUEEN = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(QUEEN.is_face(), true);
  Card JACK = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(JACK.is_face(), true);
  Card FIVE = Card(Card::RANK_TWO, Card::SUIT_CLUBS);
  ASSERT_EQUAL(FIVE.is_face(), false);
}

TEST(is_left_bower) {
  Card card1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
  Card card2(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_FALSE(card1.is_left_bower(Card::SUIT_CLUBS));
  ASSERT_TRUE(card2.is_left_bower(Card::SUIT_DIAMONDS));
}

TEST(is_right_bower) {
  Card card1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
  Card card2(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_FALSE(card1.is_right_bower(Card::SUIT_HEARTS));
  ASSERT_TRUE(card2.is_right_bower(Card::SUIT_HEARTS));
}

TEST(Trump) {
  Card card1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
  Card card2(Card::RANK_JACK, Card::SUIT_HEARTS);
  ASSERT_FALSE(card1.is_trump(Card::SUIT_HEARTS));
  ASSERT_TRUE(card2.is_right_bower(Card::SUIT_HEARTS));
}

TEST(operator_1) {
  Card HEART_KING = Card(Card::RANK_KING, Card::SUIT_HEARTS);
  Card DIAMOND_QUEEN = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
  Card SPADE_5 = Card(Card::RANK_FIVE, Card::SUIT_SPADES);
  Card CLUBE_3 = Card(Card::RANK_THREE, Card::SUIT_CLUBS);
  Card DIAMOND_3 = Card(Card::RANK_THREE, Card::SUIT_DIAMONDS);
  Card CLUBE_KING = Card(Card::RANK_KING, Card::SUIT_CLUBS);
  Card CLUBE_KING2 = Card(Card::RANK_KING, Card::SUIT_CLUBS);

  ASSERT_TRUE(HEART_KING > DIAMOND_QUEEN);
  ASSERT_TRUE(DIAMOND_QUEEN >= DIAMOND_QUEEN);
  ASSERT_FALSE(HEART_KING < SPADE_5);
  ASSERT_TRUE(HEART_KING >= CLUBE_3);
  ASSERT_TRUE(DIAMOND_3 >= CLUBE_3);
  ASSERT_FALSE(HEART_KING <= DIAMOND_QUEEN);
  ASSERT_TRUE(CLUBE_KING == CLUBE_KING2);
  ASSERT_FALSE(HEART_KING == DIAMOND_QUEEN);
  ASSERT_TRUE(CLUBE_KING == CLUBE_KING2);
  ASSERT_FALSE(CLUBE_KING != CLUBE_KING2);
  ASSERT_TRUE(HEART_KING != DIAMOND_QUEEN);
}

TEST(Suit_next) {
  Card CLUBE_10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
  ASSERT_EQUAL(Suit_next(CLUBE_10.get_suit()), Card::SUIT_SPADES);
  Card DIAMOND_10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
  ASSERT_EQUAL(Suit_next(DIAMOND_10.get_suit()), Card::SUIT_HEARTS);
}
//
TEST(Card_less) {
  Card HEART_KING = Card(Card::RANK_KING, Card::SUIT_HEARTS);
  Card HEART_QUEEN = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
  Card HEART_JACK = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card DIAMOND_JACK = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  Card DIAMOND_QUEEN = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
  Card SPADE_10 = Card(Card::RANK_TEN, Card::SUIT_SPADES);
  Card CLUBE_10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
  Card CLUBE_9 = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
  Card DIAMOND_10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
  Card CLUBE_KING = Card(Card::RANK_KING, Card::SUIT_CLUBS);
  Card CLUBE_KING2 = Card(Card::RANK_KING, Card::SUIT_CLUBS);

  ASSERT_TRUE(Card_less(SPADE_10, CLUBE_10, Card::SUIT_DIAMONDS)); // same value

  ASSERT_FALSE(
      Card_less(SPADE_10, CLUBE_9, Card::SUIT_DIAMONDS)); // small value

  ASSERT_TRUE(Card_less(SPADE_10, DIAMOND_10, Card::SUIT_DIAMONDS)) // trump

  ASSERT_TRUE(
      Card_less(SPADE_10, HEART_JACK, Card::SUIT_DIAMONDS)); // left bowl

  ASSERT_TRUE(
      Card_less(HEART_KING, HEART_JACK, Card::SUIT_DIAMONDS)); //  left bowl

  ASSERT_FALSE(
      Card_less(HEART_KING, HEART_QUEEN, Card::SUIT_DIAMONDS)); // same color

  ASSERT_FALSE(Card_less(DIAMOND_QUEEN, HEART_QUEEN,
                         Card::SUIT_DIAMONDS)); // Trump and same color

  ASSERT_FALSE(Card_less(DIAMOND_JACK, HEART_JACK,
                         Card::SUIT_DIAMONDS)); // TWO biggest Card
}

TEST(Card_less2) {
  Card HEART_KING = Card(Card::RANK_KING, Card::SUIT_HEARTS);
  Card HEART_JACK = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card DIAMOND_QUEEN = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
  Card SPADE_5 = Card(Card::RANK_FIVE, Card::SUIT_SPADES);
  Card SPADE_4 = Card(Card::RANK_FOUR, Card::SUIT_SPADES);
  Card CLUBE_3 = Card(Card::RANK_THREE, Card::SUIT_CLUBS);
  Card CLUBE_2 = Card(Card::RANK_TWO, Card::SUIT_CLUBS);
  Card CLUBE_10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
  Card DIAMOND_3 = Card(Card::RANK_THREE, Card::SUIT_DIAMONDS);
  Card CLUBE_KING = Card(Card::RANK_KING, Card::SUIT_CLUBS);
  Card CLUBE_KING2 = Card(Card::RANK_KING, Card::SUIT_CLUBS);
  Card SPADE_10 = Card(Card::RANK_TEN, Card::SUIT_SPADES);
  Card CLUBE_9 = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
  Card DIAMOND_10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);

  Card HEART_QUEEN = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);

  Card DIAMOND_JACK = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);

  ASSERT_TRUE(Card_less(SPADE_5, CLUBE_3, CLUBE_2,
                        Card::SUIT_DIAMONDS)); // leading not trump

  ASSERT_TRUE(Card_less(SPADE_5, SPADE_10, CLUBE_2,
                        Card::SUIT_DIAMONDS)); // not leading not trump

  ASSERT_FALSE(
      Card_less(SPADE_5, CLUBE_3, CLUBE_2, Card::SUIT_SPADES)); // one of trump

  ASSERT_TRUE(Card_less(CLUBE_10, SPADE_5, SPADE_4,
                        Card::SUIT_DIAMONDS)); // leading not trump

  ASSERT_TRUE(Card_less(HEART_KING, HEART_JACK, CLUBE_3,
                        Card::SUIT_DIAMONDS)); // left bowl

  ASSERT_FALSE(Card_less(DIAMOND_JACK, HEART_JACK, CLUBE_3,
                         Card::SUIT_DIAMONDS)); // two jack

  ASSERT_FALSE(
      Card_less(DIAMOND_JACK, CLUBE_9, CLUBE_3, Card::SUIT_DIAMONDS)); // trump

  ASSERT_FALSE(Card_less(DIAMOND_JACK, DIAMOND_10, CLUBE_3,
                         Card::SUIT_DIAMONDS)); // two trump
}
TEST_MAIN()
