#pragma once
#include <iostream>
#include<string>
#include <sstream>

using namespace std;
template <typename T>bool somef(T a) 
{
	return true;
}
bool is_int(string buf, int &k, bool(*control)(int&) = &somef)
{

	stringstream stream(buf);
	if ((buf.find('.') == std::string::npos) && (buf.find(',') == std::string::npos))
	{
		if (stream >> k)
		{
			if (control(k))
			{
				return true;
			}
			else 
			{
				cout << "Wrong diapason" << endl;
				return false;
			}
		}
		else
		{
			cout << "Not a number" << endl;
			return false;
		}
	}
	else
	{
		cout << "This is not a integer number " << endl;
		return false;
	}
}

bool is_long(string buf, long &k, bool(*control)(long)=&somef)
{

	stringstream stream(buf);
	if ((buf.find('.') == std::string::npos) && (buf.find(',') == std::string::npos))
	{
		if (stream >> k)
		{
			if (control(k))
			{
				return true;
			}
			else
			{
				cout << "Wrong diapason" << endl;
				return false;
			}

		}
		else
		{
			cout << "Not a number" << endl;
			return false;
		}
	}
	else
	{
		cout << "This is not a long integer number " << endl;
		return false;
	}
}

bool is_float(string buf, float &k, bool (*control)(float)=&somef)
{
	stringstream stream(buf);
	if (stream >> k)
	{
		if (control(k))
		{
			return true;
		}
		else
		{
			cout << "Wrong diapason" << endl;
			return false;
		}

	}
	else
	{
		cout << "This is not a float number." << endl;
		return false;
	}

}

bool is_double(string buf, double &k,bool(*control)(double)=&somef)
{
	stringstream stream(buf);
	if (stream >> k)
	{
		if (control(k))
		{
			return true;
		}
		else
		{
			cout << "Wrong diapason" << endl;
			return false;
		}

	}
	else
	{
		cout << "This is not a double number." << endl;
		return false;
	}

}

template<typename T> bool input_t_var(string buff, T &x, bool(*cobdition)(T&) = &somef)
{
	stringstream stream(buff);

	if (stream >> x)
	{
		if (cobdition(x))
		{
			return true;
		}
		else
			cout << "Wrong condition" << endl;

	}
	else
	{
		cout << "Type Eror" << endl;
		return false;
	}
}

bool input_t_var(string buff, int &x, bool(*cobdition)(int&) = &somef)
{
	return is_int(buff,x,cobdition);
}
