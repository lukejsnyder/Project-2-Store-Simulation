
#pragma once
#include "Customer.cpp"
#include <stdlib.h>

enum EventType { Arrival, EndShopping, EndCheckout };

class Event{
private:
  EventType type;
  double simTime;
  Customer person;

public:
  Event(){
      simTime = -1;
  }

  Event(EventType e, double t, Customer c){
    type = e;
    simTime = t;
    person = c;
  }

  EventType getType(){
      return type;
  }
  double getSimTime(){
      return simTime;
  }
  Customer getPerson(){
      return person;
  }

   void setType(EventType type){
      this->type = type;
  }
   void setSimTime(double simTime){
      this->simTime = simTime;
  }
   void setPerson(Customer person){
      this->person = person;
  }

  bool operator<(const Event& other){
    return (simTime < other.simTime);
  }

  bool operator>(const Event& other){
    return (simTime > other.simTime);
  }

  bool operator<=(const Event& other){
    return(simTime <= other.simTime);
  }

  bool operator>=(const Event& other){
    return (simTime >= other.simTime);
  }

  bool operator==(const Event& other){
    return (simTime == other.simTime);
  }

  bool operator!=(const Event& other){
    return (simTime != other.simTime);
  }
};
