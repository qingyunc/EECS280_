// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
  Player *alice = Player_factory("Alice", "Simple");
  ASSERT_EQUAL("Alice", alice->get_name());
  delete alice;
}

// Add more tests here

// Finished
TEST(get_name_1) {

  Player *player1 = Player_factory("player1", "Simple");
  ASSERT_EQUAL("player1", player1->get_name());

  delete player1;

  Player *player_ = Player_factory("player_", "Simple");
  ASSERT_EQUAL("player_", player_->get_name());

  delete player_;

  Player *player2 = Player_factory("Player2", "Human");
  ASSERT_EQUAL("Player2", player2->get_name());

  delete player2;
}

// Finished
TEST(add_card_1) {

  Player *player1 = Player_factory("player1", "Simple");

  // Player* Player4 = Player_factory("player4", "Simple");
  // Player* Player5 = Player_factory("player5", "Simple");

  Card card1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
  Card card2(Card::RANK_JACK, Card::SUIT_HEARTS); //
  Card card3(Card::RANK_KING, Card::SUIT_DIAMONDS);
  Card card4(Card::RANK_QUEEN, Card::SUIT_HEARTS);
  Card card5(Card::RANK_NINE, Card::SUIT_DIAMONDS);
  //
  Card card10(Card::RANK_THREE, Card::SUIT_CLUBS);

  player1->add_card(card1);
  player1->add_card(card2);
  player1->add_card(card3);
  player1->add_card(card4);
  player1->add_card(card5);

  // TODO:
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS), card1);
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_DIAMONDS), card4);         // card2
  ASSERT_EQUAL(player1->play_card(card10, Card::SUIT_DIAMONDS), card5); //
  delete player1;
}

TEST(add_card_2) {
  Player *Player2 = Player_factory("player2", "Simple");

  Card card6(Card::RANK_JACK, Card::SUIT_SPADES);
  Card card7(Card::RANK_KING, Card::SUIT_SPADES);
  Card card8(Card::RANK_QUEEN, Card::SUIT_SPADES);
  Card card9(Card::RANK_ACE, Card::SUIT_SPADES);
  Card card10(Card::RANK_NINE, Card::SUIT_CLUBS);

  Player2->add_card(card6);
  Player2->add_card(card7);
  Player2->add_card(card8);
  Player2->add_card(card9);
  Player2->add_card(card10);
  ASSERT_EQUAL(Player2->lead_card(Card::SUIT_CLUBS), card9)
  delete Player2;
}

TEST(add_card_3)

{
  Player *player3 = Player_factory("player3", "Simple");

  Card card3(Card::RANK_KING, Card::SUIT_DIAMONDS);
  Card card6(Card::RANK_JACK, Card::SUIT_SPADES);
  Card card7(Card::RANK_KING, Card::SUIT_SPADES);
  Card card8(Card::RANK_QUEEN, Card::SUIT_SPADES);
  Card card9(Card::RANK_ACE, Card::SUIT_SPADES);

  player3->add_card(card6);
  player3->add_card(card7);
  player3->add_card(card8);
  player3->add_card(card9);
  player3->add_card(card3);

  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), card9)
  delete player3;
}

