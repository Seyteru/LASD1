
// #include "..."

/* ************************************************************************** */
#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>   
#include <time.h>       
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>  

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

using namespace std;

std::string characters {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
std::random_device rd;
std::mt19937 generator(rd());
std::string randomString(int length){
  std::string output(characters);
  std::shuffle(output.begin(), output.end(), generator);
  return output.substr(0, length);
}

/* ************************************************************************** */

//Vector and List ausiliary test functions
bool Empty(lasd::Container &con){
  return con.Empty();
}

template <typename Data>
void getDataFromIndex(lasd::LinearContainer<Data> &con, ulong index){
  try{
    cout << "At index: " << index << ". " << "Data is: " << con[index] << endl;
  }
  catch(std::out_of_range &exc){
    cout << exc.what() << "!" <<endl;
  }
  catch(...){
    cout << "Wrong Exception" << endl;
  }
}

template <typename Data>
void setDataFromIndex(lasd::LinearContainer<Data> &con, const ulong &index, const Data &dat){
  try{
    cout << "At index: " << index << ". " << "Setting Data to: " << dat << endl;
    con[index] = dat;
  }
  catch(std::out_of_range &exc){
    cout << exc.what() << "!" <<endl;
  }
  catch(...){
    cout << "Wrong Exception" << endl;
  }
}

template <typename Data>
void getFront(lasd::LinearContainer<Data> &con){
  try{
    cout << "The Front is: " << con.Front() << endl;
  }
  catch(std::length_error & exc){
    cout << exc.what() << endl;
  }
}

template <typename Data>
void getBack(lasd::LinearContainer<Data> &con){
  try{
    cout << "The Back is: " << con.Back() << endl;
  }
  catch(std::length_error & exc){
    cout << exc.what() << endl;
  }
}

template <typename Data>
void equalLinear(const lasd::LinearContainer<Data> & con1, const lasd::LinearContainer<Data> & con2){
  if(con1 == con2){
    cout << "These containers are Equals" <<  endl;
  } else{
    cout << "These containers are not Equals" <<  endl;
  }
}

//Fill functions for structures
template <typename Data>
void fill(lasd::StackVec<Data> &stkvec, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    stkvec.Push(dataRandom);
  }
}

void fill(lasd::StackVec<string> &stkvec, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    stkvec.Push(randomString(4));
  }
}

template <typename Data>
void fill(lasd::StackLst<Data> &stklist, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    stklist.Push(dataRandom);
  }
}

void fill(lasd::StackLst<string> &stkvec, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    stkvec.Push(randomString(4));
  }
}

template <typename Data>
void fill(lasd::QueueVec<Data> &quevec, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    quevec.Enqueue(dataRandom);
  }
}

void fill(lasd::QueueVec<string> &quevec, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    quevec.Enqueue(randomString(4));
  }
}

template <typename Data>
void fill(lasd::QueueLst<Data> &quelst, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    quelst.Enqueue(dataRandom);
  }
}

void fill(lasd::QueueLst<string> &quelst, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    quelst.Enqueue(randomString(4));
  }
}

template <typename Data>
void fill(lasd::Vector<Data> &vec){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < vec.Size(); i++){
    dataRandom = rand() / (100 + 1);
    vec[i] = dataRandom;
  }
}

void fill(lasd::Vector<string> &vec){
  for(ulong i = 0; i < vec.Size(); i++){
    vec[i] = randomString(4);
  }
}

template <typename Data>
void fill(lasd::List<Data> &list, ulong dimension){
  Data dataRandom;
  srand((unsigned int)time(NULL));

  for(ulong i = 0; i < dimension; i++){
    dataRandom = rand() / (100 + 1);
    list.InsertAtBack(dataRandom);
  }
}

void fill(lasd::List<string> &list, ulong dimension){
  for(ulong i = 0; i < dimension; i++){
    list.InsertAtBack(randomString(4));
  }
}


