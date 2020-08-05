//Basket.h

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>
#include <cstring>

namespace sdds
{
    class Basket
    {
        char* m_fruitName;
        int m_qty;
        double m_price;
    public:
        Basket();                                                                                     //default constructor
        Basket(const char* fruitNam, int qty, double prix);                                           // 3 arg constructor
        ~Basket();                                                                                    //destructor
        void setName(const char* fName);
        void setQty(int qt);
        void setPrice(double prc);
        bool isempty() const;
        bool addPrice(double addPrc);

        std::ostream& display(std::ostream& os) const;

        Basket(const Basket& bas);                                                                  // copy constructor
        Basket& operator=(const Basket& basket);                                                    //copy assignment operator
        bool operator==(const Basket& other_bas);
        bool operator!=(const Basket& other_b);
    };
        std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}

#endif
