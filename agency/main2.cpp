//
// Created by Miriam Lipkovich on 2019-04-03.
//
#include "agency.h"
int main() {
    std::ifstream smert;
    smert.open("Agency.txt");
    int index, quantity;
    if (!smert.is_open()){
        throw std::logic_error("error");
    }
    int size = Length(smert);
    smert.close();
    smert.open("Agency.txt");
    Agency b(size);
    smert>>b;
    b.sort_by_date();
    b.sort_by_name();
    std::cout<<b;
    std::cin>>index;
    std::cin>>quantity;
    std::cout<<b.Booking(index, quantity);
    return 0;
}