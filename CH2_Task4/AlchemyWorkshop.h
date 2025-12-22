#pragma once
#include "RecipeManager.h"
#include "StockManager.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AlchemyWorkshop {
public:
    AlchemyWorkshop()
    {
        recipemanager = new RecipeManager;
        stockmanager = new StockManager;
    }

    void displayAllRecipes() const;

    void AddRecipe(string name, vector<string> ingredients);
    void SearchRecipeByName(string name);
    void SearchRecipeByIngredient(string ingredient);
    void DispensePotion(string name);
    void ReturnPotion(string name);
private:
    RecipeManager* recipemanager;
    StockManager* stockmanager;
};