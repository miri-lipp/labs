//
// Created by Miriam Lipkovich on 2019-04-02.
//

#ifndef LABS_CONCERT_H
#define LABS_CONCERT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
int Length(std::ifstream &smert);
struct event{
    char name[128];
    char date[128];
    int tickets;
    int tickets_left;
};
class Agency {
    int size;
    event* agency;
public:
    friend std::ostream& operator <<(std::ostream& out, Agency& a);
    friend std::ifstream& operator >>(std::ifstream& in, Agency& a);
    friend void sort_by_date(Agency& a);
    friend void sort_by_name(Agency& a);
    Agency(int size);
    Agency(Agency const &a);
    Agency(Agency &&a);
    virtual ~Agency();
    int Booking(int index, int quantity);
    event &operator[](int index);
};

#endif //LABS_CONCERT_H
