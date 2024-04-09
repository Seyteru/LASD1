#include "traversable.hpp"

namespace lasd {

    template <typename Data>
    inline bool TraversableContainer<Data>::Exists(const Data &val)const noexcept{
        bool exists = false;
        Traverse(
            [val, &exists](const Data &data){
                exists = exists || (data == val);
            }
        );
        return exists;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator acc){
        Traverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        PreOrderTraverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

}