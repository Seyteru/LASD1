
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>,virtual public PostOrderMappableContainer<Data>{
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~LinearContainer() specifiers
  virtual ~LinearContainer() = delete;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  LinearContainer &operator=(const LinearContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  LinearContainer &operator=(LinearContainer &&) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(const LinearContainer &) noexcept = delete;
  bool operator!=(const LinearContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
  virtual const Data &operator[](const ulong) = 0;
  virtual Data &operator[](const ulong) = 0;
  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual const Data &Front() = 0;
  virtual Data &Front() = 0;
  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual const Data &Back() = 0;
  virtual Data &Back() = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;
  // type Traverse(argument) specifiers; // Override TraversableContainer member
  virtual void Traverse(TraverseFun) override = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member
  virtual void PreOrderTraverse(TraverseFun) override = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member
  virtual void PostOrderTraverse(TraverseFun) override = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  virtual void PreOrderMap(MapFun) override = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  virtual void PreOrderMap(MapFun) override = 0;
};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data>{
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~SortableLinearContainer() specifiers
  virtual ~SortableLinearContainer() = delete;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  SortableLinearContainer &operator=(const SortableLinearContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not be possible.
  SortableLinearContainer &operator=(SortableLinearContainer &&) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(const SortableLinearContainer &) noexcept = delete;
  bool operator!=(const SortableLinearContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;
  virtual void Sort() = 0;
protected:

  // Auxiliary member functions

  // ...

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
