#include "timetable.h"

int main() {
    std::ifstream file;
    file.open("train.txt");
    int index, quantity;
    if (!file.is_open()){
        throw std::logic_error("error");
    }
    int size = length_of_file(file);
    file.close();
    file.open("train.txt");
    Timetable b(size);
    file>>b;
    b.sort_by_time();
    std::cout<<b;
    std::cin>>index;
    std::cin>>quantity;
    std::cout<<b.tickets_booking(index, quantity);
    return 0;
}