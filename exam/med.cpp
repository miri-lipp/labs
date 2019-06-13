#include "med.h"

std::ifstream& operator>>(std::ifstream& in, Med& a)
{
	if (!in.is_open())
		throw std::logic_error("error");
	in >> a.name >> a.myDate >> a.section >> a.price >> a.count;
	return in;
}
std::ofstream& operator<<(std::ofstream& out, Med& a)
{
	if (!out.is_open())
		throw std::logic_error("error");
	out << a.name << " " << a.myDate << " " << a.section << " " << a.price << " " 
	<< a.count << std::endl;;
	return out;
}

bool Med::operator==(Med& a) const
{
	return strcmp(name, a.name);
}



