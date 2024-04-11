#include "vector.hpp"

namespace lasd {

    //Specific Constructors.
    template <typename Data>
    Vector<Data>::Vector(const ulong newsize){
        size = newsize;
        elements = new Data[size]{};
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> &container){
        ulong index = 0;
        container.Traverse(
            [this, &index](const Data &dat){
                elements[index++] = dat;
            }
        )
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data> &&container){
        ulong index = 0;
        container.Map(
            [this, &index](Data &dat){
                elements[index++] = std::move(dat);
            }
        )
    }

    template <typename Data>
    Vector<Data>::Vector(const Vector<Data> &vect){
        size = vect.size;
        elements = new Data[size];
        std::copy(vect.elements, vect.elements + size, elements);
    }

    template <typename Data>
    Vector<Data>::Vector(Vector<Data> &&vect) noexcept{
        std::swap(size, vect.size);
        std::swap(elements, vect.elements)
    }

    template <typename Data>
    Vector<Data>::~Vector()
    {
        delete[] elements;
    }

    template <typename Data>
    Vector<Data> &Vector<Data>::operator=(const Vector &vect) noexcept{
        Vector<Data> *tempVector = new Vector<Data>(vect);
        std::swap(*tempVector, *this);
        delete *tempVector;
        return *this;
    }

    //Comparison Operator

    template <typename Data>
    bool Vector<Data>::operator==(const Vector &) const noexcept{
        
    }

}