TEST(add_card_4_and_5) {
  Player *player4 = Player_factory("player4", "Simple");
  Player *player5 = Player_factory("player5", "Simple");

  Card card11(Card::RANK_NINE, Card::SUIT_SPADES);
  Card card12(Card::RANK_TEN, Card::SUIT_SPADES);
  Card card13(Card::RANK_JACK, Card::SUIT_SPADES);
  Card card14(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card card15(Card::RANK_NINE, Card::SUIT_DIAMONDS);
  Card card16(Card::RANK_KING, Card::SUIT_SPADES);
  Card card17(Card::RANK_ACE, Card::SUIT_SPADES);

  player4->add_card(card11);
  player4->add_card(card12);
  player4->add_card(card13);
  player4->add_card(card14);
  player4->add_card(card15);
  ASSERT_EQUAL(player4->play_card(card11, Card::SUIT_DIAMONDS), card13);

  player5->add_card(card11);
  player5->add_card(card12);
  player5->add_card(card13);
  player5->add_card(card16);
  player5->add_card(card17);

  ASSERT_EQUAL(player5->play_card(card11, Card::SUIT_DIAMONDS), card17);

  delete player4;
  delete player5;
}

// Finished
TEST(make_trump) {
  // 5
  // round 1
  // upcard->trump
  string order_up_suit;
  // trump face >= 2

  // round 2
  // is dealer

  Player *player1 = Player_factory("player1", "Simple");
  Card card1(Card::RANK_ACE, Card::SUIT_HEARTS);
  Card card2(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card card3(Card::RANK_KING, Card::SUIT_HEARTS);
  Card card4(Card::RANK_QUEEN, Card::SUIT_SPADES);
  Card card5(Card::RANK_THREE, Card::SUIT_SPADES);
  Card card6(Card::RANK_THREE, Card::SUIT_HEARTS);
  string a = Card::SUIT_HEARTS;

  player1->add_card(card1);
  player1->add_card(card2);
  player1->add_card(card3);
  player1->add_card(card4);
  player1->add_card(card5);

  ASSERT_TRUE(player1->make_trump(card6, false, 1, a));

  delete player1;

  string b = Card::SUIT_HEARTS;
  Player *player2 = Player_factory("player2", "Simple");
  Card card7(Card::RANK_THREE, Card::SUIT_SPADES);
  Card card8(Card::RANK_FOUR, Card::SUIT_SPADES);
  Card card9(Card::RANK_FIVE, Card::SUIT_SPADES);
  Card card10(Card::RANK_KING, Card::SUIT_HEARTS);
  Card card11(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  //
  Card card12(Card::RANK_THREE, Card::SUIT_HEARTS);

  player2->add_card(card7);
  player2->add_card(card8);
  player2->add_card(card9);
  player2->add_card(card10);
  player2->add_card(card11);

  ASSERT_TRUE(player2->make_trump(card12, false, 1, b));

  delete player2;

  Player *player3 = Player_factory("player3", "Simple");
  string c = Card::SUIT_HEARTS;
  Card card13(Card::RANK_THREE, Card::SUIT_SPADES);
  Card card14(Card::RANK_FOUR, Card::SUIT_SPADES);
  Card card15(Card::RANK_FIVE, Card::SUIT_SPADES);
  Card card16(Card::RANK_KING, Card::SUIT_DIAMONDS);
  Card card17(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  Card card18(Card::RANK_THREE, Card::SUIT_HEARTS);

  player3->add_card(card13);
  player3->add_card(card14);
  player3->add_card(card15);
  player3->add_card(card16);
  player3->add_card(card17);

  ASSERT_FALSE(player3->make_trump(card18, false, 1, c));
  ASSERT_TRUE(player3->make_trump(card18, false, 2, c));
  ASSERT_TRUE(player3->make_trump(card18, true, 2, c));

  delete player3;

  Player *player4 = Player_factory("player4", "Simple");
  string d = Card::SUIT_HEARTS;
  Card card19(Card::RANK_THREE, Card::SUIT_SPADES);
  Card card20(Card::RANK_FOUR, Card::SUIT_SPADES);
  Card card21(Card::RANK_FIVE, Card::SUIT_SPADES);
  Card card22(Card::RANK_SIX, Card::SUIT_SPADES);
  Card card23(Card::RANK_SEVEN, Card::SUIT_SPADES);
  Card card24(Card::RANK_THREE, Card::SUIT_HEARTS);

  player4->add_card(card19);
  player4->add_card(card20);
  player4->add_card(card21);
  player4->add_card(card22);
  player4->add_card(card23);

  ASSERT_FALSE(player4->make_trump(card24, false, 1, d));
  ASSERT_FALSE(player4->make_trump(card24, false, 2, d));
  ASSERT_TRUE(player4->make_trump(card24, true, 2, d));

  delete player4;
}

// Working on

TEST(add_discard1) {
  Player *player1 = Player_factory("player1", "Simple");

  Card SPADE_10(Card::RANK_TEN, Card::SUIT_SPADES);
  Card SPADE_JACK(Card::RANK_JACK, Card::SUIT_SPADES);
  Card SPADE_QUEEN(Card::RANK_QUEEN, Card::SUIT_SPADES);
  Card SPADE_KING(Card::RANK_KING, Card::SUIT_SPADES);
  Card SPADE_ACE(Card::RANK_ACE, Card::SUIT_SPADES);

  Card HEART_NINE(Card::RANK_NINE, Card::SUIT_HEARTS);

  player1->add_card(SPADE_10);
  player1->add_card(SPADE_JACK);
  player1->add_card(SPADE_QUEEN);
  player1->add_card(SPADE_KING);
  player1->add_card(SPADE_ACE);

  player1->add_and_discard(HEART_NINE); //

  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS), SPADE_ACE)
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS), SPADE_KING)
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS), SPADE_QUEEN)
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS), HEART_NINE) //
  ASSERT_EQUAL(player1->lead_card(Card::SUIT_CLUBS),
               SPADE_JACK) // left bowl the trump card

  delete player1;
}

