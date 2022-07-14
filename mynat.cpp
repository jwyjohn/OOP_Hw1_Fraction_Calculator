#include "mynat.h"
#include<string>
#include<iostream>

mynat::mynat()
{
	v = "0";
}

mynat::mynat(int n)
{
	if (n <= 0)
	{
		v = "0";
		return;
	}
	while (n)
	{
		char ch = n % 10 + '0';
		v.push_back(ch);
		n = n / 10;
	}
	while (v.length() > 1 && v.back() == '0')
		v.pop_back();
}

mynat::mynat(long long n)
{
	if (n <= 0)
	{
		v = "0";
		return;
	}
	while (n)
	{
		char ch = n % 10 + '0';
		v.push_back(ch);
		n = n / 10;
	}
	while (v.length() > 1 && v.back() == '0')
		v.pop_back();
}

mynat::mynat(const mynat& m)
{
	v = m.v;
	while (v.length() > 1 && v.back() == '0')
		v.pop_back();
}

mynat::mynat(const mynat* m)
{
	v = m->v;
	while (v.length() > 1 && v.back() == '0')
		v.pop_back();
}

mynat::mynat(const std::string& sn)
{
	std::string tmp = sn;
	while (tmp.length() > 0)
	{
		char ch = tmp.back();
		if (ch > '9' || ch < '0')
			break;
		v.push_back(ch);
		tmp.pop_back();
	}
	while (v.length() > 1 && v.back() == '0')
		v.pop_back();
}

std::string mynat::to_string() const
{
	std::string ret;
	int len = (int)v.length(), i = 0;
	while (len--)
	{
		ret.push_back(v[len]);
	}
	return ret;
}

mynat mynat::operator+(const mynat& m) const
{
	mynat ret;
	int len1 = (int)v.length(), len2 = (int)m.v.length(), len = len1 > len2 ? len1 : len2, i = 0;
	int buf = 0;
	ret.v = "";
	while (i < len)
	{
		int d1 = 0, d2 = 0;
		if (i < len1)
			d1 = v[i] - '0';
		if (i < len2)
			d2 = m.v[i] - '0';
		buf += d1 + d2;
		ret.v.push_back(buf % 10 + '0');
		buf = buf / 10;
		i++;
	}
	if (buf > 0)
	{
		ret.v.push_back(buf % 10 + '0');
	}
	return ret;
}

mynat mynat::operator*(const mynat& m) const
{
	mynat ret;
	int len1 = (int)v.length(), len2 = (int)m.v.length(), len = len1 > len2 ? len1 : len2, i = 0, j = 0;
	int buf = 0;
	while (j < len1)
	{
		int buf = 0, d1 = v[j] - '0';
		mynat tmp;
		tmp.v = "";
		for (int k = 0; k < j; k++)
			tmp.v.push_back('0');
		i = 0;
		while (i < len2)
		{
			int d2;
			d2 = m.v[i] - '0';
			buf += d1 * d2;
			tmp.v.push_back(buf % 10 + '0');
			buf = buf / 10;
			i++;
		}
		if (buf > 0)
		{
			tmp.v.push_back(buf % 10 + '0');
		}
		ret = ret + tmp;
		j++;
	}
	return ret;
}

mynat mynat::operator/(const mynat& m) const
{
	if (m == 0)
	{
		std::clog << "[Warninig] mynat div by 0 " << std::endl;
		return mynat(0);
	}
	mynat a = this;
	int len1 = (int)a.v.length(), len2 = (int)m.v.length(), i = 0, j = 0;
	if (a < m)
		return mynat(0);
	j = len1 - len2;
	std::string ans;
	mynat tmp(0);
	while (j >= 0)
	{
		int buf = 0;
		mynat tmp1 = m;
		for (int k = 0; k < j; k++)
			tmp1 = tmp1 * 10;
		while (tmp + tmp1 <= a)
		{
			buf++;
			tmp = tmp + tmp1;
		}
		ans.push_back(buf + '0');
		//std::clog << tmp1.to_string() << " " << buf << std::endl;
		j--;
	}
	mynat ret(ans);
	while (ret.v.length() > 1 && ret.v.back() == '0')
		ret.v.pop_back();
	return ret;
}

