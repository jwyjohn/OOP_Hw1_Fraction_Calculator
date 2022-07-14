#include "fraction.h"
#include"myint.h"
#include<iostream>

myint gcd(const myint& a, const myint& b)
{

	myint t, r, m = a, n = b;
	if (m < n)
	{
		t = m;
		m = n;
		n = t;
	}
	while ((m % n) != 0)
	{
		//std::clog << "\n[Debug] gcd " << m.to_string() << " " << n.to_string() << std::endl;
		r = m % n;
		m = n;
		n = r;
		//std::clog << "\n[Debug] gcd " << " " << r.to_string() << m.to_string() << " " << n.to_string() << std::endl;
	}
	//std::clog << "\n[Debug] gcd done " << n.to_string() << std::endl;
	return n;
}

void fraction::normalize()
{
	//std::clog << "\n[Debug] 1 reducing" << this->to_string() << std::endl;
	if (b < 0)
	{
		//std::clog << "\n[Debug] 1.1 reducing" << this->to_string() << std::endl;
		a = -a;
		b = -b;
	}
	//std::clog << "\n[Debug] 2 reducing" << this->to_string() << std::endl;
	if (b == 0)
	{
		std::cerr << "\n[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
		return;
	}
	if (a == 0)
	{
		b = 1;
		return;
	}
	//std::clog << "\n[Debug] 3 reducing" << this->to_string() << std::endl;
	bool is_neg = (a < 0);
	if (is_neg) { a = -a; }
	//std::clog << "\n[Debug] 4 reducing" << this->to_string() << std::endl;
	myint g = gcd(a, b);
	//std::clog << "\n[Debug] 5 reducing" << this->to_string() << " gcd = " << g.to_string() << std::endl;
	a = a / g;
	b = b / g;
	if (is_neg) { a = -a; }
	//std::clog << "\n[Debug] 6 reducing" << this->to_string() << std::endl;
}

fraction::fraction() : a(0), b(1)
{
}

fraction::fraction(const myint& n) : a(n), b(1)
{
}

fraction::fraction(const fraction& m)
{
	a = m.a;
	b = m.b;
	if (b == 0)
	{
		std::clog << "\n[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const fraction* m)
{
	a = m->a;
	b = m->b;
	if (b == 0)
	{
		std::clog << "\n[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const myint& am, const myint& bm)
{
	a = am;
	b = bm;
	if (b == 0)
	{
		std::clog << "\n[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const std::string& s)
{
	//std::clog << "[Debug] called fraction from str " << s << std::endl;
	// -a/b , a/b
	int pos = 0, n = (int)s.length();
	while (s[pos] != '/' && pos < n)
		pos++;
	//std::clog << "[Debug] pos=" << pos << std::endl;
	if (pos == n)
	{
		a = myint(s);
		b = 1;
		return;
	}
	a = myint(s.substr(0, pos));
	b = myint(s.substr(pos + 1));
	if (b == 0)
	{
		std::clog << "\n[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const double f, int n)
{
	double x = f;
	if (x < 0) { x = -x; }
	int ans1 = 1, ans2 = 1;
	for (int i = 1; i <= n; i++)
	{
		double z = (i * 1.0) / x + 0.5;
		int a = (int)z;
		if (fabs((i * 1.0) / (a * 1.0) - x) < fabs((ans1 * 1.0) / (ans2 * 1.0) - x) && a <= n)
		{
			ans1 = i;
			ans2 = a;
		}
	}
	if (f < 0) { ans1 = -ans1; };
	a = myint(ans1);
	b = myint(ans2);
	normalize();
}

std::string fraction::to_string() const
{
	if (a == b && b != 0)
		return std::string("1");
	if (b == 1)
		return std::string(a.to_string());
	return std::string(a.to_string() + "/" + b.to_string());
}

fraction fraction::operator-() const
{
	return fraction(-a, b);
}

fraction fraction::reciprocal() const
{
	if (a == 0)
	{
		std::cerr << "[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
	}
	return fraction(b, a);
}

fraction fraction::operator+(const fraction& m) const
{
	return fraction(a * m.b + b * m.a, b * m.b);
}

fraction fraction::operator-(const fraction& m) const
{
	return fraction(a * m.b - b * m.a, b * m.b);
}

fraction fraction::operator*(const fraction& m) const
{
	return fraction(a * m.a, b * m.b);
}

fraction fraction::operator/(const fraction& m) const
{
	return fraction(m.reciprocal() * this);
}

bool fraction::operator>(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b > f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator<(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b < f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator>=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b >= f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator<=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b <= f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator==(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b == f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator!=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b != f2.a * f1.b)
		return true;
	return false;
}

fraction fraction::reduce() const
{
	fraction ret(this);
	ret.normalize();
	return ret;
}

void fraction::display() const
{
	if (b == 0)
	{
		std::cerr << "[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
		return;
	}
	std::cout << this->to_string() << std::endl;
}
