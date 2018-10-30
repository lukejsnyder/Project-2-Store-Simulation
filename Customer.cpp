#pragma once
#include <ostream>
using namespace std;

class Customer{
private:
  double customerArrival; //when the customer arrives at the store
  int orderSize; //how many items they will buy
  double itemPickupTime; //how long on average it takes the customer to pick up an item.
  int registerCheckoutLine;
  double endShopping;
  double startCheckingOut;


  friend ostream& operator<<(ostream& os, const Customer& c){
    os << c.customerArrival << " " << c.orderSize ;
    return os;
  }

public:
  Customer(){
    this->customerArrival = 0;
    this->orderSize = 0;
  }

  Customer(double customerArrival, int orderSize, double itemPickupTime) {
    this->customerArrival = customerArrival;
    this->orderSize = orderSize;
    this->itemPickupTime = itemPickupTime;

  }


  /******  GETTERS_SETTERS  *********/
  double getCustomerArrival() {
    return customerArrival;
  }

  void setCustomerArrival(double customerArrival) {
    this->customerArrival = customerArrival;
  }
  double getEndShopping(){
    return endShopping;
  }

  int getOrderSize() {
    return orderSize;
  }

  void setOrderSize(int orderSize) {
    this->orderSize = orderSize;
  }
  int getItemPickupTime() {
    return itemPickupTime;
  }
  void setItemPickupTime(int itemPickupTime) {
    this->itemPickupTime = itemPickupTime;
  }
};
