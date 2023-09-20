// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Pack.h"
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

// EFFECTS: Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function

Pack::Pack() {
  next = 0;
  for (int i = 0; i < NUM_SUITS; i++) {
    for (int j = 7; j < NUM_RANKS; j++) {
      cards[next++] = Card(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
    }
  }
  next = 0;
}

// REQUIRES: pack_input contains a representation of a Pack in the
//           format required by the project specification
// MODIFIES: pack_input
// EFFECTS: Initializes Pack by reading from pack_input.

Pack::Pack(std::istream &pack_input) {
  string rank;
  string suit;
  string of;
  for (int i = 0; i < PACK_SIZE; i++) {
    pack_input >> rank >> of >> suit;
    cards[i] = Card(rank, suit);
  }
  next = 0;
}

// REQUIRES: cards remain in the Pack
// EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one() { return cards[next++]; }

// EFFECTS: Resets next index to first card in the Pack
void Pack::shuffle() {
  std::array<Card, PACK_SIZE> shuffle;
  int t = 0;
  while (t < 7) {
    int k = 0;
    for (int i = 0, j = 12; k < PACK_SIZE; ++i, ++j) {
      shuffle[k] = cards[j];
      shuffle[k + 1] = cards[i];
      k += 2;
    }
    cards = shuffle;
    t++;
  }
  next = 0;
}

void Pack::reset() { next = 0; }

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const {
  if (next >= PACK_SIZE) {
    return true;
  } else {
    return false;
  }
}