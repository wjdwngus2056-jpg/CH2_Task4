#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PotionRecipe {
public:
    PotionRecipe(const string& name, const vector<string>& ingredients)
        : potionName(name), ingredients(ingredients) {}

    string getPotionName();
    vector<string> getIngredients();
private:
    string potionName;
    vector<string> ingredients;
};