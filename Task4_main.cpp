#include "AlchemyWorkshop.h"
using namespace std;

int main() {
    AlchemyWorkshop myWorkshop;

    while (true) 
    {
        cout << "★  연금술 공방 관리시스템 ★" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 모든 레시피 출력" << endl;
        cout << "3. 물약 검색" << endl;
        cout << "4. 물약 지급" << endl;
        cout << "5. 공병 반환" << endl;
        cout << "6. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail()) 
        {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) 
        {
            string name;
            cout << "\n[ 레시피 추가 ]" << endl;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            vector<string> ingredients_input;
            string ingredient;
            cout << "[ 필요한 재료들을 입력하세요. ] (입력 완료 시 '끝' 입력)" << endl;

            while (true) 
            {
                cout << "재료 입력: ";
                getline(cin, ingredient);

                if (ingredient == "끝") 
                {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            if (!ingredients_input.empty()) 
            {
                myWorkshop.AddRecipe(name, ingredients_input);
            }
            else 
            {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
            }
        }
        else if (choice == 2) 
        {
            myWorkshop.displayAllRecipes();
        }
        else if (choice == 3) 
        {
            while (true)
            {
                int NextChoice;
                string Input_name;
                string Input_ingredient;
                cout << "\n[ 검색 기준 ]" << endl;
                cout << "1. 물약이름 기준 검색" << endl;
                cout << "2. 물약재료 기준 검색" << endl;
                cout << "선택: ";
                cin >> NextChoice;

                if (cin.fail())
                {
                    cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                switch (NextChoice)
                {
                case 1:
                    cout << "\n[ 물약이름 검색 ]" << endl;
                    cout << "물약이름 : ";
                    cin.ignore(10000, '\n');
                    getline(cin, Input_name);
                    myWorkshop.SearchRecipeByName(Input_name);
                    break;
                case 2:
                    cout << "\n[ 물약재료 검색 ]" << endl;
                    cout << "물약재료 : ";
                    cin.ignore(10000, '\n');
                    getline(cin, Input_ingredient);
                    myWorkshop.SearchRecipeByIngredient(Input_ingredient);

                    break;
                default:
                    cout << "잘못된 입력입니다." << endl;
                    continue;
                }
                break;
            }
        }
        else if (choice == 4)
        {
            string Input_name;
            cout << "\n[지급받을 포션 입력]" << endl;
            cout << "포션이름 : ";
            cin.ignore(10000, '\n');
            getline(cin, Input_name);
            myWorkshop.DispensePotion(Input_name);
        }
        else if (choice == 5)
        {
            string Input_name;
            cout << "\n[반환 할 포션 입력]";
            cout << "포션이름 : ";
            cin.ignore(10000, '\n');
            getline(cin, Input_name);
            myWorkshop.ReturnPotion(Input_name);
        }
        else if (choice == 6) 
        {
            cout << "공방 문을 닫습니다..." << endl;
            break;
        }
        else 
        {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}