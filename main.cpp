
/*
 
 Black Scholes Options Pricing Model
 Createad by Eric Israel
 Created On 10/4/2016
 last modfied on 2/14/2017
 
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include "BSM.hpp"


using namespace std;

enum BSMExecution
{
    ASSET = 1,  // CUrRENT ASSET PRICE
    STRIKE = 2, // PRICE OF OPTION
    GROWTH_RATE = 3, // OF MARKET
    VOLALTITY = 4, // of stock
    YEARS = 5, // HOW MANY YEARS BEFORE MATURITY/EXPIRATION
    STEPS= 6, // how many steps
    SIMULATIONS = 7 // how many times the monte carlo engine going to run
};

int main(int argc, const char* argv[]) // argV = argument vector ... one dimensional array of strings
{
    // BSM = BLACK SCHOLES MONTE-CARLO
    
    
    BSM bsm(atof(argv[ASSET]), // turns string into a float
            atof(argv[STRIKE]),
            atof(argv[GROWTH_RATE]),
            atof(argv[VOLALTITY]),
            atof(argv[YEARS]),
            atol(argv[STEPS]),  // turns argument into long
            atol(argv[SIMULATIONS]));
    
    cout << "Asset: " << bsm.getBsmAsset() << endl <<
    "Strike: " << bsm.getBsmStrike() << endl <<
    "Growth: " << bsm.getBsmAsset() << endl <<
    "Volatity: " << bsm.getBsmVol() << endl <<
    "Years: " << bsm.getBsmYears() << endl <<
    "Steps: " << bsm.getBsmSteps() << endl <<
    "Simulations" << bsm.getBsmSimulations() << endl;
    
    bsm.logNormalRandomWalk();
    
    cout << endl;
    
    cout << "Call Option Price: " << bsm.getCallPrice() << endl;
    cout << "Put Option Price: " << bsm.getPutPrice()<< endl;
    
    return (0);
    
}
