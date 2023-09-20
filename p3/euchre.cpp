// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Card.h"
#include "Pack.h"
#include "Player.h"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game {
private:
  Card upcard;
  vector<Player *> players = {};
  Pack pack;
  int points_to_win;
  int dealer_index = 0;
  string order_up_suit;
  // Team 1: Players 0 and 2.
  // Team 2: Players 1 and 3.
  int ordered_up_team;
  // counter for teams 1 and 2
  int team_1_pts_ctr = 0;
  int team_2_pts_ctr = 0;
  int previous_trick_taker = 1;
  bool shuffle = false;

public:
  // FINISHED
  Game(char *argv[]) {
    players.push_back(Player_factory(argv[4], argv[5]));
    players.push_back(Player_factory(argv[6], argv[7]));
    players.push_back(Player_factory(argv[8], argv[9]));
    players.push_back(Player_factory(argv[10], argv[11]));
    points_to_win = atoi(argv[3]);
  }

  // FINISHED
  void init_pack(ifstream &pack_input, bool shuffle_arg) {
    Pack input(pack_input);
    pack = input;
    shuffle = shuffle_arg;
    if (shuffle_arg) {
      pack.shuffle();
    }
  }

  void deal_card() {
    for (int i = dealer_index + 1; i < dealer_index + 5; i += 2) {
      for (int j = 0; j < 3; j++) {
        players[i % 4]->add_card(pack.deal_one());
      }
      for (int j = 0; j < 2; j++) {
        players[(i + 1) % 4]->add_card(pack.deal_one());
      }
    }
    for (int i = dealer_index + 1; i < dealer_index + 5; i += 2) {
      for (int j = 0; j < 2; j++) {
        players[i % 4]->add_card(pack.deal_one());
      }
      for (int j = 0; j < 3; j++) {
        players[(i + 1) % 4]->add_card(pack.deal_one());
      }
    }
  }

  void order_up() {
    upcard = pack.deal_one();
    cout << upcard << " turned up\n";
    Player *p;
    // round 1
    for (int i = (dealer_index + 1); i < (dealer_index + 5); i++) {
      bool is_dealer = false;
      p = players[i % 4];
      if (i % 4 == dealer_index) {
        is_dealer = true;
      } else {
        is_dealer = false;
      }
      if (p->make_trump(upcard, is_dealer, 1, order_up_suit)) {
        if (i % 4 == 0 || i % 4 == 2) {
          ordered_up_team = 1;
        } else if (i % 4 == 1 || i % 4 == 3) {
          ordered_up_team = 2;
        }
        cout << *p << " orders up " << order_up_suit << "\n";
        players[dealer_index]->add_and_discard(upcard);
        cout << "\n\n";
        return;
      } else {
        cout << *p << " passes\n";
      }
    }

    for (int i = dealer_index + 1; i < (dealer_index + 5); i++) {
      p = players[i % 4];
      bool is_dealer = false;
      if (i % 4 == dealer_index) {
        is_dealer = true;
      } else {
        is_dealer = false;
      }
      if (p->make_trump(upcard, is_dealer, 2, order_up_suit)) {
        if (i % 4 == 0 || i % 4 == 2) {
          ordered_up_team = 1;
        } else if (i % 4 == 1 || i % 4 == 3) {
          ordered_up_team = 2;
        }
        cout << *p << " orders up " << order_up_suit << "\n\n";
        return;
      } else {
        cout << *p << " passes\n";
      }
    }
  }

  void play_trick() {
    Player *current_player;
    Card led_card;
    Card played_card;
    //?
    Card maximum_card;

    int trick_taker_index = previous_trick_taker;
    Player *leader = players[(size_t)trick_taker_index];

    led_card = leader->lead_card(order_up_suit);
    maximum_card = led_card;
    cout << led_card << " led by " << *leader << "\n";

    for (int i = previous_trick_taker + 1; i < (previous_trick_taker + 4);
         i++) {
      int player_index = i % 4;
      current_player = players[player_index];
      played_card = current_player->play_card(led_card, order_up_suit);
      cout << played_card << " played by " << *current_player << "\n";
      // find maximum card and the winner
      if (Card_less(maximum_card, played_card, led_card, order_up_suit)) {
        trick_taker_index = i % 4;
        maximum_card = played_card;
      }
    }
    previous_trick_taker = trick_taker_index;
    cout << *players[trick_taker_index] << " takes the trick\n\n";
  }

  void play_hand() {
    int team1_tricks_won = 0;
    int team2_tricks_won = 0;

    for (int i = 1; i < 6; i++) {
      play_trick();
      if (previous_trick_taker == 0 || previous_trick_taker == 2) {
        team1_tricks_won++;
      } else if (previous_trick_taker == 1 || previous_trick_taker == 3) {
        team2_tricks_won++;
      }
    }

    if (team1_tricks_won > team2_tricks_won) {
      cout << *players[0] << " and " << *players[2] << " win the hand\n";
      if (ordered_up_team == 1) {
        if (team1_tricks_won == 3 || team1_tricks_won == 4) {
          team_1_pts_ctr += 1;
        } else if (team1_tricks_won == 5) {
          team_1_pts_ctr += 2;
          cout << "march!\n";
        }
      } else {
        if (team1_tricks_won > 2) {
          team_1_pts_ctr += 2;
          cout << "euchred!\n";
        }
      }
    } else {
      cout << *players[1] << " and " << *players[3] << " win the hand\n";
      if (ordered_up_team == 2) {
        if (team2_tricks_won == 3 || team2_tricks_won == 4) {
          team_2_pts_ctr += 1;
        } else if (team2_tricks_won == 5) {
          team_2_pts_ctr += 2;
          cout << "march!\n";
        }
      } else {
        if (team2_tricks_won > 2) {
          team_2_pts_ctr += 2;
          cout << "euchred!\n";
        }
      }
    }
  }

  void play_hands() {
    for (int hand = 0;
         team_1_pts_ctr < points_to_win && team_2_pts_ctr < points_to_win;
         hand++) {
      cout << "Hand " << hand << "\n";
      cout << *players[dealer_index] << " deals\n";
      deal_card();
      order_up();
      play_hand();
      cout << *players[0] << " and " << *players[2] << " have ";
      cout << team_1_pts_ctr << " points\n";
      cout << *players[1] << " and " << *players[3] << " have ";
      cout << team_2_pts_ctr << " points\n\n";
      dealer_index = (dealer_index + 1) % 4;
      if (shuffle) {
        pack.shuffle();
      } else {
        pack.reset();
      }
      previous_trick_taker = (dealer_index + 1) % 4;
    }
    if (team_1_pts_ctr > team_2_pts_ctr) {
      cout << *players[0] << " and " << *players[2] << " win!\n";
    } else {
      cout << *players[1] << " and " << *players[3] << " win!\n";
    }
    delete players[0];
    delete players[1];
    delete players[2];
    delete players[3];
  }
};

