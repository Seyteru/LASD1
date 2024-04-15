#include "list.hpp"

namespace lasd {

    template <typename Data>
    inline List<Data>::List(const TraversableContainer<Data> &container){
        container.Traverse(
            [this](const Data &data){
                InsertAtBack(data);
            }
        );
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data> &&container){
        container.Map(
            [this](Data &data){
                InsertAtBack(std::move(data));
            }
        );
    }

    template <typename Data>
    List<Data>::List(const List<Data> &list){
        if(list.tail != nullptr){
            tail = new Node(*list.tail);
            head = list.head -> Clone(tail);
            size = list.size;
        }
    }

    template <typename Data>
    List<Data>::List(List<Data> &&list) noexcept{
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
    }

    template <typename Data>
    List<Data>::~List(){
        delete head;
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(const List<Data> &list){
        if(size <= list.size){
            if(tail == nullptr){
                List *tempList = new List<Data>(list);
                std::swap(*tempList, *this);
                delete tempList;
            } else{
                Node *name = list.head;
            }
        }
    }

    template <typename Data>
    List<Data> &List<Data>::operator=(List<Data> &&list) noexcept{

    }

    template <typename Data>
    inline bool List<Data>::operator==(const List &lista) const noexcept{
        if(size != lista.size){
            return false;
        } else {
            Node *lista1 = head;
            Node *lista2 = lista.head;
            while(lista1 != nullptr){
                if(lista1 -> element != lista2 -> element){
                    return false;
                }
                lista1 -> next;
                lista2 -> next;
            }
            return true;
        }
    }

    template <typename Data>
    inline bool List<Data>::operator!=(const List &lista) const noexcept{
        return !(*this == lista);
    }

    template <typename Data>
    void List<Data>::InsertAtFront(const Data &data){
        Node *front = new Node(data);
        front -> next = head;
        head = front;
        if(tail == nullptr){
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data &&data){
        Node *front = new Node(std::move(data));
        front -> next = head;
        head = front;
        if(tail == nullptr){
            tail = head;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront(){
        if(head != nullptr){
            Node *front = head;
            if(tail == head){
                head = nullptr;
                tail = nullptr;
            } else{
                head = head -> next;
            }
            size--;
            front -> next = nullptr;
            delete front;
        } else{
            throw std::lenght_error("Access to Empty List");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove(){
        if(head != nullptr){
            //TODO
        } else{
            throw std::lenght_error("Access to Empty List");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data &data){
        Node *back = new Node(data);
        if(tail == nullptr){
            head = back;
        } else{
            tail -> next = back;
        }
        tail = back;
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data &&data){
        Node *back = new Node(std::move(data));
        if(tail == nullptr){
            head = back;
        } else{
            tail -> next = back;
        }
        tail = back;
        size++;
    }

    template <typename Data>
    void List<Data>::Clear(){
        for(ulong index = 0; index < size; index++){
            RemoveFromFront();
        }
        size = 0;
    }

    template <typename Data>
    bool List<Data>::Insert(const Data &data){
        for(Node *current = head; current !=nullptr; current = current -> next){
            if(current -> element == data){
                return false;
            }
        }
        InsertAtBack(data);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data &&data){
        for(Node *current = head; current !=nullptr; current = current -> next){
            if(current -> element == data){
                return false;
            }
        }
        InsertAtBack(std::move(data));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data &data){
        Node *end = nullptr;
        for(Node **current = &head; *current != nullptr; end = *current, current = &((/*ToDo*/))){
            if((*current) -> element == data){
                Node *node = *current;
                *current = node -> next;
                node -> next = nullptr;
                delete node;
                size--;
                if(tail == node){
                    tail = end;
                }
                return true;
            }
        }
        return false;
    }

    template <typename Data>
    const Data &List<Data>::operator[](const ulong index) const{
        if(index < size){
            Node *current = head;
            for(ulong curIndex = 0; curIndex < index; curIndex++, current = current -> next){
                return current -> element;
            }
        } else{
            throw std::out_of_range("Invalid Access at Index " + std::to_string(index));
        }
    }

    template <typename Data>
    Data &List<Data>::operator[](const ulong index){

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

    template <typename Data>
    inline List<Data>::Node::~Node(){

    }
    template <typename Data>
    bool List<Data>::Node::operator==(const Node &) const noexcept{
        return false;
    }
    template <typename Data>
    inline bool List<Data>::Node::operator!=(const Node &) const noexcept{
        return false;
    }

    template <typename Data>
    List<Data>::Node *List<Data>::Node::Clone(Node *){
        return nullptr;
    }
}
