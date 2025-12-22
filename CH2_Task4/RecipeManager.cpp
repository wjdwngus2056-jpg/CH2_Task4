#include "RecipeManager.h"
using namespace std;

void RecipeManager::addRecipe(string name, vector<string> ingredients)
{
    PotionRecipe* potion = new PotionRecipe(name, ingredients);
    recipes.push_back(*potion);
}

vector<PotionRecipe> RecipeManager::findRecipeByName(string name)
{
    vector<PotionRecipe> recipe_list;

    for (int i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].getPotionName() == name)
        {
            recipe_list.push_back(recipes[i]);
        }
    }
    return recipe_list;
}

vector<PotionRecipe> RecipeManager::findRecipeByIngredient(string ingredient)
{
	vector<PotionRecipe> recipe_list;
	for (int i = 0; i < recipes.size(); i++)
	{
		for (int j = 0; j < recipes[i].getIngredients().size(); j++)
		{
			if (recipes[i].getIngredients()[j] == ingredient)
			{
				recipe_list.push_back(recipes[i]);
			}
		}
	}
	return recipe_list;
}

const vector<PotionRecipe>& RecipeManager::getAllRecipes()
{
    return recipes;
}