// HELPER FUNCS FOR MAIN BEGIN
//==================================================================

void error_msg() {
  cout << "Usage: euchre.exe pack_input_FILENAME [shuffle_arg|noshuffle_arg] "
       << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
       << "NAME4 TYPE4" << endl;
}

//==================================================================
// HELPER FUNCS FOR MAIN END

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << " ";
  }
  cout << "\n";
  bool shuffle_arg = false;
  if (argc != 12) {
    error_msg();
    return 1;
  }
  int points_to_win = atoi(argv[3]);
  if (points_to_win < 1 || points_to_win > 100) {
    error_msg();
    return 1;
  }

  if (string(argv[2]) == "shuffle") {
    shuffle_arg = true;
  } else if (string(argv[2]) == "noshuffle") {
    shuffle_arg = false;
  } else {
    error_msg();
    return 1;
  }

  if (string(argv[5]) != "Simple" && string(argv[5]) != "Human") {
    error_msg();
    return 1;
  }
  if (string(argv[7]) != "Simple" && string(argv[7]) != "Human") {
    error_msg();
    return 1;
  }
  if (string(argv[9]) != "Simple" && string(argv[9]) != "Human") {
    error_msg();
    return 1;
  }
  if (string(argv[11]) != "Simple" && string(argv[11]) != "Human") {
    error_msg();
    return 1;
  }

  ifstream pack_input;
  pack_input.open(argv[1]);
  if (!pack_input.is_open()) {
    cout << "Error opening " << argv[1] << endl;
    return 1;
  }
  Game game(argv);
  game.init_pack(pack_input, shuffle_arg);
  game.play_hands();
}