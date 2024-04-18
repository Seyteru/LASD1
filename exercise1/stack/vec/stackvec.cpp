#include "stackvec.hpp"

namespace lasd {    

    template <typename Data>
    inline StackVec<Data>::StackVec(const TraversableContainer<Data> &container) : Vector<Data>::Vector(container){
        index = container.Size() - 1;
    }

    template <typename Data>
    StackVec<Data>::StackVec(MappableContainer<Data> &&container){

    }

    template <typename Data>
    StackVec<Data>::StackVec(const StackVec<Data> &stackVec) : Vector<Data>(stackVec){
        index = stackVec.index;
    }

    template <typename Data>
    StackVec<Data>::StackVec(StackVec<Data> &&stackVec) noexcept{
        std::swap(elements, stackVec.elements);
        std::swap(index, stackVec.index);
        std::swap(size, stackVec.size);
    }

    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(const StackVec &stackVec){
        Vector<Data>::operator=(stackVec);
        index = stackVec.index;
        return *this;
    }

    template <typename Data>
    StackVec<Data> &StackVec<Data>::operator=(StackVec &&stackVec) noexcept{
        Vector<Data>::operator=(std::move(stackVec));
        std::swap(index, stackVec.index);
        return *this;
    }

    template <typename Data>
    bool StackVec<Data>::operator==(const StackVec &stackVec) const noexcept{
        return false;
    }

    template <typename Data>
    bool StackVec<Data>::operator!=(const StackVec &stackVec) const noexcept{
        return false;
    }

    template <typename Data>
    const Data &StackVec<Data>::Top() const
    {
        if(index != 0){
            return elements[index - 1];
        } else{
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    template <typename Data>
    Data &StackVec<Data>::Top(){
        if(index != 0){
            return elements[index - 1];
        } else{
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    template <typename Data>
    void StackVec<Data>::Pop(){
        if(index != 0){
            //Reduce();
        } else{
            throw std::length_error("Invalid Access to an Empty Stack ");
        }
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop(){
        
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data &data){
        
    }

    template <typename Data>
    void StackVec<Data>::Push(Data &&data) noexcept{
        
    }

    template <typename Data>
    bool StackVec<Data>::Empty() const noexcept{
        return false;
    }
    
    template <typename Data>
    ulong StackVec<Data>::Size() const noexcept{
        return ulong();
    }

    template <typename Data>
    void StackVec<Data>::Clear(){

    }

    template <typename Data>
    void StackVec<Data>::Resize(){

    }

    template <typename Data>
    void StackVec<Data>::Reduce(){

    }

}
