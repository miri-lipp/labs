//
// Created by Miriam Lipkovich on 2019-03-29.
//

#ifndef LABS_AGENCY_H
#define LABS_AGENCY_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
int Length(std::fstream &smert);
int compar(const void* a, const void *b);
struct event{
    std::string name;
    tm date;
    int tickets;
    int tickets_left;
};

class Agency {
    int size;
    std::vector<event> agency;
public:
    friend std::ostream& operator <<(std::ostream& out, Agency& a);
    friend std::istream operator >>(std::istream& in, Agency& a);
    Agency(int size);
    Agency(Agency const &a) = delete;
    Agency(Agency &&a) = delete;
    virtual ~Agency();
    void append(std::fstream &smert);
    int Booking(int index, int quantity);
    std::vector<event>::iterator begin();
    std::vector<event>::iterator end();
    void sort_by_date();
    void sort_by_name();
    event &operator[](int index);
};
#endif //LABS_AGENCY_H