//StackTests
template <typename Stk>
void testStack(Stk &stk) {
  try {
    cout << "Size should be 0." << endl;
    cout << "Size is: " << stk.Size() << endl;

    fill(stk, 100);
    cout << "Added Stack with 100 random <Data>" << endl;
    cout << "Size should be 100." << endl;
    cout << "Size is: " << stk.Size() << endl;

    fill(stk, 1900);
    cout << "Added Stack with 1900 random <Data>" << endl;
    cout << "Size should be 2000." << endl;
    cout << "Size is: " << stk.Size() << endl;

    stk.Clear();
    cout << "Size should be 0." << endl;
    cout << "Size is: " << stk.Size() << endl;
    cout << "Stack should be empty(1): "<< stk.Empty() << endl;

    fill(stk, 100);
    cout << "Added Stack with 100 random <Data>" << endl;
    cout << "Data Top of the Stack: ";
    cout << stk.Top() << endl;
    cout << "Popped from the Stack" << endl;
    stk.Pop();
    cout << "New Data Top of the Stack: ";
    cout << stk.Top() << endl;
    cout << "Data TopNPop of the Stack: ";
    cout << stk.TopNPop() << endl;
    cout << "New Data Top of the Stack: ";
    cout << stk.Top() << endl;

    Stk copstk(stk);
    Stk movstk(move(stk));
    cout << "Data Top of the Stack Copied: ";
    cout << copstk.Top() << endl;
    cout << "Data Top of the Stack Moved: ";
    cout << movstk.Top() << endl;

    cout << "Size of Original Stack should be 0." << endl;
    cout << "Size is: " << stk.Size() << endl;
    cout << "Size of Stack copied should be 98." << endl;
    cout << "Size is: " << copstk.Size() << endl;
    cout << "Size of Stack moved should be 98." << endl;
    cout << "Size is: " << movstk.Size() << endl;

    stk.Clear();
    copstk.Clear();
    movstk.Clear();
    cout << "Cleared Stack"<< endl;
    cout << "Size of Stack should be 0." << endl;
    cout << "Size is: " << stk.Size() << endl;
    
  }
  catch (...) {
    cout << "Error!" << endl;
  }
}

