#include "AlchemyWorkshop.h"
using namespace std;

void AlchemyWorkshop::displayAllRecipes() const {
    vector<PotionRecipe> recipesList = recipemanager->getAllRecipes();
    if (recipesList.empty()) {
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
    for (size_t i = 0; i < recipesList.size(); ++i) {
        cout << "● 물약 이름: " << recipesList[i].getPotionName() << endl;
        cout << "- 현재 재고: " << stockmanager->getStock(recipesList[i].getPotionName()) << endl;
        cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipesList[i].getIngredients().size(); ++j) {
            cout << recipesList[i].getIngredients()[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipesList[i].getIngredients().size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << "---------------------------" << endl << endl;
}

void AlchemyWorkshop::addRecipe(string name, vector<string> ingredients)
{
    recipemanager->addRecipe(name, ingredients);
    stockmanager->initializeStock(name);
    cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl << endl;
}

void AlchemyWorkshop::SearchRecipeByName(string name)
{
    vector<PotionRecipe> SearchList = recipemanager->findRecipeByName(name);
    recipemanager->findRecipeByName(name);
    if (!SearchList.empty())
    {
        cout << "\n-------[ 물약 목록 ]-------" << endl;
        for (int i = 0; i < SearchList.size(); i++)
        {
            cout << "● 물약 이름: " << SearchList[i].getPotionName() << endl;
            cout << "- 현재 재고: " << stockmanager->getStock(SearchList[i].getPotionName()) << endl;
            cout << "  > 필요 재료: ";
            for (int j = 0; j < SearchList[i].getIngredients().size(); j++)
            {
                cout << SearchList[i].getIngredients()[j];
                if (j != SearchList[i].getIngredients().size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        cout << "---------------------------" << endl << endl;
    }
    else
    {
        cout << "\n등록된 레시피가 없습니다." << endl;
    }
}

void AlchemyWorkshop::SearchRecipeByIngredient(string ingredient)
{
    vector<PotionRecipe> SearchList = recipemanager->findRecipeByIngredient(ingredient);
    if (!SearchList.empty())
    {
        cout << "\n-------[ 물약 목록 ]-------" << endl;
        for (int i = 0; i < SearchList.size(); i++)
        {
            cout << "● 물약 이름: " << SearchList[i].getPotionName() << endl;
            cout << "- 현재 재고: " << stockmanager->getStock(SearchList[i].getPotionName()) << endl;
            cout << "  > 필요 재료: ";
            for (int j = 0; j < SearchList[i].getIngredients().size(); j++)
            {
                cout << SearchList[i].getIngredients()[j];
                if (j != SearchList[i].getIngredients().size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        cout << "---------------------------" << endl << endl;
    }
    else
    {
        cout << "\n등록된 레시피가 없습니다." << endl;
    }
}

void AlchemyWorkshop::DispensePotion(string name)
{
    if (stockmanager->dispensePotion(name) == true)
    {
        stockmanager->getStock(name);
        cout << "\n[" << name << "] 현재 재고 : " << stockmanager->getStock(name) << endl;

        while (true)
        {
            int Input_choice;
            cout << "1. [" << name << "] 지급" << endl;
            cout << "2. 취소" << endl;
            cout << "선택: ";
            cin >> Input_choice;

            if (cin.fail())
            {
                cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            switch (Input_choice)
            {
            case 1:
                stockmanager->setStock(name, stockmanager->getStock(name) - 1);
                cout << "\n[ 포션 지급 완료 ]" << endl;
                cout << "[" << name << "] 재고 : " << stockmanager->getStock(name) << endl << endl;
                break;
            case 2:
                break;
            default:
                cout << "잘못된 입력입니다." << endl;
                break;
            }
            break;
        }
    }
}

void AlchemyWorkshop::ReturnPotion(string name)
{
    if (stockmanager->returnPotion(name) == true)
    {
        stockmanager->getStock(name);
        cout << "\n[" << name << "] 현재 재고 : " << stockmanager->getStock(name) << endl;

        while (true)
        {
            int Input_choice;
            cout << "1. [" << name << "] 반환" << endl;
            cout << "2. 취소" << endl;
            cout << "선택: ";
            cin >> Input_choice;

            if (cin.fail())
            {
                cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            switch (Input_choice)
            {
            case 1:
                stockmanager->setStock(name, stockmanager->getStock(name) + 1);
                cout << "\n[ 포션 반환 완료 ]" << endl;
                cout << "반환 후 [" << name << "] 재고 : " << stockmanager->getStock(name) << endl << endl;
                break;
            case 2:
                break;
            default:
                cout << "잘못된 입력입니다." << endl;
                continue;
            }
            break;
        }
    }
}