#include "Customer.h"

Customer::Customer(){}

Customer::Customer(const char* _name, int _y, int _m, int _d) :Identifiable(_name, _y, _m, _d){}

void Customer::setName(const char* _name) { name = _name; }

String Customer::getName() const { return name; }

void Customer::setDate(int _y, int _m, int _d) { date(_y, _m, _d); };

Date Customer::getDate() const { return date; }




//2019 5 19  2001 5 21
bool Customer::isAdult(Date& _today)
{
	if ((_today.getYear() - date.getYear()) > 18)
	{
		return true;
	}
	if ((_today.getYear() - date.getYear()) == 18)
	{
		if (_today.getMonth() >= date.getMonth())
		{
			if (_today.getDay() >= date.getDay())
			{
				return true;
			}
		}
	}
	return false;
}