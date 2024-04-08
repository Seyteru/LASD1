
namespace lasd {

    template <typename Data>
    bool Exists(Data val){
        bool exists = false;
        Traverse(
            [val, &exists](const Data &data){
                exists = exists || (data == val)
            }
        );
        return exists;
        
    }

}
