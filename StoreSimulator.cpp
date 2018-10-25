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
    vector<RegisterQueue> registers;
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
        double endShopTime = e.getPerson().getCustomerArrival() * (e.getPerson().getorderSize() * getItemPickupTime()));
    }

    void handleEndShopping(Event& e){
        //You will fill in this method.
    }



    void handleEndCheckout(Event& e){
        //You will fill in this method.
    }

    int getShortestLine(){
        for(int i = 0; i < totalNumberOfRegisters - 1; i++){
          registers[i]
        }
    }

    void statsHandling(){
        //You will fill in this method.
    }
};
