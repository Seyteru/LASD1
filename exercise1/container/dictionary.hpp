
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : TestableContainer<Data>{
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers
  virtual ~DictionaryContainer() = delete;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  DictionaryContainer &operator=(const DictionaryContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  DictionaryContainer &operator=(DictionaryContainer &&) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const DictionaryContainer &) noexcept = delete;
  bool operator!=(const DictionaryContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  // type Insert(argument) specifiers; // Move of the value
  // type Remove(argument) specifiers;
  virtual bool Insert(const Data &) = 0;
  virtual bool Insert(Data &&) noexcept = 0;
  virtual bool Remove(Data &&) = 0;
  // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
  // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
  // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
  virtual bool InsertAll(const TraversableContainer<Data> &);
  virtual bool InsertAll(MappableContainer<Data> &&);
  virtual bool RemoveAll(const TraversableContainer<Data> &);
  // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
  // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
  // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
  virtual bool InsertSome(const TraversableContainer<Data> &);
  virtual bool InsertSome(MappableContainer<Data> &&);
  virtual bool RemoveSome(const TraversableContainer<Data> &);
};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
