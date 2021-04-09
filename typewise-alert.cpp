#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType Passive_Cooling::classifyLimits(double temperatureInC){
    int lowerLimit = 0;
    int upperLimit = 35;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

BreachType High_Active_Cooling::classifyLimits(double temperatureInC){
    int lowerLimit = 0;
    int upperLimit = 45;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

BreachType Med_Active_Cooling::classifyLimits(double temperatureInC){
    int lowerLimit = 0;
    int upperLimit = 40;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

BreachType TemperatureContext::classifyTemperature(double temperatureInC){
  return temperatureCheck.classifyLimits(double temperatureInC);
}
  
void checkAndAlert() {
  TemperatureContext temperatureContext = new TemperatureContext(new Passive_Cooling());
  temperatureContext.classifyTemperature(7);
  
  AlertContext alertContext = new AlertContext(new AlertToEmail());
  alertContext.sendMsg();
}

void AlertToEmail::sendAlertMsg(BreachType breachType){
    const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
}

  void AlertToController::sendAlertMsg(BreachType breachType){
      const unsigned short header = 0xfeed;
      printf("%x : %x\n", header, breachType);
  }
  
    void AlertToConsole::sendAlertMsg(BreachType breachType){
      printf("%x", breachType);
  }
