#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <cassert> //assert
#include <cstddef> //NULL
#include <iostream>

template <typename T> class List {
  // OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
  List() : first(nullptr), last(nullptr), size_of(0) {}

  List(const List &rhs) : first(nullptr), last(nullptr), size_of(0) {
    copy_all(rhs);
  }

  List &operator=(const List &rhs) {
    if (this != &rhs) {
      clear();
      copy_all(rhs);
    }
    return *this;
  }

  ~List() { clear(); }

  // EFFECTS:  returns true if the list is empty
  bool empty() const { return first == nullptr; }

  // EFFECTS: returns the number of elements in this List
  // HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //          with a private member variable.  That's how std::list does it.
  int size() const { return size_of; }

  // REQUIRES: list is not empty
  // EFFECTS: Returns the first element in the list by reference
  T &front() { return first->datum; }

  // REQUIRES: list is not empty
  // EFFECTS: Returns the last element in the list by reference
  T &back() { return last->datum; }

  // EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    p->prev = nullptr;
    if (empty()) {
      first = last = p;
    } else {
      first->prev = p;
      p->next = first;
      first = p;
    }
    ++size_of;
  }

  // EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    p->prev = nullptr;
    if (empty()) {
      first = last = p;
    } else {
      p->prev = last;
      last->next = p;
      last = p;
    }
    ++size_of;
  }

  // REQUIRES: list is not empty
  // MODIFIES: may invalidate list iterators
  // EFFECTS:  removes the item at the front of the list
  void pop_front() {
    assert(!empty());
    Node *victim = first;
    if (first == last) {
      delete last;
      first = nullptr;
      last = nullptr;
      --size_of;
      return;
    }
    first = first->next;
    delete victim;
    first->prev = nullptr;
    --size_of;
  }

  // REQUIRES: list is not empty
  // MODIFIES: may invalidate list iterators
  // EFFECTS:  removes the item at the back of the list
  void pop_back() {
    assert(!empty());
    Node *victim_2 = last;
    if (first == last) {
      delete first;
      last = nullptr;
      first = nullptr;
      --size_of;
      return;
    }
    last = last->prev;
    delete victim_2;
    last->next = nullptr;
    --size_of;
  }

  // MODIFIES: may invalidate list iterators
  // EFFECTS:  removes all items from the list
  void clear() {
    while (!empty()) {
      pop_front();
    }
    first = last = nullptr;
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  // a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  // REQUIRES: list is empty
  // EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    for (Node *np = other.first; np; np = np->next) {
      push_back(np->datum);
    }
  }

  Node *first; // points to first Node in list, or nullptr if list is empty
  Node *last;  // points to last Node in list, or nullptr if list is empty
  int size_of;

public:
  ////////////////////////////////////////
  class Iterator {
    // OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator &operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

    Iterator &operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(Iterator rhs) const { return node_ptr == rhs.node_ptr; }

    bool operator!=(Iterator rhs) const { return node_ptr != rhs.node_ptr; }

    T &operator*() {
      assert(node_ptr);
      return node_ptr->datum;
    }

    Iterator() : node_ptr(nullptr) {}

  private:
    Node *node_ptr; // current Iterator position is a List node
                    // add any additional necessary member variables here

    Iterator(Node *node_ptr_in) : node_ptr(node_ptr_in) {}

    // add any friend declarations here
    friend class List;

    // construct an Iterator at a specific position

  }; // List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const { return Iterator(first); }

  // return an Iterator pointing to "past the end"
  Iterator end() const { return Iterator(); }

  // REQUIRES: i is a valid, dereferenceable iterator associated with this list
  // MODIFIES: may invalidate other list iterators
  // EFFECTS: Removes a single element from the list container

  void erase(Iterator i) {
    Node *victim_3 = i.node_ptr;
    Node *r = i.node_ptr;
    Node *s = r->prev;
    Node *n = r->next;
    if (s == nullptr) {
      pop_front();
      return;
    }
    if (n == nullptr) {
      pop_back();
      return;
    }
    s->next = n;
    n->prev = s;
    delete victim_3;
    --size_of;
  }

  // REQUIRES: i is a valid iterator associated with this list
  // EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
    // Node *victim_4 = i.node_ptr;
    Node *r = i.node_ptr;
    if (r == nullptr) {
      push_back(datum);
      return;
    }

    if (r->prev == nullptr) {
      push_front(datum);
      return;
    }

    Node *s = r->prev;
    Node *n = new Node;
    n->next = i.node_ptr;
    n->prev = s;
    n->datum = datum;

    s->next = n;
    r->prev = n;
    ++size_of;
  }

}; // List

////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.

#endif // Do not remove this. Write all your code above this line.
