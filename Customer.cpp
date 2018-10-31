#pragma once
#include <ostream>
using namespace std;

class Customer{
private:
  double customerArrival; //when the customer arrives at the store
  int orderSize; //how many items they will buy
  double itemPickupTime; //how long on average it takes the customer to pick up an item.
  int registerCheckoutLine;//what line they hop in, should be the shortest
  double endShopping;//start waiting variable
  double startCheckingOut;//after waiting

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

  int getOrderSize() {
    return orderSize;
  }

  void setOrderSize(int orderSize) {
    this->orderSize = orderSize;
  }
  double getItemPickupTime() {
    return itemPickupTime;
  }
  void setItemPickupTime(int itemPickupTime) {
    this->itemPickupTime = itemPickupTime;
  }
  double getEndShopping(){
    return endShopping;
  }
  void setEndShopping(double endShopTime){
    endShopping = endShopTime;
  }
  double getStartCheckingOut(){
    return startCheckingOut;
  }
  void setStartCheckingOut(double startCheckout){
    startCheckingOut = startCheckout;
  }
  int getRegisterCheckoutLine(){
    return registerCheckoutLine;
  }
  void setRegisterCheckoutLine(int shortestLine){
    registerCheckoutLine = shortestLine;
  }
};
