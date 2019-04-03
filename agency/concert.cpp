//
// Created by Miriam Lipkovich on 2019-04-02.
//
#include "concert.h"

int Length(std::ifstream &smert){
    char buff[128];
    int count = 0;
    while (smert.getline(buff, 128)) {
        count++;
    }
    return count;
}

Agency::Agency(int size) : size(size) {
    agency = new event[size];
    this->size = size;
}

Agency::Agency(Agency const &a) {
    size = a.size;
    agency = new event[a.size];
    agency[size] = a.agency[a.size];
}

Agency::Agency(Agency &&a){
    agency = a.agency;
    size = a.size;
    a.agency = nullptr;
}

event& Agency::operator[](int index) {
    if(index > size || index < 0)
        throw std::out_of_range("Error");
    return agency[index];
}

int Agency::Booking(int index, int quantity) {
    if(index < 1 || index > size)
        throw std::overflow_error("Error");
    agency[index - 1].tickets_left = agency[index - 1].tickets_left - quantity;
    if(agency[index - 1].tickets_left < 0){
        throw std::overflow_error("Not enough place");
    }
    return agency[index - 1].tickets_left;
}

std::ifstream& operator>>(std::ifstream &in, Agency& a) {
    char buffer[128];
    int i = 0;
    in.getline(a.agency[i].name, 128, ';');
    in.getline(buffer, 128, ';');
    a.agency[i].tickets = atoi(buffer);
    strcpy(buffer, "");
    in.getline(buffer, 128, ';');
    a.agency[i].tickets_left = atoi(buffer);
    strcpy(buffer, "");
    in.getline(a.agency[i].date, 128, '\n');
    i++;
    return in;
}

Agency::~Agency() {
    delete[] agency;
}

std::ostream& operator <<(std::ostream& out, Agency &a){
    for(int i = 0; i < a.size; i++)
        out<<a.agency[i].name<<"; "<<a.agency[i].tickets<<"; "<<a.agency[i].tickets_left<<"; "<<a.agency[i].date<<std::endl;
    return out;
}

void sort_by_date(Agency& a){
    std::sort(a.agency, a.agency + a.size, [](const event& a, const event& b){
        return strcmp(a.date, a.date);
    });
}

void sort_by_name(Agency&a){
    std::sort(a.agency, a.agency + a.size, [](const event& a, const event& b){
        return strcmp(a.name, b.name);
    });
}
