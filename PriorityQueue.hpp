#include <iostream>
#include <string>
using namespace std;
template <class T> class PriorityQueue{
  private:
    T * arrq;
    int arraySize;
    int simTime;
  public:
    void insert(T e);
    void remove();
    int size;
  };
  template class PriorityQueue<int>;
  template class PriorityQueue<float>;
  template class PriorityQueue<double>;
  template class PriorityQueue<string>;
  template class PriorityQueue<char>;
