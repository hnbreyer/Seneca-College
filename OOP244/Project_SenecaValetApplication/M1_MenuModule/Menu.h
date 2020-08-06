//Menu.h

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include <cstring>

const int MAX_NO_OF_ITEMS = 10;  
namespace sdds
{
    class Menu;                                                                                  //forward declaration
    class MenuItem
    {
        char* m_itemName;
        MenuItem();
        MenuItem(const char* nam);
        std::ostream& display(std::ostream& os = std::cout) const;
        MenuItem(const MenuItem&) = delete;                                                     //copy and copy assignment prohibited
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();                                                                            //destruction
        friend class Menu;                                                                      //friend class

    };

    class Menu
    {
        char* m_title;
        MenuItem* m_menuArr[MAX_NO_OF_ITEMS] = {nullptr};
        int m_indent;
        int number_menuItems;                                                                  //added member

    public:
        Menu(const char* t, int indent = 0);
        void init(const Menu& menu);
        Menu(const Menu& mn);
        Menu& operator=(const Menu& menu);
        operator bool() const;
        bool isEmpty() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        void add(const char* tl);
        Menu& operator=(const char* nam);
        Menu& operator<<(const char* menuitem);
        int run() const;
        operator int() const;
        ~Menu();
        void setEmpty();                                                                       //added functions
    };
}

#endif
