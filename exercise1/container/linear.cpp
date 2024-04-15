#include "linear.hpp"
namespace lasd {

    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const{
        return operator[](0);
    }

    template <typename Data>
    inline Data &LinearContainer<Data>::Front(){
        return operator[](0);
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Back() const{
        return operator[](size-1);
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back(){
        return operator[](size-1);
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun) const{
        for(ulong index = 0; index < size; ++index){
            traverseFun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun) const{
        ulong index = size;
        while(index > 0){
            traverseFun(operator[](--index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFun mapFun){
        for(ulong index = 0; index < size; ++index){
            mapFun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun mapFun){
        ulong index = size;
        while(index > 0){
            mapFun(operator[](--index));
        }
    }

    template <typename Data>
    ulong SortableLinearContainer<Data>::Partition(ulong start, ulong end) noexcept{
        Data pivotValue = (*this)[start];
        ulong pivotPosition = start;
        for(ulong position = start + 1; position <= end; ++position){
            if((*this)[position] < pivotValue){
                std::swap((*this)[pivotPosition + 1], (*this)[position]);
                std::swap((*this)[pivotPosition], (*this)[pivotPosition + 1]);
                pivotPosition++;
            }
        }
        return pivotPosition;
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong start, ulong end) noexcept{
        if(start < end){
            ulong partition = Partition(start, end);
            QuickSort(start, partition-1);
            QuickSort(partition+1, end);
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept{
        ulong start = 0;
        ulong end = size - 1; 
        QuickSort(start, end);
    }
}
