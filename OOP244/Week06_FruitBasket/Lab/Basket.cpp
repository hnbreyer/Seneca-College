//Basket.cpp

#define _CRT_SECURE_NO_WARNINGS

#include "Basket.h"

namespace sdds
{
    Basket::Basket() {
        m_fruitName = nullptr;
        m_qty = 0;
        m_price = 0;
    }

    Basket::Basket(const char* fruitNam, int qty, double prix) {
        m_fruitName = nullptr;
        m_qty = 0;
        m_price = 0;
        if (fruitNam != nullptr && fruitNam[0] != '\0' && qty > 0 && prix > 0) {
            //reusing code
            setName(fruitNam);
            setQty(qty);
            setPrice(prix);
        }
        else {
            m_fruitName = nullptr;
            m_qty = 0;
            m_price = 0;
        }
    }

    Basket::Basket(const Basket& bas) {
        m_qty = bas.m_qty;                                                                         //shallow copies
        m_price = bas.m_price;
        if (bas.m_fruitName != nullptr && bas.m_fruitName[0] != '\0') {                            //allocate dynamic memory for name
            int size = strlen(bas.m_fruitName);
            m_fruitName = new char[size + 1];
            strcpy(this->m_fruitName, bas.m_fruitName);
            m_fruitName[size] = '\0';
        }
        else {
            m_fruitName = nullptr;
        }
    }

    Basket& Basket::operator=(const Basket& basket) {
        if (this != &basket) {                                                                     //check self assignment
            m_qty = basket.m_qty;
            m_price = basket.m_price;
                                                                                              
            delete[] m_fruitName;                                                                  //deallocate previous allocated memory
                                                                                              
            if (basket.m_fruitName != nullptr) {                                                   //allocate new dynamic memory
                int size = 0;
                size = strlen(basket.m_fruitName);
                m_fruitName = new char[size + 1];
                strcpy(m_fruitName, basket.m_fruitName);
                m_fruitName[size] = '\0';
            }
            else {
                m_fruitName = nullptr;
            }
        }
        return *this;
    }

    Basket::~Basket() {
        delete[] m_fruitName;
        m_fruitName = nullptr;
    }

    void Basket::setName(const char* fName) {
        if (fName != nullptr && fName[0] != '\0') {
            if (m_fruitName == nullptr) {
                int size = 0;
                size = strlen(fName);
                m_fruitName = new char[size + 1];
                strcpy(m_fruitName, fName);
                m_fruitName[size] = '\0';
            }
        }
    }

    void Basket::setQty(int qt) {
        if (qt >= 1) {
            m_qty = qt;
        }
    }

    void Basket::setPrice(double prc) {
        if (prc >= 0) {
            m_price = prc;
        }
    }

    bool Basket::isempty() const {
        bool empty = false;
        if (m_fruitName == nullptr && m_qty == 0 && m_price == 0) {
            empty = true;
        }
        return empty;
    }

    bool Basket::addPrice(double addPrc) {
        bool add = false;
        if (addPrc > 0) {
            m_price += addPrc;
            add = true;
        }
        return add;
    }

    std::ostream& Basket::display(std::ostream& os) const {
        if (isempty()) {
            os << "The Basket has not yet been filled" << std::endl;
        }
        else {
            os << "Basket Details" << std::endl;
            os << "Name: " << m_fruitName << std::endl;
            os << "Quantity: " << m_qty << std::endl;
            os.setf(std::ios::fixed);
            os.precision(2);
            os << "Price: " << m_price << std::endl;
        }
        return os;
    }
 

    bool Basket::operator==(const Basket& other_bas) {
        bool same = true;
        if (strcmp(this->m_fruitName, other_bas.m_fruitName) && this->m_qty != other_bas.m_qty && this->m_price != other_bas.m_price) {
            same = false;
        }
        return same;
    }

    bool Basket::operator!=(const Basket& other_b) {
        bool notSame = true;
        if (strcmp(this->m_fruitName, other_b.m_fruitName) && this->m_qty != other_b.m_qty && this->m_price != other_b.m_price) {
            notSame = false;
            std::cout << "Press any key to continue . . ." << std::endl;
        }
        return notSame;
    }

    std::ostream& operator<<(std::ostream& os, const Basket& bsk) {
        bsk.display(os);
        return os;
    }
}