mynat mynat::operator-(const mynat& m) const
{
	mynat a(this), b(m);
	if (b > a)
	{
		mynat tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	mynat ret = a;
	mynat k = b;
	int len1 = (int)ret.v.length(), len2 = (int)k.v.length(), j = len2;
	while (j--)
	{
		int i = j;
		if (ret.v[i] >= k.v[i])
		{
			ret.v[i] = ret.v[i] - k.v[i] + '0';
		}
		else
		{
			int buf = 10 + ret.v[i] - '0';
			buf = buf - (k.v[i] - '0');
			ret.v[i] = buf + '0';
			int pos = i + 1;
			while (ret.v[pos] == '0')
			{
				ret.v[pos] = '9';
				pos++;
			}
			ret.v[pos] = ret.v[pos] - 1;
		}
		while (ret.v.length() > 1 && ret.v.back() == '0')
			ret.v.pop_back();
	}
	return ret;
}


mynat mynat::operator%(const mynat& m) const
{
	if (m == 0)
	{
		std::clog << "[Warninig] mynat mod by 0 " << std::endl;
		return mynat(0);
	}
	if (m >= mynat(this))
		return mynat(this);
	mynat ret = mynat(this);
	mynat k = m * ((ret + 1) / m);
	int len1 = (int)ret.v.length(), len2 = (int)k.v.length(), j = len2;
	while (j--)
	{
		int i = j;
		if (ret.v[i] >= k.v[i])
		{
			ret.v[i] = ret.v[i] - k.v[i] + '0';
		}
		else
		{
			int buf = 10 + ret.v[i] - '0';
			buf = buf - (k.v[i] - '0');
			ret.v[i] = buf + '0';
			int pos = i + 1;
			while (ret.v[pos] == '0')
			{
				ret.v[pos] = '9';
				pos++;
			}
			ret.v[pos] = ret.v[pos] - 1;
		}
		while (ret.v.length() > 1 && ret.v.back() == '0')
			ret.v.pop_back();
	}
	return ret;
}

bool mynat::operator<(const mynat& m) const
{
	int len1 = (int)v.length(), len2 = (int)m.v.length(), i = 0, j = 0;
	if (len1 > len2)
		return false;
	if (len1 < len2)
		return true;
	int len = len1;
	while (len--)
	{
		if (v[len] < m.v[len])
			return true;
		if (v[len] == m.v[len])
			continue;
		if (v[len] > m.v[len])
			return false;
	}
	return false;
}

bool mynat::operator>(const mynat& m) const
{
	int len1 = (int)v.length(), len2 = (int)m.v.length(), i = 0, j = 0;
	if (len1 > len2)
		return true;
	if (len1 < len2)
		return false;
	int len = len1;
	while (len--)
	{
		if (v[len] > m.v[len])
			return true;
		if (v[len] == m.v[len])
			continue;
		if (v[len] < m.v[len])
			return false;
	}
	return false;
}

bool mynat::operator==(const mynat& m) const
{
	int len1 = (int)v.length(), len2 = (int)m.v.length(), i = 0, j = 0;
	if (len1 > len2)
		return false;
	if (len1 < len2)
		return false;
	int len = len1;
	while (len--)
	{
		if (v[len] != m.v[len])
			return false;
	}
	return true;
}

bool mynat::operator<=(const mynat& m) const
{
	return (mynat(this) < m) || (mynat(this) == m);
}

bool mynat::operator>=(const mynat& m) const
{
	return (mynat(this) > m) || (mynat(this) == m);
}

bool mynat::operator!=(const mynat& m) const
{
	return !(mynat(this) == m);
}