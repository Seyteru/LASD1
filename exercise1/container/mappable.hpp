
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MappableContainer() specifiers
  virtual ~MappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  MappableContainer &operator=(const MappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  MappableContainer &operator=(MappableContainer &&) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const MappableContainer &) noexcept = delete;
  bool operator!=(const MappableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using MapFun = std::function<void(Data &)>;
  using MapFun = std::function<void(Data &)>;
  // type Map(argument) specifiers;
  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PreOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderMappableContainer() specifiers
  virtual ~PreOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PreOrderMappableContainer &) noexcept = delete;
  bool operator!=(const PreOrderMappableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual Map(MapFun) override = 0;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderMappableContainer() specifiers
  virtual ~PostOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PostOrderMappableContainer &) noexcept = delete;
  bool operator!=(const PostOrderMappableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type PostOrderMap(argument) specifiers;
  virtual void PostOrderMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override = 0;
};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>, virtual public InOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             InOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers
  virtual ~InOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  InOrderMappableContainer &operator=(const InOrderMappableContainer &) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const InOrderMappableContainer &) noexcept = delete;
  bool operator!=(const InOrderMappableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type InOrderMap(argument) specifiers;
  virtual void InOrderMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override = 0;
};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>, virtual public BreadthTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers
  virtual ~BreadthMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  BreadthMappableContainer &operator=(const BreadthMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  BreadthMappableContainer &operator=(const BreadthMappableContainer &) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const BreadthMappableContainer &) noexcept = delete;
  bool operator!=(const BreadthMappableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type BreadthMap(argument) specifiers;
  virtual void BreadthMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override = 0;
};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
