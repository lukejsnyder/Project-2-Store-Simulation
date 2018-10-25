// basic file operations
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Customer.cpp"
#include "RegisterQueue.cpp"
using namespace std;

class RegisterSimulator{

private:

    RegisterQueue  checkoutRegister;
    double simClock;

public:
    RegisterSimulator() : checkoutRegister(1.5, .02)
    {

        simClock = 0;
    }

    void startSimulation() {
        loadCustomerData();
        simClock = checkoutRegister.peek().getCustomerArrival();
        while(!checkoutRegister.isEmpty()){
            checkout();
        }
    }

    void loadCustomerData(){
        ifstream myfile ("customer_checkout_data_test.txt");
        if (!myfile.is_open()){
            cout << "ERROR READING FILE!" << endl;
            throw(1);
        }

        double arrivalTime;
        int items;

        while ( myfile >> arrivalTime >> items){
            Customer cust(arrivalTime, items) ;
            checkoutRegister.enqueue(cust);
        }

        myfile.close();
    }

    void checkout(){
        Customer c = checkoutRegister.dequeue(); //Next thing to be removed without removing it
        double finishCheckoutTime = (c.getOrderSize() * checkoutRegister.getScanTime()) + checkoutRegister.getPayTime() + simClock;
        simClock = finishCheckoutTime;
        checkoutRegister.setTotalWaitTime( checkoutRegister.getTotalWaitTime() + (simClock - c.getCustomerArrival()) );
    }

};
