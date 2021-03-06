// ConsoleApplication27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<list>
#include<string>
#include<algorithm>
#include"StupidUser.h"



template<typename T>
class Stack
{
private:
	std::list<T> base;
public:
	template<typename U> 
	class stack_result
	{
	private:
		U*el;
	public:
		stack_result(U el) 
		{
			this->el = new U(el);
		}
		~stack_result()
		{
		
		}
		stack_result() 
		{
			el = nullptr;
		}

		bool operator ()()
		{
			if (el == nullptr)
				return false;
			else
				return true;
		}
		U unpack() 
		{
			return *(el);
		}

	};
	
	Stack()
	{
	}

	void push(T el)
	{
		base.push_back(el);
	}

	stack_result<T> pop()
	{
		stack_result<T> res;
		if (!base.empty())
		{
			res=stack_result<T>(*(--base.end()));
			base.pop_back();
			return res;
		}
		else
		{
			res = stack_result<T>();
			return res;
		}
		
	}
};

void reverse(Stack<char> s, std::string x)
{
	
	while (x != "")
	{
		char a = x[x.size()-1];
		x.pop_back();
		s.push(a);
		

	}
	std::string res("");
	Stack<char>::stack_result<char> el = s.pop();
	Stack<char> temp;
	while ( el())
	{
		temp.push(el.unpack());
		el = s.pop();
	}
	el = temp.pop();
	while (el())
	{
		res += el.unpack();
		el = temp.pop();
	}
	std::cout << "result - " << res << std::endl;

}



int main()
{
	Stack<char> s;
	while (1) 
	{
		std::cout << "Input number" << std::endl;
		std::string x("");
		int i=0;
		double d = 0.0;
		std::cin >> x;
		if (x == "-1")
			break;
		if (input_t_var<int>(x, i) || input_t_var<double>(x, d))
		{
			reverse(s,x);
		}

		
		

	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
