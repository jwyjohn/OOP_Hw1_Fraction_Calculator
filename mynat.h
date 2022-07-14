/*****************************************************************//**
 * \file   mynat.h
 * \brief  
 * 
 * \author jwyjo
 * \date   July 2022
 *********************************************************************/
#pragma once
#include<string>
class mynat
{
private:
	std::string v;
public:
	mynat();
	mynat(int);
	mynat(long long);
	mynat(const mynat&);
	mynat(const mynat*);
	mynat(const std::string&);
	std::string to_string() const;
	mynat operator+(const mynat&) const;
	mynat operator-(const mynat&) const;
	mynat operator*(const mynat&) const;
	mynat operator/(const mynat&) const;
	mynat operator%(const mynat&) const;
	bool operator>(const mynat&) const;
	bool operator<(const mynat&) const;
	bool operator>=(const mynat&) const;
	bool operator<=(const mynat&) const;
	bool operator==(const mynat&) const;
	bool operator!=(const mynat&) const;
};

