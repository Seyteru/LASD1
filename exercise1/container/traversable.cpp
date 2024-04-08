
namespace lasd {

    template <typename Data>
    bool Exists(Data val){
        bool exists = false;
        Traverse(
            [val, &exists](const Data &data){
                exists = exists || (data == val);
            }
        );
        return exists;
    }

    template <typename Accumulator>
    Accumulator Fold(FoldFun<Accumulator> foldFun, Accumulator acc){
        Traverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

    template <typename Accumulator>
    Accumulator PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc){
        PreOrderTraverse(
            [foldFun, &acc](const Data &data){
                acc = foldFun(data, acc);
            }
        );
        return acc;
    }

}