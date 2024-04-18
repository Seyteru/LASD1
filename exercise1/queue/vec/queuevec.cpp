#include "queuevec.hpp"

namespace lasd {

    template <typename Data>
    inline QueueVec<Data>::QueueVec(const TraversableContainer<Data> &container){

    }

    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&container){

    }

    template <typename Data>
    QueueVec<Data>::QueueVec(const QueueVec<Data> &queueVec){

    }

    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec<Data> &&queueVec) noexcept{

    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(const QueueVec<Data> &queueVec){
        // TODO: insert return statement here
    }

    template <typename Data>
    QueueVec<Data> &QueueVec<Data>::operator=(QueueVec<Data> &&queueVec) noexcept{
        // TODO: insert return statement here
    }

    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data> &queueVec) const noexcept{
        return false;
    }

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec<Data> &queueVec) const noexcept{
        return false;
    }

    template <typename Data>
    inline const Data &QueueVec<Data>::Head() const{

    }

    template <typename Data>
    inline Data &QueueVec<Data>::Head(){
        
    }

    template <typename Data>
    inline void QueueVec<Data>::Dequeue(){
        
    }

    template <typename Data>
    inline Data QueueVec<Data>::HeadNDequeue(){
        
    }

    template <typename Data>
    inline void QueueVec<Data>::Enqueue(const Data &data){

    }

    template <typename Data>
    inline void QueueVec<Data>::Enqueue(Data &&data) noexcept{
        
    }

    template <typename Data>
    bool QueueVec<Data>::Empty() const noexcept{
        return false;
    }

    template <typename Data>
    ulong QueueVec<Data>::Size() const noexcept{
        return ulong();
    }

    template <typename Data>
    void QueueVec<Data>::Clear(){

    }
    template <typename Data>
    void QueueVec<Data>::Resize(ulong newSize, ulong num){
        
    }
    template <typename Data>
    void QueueVec<Data>::Reduce(){

    }
}
