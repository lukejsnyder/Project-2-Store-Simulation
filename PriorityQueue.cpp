#include "customer.cpp"
#include <iostream>
using namespace std;

template <class T> class MyPriorityQueue{
private:
  int simTime;
  T array = new T[100000];
  int arraySize = 0;
public:
  insert(Event e){
    if(arraySize == 0){
      array[1] = e;
      arraySize = 1;
    }else{
      array[arraySize + 1] = e;
      arraySize++;
      int parent = arraySize;
      Event temp;
      while(int parent != 1){
        if((parent % 2) != 0){
          parent = parent - 1;
        }
        parent = parent / 2;
        temp = array[arraySize];
        testParent = array[parent];
        if(testParent.getSimTime() > temp.getSimTime()){
          array[arraySize] = array[parent];
          array[parent] = temp;
          }
        }
      }
    }
  remove(){
    Event temp = array[1];
    Event temp2;
    array[1] = array[arraySize];
    array[arraySize] = array[arraySize + 1];
    arraySize = arraySize - 1;
    int i = 1;
    while(i < arraySize){
      if(array[(2*i).getSimTime()] > array[(2*i+ 1).getSimTime()]){
        array[i] = array[2*i + 1];
        array[2*i + 1] = temp;
        i = 2*i + 1;
      }else{
        array[i] = array[2*i];
        array[2*i] = temp;
        i = 2*i;
      }
    }
  }
  int size(){
    return arraySize;
  }
}
