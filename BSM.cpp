//
//  BSM.cpp
//  Black Scholes Options Model
//
//  Created by Eric Israel on 10/26/16.
//  Copyright © 2016 Eric Israel. All rights reserved.
//

#include "BSM.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

BSM::BSM(float ass,
         float strk,
         float grwth,
         float volty,
         float yrs,
         long steps,
         long sims)

{
    bsmAsset = ass;
    bsmStrike = strk;
    bsmGrowth = grwth;
    bsmVol = volty;
    bsmYears = yrs;
    bsmMonteCarloSims = sims;
}
BSM::~BSM(){}

/*
 
 Black Scholes =  S{PHI}(d1) - Ke-rT{PHI}(d2)
 
 */

void BSM::logNormalRandomWalk(){
    
    srand((unsigned)time(0));
    
    double callPayoffPot = 0.0;
    double putPayoffPot = 0.0;
    double timeStep = getBsmYears()/getBsmSteps();
    double sqrtTimeStep = sqrt(timeStep);
    
    // for loop for simulations
    
    for(long i = 1; i<= bsmMonteCarloSims;i++) // simulations
    {
        double assetPrice = getBsmAsset();
        
        // for loop for number of steps
        
        for(int j=1; j<= getBsmSteps(); j++)
        {
            assetPrice = assetPrice * (1+getBsmGrowth()*timeStep + getBsmVol()*sqrtTimeStep)* (
                                                                                               
                                                                                               rn() + rn() + rn() + rn() + rn() + rn() + rn() + rn() + rn() + rn() + rn() + rn() - 6);
        }
        
        if (assetPrice > getBsmStrike()){
            callPayoffPot += (assetPrice - getBsmStrike()); // if final price is > call option price add 5 onto pot
        }
        
        else if (assetPrice < getBsmStrike()){
            putPayoffPot += (getBsmStrike() - assetPrice);
        }
        
    }
    
    bsmCallPrice = callPayoffPot / getBsmSimulations();
    bsmPutPrice = putPayoffPot / getBsmSimulations();
    
    return;
    
}

double BSM::rn(){
    return (double)rand()/(double)(RAND_MAX+ 1.0);  // looks like rand in excel *USE FUNCTION TEMPLATES INSTEAD
}
float BSM::getBsmAsset(){
    return bsmAsset;
}

float BSM::getBsmStrike(){
    return bsmStrike;
}

float BSM::getBsmGrowth(){
    return bsmGrowth;
}

float BSM::getBsmVol(){
    return bsmVol;
}

long BSM::getBsmSteps(){
    return bsmSteps;
}

long BSM::getBsmSimulations(){
    return bsmMonteCarloSims;
}

double BSM::getPutPrice(){
    return bsmPutPrice;
}

double BSM::getCallPrice(){
    return bsmCallPrice;
}
