/*****************************************************************//**
 * \file   myint.h
 * \brief  
 * 
 * \author jwyjo
 * \date   July 2022
 *********************************************************************/
#pragma once
#include<string>
class myint
{
private:
	long long v;
public:
	myint();
	myint(int);
	myint(long long);
	myint(const myint&);
	myint(const myint*);
	myint(const std::string&);
	std::string to_string() const;
	myint operator-() const;
	myint operator+(const myint&) const;
	myint operator-(const myint&) const;
	myint operator*(const myint&) const;
	myint operator/(const myint&) const;
	myint operator%(const myint&) const;
	bool operator>(const myint&) const;
	bool operator<(const myint&) const;
	bool operator>=(const myint&) const;
	bool operator<=(const myint&) const;
	bool operator==(const myint&) const;
	bool operator!=(const myint&) const;
};

