#ifndef MENU_H
#define MENU_H

class Menu {
private:
    void showMainMenu();

    void showHashTableListMenu();
    void runHashTableListMenu();

    void showHashTableOpenMenu();
    void runHashTableOpenMenu();

    void showHashTableAVLMenu();
    void runHashTableAVLMenu();

public:
    void run();
};

#endif