TEST(add_discard2) {
  Player *player2 = Player_factory("player2", "Simple");

  Card HEART_JACK(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card SPADE_9(Card::RANK_NINE, Card::SUIT_SPADES);
  Card SPADE_10(Card::RANK_TEN, Card::SUIT_SPADES);
  Card SPADE_JACK(Card::RANK_JACK, Card::SUIT_SPADES);
  Card SPADE_QUEEN(Card::RANK_QUEEN, Card::SUIT_SPADES);

  Card HEART_KING(Card::RANK_KING, Card::SUIT_HEARTS);

  player2->add_card(HEART_JACK);
  player2->add_card(SPADE_9);
  player2->add_card(SPADE_10);
  player2->add_card(SPADE_JACK);
  player2->add_card(SPADE_QUEEN);

  player2->add_and_discard(HEART_KING);

  ASSERT_EQUAL(player2->lead_card(Card::SUIT_CLUBS), HEART_KING);
  ASSERT_EQUAL(player2->lead_card(Card::SUIT_CLUBS), SPADE_QUEEN);
  ASSERT_EQUAL(player2->lead_card(Card::SUIT_CLUBS),
               HEART_JACK); // no consider about the leading suit
  ASSERT_EQUAL(player2->lead_card(Card::SUIT_CLUBS), SPADE_10);
  ASSERT_EQUAL(player2->lead_card(Card::SUIT_CLUBS), SPADE_JACK); // trump
  delete player2;
}

TEST(add_discard3) {

  Player *player3 = Player_factory("player3", "Simple");
  Card HEART_JACK(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card DIAMOND_JACK(Card::RANK_JACK, Card::SUIT_DIAMONDS);
  Card SPADE_9(Card::RANK_NINE, Card::SUIT_SPADES);
  Card SPADE_10(Card::RANK_TEN, Card::SUIT_SPADES);
  Card SPADE_KING(Card::RANK_KING, Card::SUIT_SPADES);

  Card HEART_KING(Card::RANK_KING, Card::SUIT_HEARTS);

  player3->add_card(HEART_JACK);
  player3->add_card(DIAMOND_JACK);
  player3->add_card(SPADE_9);
  player3->add_card(SPADE_10);
  player3->add_card(SPADE_KING);

  player3->add_and_discard(HEART_KING);

  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), HEART_KING);
  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), SPADE_KING);
  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), DIAMOND_JACK);
  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), HEART_JACK);
  ASSERT_EQUAL(player3->lead_card(Card::SUIT_CLUBS), SPADE_10);
  delete player3;
}

