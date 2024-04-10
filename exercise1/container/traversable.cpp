namespace lasd {

    template <typename Data>
    bool TraversableContainer<Data>::Exists(const Data &val) const noexcept{
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
    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator acc){
        Traverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        PreOrderTraverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun){
        PreOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        PostOrderTraverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun){
        PostOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        InOrderTraverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun traverseFun){
        InOrderTraverse(traverseFun);
    }

    template <typename Data>
    template <typename Accumulator>
    Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        BreadthFold(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Data>
    inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun traverseFun){
        BreadthTraverse(traverseFun);
    }

}