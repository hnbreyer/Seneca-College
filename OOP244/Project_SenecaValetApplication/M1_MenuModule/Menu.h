/**********************************************************
 * Name: Helen Nunes Breyer
 * Student ID: 120046198
 * Seneca email: hnunes-breyer@myseneca.ca
 * Section: NEE
 **********************************************************/

//Menu.h

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include <cstring>

const int MAX_NO_OF_ITEMS = 10;  
namespace sdds
{
    class Menu; //forward declaration
    class MenuItem
    {
        char* m_itemName;
        MenuItem();
        MenuItem(const char* nam);
        //member functions
        std::ostream& display(std::ostream& os = std::cout) const;
        //copy and copy assignment prohibited
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        //destruction
        ~MenuItem();
        //friend class
        friend class Menu;

    };

    class Menu
    {
        char* m_title;
        MenuItem* m_menuArr[MAX_NO_OF_ITEMS] = {nullptr};
        int m_indent;
        //added member
        int number_menuItems;

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
        //added functions
        void setEmpty();
    };
}

#endif