TEST(add_discard4) {
  Player *player4 = Player_factory("player3", "Simple");
  Card HEART_JACK(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card HEART_QUEEN(Card::RANK_QUEEN, Card::SUIT_HEARTS);
  Card HEART_KING(Card::RANK_KING, Card::SUIT_HEARTS);
  Card HEART_TEN(Card::RANK_TEN, Card::SUIT_HEARTS);
  Card HEART_NINE(Card::RANK_NINE, Card::SUIT_HEARTS);

  Card HEART_ACE(Card::RANK_ACE, Card::SUIT_HEARTS);

  player4->add_card(HEART_NINE);
  player4->add_card(HEART_TEN);
  player4->add_card(HEART_JACK);
  player4->add_card(HEART_QUEEN);
  player4->add_card(HEART_KING);

  player4->add_and_discard(HEART_ACE);

  ASSERT_EQUAL(player4->lead_card(Card::SUIT_HEARTS), HEART_JACK); //
  ASSERT_EQUAL(player4->lead_card(Card::SUIT_HEARTS), HEART_ACE);
  ASSERT_EQUAL(player4->lead_card(Card::SUIT_HEARTS), HEART_KING);
  ASSERT_EQUAL(player4->lead_card(Card::SUIT_HEARTS), HEART_QUEEN);
  ASSERT_EQUAL(player4->lead_card(Card::SUIT_HEARTS), HEART_TEN);
  delete player4;
}

TEST(add_discard5) {
  Player *player5 = Player_factory("player3", "Simple");
  Card HEART_JACK(Card::RANK_JACK, Card::SUIT_HEARTS);
  Card HEART_QUEEN(Card::RANK_QUEEN, Card::SUIT_HEARTS);
  Card HEART_KING(Card::RANK_KING, Card::SUIT_HEARTS);
  Card HEART_TEN(Card::RANK_TEN, Card::SUIT_HEARTS);
  Card HEART_NINE(Card::RANK_NINE, Card::SUIT_HEARTS);

  Card DIAMON_JACK(Card::RANK_JACK, Card::SUIT_DIAMONDS);

  player5->add_card(HEART_NINE);
  player5->add_card(HEART_TEN);
  player5->add_card(HEART_JACK);
  player5->add_card(HEART_QUEEN);
  player5->add_card(HEART_KING);

  player5->add_and_discard(DIAMON_JACK);

  ASSERT_EQUAL(player5->lead_card(Card::SUIT_CLUBS), HEART_KING);
  ASSERT_EQUAL(player5->lead_card(Card::SUIT_CLUBS), HEART_QUEEN);
  ASSERT_EQUAL(player5->lead_card(Card::SUIT_CLUBS), DIAMON_JACK);
  ASSERT_EQUAL(player5->lead_card(Card::SUIT_CLUBS), HEART_JACK);
  ASSERT_EQUAL(player5->lead_card(Card::SUIT_CLUBS), HEART_TEN);
  delete player5;
}

TEST(simple_makeup) {
  Player *A = Player_factory("A", "Simple");
  string trump = Card::SUIT_SPADES;
  Card DIAMOND_3 = Card(Card::RANK_THREE, Card::SUIT_DIAMONDS);
  Card DIAMOND_4 = Card(Card::RANK_FOUR, Card::SUIT_DIAMONDS);
  Card DIAMOND_5 = Card(Card::RANK_FIVE, Card::SUIT_DIAMONDS);
  Card DIAMOND_6 = Card(Card::RANK_SIX, Card::SUIT_DIAMONDS);
  Card DIAMOND_7 = Card(Card::RANK_SEVEN, Card::SUIT_DIAMONDS);
  Card SPADE_4 = Card(Card::RANK_FOUR, Card::SUIT_SPADES);
  A->add_card(DIAMOND_3);
  A->add_card(DIAMOND_4);
  A->add_card(DIAMOND_5);
  A->add_card(DIAMOND_6);
  A->add_card(DIAMOND_7);
  ASSERT_FALSE(A->make_trump(SPADE_4, false, 1, trump));
  ASSERT_FALSE(A->make_trump(SPADE_4, false, 2, trump));
  ASSERT_TRUE(A->make_trump(SPADE_4, true, 2, trump));
  delete A;
}

TEST_MAIN()
