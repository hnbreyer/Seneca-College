//Menu.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "string"

namespace sdds
{
    MenuItem::MenuItem() {                                                                           //menuItem functions
        m_itemName = nullptr;
    }

    MenuItem::MenuItem(const char* nam) {
        m_itemName = nullptr;
        if (nam != nullptr && nam[0] != '\0') {
            if (m_itemName == nullptr) {
                int size = 0;
                size = strlen(nam);
                m_itemName = new char[size + 1];
                strcpy(m_itemName, nam);
                m_itemName[size] = '\0';
            }
        }
        else {
            m_itemName = nullptr;
        }
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (m_itemName != nullptr) {
            os << m_itemName << std::endl;
        }
        return os;
    }

    MenuItem::~MenuItem() {
        delete[] m_itemName;
        m_itemName = nullptr;
    }
    

    Menu::Menu(const char* t, int indent) :m_menuArr{ nullptr } {                                 //menu functions
        if (t != nullptr && t[0] != '\0') {

            int size = 0;
            size = strlen(t);
            m_title = new char[size + 1];
            strcpy(m_title, t);
            m_title[size] = '\0';
            m_indent = indent;
            number_menuItems = 0;
        }
        else {
            setEmpty();
        }
    }

    void Menu::setEmpty() {

        delete[] m_title;
        m_title = nullptr;
        for (int i = 0; i < number_menuItems; i++) {
            delete m_menuArr[i];
            m_menuArr[i] = nullptr;
        }
        number_menuItems = 0;
        m_indent = 0;
    }

    void Menu::init(const Menu& menu) {
        if (menu.m_title != nullptr && menu.m_title[0] != '\0') {
            int size = strlen(menu.m_title);
            m_title = new char[size + 1];
            strcpy(this->m_title, menu.m_title);
            m_title[size] = '\0';

            for (int i = 0; i < menu.number_menuItems; i++) {
                m_menuArr[i] = new MenuItem(menu.m_menuArr[i]->m_itemName);
            }
            m_indent = menu.m_indent;
            number_menuItems = menu.number_menuItems;
        }
        else {
            setEmpty();
        }
    }

    Menu::Menu(const Menu& mn) {
        init(mn);
    }

    Menu& Menu::operator=(const Menu& menu) {
        setEmpty();
        if (this != &menu) {
            delete[] m_title;
            if (menu.m_menuArr != nullptr) {
                for (int i = 0; i < number_menuItems; i++) {
                    delete m_menuArr[i];
                    m_menuArr[i] = nullptr;
                }
            }
            init(menu);
        }
        return *this;
    }

    Menu::operator bool() const {
        bool empty = false;
        if (m_title != nullptr && m_menuArr[0] != nullptr && number_menuItems != 0) {
            empty = true;
        }
        return empty;
    }

    bool Menu::isEmpty() const {
        bool empty = false;
        if (m_title == nullptr || m_title[0] == '\0') {
            empty = true;
        }
        return empty;
    }

    std::ostream& Menu::display(std::ostream& os) const {
        if (isEmpty()) {
            std::cout << "Invalid Menu!" << std::endl;
        }
        else {

            if (m_indent == 0) {
                std::cout << m_title << std::endl;
                for (int i = 0; i < number_menuItems; i++) {
                    std::cout << i + 1 << "-" << " " << m_menuArr[i]->m_itemName << std::endl;
                }
                std::cout << "> ";
            }
            else {
                char indent[50] = { '\0' };
                for (int i = 0; i < m_indent; i++) {
                    strcat(indent, "    ");
                }
                std::cout << indent << m_title << std::endl;
                if (number_menuItems == 0) {
                    std::cout << "No Items to display!" << std::endl;
                }
                for (int i = 0; i < number_menuItems; i++) {
                    std::cout << indent << i + 1 << "-" << " " << m_menuArr[i]->m_itemName << std::endl;
                }
                if (m_menuArr[0] != nullptr) {

                    std::cout << indent << "> ";
                }
            }
        }
        return os;
    }

    Menu& Menu::operator=(const char* nam) {
        if (nam != nullptr && nam[0] != '\0') {
            delete[] m_title;
            m_title = nullptr;
            int size = strlen(nam);
            m_title = new char[size + 1];
            strcpy(m_title, nam);
            m_title[size] = '\0';
        }
        else {
            setEmpty();
        }
        return *this;
    }

    void Menu::add(const char* tl) {
        if (!isEmpty()) {
            if (tl != nullptr && tl[0] != '\0') {
                if (number_menuItems < MAX_NO_OF_ITEMS) {
                    delete m_menuArr[number_menuItems];
                    m_menuArr[number_menuItems] = nullptr;
                    m_menuArr[number_menuItems] = new MenuItem(tl);
                }
                number_menuItems++;
            }
            else {
                setEmpty();
            }
        }
        else {
            setEmpty();
        }
    }

    Menu& Menu::operator<<(const char* menuitem) {
        if (menuitem != nullptr && menuitem[0] != '\0' && m_title != nullptr) {
            add(menuitem);
        }
        else {
            setEmpty();
        }
        return *this;
    }

    int Menu::run() const {
        int choice;
        display();

        if (number_menuItems == 0) {
            choice = 0;
        }
        else {
            std::cin >> choice;

            while (std::cin.fail()) {
                std::cerr << "Invalid Integer, try again: ";
                std::cin.clear();
                std::cin.ignore(2000, '\n');
                std::cin >> choice;
            }
            while (choice > number_menuItems || choice == 0) {
                std::cerr << "Invalid selection, try again: ";
                std::cin.clear();
                std::cin.ignore(2000, '\n');
                std::cin >> choice;
            }
            std::cin.clear();
            std::cin.ignore(2000, '\n');
        }
        return choice;
    }

    Menu::operator int() const {
        return run();
    }

    Menu::~Menu() {
        delete[] m_title;
        m_title = nullptr;

        for (int i = 0; i < number_menuItems; i++) {
            delete m_menuArr[i];
            m_menuArr[i] = nullptr;
        }
    }
}
