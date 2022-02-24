#ifndef __STRING__H__
#define __STRING__H__
#include <ostream>

namespace Kno
{
class string
{
private:
    int m_size;
    int m_cap;
    char* m_arr;
public:
    string();
    string(const string&);
    string(char*);
    string(string&&);
    ~string();
public:
    string& operator=(const string&);
    string& operator=(string&&);
    int operator[](int);
    const int operator[](int) const;
    string operator+(const string&);
    friend std::ostream& operator<<(std::ostream& cout , const string& oth)
    {
        cout << oth.m_arr;
        return cout;
    }
public:
    int find(char , int);
    void push_back(char);
    void pop_back();
    void insert(int , char*);
    int length();
    int capacity();
    char at(int);
};



};


#endif // __STRING__H__