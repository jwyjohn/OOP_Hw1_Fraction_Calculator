#pragma once
#include"myint.h"
#include<string>

class fraction
{
private:
	myint a;
	myint b;
	// frac = a/b, b \in N+
	void normalize();
public:
	fraction();
	fraction(const myint&);
	fraction(const fraction&);
	fraction(const fraction*);
	fraction(const myint&, const myint&);
	fraction(const std::string&);
	fraction(const double, int n = 10000);
	std::string to_string() const;
	fraction operator-() const;
	fraction reciprocal() const;
	fraction operator+(const fraction&) const;
	fraction operator-(const fraction&) const;
	fraction operator*(const fraction&) const;
	fraction operator/(const fraction&) const;
	bool operator>(const fraction&) const;
	bool operator<(const fraction&) const;
	bool operator>=(const fraction&) const;
	bool operator<=(const fraction&) const;
	bool operator==(const fraction&) const;
	bool operator!=(const fraction&) const;
	fraction reduce() const;
	void display() const;
};

