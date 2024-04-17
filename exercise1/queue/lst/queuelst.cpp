
namespace lasd {

    template <typename Data>
    inline const Data &QueueLst<Data>::Head() const{
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data &QueueLst<Data>::Head(){
        return List<Data>::Front();
    }

    template <typename Data>
    inline void QueueLst<Data>::Dequeue(){
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    inline Data QueueLst<Data>::HeadNDequeue(){
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(const Data &data){
        return List<Data>::InsertAtBack(data);
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(Data &&data){
        return List<Data>::InsertAtBack(data);
    }

}
