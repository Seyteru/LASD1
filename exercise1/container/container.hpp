
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...

  /* ************************************************************************ */
  ulong size = 0;
  // Default constructor
  // Container() specifiers;
  Container() = default;

public:

  // Destructor
  // ~Container() specifiers
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  Container &operator=(const Container &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  Container &operator=(Container &&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const Container &) noexcept = delete;
  bool operator!=(const Container &) noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  // Vedere se conviene definirlo o farlo puro.
  virtual bool Empty() const noexcept = 0;

  // type Size() specifiers; // (concrete function should not throw exceptions)
  // Vedere se conviene definirlo o farlo puro.
  virtual ulong Size() const noexcept = 0;
};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
  ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ClearableContainer &operator=(const ClearableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ClearableContainer &operator=(ClearableContainer &&)noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer &) noexcept = delete;
  bool operator!=(const ClearableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  // Vedere se conviene definirlo o farlo puro.
  virtual void Clear(){
    size = 0;
  }

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResizableContainer() specifiers
  ~ResizableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResizableContainer &operator=(const ResizableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResizableContainer &operator=(ResizableContainer &&) = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ResizableContainer &) noexcept = delete;
  bool operator!=(const ResizableContainer &) noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
  // Vedere se conviene definirlo o farlo puro.
  virtual void Resize(ulong resize){
    size = resize; 
  }
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  // Forse non necessario perche definito in container
  virtual void Clear() override{
    Resize(0);
  };

};

/* ************************************************************************** */

}

#endif
