#include <iostream>
#include <cstring>
#include "string.h"

Kno::string::string()
{
    m_size = 0;
    m_cap = 1;
    m_arr = new char[m_cap];
}

Kno::string::~string()
{
    delete m_arr;
    m_arr = nullptr;
}

Kno::string::string(char* arr) : m_arr{arr}
{
    // parametr ctor
}

Kno::string::string(const string& oth)
{
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    m_arr = new char[m_cap];
    for(int i = 0; i < m_size; ++i)
    {
        m_arr[i] = oth.m_arr[i];
    }
}

Kno::string::string(string&& oth)
{
    m_size = oth.m_size;
    m_cap = oth.m_cap;
    m_arr = new char[m_cap];
    for (int i = 0; i < m_size; ++i)
    {
        m_arr[i] = oth.m_arr[i];
    }
}

Kno::string& Kno::string::operator=(const string& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    else
    {
        m_size = oth.m_size;
        m_cap = oth.m_cap;
        delete[] m_arr;
        m_arr = new char[m_cap];
        for(int i = 0; i < m_size; ++i)
        {
            m_arr[i] = oth.m_arr[i];
        }
    }
    return *this;
}

Kno::string& Kno::string::operator=(string&& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    else
    {
        m_size = oth.m_size;
        m_cap = oth.m_cap;
        delete[] m_arr;
        m_arr = new char[m_cap];
        for (int i = 0; i < m_size; ++i)
        {
            m_arr[i] = oth.m_arr[i];
        }
    }
    return *this;
}

int Kno::string::operator[](int index)
{
    return m_arr[index];
}

const int Kno::string::operator[](int index) const
{
    return m_arr[index];
}

Kno::string Kno::string::operator+(const string& oth)
{
    Kno::string tmp1(oth);
    for(int i = 0; i < m_size; ++i)
    {
        tmp1.push_back(m_arr[i]);
    }
    return tmp1;

}

int Kno::string::length()
{
    return m_size;
}

int Kno::string::capacity()
{
    return m_cap;
}

void Kno::string::pop_back()
{
    m_arr[--m_size] = '\0';
}

void Kno::string::push_back(char arr)
{
    if(m_size == m_cap)
    {
        m_cap *= 2;
        char* tmp = new char[m_cap];

        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        tmp[m_size] = arr;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
    }
    else
    {
        m_arr[m_size] = arr;
        ++m_size;
    }
}

void Kno::string::insert(int index ,char* arr)
{
    if(m_size == m_cap)
    {
        m_cap *= 2;
        char * tmp = new char[m_cap];

        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        for(int i = m_size - 1; i >= index; --i)
        {
            tmp[i+1] = tmp[i];
            tmp[index] = arr[i];
        }
        delete[]m_arr;
        m_arr = tmp;
        tmp = nullptr;
        m_size++;
    }
    else
    {
        for(int i = m_size - 1; i >= index; --i)
        {
            m_arr[i+1] = m_arr[i];
            m_arr[index] = arr[i];
            m_size++;
        }
    }
}

int Kno::string::find(char arr, int index)
{
    for(int i = 0; i < m_size; ++i)
    {
        if(m_arr[index] == arr)
        {
            return i;
        }
    }
    return -1;
}

char Kno::string::at(int index)
{
    try
    {
        throw (m_size > index);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for(int i = 0; i < m_size; ++i)
    {
        if(m_arr[i] == index)
        {
            return m_arr[i];
        }
    }

    return ' ';
    
}





