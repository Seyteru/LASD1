
namespace lasd {

    template <typename Data>
    inline const Data &StackLst<Data>::Top() const{
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data &StackLst<Data>::Top(){
        return List<Data>::Front();
    }

    template <typename Data>
    inline void StackLst<Data>::Pop(){
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    inline Data StackLst<Data>::TopNPop(){
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    inline void StackLst<Data>::Push(const Data &data){
        return List<Data>::InsertAtFront(data);
    }

    template <typename Data>
    inline void StackLst<Data>::Push(Data &&data){
        return List<Data>::InsertAtFront(data);
    }

}
