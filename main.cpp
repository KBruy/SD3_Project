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

void showHashTableListMenu() {
    cout <<endl;
    cout <<"===== HASHTABLE LIST ====="<<endl;
    cout << "1. Dodaj element"<<endl;
    cout << "2. Znajdz element"<<endl;
    cout <<"3. Wyswietl tablice" << endl;
    cout << "0. Powrot"<<endl;
}

void runHashTableListMenu() {
   int capacity;

   cout << "podaj rozmiar tablicy: ";
   cin >> capacity;
   
   HashTableList table(capacity);

   int choice;

   do {
    showHashTableListMenu();
    cin >> choice;

    switch (choice) {
        case 1: {
            int key;
            int value;

            cout << "Podaj klucz: ";
            cin >> key;
            
            cout << "Podaj wartosc";
            cin >> value;

            table.insert(key, value);

            cout << "Dodano element" << endl;
            break;
        }

        case 2: {
            int key;
            int value;

            cout << "Podaj klucz do znalezienia: ";
            cin >> key;

            if (table.find(key, value)) {
                cout << "Znaleziono wartosc: "<<value <<endl;
            } else {
                cout << "Nie znaleziono elementu" << endl;
            }

            break;
        }

        case 3:
            table.print();
            break;

        case 0:
            cout << "Powrot do menu glownego" << endl;
            break;

        default:
        cout << "Niepoprawny wybor" << endl;
        break;
        
    }
   } while (choice != 0);
}

int main() {
    int choice;

    do {
        showMainMenu();
        cin>>choice;
        switch(choice){
            case 1: {
               runHashTableListMenu();
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