#include "Prescription.h"

Prescription::Prescription() {}

Prescription::Prescription(const char* _name, int _y, int _m, int _d, const char* _diag, int _prscID) 
	:Identifiable(_name, _y, _m, _d),
	diagnosis(_diag),
	prscID(_prscID){}

void Prescription::setName(const char* _name) { name = _name; }

String Prescription::getName() const { return name; }

void Prescription::setDate(int _y, int _m, int _d) { date(_y, _m, _d); };

Date Prescription::getDate() const { return date; }

void Prescription::setDiagnosis(const char* _diag) { diagnosis=_diag; };

String Prescription::getDiagnosis()const { return diagnosis; };

void Prescription::setPrescriptionID(int _prscID) { prscID = _prscID; };

int Prescription::getPrescriptionID()const { return prscID; };

bool Prescription::isValid(Date& _today)
{
	if (IDisValid())
	{
		if (_today.getYear() == date.getYear())
		{
			if (_today.getMonth() == date.getMonth())
			{
				if (_today.getDay() >= date.getDay())
				{
					return true;
				}
			}
			if (_today.getMonth() > date.getMonth())
			{
				return true;
			}
			return false;
		}

		if ((_today.getYear() - date.getYear()) == 1)
		{
			if (_today.getMonth() == date.getMonth())
			{
				if (_today.getDay() <= date.getDay())
				{
					return true;
				}
			}
			if (_today.getMonth() < date.getMonth())
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

bool Prescription::isPrime(int pair)
{
	for (int i = 2; i <= pair / 2; ++i)
	{
		if (pair % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool Prescription::IDisValid() 
{
	int fSum=(prscID/1000)+((prscID/100)%10);
	int sSum=((prscID / 10)%10) + (prscID % 10);

	if (isPrime(fSum) && isPrime(sSum) && (fSum > sSum))
	{
		return true;
	}
	return false;
}