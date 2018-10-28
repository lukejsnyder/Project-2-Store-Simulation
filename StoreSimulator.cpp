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
    std::vector<RegisterQueue*> registers;
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
        while(events.size() > 0){
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
        //double endShopTime = e.getPerson().getCustomerArrival() * (e.getPerson().getorderSize() * getItemPickupTime()));
    }

    void handleEndShopping(Event& e){
        //You will fill in this method.
    }



    void handleEndCheckout(Event& e){
        //You will fill in this method.
    }
    //Register with shortest number of customers
    int getShortestLine(){
    //     int shortestLine = 0; //index for current shortest line
    //     int nextLine = 0; //
    //     for(int i = 0; i < totalNumberOfRegisters - 1; i++){
    //         if(shortestLine > numberOfCustomers.registers[i] ){
    //           shortestLine = shortestLine + numberOfCustomers.registers[i];
    //         }
    //       registers[i]
    //     }
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
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------


    }
};
