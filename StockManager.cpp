#include "StockManager.h"

void StockManager::initializeStock(string potionName)
{
    potionStock.insert(make_pair(potionName, 3));
}

bool StockManager::dispensePotion(string potionName)
{
    if (potionStock.find(potionName) != potionStock.end())
    {
        if (potionStock[potionName] > 0 && potionStock[potionName] <= Max_STOCK)
        {
            return true;
        }
        else if (potionStock[potionName] == 0)
        {
            cout << "[" << potionName << "] 재고가 없습니다." << endl << endl;
            return false;
        }
    }
    else
    {
        cout << "[" << potionName << "] 포션이 없습니다." << endl << endl;
        return false;
    }
}
bool StockManager::returnPotion(string potionName)
{
    if (potionStock.find(potionName) != potionStock.end())
    {
        if (potionStock[potionName] >= Max_STOCK)
        {
            cout << "[" << potionName << "] 재고가 가득 차 있습니다." << endl << endl;
            return false;
        }
        else if (potionStock[potionName] < Max_STOCK)
        {
            return true;
        }
    }
    else
    {
        cout << "[" << potionName << "] 포션이 없습니다." << endl << endl;
        return false;
    }
}

const int& StockManager::getStock(string potionName)
{
    if (potionStock.find(potionName) != potionStock.end())
    {
        return potionStock[potionName];
    }
    return 0;
}
void StockManager::setStock(string potionName, int value)
{
    if (potionStock.find(potionName) != potionStock.end())
    {
        potionStock[potionName] = value;
    }
}