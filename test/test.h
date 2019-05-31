#pragma once
#include<ctime>
#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <sstream>

template <typename T>
class demo
{
	std::string name;
	char* surname;
	tm date;
	double payment;
public:
	demo();
	virtual ~demo();
};

template <typename T>
class hospital : private demo<T>
{
	
public:
	std::vector<demo<T>> place;
	hospital();
	hospital(hospital const& a) = delete;
	hospital(hospital&& a) = delete;
	friend std::ostream& operator<<(std::ostream& out, hospital<T>& a);
	friend bool operator<(const hospital<T>& a, const hospital<T>& b);
	void search_by_name();
	virtual ~hospital();

	T& operator[](int index)
	{
		if (index > place.size() || index < 0)
			throw std::out_of_range("Error");
		return place[index];
	}
	friend std::ostream& operator<<(std::ostream& out, hospital<T>& a)
	{
		for (auto i : a.place) {
			out << i.surname << " " << i.name << " " << i.payment << " " <<
				std::put_time((&i.date), "%b %d %Y, %H:%M") << std::endl;
		}
		return out;
	}

	friend std::ifstream& operator>>(std::ifstream &in, hospital<T>& a)
	{
		char buff[128];
		demo<T> k;
		std::string line;
		std::getline(in, line);

		std::string fields[6];

		for (auto i = 0; i < 5; i++)
		{
			const auto pos = line.find(';');
			fields[i] = line.substr(0, pos);
			line.erase(0, pos + 1);
		}
		fields[5] = line;

		k.name = fields[0];
		k.surname = fields[1];
		k.payment = std::stod(fields[2]);
		std::stringstream start_date_stream(fields[3]);
		start_date_stream >> std::get_time(&(k.date), "%Y-%m-%d %H:%M");

		a.place.push_back(k);
		return in;

	}

	friend bool operator<(const hospital<T>& a, const hospital<T>& b)
	{
		std::sort(place.begin(), place.end(), [](demo<T> a1, demo<T> a2)->bool {
			std::sort(place.begin(), place.end(), [](demo<T> a1, demo<T> a2)->bool {
				return (mktime(&a1.date) > mktime(&a2.date)) && (a1.name > a2.name);
			});
		});
		return false;
	}
};