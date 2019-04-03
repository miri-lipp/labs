//
// Created by Miriam Lipkovich on 2019-04-03.
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