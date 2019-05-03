//
// Created by Miriam Lipkovich on 2019-05-03.
//
#include "timetable.h"

Timetable::Timetable(int size):size(size) {
    timetable.reserve(size);
    this->size = size;
}

Timetable::~Timetable() {
    timetable.clear();
}

int length_of_file(std::ifstream& file){
    char buff[128];
    int count = 0;
    while(file.getline(buff, 128)){
        count++;
    }
    return count;
}

train& Timetable::operator[](int index){
    if(index < 0 || index > timetable.size())
        throw std::out_of_range("error");
    return timetable[index];
}

std::ifstream& operator>>(std::ifstream& in, Timetable& a){
    char buff[128];
    train tr;
    std::string str, str1, buf[5];
    while(in.getline(buff, 128)){
        str = buff;
        auto s = str.find(';');
        str1 = str.substr(0, s);
        tr.departure_city = str1;
        str = str.substr(s + 1);
        str1.clear();
        s = str.find('-');
        buf[0] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find('-');
        buf[1] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(' ');
        buf[2] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(':');
        buf[3] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(';');
        buf[4] = str.substr(0, s);
        str = str.substr(s + 1);
        tr.departure_date = {.tm_year = stoi(buf[0], nullptr, 10), .tm_mon = stoi(buf[1], nullptr, 10),
                             .tm_mday = stoi(buf[2],nullptr, 10), .tm_hour = stoi(buf[3], nullptr, 10), .tm_min = stoi(buf[4],
                                                                                                                       nullptr, 10)};
        for(int i = 0; i < 5; i++){
            buf[i].clear();
        }
        s = str.find(';');
        str1 = str.substr(0, s);
        tr.arrival_city = str1;
        str = str.substr(s + 1);
        str1.clear();
        s = str.find('-');
        buf[0] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find('-');
        buf[1] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(' ');
        buf[2] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(':');
        buf[3] = str.substr(0, s);
        str = str.substr(s + 1);
        s = str.find(';');
        buf[4] = str.substr(0, s);
        str = str.substr(s + 1);
        tr.arrival_date = {.tm_year = stoi(buf[0], nullptr, 10), .tm_mon = stoi(buf[1], nullptr, 10),
                .tm_mday = stoi(buf[2],nullptr, 10), .tm_hour = stoi(buf[3], nullptr, 10), .tm_min = stoi(buf[4],
                                                                                                          nullptr, 10)};
        s = str.find(';');
        str1 = str.substr(0, s);
        tr.tickets_amount = stoi(str1, nullptr, 10);
        str = str.substr(s + 1);
        str1.clear();
        tr.tickets_left = stoi(str, nullptr, 10);
        a.timetable.push_back(tr);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Timetable& a){
    for(auto const& i: a.timetable){
        out<<i.departure_city<<" "<<std::put_time((&i.departure_date),"%b %d %Y, %H:%M")<<std::endl;
        out<<i.arrival_city<<" "<<std::put_time((&i.arrival_date),"%b %d %Y, %H:%M")<<std::endl;
        out<<i.tickets_amount<<" "<<i.tickets_left<<std::endl;
    }
    return out;
}

void Timetable::sort_by_time(){
    std::sort(timetable.begin(), timetable.end(), [](train a1, train a2)->bool{
        return (mktime(&a1.departure_date) > mktime(&a2.departure_date));
    });
}

int Timetable::tickets_booking(int index, int quantity){
    if(index < 1 || index > size){
        throw std::overflow_error("error");
    }
    timetable[index - 1].tickets_left = timetable[index - 1].tickets_left - quantity;
    if(timetable[index - 1].tickets_left < 0)
        throw std::overflow_error("error");
    return timetable[index - 1].tickets_left;
}