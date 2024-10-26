// Car Instrument Simulator.cpp : This file contains a program which demonstrates the interaction of a FuelGauge object with an Odometer object.

#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;

int main()
{
  // Declare the fuel gauge and odometer objects
  FuelGauge tank;
  Odometer odom(tank);

  int amountToAdd = 0, amount = 0;

  // Fill the tank
  if (amountToAdd > 0)
  {

    while ((++amount <= amountToAdd) && !(tank.getAmount() == FuelGauge::getCapacity()))
    {
      tank.fill();
    }

  }
  else 
  {
    while (tank.getAmount() < FuelGauge::getCapacity())
      tank.fill();
  }

  // Travel until the car runs out of gas
  while (tank.getAmount() > 0)
  {
    odom.travel();
    cout << "Odometer: " << odom.getMileage() << " Fuel: " << tank.getAmount() << endl;
  }
}