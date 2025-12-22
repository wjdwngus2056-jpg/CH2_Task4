#pragma once
#include "PotionRecipe.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RecipeManager
{
public:
    void addRecipe(string name, vector<string> ingredients);
    vector<PotionRecipe> findRecipeByName(string name);
    vector<PotionRecipe> findRecipeByIngredient(string ingredient);

    const vector<PotionRecipe>& getAllRecipes();
private:
    vector<PotionRecipe> recipes;
};