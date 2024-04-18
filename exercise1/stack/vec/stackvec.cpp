
namespace lasd {    

    template <typename Data>
    const Data &StackVec<Data>::Top() const{
        if(index != 0){
            return elements[index - 1]
        } else{
            throw std::length_error("Invalid Access to an Empty Stack ")
        }
    }

    template <typename Data>
    Data &StackVec<Data>::Top(){
        if(index != 0){
            return elements[index - 1]
        } else{
            throw std::length_error("Invalid Access to an Empty Stack ")
        }
    }

    template <typename Data>
    void StackVec<Data>::Pop(){
        
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop(){
        
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data &data){
        
    }

    template <typename Data>
    void StackVec<Data>::Push(Data &&data){
        
    }


}
