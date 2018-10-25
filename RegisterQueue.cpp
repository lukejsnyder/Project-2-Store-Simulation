#include "Customer.cpp"

class RegisterQueue{
private:

    // Needed for queue
    struct Node{
        Customer person;
        Node * toFront;
        Node * toBack;
        Node(Customer person){
            this->person = person;
            toFront = NULL;
            toBack = NULL;
        }
    };
    Node * front;
    Node * back;

    //Variables for stats
    int numberOfCustomers;
    double totalCustomerWaitTime;

    //Checkout Time Factors.
    double scanTime;
    double payTime;

public:
    RegisterQueue(){
      front = NULL;
      back = NULL;
      numberOfCustomers = 0;
    }

    RegisterQueue(double payTime, double scanTime){
      this->payTime = payTime;
      this->scanTime = scanTime;

      numberOfCustomers = 0;
      totalCustomerWaitTime = 0;

      front = NULL;
      back = NULL;


    }

    RegisterQueue(const RegisterQueue& other){
        this -> scanTime = other.scanTime;
        this -> payTime = other.payTime;

        numberOfCustomers = other.numberOfCustomers;
        totalCustomerWaitTime = other.totalCustomerWaitTime;

        front = NULL;
        back = NULL;

        Node * temp = other.front;
        while(temp){
          enqueue(temp -> person);
          temp = (temp -> toBack);
        }
    }

    ~RegisterQueue(){
      clear();
    }

    RegisterQueue& operator=(const RegisterQueue& other){
      this -> scanTime = other.scanTime;
      this -> payTime = other.payTime;

      numberOfCustomers = other.numberOfCustomers;
      totalCustomerWaitTime = other.totalCustomerWaitTime;

      front = NULL;
      back = NULL;

      Node * temp = other.front;
      while(temp){
        enqueue(temp -> person);
        temp = (temp -> toBack);

    }
      return *this;
  }

    void enqueue(Customer person){
      Node * newNode;
      newNode = new Node(person);
      newNode->toFront = back;
      back = newNode;
      if(isEmpty()){
          front = newNode;
      }else{
          back->toFront->toBack = back;
      }
      numberOfCustomers++;
    }

    Customer& dequeue() {
      if(front == NULL){
          throw (1);
      }
      Customer c = front->person;
      if(front->toBack){
          front = front->toBack;
          delete(front->toFront);
          front->toFront = NULL;
      }else{
          delete(front);
          front = back = NULL;
      }
      numberOfCustomers--;
      return c;
    }

    Customer& peek() {
      if(front = NULL){
        throw(1);
      }
      Customer c = front->person;
      return c;
    }

    void clear(){
      while( !isEmpty() ){
          Node * temp = front;
          front = front -> toBack;
          delete(temp);
      }
    }

    bool isEmpty(){
        return front == NULL;
    }

    double getScanTime(){
        return scanTime;
    }
    double getPayTime(){
        return payTime;
    }
    double getTotalWaitTime(){
        return totalCustomerWaitTime;
    }

    void setTotalWaitTime(double waitTime){
        totalCustomerWaitTime = waitTime;
    }
};
