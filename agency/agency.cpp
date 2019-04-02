//
// Created by Miriam Lipkovich on 2019-03-29.
//

#include "agency.h"
int main() {
    std::fstream smert;
    smert.open("Agency.txt", std::ios::in | std::ios::out);
    int index, quantity;
    if (!smert.is_open()){
        throw std::logic_error("error");
    }
    int size = Length(smert);
    smert.close();
    smert.open("Agency.txt", std::ios::in | std::ios::out);
    Agency b(size);
    b.append(smert);
    std::cout<<b;
    std::cin>>index;
    std::cin>>quantity;
    std::cout<<b.Booking(index, quantity);
    return 0;
}

int Length(std::fstream &smert){
    char buff[128];
    int count = 0;
    while(smert.getline(buff, 128)){
        count++;
    }
    return count;
}

std::ostream& operator <<(std::ostream& out, Agency& a){
    for(auto const& i: a.agency){
        out<<i.name<<" "<<i.tickets<<"; "<<i.tickets_left<<"; "<<std::put_time((&i.date),"%b %d %Y, %H:%M")<<std::endl;
    }
    return out;
}

void Agency::append(std::fstream &smert) {
    char buff[128];
    std::string str, str1, buf[5];
    event k;
    while (smert.getline(buff, 128)) {
        str = buff;
        auto s = str.find(';');
        str1 = str.substr(0, s);
        k.name = str1;
        str1.clear();
        str = str.substr(s + 1);
        s = str.find(';');
        str1 = str.substr(0, s);
        k.tickets = stoi(str1, nullptr, 10);
        str1.clear();
        str = str.substr(s + 1);
        s = str.find(';');
        str1 = str.substr(0, s);
        k.tickets_left = stoi(str1, nullptr, 10);
        str1.clear();
        str = str.substr(s + 1);
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
        buf[4] = str;
        str.clear();
        k.date = {.tm_year = stoi(buf[0], nullptr, 10) - 1900, .tm_mon = stoi(buf[1], nullptr, 10) - 1, .tm_mday = stoi(buf[2], nullptr, 10),
                  .tm_hour = stoi(buf[3], nullptr, 10), .tm_min = stoi(buf[4], nullptr, 10)};
        agency.push_back(k);
    }
    sort_by_date();
    sort_by_name();
}

Agency::Agency(int size): size(size){
    agency.reserve(size);
    this -> size = size;
}

Agency::~Agency(){
    agency.clear();
}

int Agency::Booking(int index, int quantity){
    if(index < 1 || index > size)
        throw std::overflow_error("Error");
    agency[index - 1].tickets_left = agency[index - 1].tickets_left - quantity;
    if(agency[index - 1].tickets_left < 0){
        throw std::overflow_error("Not enough place");
    }
    return agency[index - 1].tickets_left;
}

event& Agency::operator[](int index){
    if(index > agency.size() || index < 0)
        throw std::out_of_range("Error");
    return agency[index];
}

void Agency::sort_by_name(){
    std::sort(agency.begin(), agency.end(), [](event a1, event a2)->bool{
        return (a1.name > a2.name);
    });
}

std::vector<event>::iterator Agency::begin()
{
    return agency.begin();
}

std::vector<event>::iterator Agency::end()
{
    return agency.end();
}

void Agency::sort_by_date(){
    std::sort(agency.begin(), agency.end(), [](event a1, event a2)->bool{
        return (mktime(&a1.date) > mktime(&a2.date));
    });
}
