#pragma once

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);

class TemperatureCheck{
  public:
  virtual BreachType classifyLimits(double temperatureInC) = 0;
};

class Passive_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class High_Active_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class Med_Active_Cooling : public TemperatureCheck{
  public:
  BreachType classifyLimits(double temperatureInC) override;
};

class TemperatureContext{
  private:
  TemperatureCheck temperatureCheck;
  public:
  TemperatureContext(TemperatureCheck temperatureCheck){
   this.temperatureCheck = temperatureCheck;
  }
  BreachType classifyTemperature(double temperatureInC);
};

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert();

class Alert{
  public:
  virtual void sendAlertMsg(BreachType breachType) = 0;
};

class AlertToEmail : public Alert{
  public :
  void sendAlertMsg(BreachType breachType) override;
}

class AlertToController : public Alert{
  public :
  void sendAlertMsg(BreachType breachType) override;
}

class AlertToConsole : public Alert{
  public :
  void sendAlertMsg(BreachType breachType) override;
}

class AlertContext{
  private:
  Alert alert;
  public:
  AlertContext( Alert alert){
    this.alert = alert;
  }
  void sendMsg(BreachType breachType);
};
