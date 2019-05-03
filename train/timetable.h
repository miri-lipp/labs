//
// Created by Miriam Lipkovich on 2019-05-03.
//

#ifndef TRAINS_TIMETABLE_H
#define TRAINS_TIMETABLE_H
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

int length_of_file(std::ifstream& file);
struct train{
    tm departure_date;
    tm arrival_date;
    std::string departure_city;
    std::string arrival_city;
    int tickets_left;
    int tickets_amount;
};
class Timetable{
    std::vector<train> timetable;
    int size;
public:
    Timetable(int size);
    virtual ~Timetable();
    friend std::ifstream& operator>>(std::ifstream& in, Timetable& a);
    friend std::ostream& operator<<(std::ostream& out, Timetable& a);
    train& operator[](int index);
    void sort_by_time();
    int tickets_booking(int index, int quantity);
};
#endif //TRAINS_TIMETABLE_H
