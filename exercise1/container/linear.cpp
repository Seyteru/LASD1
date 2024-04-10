#include "linear.hpp"
namespace lasd {

//  Da Rivedere le traverse e map, il Sort, e se size viene visto o bisogna chiamare Size()

    template <typename Data>
    inline const Data& LinearContainer<Data>::Front() const{
        return operator[] (0);
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Front(){
        return operator[] (0);
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Back() const{
        return operator[] (size-1);
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back(){
        return operator[] (size-1);
    }

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun traverseFun){
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun){
        for(ulong index = 0; index < size; ++index){
            traverseFun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun){
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
        for(ulong index; index < size; ++index){
            mapFun(operator[](index));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun mapFun){
        ulong index = size;
        while(index > 0){
            mapFun(operator[](--index))
        }
    }

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept{
        QuickSort();
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r){
        if(p < r){
            ulong q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q+1, r);
        }
    }

}
