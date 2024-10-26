#pragma once
#include <iostream>
#include "FuelGauge.h"

class Odometer
{
public:
  // Returns the number of miles on the odometer
  int getMileage() { return mileage; }

  // Sends the number of miles on the odometer to the display
  void print() { std::cout << mileage;  }

  // Adds 1 mile to the odometer, if more than maximum miles is reached, odometer resets to 0
  void incrementMileage()
  {
    if (++mileage > MAX_MILEAGE) 
      mileage = 0;
  }

  // Using the miles per gallon rating for the car, determines 
  // when to get the fuel gauge to decrease by one gallon, the number of gallons in its tank.  
  void travel()
  {
    static int milesMPG = 0;
    incrementMileage();
    if (++milesMPG == MPG)
    {
      tank.empty();
      milesMPG = 0;
    }
  }

  // Constructor requires an associated FuelGauge object to be supplied and
  // allows for an optional existing mileage reading on the odometer
  Odometer(FuelGauge &t, int m = 0): mileage(m), tank(t){ ; }

private:
  int mileage = 0;     // Current odometer reading
  FuelGauge &tank;     // Access to an associated FuelTank object
  static int MAX_MILEAGE;  // odometer capacity
  static int MPG;  // Fuel rating for the car
};

int Odometer::MAX_MILEAGE = 999999;
int Odometer::MPG = 24;