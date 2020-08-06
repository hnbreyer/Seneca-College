//NumbersBox.h

#ifndef SDDS_NUMBERSBOX_H__
#define SDDS_NUMBERSBOX_H__

#include <iostream>
#include <cstring>

const int MAX_NAME = 15;

namespace sdds
{
    template <typename T>
    class NumbersBox
    {
        char m_name[MAX_NAME + 1];
        int m_size;
        T* m_items;
    public:
        NumbersBox() {
            m_name[0] = { '\0' };
            m_size = 0;
            m_items = nullptr;
        }

        NumbersBox(int sz, const char* name) {
            if (sz > 0 && name != nullptr && name[0] != '\0') {
                m_size = sz;
                strcpy(m_name, name);
                m_items = new T[sz];
            }
            else {
                m_name[0] = { '\0' };
                m_size = 0;
                m_items = nullptr;
            }
        }

        ~NumbersBox() {
            delete[] m_items;
            m_items = nullptr;
        }

        T& operator[] (int i) {
            return m_items[i];
        }

        NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
            if (this->m_items != nullptr && other.m_items != nullptr && this->m_size == other.m_size) {
                for (int i = 0; i < m_size; i++) {
                    this->m_items[i] *= other.m_items[i];
                }
            }
            return *this;
        }

        NumbersBox<T>& operator+=(T num) {
            if (m_size != 0) {
                if (this != nullptr) {
                    T* temp;
                    temp = new T[m_size];

                    for (int i = 0; i < m_size; i++) {
                        temp[i] = m_items[i];
                    }
                    delete[] m_items;
                    m_items = nullptr;

                    m_items = new T[m_size + 1];

                    for (int i = 0; i < m_size; i++) {
                        m_items[i] = temp[i];
                    }
                    delete[] temp;
                    temp = nullptr;

                    m_items[m_size] = num;
                    m_size++;
                }
            }
            return *this;
        }

        std::ostream& display(std::ostream& os) const {
            if (m_name[0] == '\0' && m_size == 0 && m_items == nullptr) {
                os << "Empty Box" << std::endl;
            }
            else {
                os << "Box name: " << m_name << std::endl;
                for (int i = 0; i < m_size; i++) {
                    if (i == m_size - 1) {
                        os << m_items[m_size - 1];
                    }
                    else {
                        os << m_items[i] << ", ";
                    }                  
                }
                os << std::endl;
            }
            return os;
        }
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const NumbersBox<T>& box) {
        box.display(os);
        return os;
        }
}

#endif
