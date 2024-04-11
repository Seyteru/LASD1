
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer, virtual public LinearContainer<Data>{
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  Data *elements = nullptr;
  // ...

public:

  // Default constructor
  // Vector() specifiers;
  
  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
  // Vector(argument) specifiers; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;

  // Move constructor
  // Vector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;
  bool operator==(const Vector &) const noexcept;
  bool operator!=(const Vector &) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;
  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  void Resize(const ulong) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  const Data &operator[](const ulong) const override;
  Data &operator[](const ulong) override;
  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  const Data &Front() const override;
  Data &Front() override;
  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  const Data &Back() const override;
  Data &Back() override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data>, virtual public SortableLinearContainer<Data>{
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  // SortableVector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; // A vector with a given initial dimension
  // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // SortableVector(argument) specifiers;

  // Move constructor
  // SortableVector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~SortableVector() specifiers;
  ~SortableVector() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