void testStackInteger() {
  lasd::StackVec<int> stkvec;
  cout << endl << "Begin StackTest(Vector) for Integer" << endl;
  cout<<endl;
  testStack(stkvec);
  lasd::StackLst<int> stklst;
  cout << endl << "Begin StackTest(List) for Integer" << endl;
  cout<<endl;
  testStack(stklst);
  try{
    cout<<endl;
    lasd::Vector<int> vec(5);
    for(int i = 1; i < 6; i++){
      vec[i-1] = i;
    }
    lasd::List<int> lst(vec);
    stkvec.Push(1);
    stkvec.Push(2);
    stkvec.Push(3);
    stkvec.Push(4);
    stkvec.Push(5);
    lasd::StackVec<int> newstkvecv(vec);
    lasd::StackVec<int> newstackvecl(lst);
    cout << "Created 2 new StackVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stkvec == newstkvecv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stkvec == newstackvecl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    lasd::StackLst<int> newstklstv(vec);
    lasd::StackLst<int> newstacklstl(lst);
    cout << "Created 2 new StackLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stklst == newstklstv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stklst == newstacklstl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of StackTest For Integer!" << endl;
}

void testStackFloat() {
  lasd::StackVec<float> stkvec;
  cout << endl << "Begin StackTest(Vector) for Float" << endl;
  cout<<endl;
  testStack(stkvec);
  lasd::StackLst<float> stklst;
  cout << endl << "Begin StackTest(List) for Float" << endl;
  cout<<endl;
  testStack(stklst);
  cout<<endl;
  try{
    lasd::Vector<float> vec(5);
    for(int i = 1; i < 6; i++){
      vec[i-1] = 0.5 + i;
    }
    lasd::List<float> lst(vec);
    stkvec.Push(1.5);
    stkvec.Push(2.5);
    stkvec.Push(3.5);
    stkvec.Push(4.5);
    stkvec.Push(5.5);
    lasd::StackVec<float> newstkvecv(vec);
    lasd::StackVec<float> newstackvecl(lst);
    cout << "Created 2 new StackVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stkvec == newstkvecv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stkvec == newstackvecl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    lasd::StackLst<float> newstklstv(vec);
    lasd::StackLst<float> newstacklstl(lst);
    cout << "Created 2 new StackLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stklst == newstklstv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stklst == newstacklstl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of StackTest For Float!" << endl;
}

void testStackString() {
  lasd::StackVec<string> stkvec;
  cout << endl << "Begin StackTest(Vector) for String" << endl;
  cout<<endl;
  testStack(stkvec);
  lasd::StackLst<string> stklst;
  cout << endl << "Begin StackTest(List) for String" << endl;
  cout<<endl;
  testStack(stklst);
  cout << endl;
  try{
    cout<<endl;
    lasd::Vector<string> vec(5);
    vec[0] = "A";
    vec[1] = "B";
    vec[2] = "C";
    vec[3] = "D";
    vec[4] = "E";
    lasd::List<string> lst(vec);
    stkvec.Push("A");
    stkvec.Push("B");
    stkvec.Push("C");
    stkvec.Push("D");
    stkvec.Push("E");
    lasd::StackVec<string> newstkvecv(vec);
    lasd::StackVec<string> newstackvecl(lst);
    cout << "Created 2 new StackVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stkvec == newstkvecv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stkvec == newstackvecl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    lasd::StackLst<string> newstklstv(vec);
    lasd::StackLst<string> newstacklstl(lst);
    cout << "Created 2 new StackLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Stacks are Equal" << endl;
    if(stklst == newstklstv){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
    if(stklst == newstacklstl){
      cout << "The 2 stack are Equal" <<endl;
    } else{
      cout << "The 2 stack are Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of StackTest For String!" << endl;
}

template <typename Que>
void testQueue(Que &que) {
  try {
    cout << "Size should be 0." << endl;
    cout << "Size is: " << que.Size() << endl;
    fill(que, 100);
    cout << "Added Queue with 100 random <Data>" << endl;
    cout << "Size should be 100." << endl;
    cout << "Size is: " << que.Size() << endl;

    fill(que, 1900);
    cout << "Added Queue with 1900 random <Data>" << endl;
    cout << "Size should be 2000." << endl;
    cout << "Size is: " << que.Size() << endl;
    que.Clear();
    cout << "Size should be 0." << endl;
    cout << "Size is: " << que.Size() << endl;
    cout << "Queue should be empty(1): "<< que.Empty() << endl;

    fill(que, 100);
    cout << "Added Queue with 100 random <Data>" << endl;
    cout << "Data Head of the Queue: ";
    cout << que.Head() << endl;
    cout << "Dequeued from the Queue" << endl;
    que.Dequeue();
    cout << "New Data Head of the Queue: ";
    cout << que.Head() << endl;
    cout << "Data HeadNDequeue of the Queue: ";
    cout << que.HeadNDequeue() << endl;
    cout << "New Data Head of the Queue: ";
    cout << que.Head() << endl;

    Que copque(que);
    Que movque(move(que));
    cout << "Data Head of the Queue copied: ";
    cout << copque.Head() << endl;
    cout << "Data Head of the Queue moved: ";
    cout << movque.Head() << endl;

    cout << "Size of Original Queue should be 0." << endl;
    cout << "Size is: " << que.Size() << endl;
    cout << "Size of Queue copied should be 98." << endl;
    cout << "Size is: " << copque.Size() << endl;
    cout << "Size of Queue moved should be 98." << endl;
    cout << "Size is: " << movque.Size() << endl;

    que.Clear();
    copque.Clear();
    movque.Clear();
    cout << "Cleared Queue"<< endl;
    cout << "Size is: " << que.Size() << endl;
  }
  catch (...) {
    cout << "Error!" << endl;
  }

  cout << "End of QueueTest(Vector)!" << endl;
}

void testQueueInteger() {
  lasd::QueueVec<int> quevec;
  cout << endl << "Begin QueueTest(Vector) for Integer" << endl;
  cout<<endl;
  testQueue(quevec);
  lasd::QueueLst<int> quelst;
  cout << endl << "Begin QueueTest(List) for Integer" << endl;
  cout<<endl;
  testQueue(quelst);
  try{
    cout<<endl;
    lasd::Vector<int> vec(5);
    for(int i = 1; i < 6; i++){
      vec[i-1] = i;
    }
    lasd::List<int> lst(vec);
    quevec.Enqueue(1);
    quevec.Enqueue(2);
    quevec.Enqueue(3);
    quevec.Enqueue(4);
    quevec.Enqueue(5);
    lasd::QueueVec<int> newquevecv(vec);
    lasd::QueueVec<int> newquevecl(lst);
    cout << "Created 2 new QueueVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quevec == newquevecv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    if(quevec == newquevecl){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    lasd::QueueLst<int> newquelstv(vec);
    lasd::QueueLst<int> newquelstl(lst);
    cout << "Created 2 new QueueLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quelst == newquelstv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    if(quelst == newquelstl){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For Integer!" << endl;
}

void testQueueFloat() {
  lasd::QueueVec<float> quevec;
  cout << endl << "Begin QueueTest(Vector) for Float" << endl;
  cout<<endl;
  testQueue(quevec);
  lasd::QueueLst<float> quelst;
  cout << endl << "Begin QueueTest(List) for Float" << endl;
  cout<<endl;
  testQueue(quelst);
  try{
    cout<<endl;
    lasd::Vector<float> vec(5);
    for(int i = 1; i < 6; i++){
      vec[i-1] = 0.5 + i;
    }
    lasd::List<float> lst(vec);
    quevec.Enqueue(1);
    quevec.Enqueue(2);
    quevec.Enqueue(3);
    quevec.Enqueue(4);
    quevec.Enqueue(5);
    lasd::QueueVec<float> newquevecv(vec);
    lasd::QueueVec<float> newquevecl(lst);
    cout << "Created 2 new QueueVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quevec == newquevecv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    if(quevec == newquevecl){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    lasd::QueueLst<float> newquelstv(vec);
    lasd::QueueLst<float> newquelstl(lst);
    cout << "Created 2 new QueueLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quelst == newquelstv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    if(quelst == newquelstl){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For Float!" << endl;
}

void testQueueString() {
  lasd::QueueVec<string> quevec;
  cout << endl << "Begin QueueTest(Vector) for String" << endl;
  cout<<endl;
  testQueue(quevec);
  lasd::QueueLst<string> quelst;
  cout << endl << "Begin QueueTest(List) for String" << endl;
  cout<<endl;
  testQueue(quelst);
  try{
    cout<<endl;
    lasd::Vector<string> vec(5);
    for(int i = 1; i < 6; i++){
      vec[i-1] = i;
    }
    lasd::List<string> lst(vec);
    quevec.Enqueue("A");
    quevec.Enqueue("B");
    quevec.Enqueue("C");
    quevec.Enqueue("D");
    quevec.Enqueue("E");
    lasd::QueueVec<string> newquevecv(vec);
    lasd::QueueVec<string> newquevecl(lst);
    cout << "Created 2 new QueueVec From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quevec == newquevecv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    if(quevec == newquevecl){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are Equal" <<endl;
    }
    lasd::QueueLst<string> newquelstv(vec);
    lasd::QueueLst<string> newquelstl(lst);
    cout << "Created 2 new QueueLst From List and Vec" << endl;
    cout << "The 2 control of equality should print 2 time that the Queues are Equal" << endl;
    if(quelst == newquelstv){
      cout << "The 2 queue are Equal" <<endl;
    } else{
      cout << "The 2 queue are not Equal" <<endl;
    }
    if(quelst == newquelstl){
      cout << "The 2 queue are  Equal" <<endl;
    } else{
      cout << "The 2 queue are not Equal" <<endl;
    }
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << "End of QueueTest For String!" << endl;
}

template <typename Data>
void testVector(lasd::SortableVector<Data> &vec) {
  try {
    cout << "Vector should be Empty(1): " << Empty(vec) << endl;
    cout << "Size should be 0." << endl;
    cout << "Size is: " << vec.Size() << endl;
    cout << "All index should be unaccessible." << endl;
    getDataFromIndex(vec, 0);
    getDataFromIndex(vec, 1);
    lasd::SortableVector<Data> newvec(10);
    cout << "Vector should not be Empty(0): " << Empty(newvec) << endl;
    cout << "Size should be 10." << endl;
    cout << "Size is: " << newvec.Size() << endl;
    fill(newvec);
    cout << "Vector filled with random datas." << endl;
    getDataFromIndex(newvec, 0);
    lasd::SortableVector<Data> copnewvec(newvec);
    lasd::SortableVector<Data> movnewvec(move(newvec));
    cout << "Created 2 Vectors copied and moved." << endl;
    cout << "Front and Back of the original unaccessible." << endl;
    getFront(newvec);
    getBack(newvec);
    cout << "Front and Back of the copied." << endl;
    getFront(copnewvec);
    getBack(copnewvec);
    cout << "Front and Back of the moved." << endl;
    getFront(movnewvec);
    getBack(movnewvec);
    cout << "Resize Vector with Size: 20" << endl;
    newvec.Resize(20);
    fill(newvec);
    cout << "Size should be 20." << endl;
    cout << "Size is: " << newvec.Size() << endl;
    cout << "Made assignment with the 2 new Vectors" << endl;
    copnewvec = movnewvec;
    cout << "The Vectors should be Equals" << endl;
    equalLinear(copnewvec, movnewvec);
    cout << "Change size of one Vector" << endl;
    copnewvec.Resize(50);
    cout << "Copied Vector size: " << copnewvec.Size() << endl;
    cout << "Vectors should not be Equals." << endl;
    equalLinear(copnewvec, movnewvec);

    
  }
  catch (...) {
    cout << "Error!" << endl;
  }

}

void testVectorInteger() {
  lasd::SortableVector<int> vec;
  cout << endl << "Begin Vector for Integer" << endl;
  testVector(vec);
  try{
    cout << "Resize Vector to 200" << endl;
    vec.Resize(200);
    fill(vec);
    cout << "Filled Vector with Random Data" << endl;
    lasd::SortableVector<int> copvec(vec);
    cout << "Created a copied Vector" << endl;
    cout << "Front and back of these 2 Vectors" << endl;
    getFront(vec);
    getBack(vec);
    getFront(copvec);
    getBack(copvec);
    cout << "Vector should be Eqal" << endl;
    equalLinear(vec, copvec);
    cout << "Set data at Front and Back of the First Vector" << endl;
    setDataFromIndex(vec, 0, 0);
    setDataFromIndex(vec, vec.Size(), 0);
    cout << "Vector should not be equal" << endl;
    equalLinear(vec, copvec);
    cout << "Pre Order Map of the 2 Vectors: " << endl;
    vec.PreOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PreOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Vectors: " << endl;
    vec.PostOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PostOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << endl << "Set data in unaccessible index" << endl;
    setDataFromIndex(vec, (vec.Size() + 1), 0);
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for Integer" << endl;
}

void testVectorFloat() {
  lasd::SortableVector<float> vec;
  cout << endl << "Begin Vector for Float" << endl;
  testVector(vec);
  try{
    cout << "Resize Vector to 200" << endl;
    vec.Resize(200);
    fill(vec);
    cout << "Filled Vector with Random Data" << endl;
    lasd::SortableVector<float> copvec(vec);
    cout << "Created a copied Vector" << endl;
    cout << "Front and back of these 2 Vectors" << endl;
    getFront(vec);
    getBack(vec);
    getFront(copvec);
    getBack(copvec);
    cout << "Vector should be Equal" << endl;
    equalLinear(vec, copvec);
    cout << "Set data at Front and Back of the First Vector" << endl;
    setDataFromIndex(vec, 0, 0.0f);
    setDataFromIndex(vec, vec.Size(), 0.0f);
    cout << "Vector should not be equal" << endl;
    equalLinear(vec, copvec);
    cout << "Pre Order Map of the 2 Vectors: " << endl;
    vec.PreOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PreOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Vectors: " << endl;
    vec.PostOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PostOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Set data in unaccessible index" << endl;
    setDataFromIndex(vec, (vec.Size() + 1), 0.0f);
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for Float" << endl;
}

void testVectorString() {
  lasd::SortableVector<string> vec;
  cout << endl << "Begin Vector for String" << endl;
  testVector(vec);
  try{
    cout << "Resize Vector to 200" << endl;
    vec.Resize(200);
    fill(vec);
    cout << "Filled Vector with Random Data" << endl;
    lasd::SortableVector<string> copvec(vec);
    cout << "Created a copied Vector" << endl;
    cout << "Front and back of these 2 Vectors" << endl;
    getFront(vec);
    getBack(vec);
    getFront(copvec);
    getBack(copvec);
    cout << "Vector should be Equal" << endl;
    equalLinear(vec, copvec);
    cout << "Set data at Front and Back of the First Vector" << endl;
    setDataFromIndex(vec, 0, string("A"));
    setDataFromIndex(vec, vec.Size(), string("A"));
    cout << "Vector should not be equal" << endl;
    equalLinear(vec, copvec);
    cout << "Pre Order Map of the 2 Vectors: " << endl;
    vec.PreOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PreOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Vectors: " << endl;
    vec.PostOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    copvec.PostOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Set data in unaccessible index" << endl;
    setDataFromIndex(vec, (vec.Size() + 1), string("A"));
  }
  catch(...){
    cout << "Error!" << endl;
  }
  cout << endl << "End Vector for String" << endl;
}

template <typename Data>
void testList(lasd::List<Data> &lst) {
  try {
    cout << "List should be Empty(1): " << Empty(lst) << endl;
    cout << "Size should be 0." << endl;
    cout << "Size is: " << lst.Size() << endl;
    cout << "All index should be unaccessible." << endl;
    getDataFromIndex(lst, 0);
    getDataFromIndex(lst, 1);
    lasd::List<Data> newlst;
    fill(newlst, 20);
    cout << "New List Created with Size 20." << endl;
    cout << "New List should not be Empty(0): " << Empty(newlst) << endl;
    cout << "Size should be 20." << endl;
    cout << "Size is: " << newlst.Size() << endl;
    getDataFromIndex(newlst, 0);
    cout << "Index should be unaccessible." << endl;
    getDataFromIndex(newlst, 21);
    lasd::List<Data> copnewlst(newlst);
    lasd::List<Data> movnewlst(move(newlst));
    cout << "Created 2 Lists copied and moved." << endl;
    cout << "Front and Back of the original unaccessible." << endl;
    getFront(newlst);
    getBack(newlst);
    cout << "Front and Back of the copied." << endl;
    getFront(copnewlst);
    getBack(copnewlst);
    cout << "Front and Back of the moved." << endl;
    getFront(movnewlst);
    getBack(movnewlst);
    cout << "Made assignment with the 2 new Vectors" << endl;
    copnewlst = movnewlst;
    cout << "The Vectors should be Equals" << endl;
    equalLinear(copnewlst, movnewlst);
    lasd::SortableVector<Data> vec(lst);
    cout << "Created Vector from a List and they should be Equals." << endl;
    equalLinear(lst, vec);
    cout << "Created List from a Vector and they should be Equals." << endl;
    lasd::List<Data> newlstvec(vec);
    equalLinear(newlstvec, vec);
    newlst = newlstvec;
    cout << "Copy Assignment for the 2 Lists they should be Equals." << endl;
    equalLinear(newlstvec, newlst);
    
  }
  catch (...) {
    cout << "Error!" << endl;
  }

  cout << "End of ListTest!" << endl;
}

void testListInteger() {
  lasd::List<int> lst;
  cout<<endl;
  cout << endl << "Begin List for Integer" << endl;
  cout<<endl;
  testList(lst);
  try{
    fill(lst, 30);
    lasd::List<int> newlst(lst);
    cout << "Pre Order Map of the 2 Lists: " << endl;
    lst.PreOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PreOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Lists: " << endl;
    lst.PostOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PostOrderMap([](int &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;

  }
  catch(...){
    cout << "Error!" <<  endl;
  }
}

void testListFloat() {
  lasd::List<float> lst;
  cout<<endl;
  cout << endl << "Begin List for Float" << endl;
  cout<<endl;
  testList(lst);
  try{
    fill(lst, 30);
    lasd::List<float> newlst(lst);
    cout << "Pre Order Map of the 2 Lists: " << endl;
    lst.PreOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PreOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Lists: " << endl;
    lst.PostOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PostOrderMap([](float &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;

  }
  catch(...){
    cout << "Error!" <<  endl;
  }
}

void testListString() {
  lasd::List<string> lst;
  cout<<endl;
  cout << endl << "Begin List for String" << endl;
  cout<<endl;
  testList(lst);
  try{
    fill(lst, 30);
    lasd::List<string> newlst(lst);
    cout << "Pre Order Map of the 2 Lists: " << endl;
    lst.PreOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PreOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    cout << "Post Order Map of the 2 Lists: " << endl;
    lst.PostOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;
    newlst.PostOrderMap([](string &dat){cout << dat << " - ";});
    cout<<endl;
    cout<<endl;

  }
  catch(...){
    cout << "Error!" <<  endl;
  }
}

void mytest() {
  cout << "Begin of MyTests!" << endl;
  testVectorInteger();
  testVectorFloat();
  testVectorString();
  testListInteger();
  testListFloat();
  testListString();
  testStackInteger();
  testStackFloat();
  testStackString();
  testQueueInteger();
  testQueueFloat();
  testQueueString();
  cout<< "End of MyTest!" << endl;
  cout << endl;
}


