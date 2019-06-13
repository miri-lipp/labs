#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

struct Med
{
	char name[35];
	char myDate[8];
	double price;
	char section[10];
	int count;
	friend std::ifstream& operator>>(std::ifstream& in, Med& a);
	friend std::ofstream& operator<<(std::ofstream& out, Med& a);
	bool operator==(Med& a) const;
};

struct Price
{
	char name[35];
	char myDate[8];
	double price;
	friend std::ifstream& operator>>(std::ifstream& in, Price& a);
	friend std::ofstream& operator<<(std::ofstream& out, Price& a);
	friend std::ostream& operator <<(std::ostream& out, Price& a);
	bool operator==(Price& a) const;
};

struct Item
{
	char name[35];
	char myDate[8];
	char section[10];
	int count;
	friend std::ifstream& operator>>(std::ifstream& in, Item& a);
	friend std::ofstream& operator<<(std::ofstream& out, Item& a);
	friend std::ostream& operator <<(std::ostream& out, Item& a);
	bool operator==(Item& a) const;
};

template <typename T>
class med{
	int count;
	T* m;
public:
	med(const int count) : count(count)
	{
		m = new T[count];
		this->count = count;
	}

	void ReadData(std::ifstream& fin);
	void WriteData(std::ofstream& fout);
	med(med& const a) = delete;
	med(med&& a) = delete;
	virtual ~med()
	{
		delete[] m;
	}

	friend std::ofstream& operator<<(std::ofstream& fout, med& a);
	friend std::ifstream& operator>>(std::ifstream& fin, med& a)
	{
		for (int i = 0; i < a.count; i++)
			fin >> a.m[i];
		return fin;
	}
	friend std::ostream& operator<<(std::ostream& out, med& a)
	{
		for (int i = 0; i < a.count; i++)
		{
			out << a.m[i];
		}
		return out;
	}
	med& operator=(med& a)
	{
		if (this == &a)
			return *this;
		delete[] m;
		count = a.count;
		m = new T[count];
		for (int i = 0; i < count; i++)
			m[i] = a.m[i];
		return *this;
	}
	med& operator[](int index)
	{
		if (index < 0 || index >= count)
			throw std::overflow_error("error");
		return m[index];
	}
	int GetCount()
	{
		return (sizeof(m) / sizeof(m[0]));
	}

	void sort_up()
	{
		qsort(m, count, sizeof(T),[](const void* a, const void* b)->auto
		{
			const auto a1 = static_cast<const char*>(a);
			const auto a2 = static_cast<const char*>(b);
			return strcmp(a1, a2);
		});
	}

};

inline void med<Price>::ReadData(std::ifstream& fin)
{
	if (!fin.is_open())
		throw std::logic_error("error");
	for (int i = 0; i < GetCount(); i++) {
		fin.read((char*)m[i].name, sizeof(m[i].name));
		fin.read((char*)m[i].myDate, sizeof(m[i].myDate));
		//fin.read(m[i].price, sizeof(m[i].price));
	}
}
inline void med<Price>::WriteData(std::ofstream& fout)
{
	if (!fout.is_open())
		throw std::logic_error("error");
	for (int i = 0; i < GetCount(); i++) {
		fout.write((char*)m[i].name, sizeof(m[i].name));
		fout.write((char*)m[i].myDate, sizeof(m[i].myDate));
		//fout.write((char*)m[i].price, sizeof(m[i].price));
	}
}

inline void med<Item>::ReadData(std::ifstream& fin)
{
	if (!fin.is_open())
		throw std::logic_error("error");
	for (int i = 0; i < GetCount(); i++) {
		fin.read((char*)m[i].name, sizeof(m[i].name));
		fin.read((char*)m[i].myDate, sizeof(m[i].myDate));
		fin.read((char*)m[i].section, sizeof(m[i].section));
		fin.read((char*)m[i].count, sizeof(m[i].count));
	}
}
inline void med<Item>::WriteData(std::ofstream& fout)
{
	if (!fout.is_open())
		throw std::logic_error("error");
	for (int i = 0; i < GetCount(); i++) {
		fout.write((char*)m[i].name, sizeof(m[i].name));
		fout.write((char*)m[i].myDate, sizeof(m[i].myDate));
		fout.write((char*)m[i].section, sizeof(m[i].section));
		fout.write((char*)m[i].count, sizeof(m[i].count));
	}
}