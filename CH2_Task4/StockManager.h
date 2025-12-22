#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class StockManager
{
public:
    void initializeStock(string potionName);
    bool dispensePotion(string potionName);
    bool returnPotion(string potionName);

    const int& getStock(string potionName);
    void setStock(string potionName, int value);
private:
    map<string, int> potionStock;
    const int Max_STOCK = 3;
};