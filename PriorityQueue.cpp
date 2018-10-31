#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;


template <class T> PriorityQueue<T>::PriorityQueue() {
  arraySize = 0;
  arrq = new T[10000];
}
template <class T> void  PriorityQueue<T>::insert(T e){
  if(arraySize == 0){
    arrq[1] = e;
    arraySize = 1;
  }else{
    arrq[arraySize + 1] = e;
    arraySize++;
    int parent = arraySize;
    T temp;
    T testParent;
    while(parent != 1){
      if((parent % 2) != 0){
        parent = parent - 1;
      }
      parent = parent / 2;
      temp = arrq[arraySize];
      testParent = arrq[parent];
      if(testParent > temp){
        arrq[arraySize] = arrq[parent];
        arrq[parent] = temp;
      }else{
        parent = 1;
      }
    }
  }
}
template <class T> T PriorityQueue<T>::remove(){
  T temp = arrq[1];
  T temp2 = arrq[1];
  arrq[1] = arrq[arraySize];
  arrq[arraySize] = arrq[arraySize + 1];
  arraySize = arraySize - 1;
  int i = 1;
  while(i < arraySize){
    if(arrq[(2*i)] > arrq[(2*i+ 1)]){
      arrq[i] = arrq[2*i + 1];
      arrq[2*i + 1] = temp;
      i = 2*i + 1;
    }else{
      temp = arrq[2 * i];
      arrq[i] = arrq[2*i];
      arrq[2*i] = temp;
      i = 2*i;
    }
  }
  return temp2;
}
template <class T> int PriorityQueue<T>::size(){
  return arraySize;
}
