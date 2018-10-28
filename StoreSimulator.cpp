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
    MyPriorityQueue<Event> events;
    std::vector<RegisterQueue> registers;
    double simClock;
    int totalNumberOfRegisters = 8;

public:
    StoreSimulator(){
        simClock = 0;
    }

    void startSimulation() {
        loadRegisters( 8, 0); //<--Update this line as needed.  Currently all standard registers.
        loadCustomerData();

        int indexArrival=0, indexES=0, indexEC=0;
        while(Event.size() > 0){
            Event e = events.remove();
            simClock = e.simTime;
            if(e.type == Arrival){
                handleArrival(e);
            }else if(e.type == EndShopping){
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
            RegisterQueue r(1.5, .01);
            registers.push_back(r);
        }
        for(int i = 0; i < numSelfScan; i++){
            RegisterQueue r(3.0, .04);
            registers.push_back(r);
        }
    }

    void handleArrival(Event& e){

    }

    void handleEndShopping(Event& e){
        //You will fill in this method.
    }



    void handleEndCheckout(Event& e){

    }
    //Register with shortest number of customers
    int getShortestLine(){
        int shortestLine = 0; //index for current shortest line
        for(int i = 0; i < registers.size(); i++){
          if(shortestLine > registers[i].getTotalNumberOfCustomers() ){
            shortestLine = registers[i].getTotalNumberOfCustomers();
          }
          return shortestLine;
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
        for(int i = 0; i <registers.size(); i++ ){
          meanWaitTotal = meanWaitTotal + registers[i].getTotalNumberOfCustomers();
          mean = meanWaitTotal/registers.size();
        }
          std::cout << "The mean is: " << mean << '\n';

//---------------------------------------------------------------------------------------------------------
        // //Prints the total number of customers who waited more than 2 minutes.
          for(int i = 0; i< registers.size(); i++ ){
              if(registers[i].getTotalWaitTime() > 3 ){
                waitMoreThan3min = waitMoreThan3min +1;
              }
          }
          std::cout << "There are: " << waitMoreThan3min << "customers who waited more than 3 minutes"<< '\n';
//---------------------------------------------------------------------------------------------------------
          for(int i = 0; i< registers.size(); i++ ){
              if(registers[i].getTotalWaitTime() > 3 ){
                waitMoreThan5min = waitMoreThan5min +1;
    }
}
std::cout << "There are: " << waitMoreThan5min << "customers who waited more than 5 minutes"<< '\n';
//---------------------------------------------------------------------------------------------------------
          for(int i = 0; i< registers.size(); i++ ){
              if(registers[i].getTotalWaitTime() > 10 ){
                waitMoreThan10min = waitMoreThan10min +1;
              }
        }
std::cout << "There are: " << waitMoreThan10min << "customers who waited more than 10 minutes"<< '\n';
//---------------------------------------------------------------------------------------------------------
    }
};
