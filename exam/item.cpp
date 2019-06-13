#include "med.h"

std::ifstream& operator>>(std::ifstream& in, Item& a)
{
	if (!in.is_open())
		throw std::logic_error("error");
	in >> a.name >> a.myDate >> a.section >> a.count;
	return in;
}
std::ofstream& operator<<(std::ofstream& out, Item& a)
{
	if (!out.is_open())
		throw std::logic_error("error");
	out << a.name << " " << a.myDate << " " << a.section << " " << a.count << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, Item& a) {
	out << a.name << " " << a.myDate << " " << a.section << " " <<
		a.count << std::endl;
	return out;
}

bool Item::operator==(Item& a) const
{
	return strcmp(name, a.name);
}
