
// #include "..."

/* ************************************************************************** */
#include <iostream>

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

/* ************************************************************************** */

template <typename Stk>
void testStack(Stk &stack) {
  try {

  }
  catch (...) {
    cout << endl << "Errore Non Gestito! " << endl;
  }

  cout << "Fine StackTest!" << endl;
}

void testStackInteger() {
  lasd::StackVec<int> stkvec;
  cout << endl << "Inizio StackTest(Vector) for Integer" << endl;
  testStack(stkvec);
  lasd::StackLst<int> stklst;
  cout << endl << "Inizio StackTest(List) for Integer" << endl;
  testStack(stklst);
}

void testStackFloat() {
  lasd::StackVec<float> stkvec;
  cout << endl << "Inizio StackTest(Vector) for Float" << endl;
  testStack(stkvec);
  lasd::StackLst<float> stklst;
  cout << endl << "Inizio StackTest(List) for Float" << endl;
  testStack(stklst);
}

void testStackString() {
  lasd::StackVec<string> stkvec;
  cout << endl << "Inizio StackTest(Vector) for String" << endl;
  testStack(stkvec);
  lasd::StackLst<string> stklst;
  cout << endl << "Inizio StackTest(List) for String" << endl;
  testStack(stklst);
}

template <typename Que>
void testQueue(Que &queue) {
  try {

  }
  catch (...) {
    cout << endl << "Errore Non Gestito! " << endl;
  }

  cout << "Fine QueueTest!" << endl;
}

void testQueueInteger() {
  lasd::QueueVec<int> quevec;
  cout << endl << "Inizio QueueTest(Vector) for Integer" << endl;
  testQueue(quevec);
  lasd::QueueLst<int> quelst;
  cout << endl << "Inizio QueueTest(List) for Integer" << endl;
  testQueue(quelst);
}

void testQueueFloat() {
  lasd::QueueVec<float> quevec;
  cout << endl << "Inizio QueueTest(Vector) for Float" << endl;
  testQueue(quevec);
  lasd::QueueLst<float> quelst;
  cout << endl << "Inizio QueueTest(List) for Float" << endl;
  testQueue(quelst);
}

void testQueueString() {
  lasd::QueueVec<string> quevec;
  cout << endl << "Inizio QueueTest(Vector) for String" << endl;
  testQueue(quevec);
  lasd::QueueLst<string> quelst;
  cout << endl << "Inizio QueueTest(List) for String" << endl;
  testQueue(quelst);
}

template <typename Data>
void testVector(lasd::SortableVector<Data> &vector) {
  try {

  }
  catch (...) {
    cout << endl << "Errore Non Gestito! " << endl;
  }

  cout << "Fine VectorTest!" << endl;
}

void testVectorInteger() {
  lasd::SortableVector<int> vec;
  cout << endl << "Inizio Vector for Integer" << endl;
  testVector(vec);
}

void testVectorFloat() {
  lasd::SortableVector<float> vec;
  cout << endl << "Inizio Vector for Float" << endl;
  testVector(vec);
}

void testVectorString() {
  lasd::SortableVector<string> vec;
  cout << endl << "Inizio Vector for String" << endl;
  testVector(vec);
}

template <typename Data>
void testList(lasd::List<Data> &list) {
  try {

  }
  catch (...) {
    cout << endl << "Errore Non Gestito! " << endl;
  }

  cout << "Fine ListTest!" << endl;
}

void testListInteger() {
  lasd::List<int> lst;
  cout << endl << "Inizio List for Integer" << endl;
  testList(lst);
}

void testListFloat() {
  lasd::List<float> lst;
  cout << endl << "Inizio List for Float" << endl;
  testList(lst);
}

void testListString() {
  lasd::List<string> lst;
  cout << endl << "Inizio List for String" << endl;
  testList(lst);
}

void mytest() {
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
  cout<< "Fine MyTest!" << endl;
}


