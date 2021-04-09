#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

class TemperatureCheck{
  public:
  virtual BreachType classifyLimits(double temperatureInC) = 0;
};

class Passive_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class Highw_Active_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class Med_Active_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class TemperatureContext{
  private:
  TemperatureCheck temperatureCheck
  public:
  TemperatureContext(TemperatureCheck temperatureCheck){
   this.
};

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
