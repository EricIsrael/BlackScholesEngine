/*
 
 BSM.h
 Black Scholes Options Model
 
 */

#ifndef BSM_hpp
#define BSM_hpp

#include "iostream"

class BSM // BSM = black scholes monte carlo
{
public:
    BSM(float, float, float, float, float, long, long); // 5 floats, two longs
    
    ~BSM(); //  * Remember no brackets... defining it
    
    float getBsmAsset();
    float getBsmStrike();
    float getBsmGrowth();
    float getBsmVol();
    float getBsmYears();
    long getBsmSteps();
    long getBsmSimulations();
    
    void logNormalRandomWalk();
    
    
    double getCallPrice();
    double getPutPrice();
    
    double rn(); // random... USE FUNCTION TEMPLATE OVER THIS!!!!
    
private:
    float bsmAsset;
    float bsmStrike;
    float bsmGrowth;
    float bsmVol;
    float bsmYears;
    long bsmSteps;
    long bsmMonteCarloSims;
    
    double bsmCallPrice;
    double bsmPutPrice;
};

#endif /* BSM_hpp */
