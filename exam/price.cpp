#include"med.h"
std::ifstream& operator>>(std::ifstream& in, Price& a)
{
	if (!in.is_open())
		throw std::logic_error("error");
	in >> a.name >> a.myDate >> a.price;
	return in;
}
std::ofstream& operator<<(std::ofstream& out, Price& a)
{
	if (!out.is_open())
		throw std::logic_error("error");
	out << a.name << " " << a.myDate << " " << a.price << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, Price& a) {
	out << a.name << " " << a.myDate << " " << a.price << std::endl;
	return out;
}

bool Price::operator==(Price& a) const
{
	return strcmp(name, a.name);
}