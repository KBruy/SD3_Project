#include <iostream>
#include "HashTableList.h"
using namespace std;

void showMainMenu() {
    cout << endl;
    cout <<"==== SD 3 ===="<< endl;
    cout << "1. HashTableList" << endl;
    cout << "2. HashTableOpen" << endl;
    cout << "3. HashTableAVL" << endl;
    cout << "0. Wyjscie"<<endl;
    cout <<"Wybor: ";

}

int main() {
    int choice;

    do {
        showMainMenu();
        cin>>choice;
        switch(choice){
            case 1: {
                HashTableList table(10);
                table.print();
                break;
            }

            case 2:
            cout <<"Wybrano HashTableOpen"<<endl;
            break;

            case 3:
            cout <<"Wybrano HashTableAVL"<<endl;

            case 0:
            cout <<"Koniec programu"<<endl;

            default:
            cout <<"Niepoprawny wybor"<<endl;
            break;
        }

    } while (choice != 0);
    return 0;
}