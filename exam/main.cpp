#include "med.h"
void toBinary1(med<Price>& b);
void toBinary2(med<Item>& b);

int main()
{
	med<Item> m1(3);
	med<Price> k1(3);
	std::ifstream f1("f1.bin");
	k1.ReadData(f1);
	std::ifstream f2("f1.bin");
	m1.ReadData(f2);
	std::ifstream out1("item.txt");
	out1 >> m1;
	std::cout << m1;
	std::cout << std::endl;
	m1.sort_up();
	std::cout << m1;
	std::cout << std::endl;
	std::ifstream out2("price.txt");
	out2 >> k1;
	std::cout << std::endl;
	std::cout << k1;
	k1.sort_up();
	std::cout << std::endl;
	std::cout << k1;

	system("pause");
}

inline void toBinary1(med<Price>& b)
{
	med<Price> m1(3);
	std::ofstream f1("f1.bin");
	m1.WriteData(f1);
}

inline void toBinary2(med<Item>& b)
{
	med<Item> m1(3);
	std::ofstream f1("f2.bin");
	m1.WriteData(f1);
}