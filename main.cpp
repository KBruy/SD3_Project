#include <iostream>
#include "HashTableList.h"
#include "HashTableOpen.h"
#include <AVLTree.h>

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
//----------------------------------------------
//HASH TABLE MENU
//----------------------------------------------

void showHashTableListMenu() {
    cout <<endl;
    cout <<"===== HASHTABLE LIST ====="<<endl;
    cout << "1. Dodaj element"<<endl;
    cout << "2. Znajdz element"<<endl;
    cout << "3. Usun element"<<endl;
    cout <<"4. Wyswietl tablice" << endl;
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

        case 3:{
            int key;

            cout<<"Podaj klucz do usuniecia: ";
            cin >> key;

            if (table.remove(key)) {
                cout << "Usunieto element" << endl;
            } else {
                cout << "Nie znaleziono elementu do usuniecia" << endl;
            }

            break;
    }

        case 4:
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

//===============================================
// HASH TABLE OPEN MENU
//===============================================

void showHashTableOpenMenu(){
    cout << endl;
    cout << "==== HASHTABLE OPEN ====" << endl;
    cout << "1. Dodaj element" << endl;
    cout << "2. Znajdz element" << endl;
    cout << "3. Usun element" << endl;
    cout << "4. Wyswietl tablice" << endl;
    cout << "0. Powrot"<<endl;
    cout<<"Wybor: ";
}

void runHashTableOpenMenu() {
    int capacity;

    cout << "Podaj rozmiar tablicy: ";
    cin >> capacity;

    HashTableOpen table(capacity);

    int choice;

    do {
        showHashTableOpenMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                int value;

                cout << "Podaj klucz: ";
                cin >> key;

                cout <<"Podaj wartosc: ";
                cin >> value;

                if (table.insert(key, value)) {
                    cout << "Dodano element"<<endl;
                }
                else{
                    cout << "Nie udalo sie dodac elementu. Tablica jest pelna"<< endl;
                }

                break;
            }

            case 2: {
                int key;
                int value;

                cout << "Podaj klucz do znalezienia: ";
                cin >> key;

                if (table.find(key, value)) {
                    cout << "Znaleziono wartosc: " << value << endl;
                } else {
                    cout << "Nie znaleziono elementu" << endl;
                }

                break;
            } 

            case 3:
                {
                    int key;

                    cout << "Podaj klucz do usuniecia: ";
                    cin >> key;

                    if (table.remove(key)) {
                        cout << "Usunieto element" << endl;
                    } else {
                        cout << "Nie znaleziono elemenut do usuniecia" << endl;
                    }

                    break;
                }

            case 4:
            table.print();
            break;

            case 0:
                cout<< "powrot do menu glownego" << endl;
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

            case 2: {

                runHashTableOpenMenu();
                break;
            }

            case 3: {
                AVLTree tree;

                tree.insert(30, 300);
                tree.insert(20, 200);
                tree.insert(10, 100);
                tree.insert(40, 400);

                tree.print();

                int value;
                
                if (tree.find(20, value)) {
                    cout << "Znaleziono 20: "<<value<<endl;
                } else {
                    cout << "Nie znaleziono 20 "<<endl;
                }

                if (tree.find(99, value)) {
                    cout << "Znaleziono 99: " << value << endl;
                } else{
                    cout <<"Nie znaleziono 99" << endl;
                }

                break;
            }
            

            case 0:
            cout <<"Koniec programu"<<endl;
           

            default:
            cout <<"Niepoprawny wybor"<<endl;
            break;
        }

    } while (choice != 0);
    return 0;
}