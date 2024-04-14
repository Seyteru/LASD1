#include "list.hpp"

namespace lasd {

    template <typename Data>
    inline List<Data>::List(const TraversableContainer<Data> &){

    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data> &&){

    }

    template <typename Data>
    List<Data>::List(const List<Data> &list){

    }

    template <typename Data>
    List<Data>::List(List<Data> &&list) noexcept{

    }

    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &list){

    }

    template <typename Data>
    List<Data> &List<Data>::operator=(List<Data> &&list) noexcept{

    }

    template <typename Data>
    inline bool List<Data>::operator==(const List &) const noexcept{
        return false;
    }

    template <typename Data>
    inline bool List<Data>::operator!=(const List &) const noexcept{
        return false;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &){

    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&){

    }

    template <typename Data>
    void List<Data>::RemoveFromFront(){

    }

    template <typename Data>
    Data List<Data>::FrontNRemove(){
        return Data();
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &){

    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data &&){

    }

    template <typename Data>
    void List<Data>::Clear(){

    }

    template <typename Data>
    bool List<Data>::Insert(const Data &){
        return false;
    }

    template <typename Data>
    bool List<Data>::Insert(Data &&){
        return false;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data &){
        return false;
    }

    template <typename Data>
    const Data &List<Data>::operator[](const ulong) const{

    }

    template <typename Data>
    Data &List<Data>::operator[](const ulong){

    }

    template <typename Data>
    const Data &List<Data>::Front() const{

    }

    template <typename Data>
    Data &List<Data>::Front(){

    }

    template <typename Data>
    const Data &List<Data>::Back() const{

    }

    template <typename Data>
    Data &List<Data>::Back(){

    }

    template <typename Data>
    void List<Data>::Traverse(TraverseFun) const{

    }

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun) const{

    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun) const{

    }

    template <typename Data>
    void List<Data>::Map(MapFun){

    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun){

    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun){
        
    }
}
