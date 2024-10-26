#pragma once
#include <iostream>

// Simulates a fuel guage in a car
class FuelGauge
{
public:
  // Returns the number of gallons of fuel in the tank
  int getAmount() { return amount; }

  // Outputs the number 
  void print() { std::cout << amount; }

  // Increments the amount of fuel in the tank by 1 gallon.
  // If amount goes above the tank capacity, the amount
  // is set to the tank capacity.
  void fill()
  {
    if (++amount > MAX_AMOUNT)
      amount = MAX_AMOUNT;	
  }

  // Decrements the amount of fuel in the tank by 1 gallon.
  // if amount goes below 0, sets the amount to 0.
  void empty()
  {
    if (--amount < 0)
      amount = 0;
  }

  // Constructor allows for an pre-existing amount of gas in the tank.
  FuelGauge(int a = 0) : amount(a) { ; }

  // Allows access to the class max amount for the fuel guage
  static int getCapacity() { return MAX_AMOUNT;  }

private:
  int amount = 0;             // current gallons in fuel tank
  static int MAX_AMOUNT;     // maximum capacity or fuel tank in gallons
};

int FuelGauge::MAX_AMOUNT = 15;
