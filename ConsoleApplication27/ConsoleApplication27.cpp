// ConsoleApplication27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<list>
#include<string>
#include<algorithm>




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

void reverse(Stack<std::string> s, int x)
{
	
	while (x != 0)
	{
		int a = x % 10;
		s.push(std::to_string(a));
		x /= 10;
		

	}
	std::string res("");
	Stack<std::string>::stack_result<std::string> el = s.pop();
	while ( el())
	{
		res += el.unpack();
		
		el = s.pop();
	}
	std::reverse(res.begin(),res.end());
	std::cout << "result - " << res << std::endl;

}



int main()
{
	Stack<std::string> s;
	while (1) 
	{
		std::cout << "Input number" << std::endl;
		int x;
		std::cin >> x;
		if (x == -1)
			break;
		reverse(s,x);
		

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
