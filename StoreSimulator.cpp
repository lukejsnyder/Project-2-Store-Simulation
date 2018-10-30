// basic file operations
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "Customer.cpp"
#include "Event.cpp"
#include "PriorityQueue.cpp"
#include "RegisterQueue.cpp"
using namespace std;

class StoreSimulator{

private:
    PriorityQueue<Event> events;
    vector<RegisterQueue> registers;
    double simClock;
    int totalNumberOfRegisters = 8;

public:
    StoreSimulator(){
        simClock = 0;
    }

    void startSimulation() {
        loadRegisters(8, 0); //<--Update this line as needed.  Currently all standard registers.
        loadCustomerData();

        while(events.size() > 0){
            Event e = events.remove();
            simClock = e.getSimTime();
            if(e.getType() == Arrival){
                handleArrival(e);
            }else if(e.getType() == EndShopping){
                handleEndShopping(e);
            }else{
                handleEndCheckout(e);
            }
        }

        statsHandling();

    }

    void loadCustomerData(){
        double arriveTime, avgSelectionTime;
        int items;
        ifstream myfile ("arrival.txt");
        if (myfile.is_open()){
            while ( myfile >> arriveTime >> items >> avgSelectionTime){

                Customer cust(arriveTime, items, avgSelectionTime) ;
                Event e(Arrival, arriveTime, cust);
                events.insert(e);
            }
            myfile.close();
        }else{
            throw(1);
        }
    }

    void loadRegisters(int numNormal, int numSelfScan){
        for(int i = 0; i < numNormal; i ++){
            RegisterQueue r(2.3, .02);
            registers.push_back(r);
        }
        for(int i = 0; i < numSelfScan; i++){
            RegisterQueue r(3.7, .08);
            registers.push_back(r);
        }
    }

    void handleArrival(Event& e){
        double endShopTime = e.getPerson().getCustomerArrival() *
          (e.getPerson().getOrderSize() * e.getPerson().getItemPickupTime());
        Event p(EndShopping, endShopTime, e.getPerson());
        p.getPerson().setEndShopping(endShopTime);
        events.remove();
        events.insert(p);
    }

    void handleEndShopping(Event& e){
        Customer q = e.getPerson();
        int shortestLine = getShortestLine();
        q.setRegisterCheckoutLine(shortestLine);
        registers[shortestLine].enqueue(q);
        double waitTime = q.getEndShopping() +
          registers[shortestLine].getTotalWaitTime();
        q.setStartCheckingOut(waitTime);
        events.remove();
        Event p(EndCheckout, waitTime, q);
        events.insert(p);

    }

    void handleEndCheckout(Event& e){

    }

    int getShortestLine(){
        for(int i = 0; i < totalNumberOfRegisters - 1; i++){
          int j;
          int k;
          if(i == 0){
            j = i;
            k = j + 1;
          }
        }
    }

    void statsHandling(){
      double meanWaitTotal; // Used to find the mean
      double mean; //Average of customer wait time
      double waitMoreThan2min; //Customers who wait more than 2 minutes
      double waitMoreThan3min; //Customers who wait more than 3 minutes
      double waitMoreThan5min; //Customers who wait more than 5 minutes
      double waitMoreThan10min; //Customers who wait more than 10 minutes
//---------------------------------------------------------------------------------------------------------
      // Prints the mean waiting time of the customers.
      for(int i = 0; i< registers.size(); i++ ){ //Iterates through <vector> registers
        meanWaitTotal = meanWaitTotal + registers[i]->getTotalWaitTime(); //Calls getTotalWaitTime() from RegisterQueue through <vector> registers.
      }
      mean = meanWaitTotal/RegisterQueue->getTotalNumberOfCustomers(); // To find the mean you must first
      cout << "The mean wait time for the customers was" << mean << '\n';
//---------------------------------------------------------------------------------------------------------
      //Prints the total number of customers who waited more than 2 minutes.
        for(int i = 0; i< registers->size(); i++ ){ //Iterates through <vector> registers
            if(RegisterQueue->getTotalWaitTime() > 2){ //Calls getTotalWaitTime from register
              waitMoreThan2min = waitMoreThan2min + 1; // Adds a customer that has been waiting longer than 2 minutes
            }
        }
    }

};
