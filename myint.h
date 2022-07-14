/*****************************************************************//**
 * \file   myint.h
 * \brief  
 * 
 * \author jwyjo
 * \date   July 2022
 *********************************************************************/
#pragma once
#include<string>
#include"mynat.h"
class myint
{
private:
	mynat v;
	int sign;
public:
	myint();
	myint(int);
	myint(long long);
	myint(const myint&);
	myint(const myint*);
	myint(const mynat&, const int s = 1);
	myint(const mynat*, const int s = 1);
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

