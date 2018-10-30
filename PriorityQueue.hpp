#include <iostream>
#include "Event.cpp"
#include <string>
using namespace std;
template <class T> class PriorityQueue{
  private:
    T * arrq;
    int arraySize;
    int simTime;
  public:
    PriorityQueue();
    void insert(T e);
    T remove();
    int size();
    PriorityQueue& operator=(const PriorityQueue<T>& other){//incoming tote has the same size and values as the main
      arraySize = other.arraySize;
      arrq = new T[arraySize];
      for(int i = 0; i < arraySize; i++){
        arrq[i] = other.arrq[i];
      }
    }
    friend ostream& operator<<(ostream& os, const PriorityQueue<T>& list){// prints out the entire tote to the screen
      int otherTemp = list.arrq[list.size-1];
      os << "[";
      for(int i = 0; i < list.arraySize - 1; i++){
        int temp = list.arrq[i];
        os << temp << " -- ";
      }
      os << otherTemp;
      os << "]";
      return os;
    }
  };
  template class PriorityQueue<Event>;
  template class PriorityQueue<int>;
  template class PriorityQueue<float>;
  template class PriorityQueue<double>;
  template class PriorityQueue<string>;
  template class PriorityQueue<char>;
