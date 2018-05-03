#include "combination.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <functional>

//конструктор с параметрами, задаем сохранение и печать по умолчанию true
combination::combination(int _m, int _n):saveFlag(true),printFlag(true)
{
	m = _m;
	n = _n;
	count = 0;

	// рекурсивный расчет числа разбиений
	true_count = calculate_count(m, n, m);
}

combination::~combination()
{
	clear();
}

// очищаем память
void combination::clear()
{
	current.clear();
	data.clear();
	current.resize(n);
	count = 0;
}

// генерируем разбиение
void combination::generate(int sum, int num, int val)
{
	if (num == 1)
	{
		current[n - 1] = sum;
		for (int i = 1; i < n; i++)
		{
			if (current[i] < current[i - 1])
				return;
		}
		save_and_print();
		count++;
		return;
	}
	else
	{
		for (int i = val; i < sum; i++)
		{
			current[n - num] = i;
			generate(sum - i, num - 1, i);
		}
	}
}

void combination::run()
{
	// очистим последовательности
	clear();
	
	generate(m, n, 1);

	if (!check_count())
	{
		std::cerr << "ERROR! Counts do not match!" << std::endl;
		_getch();
		exit(1);
	}
}

// сохраняем и выводим текущую последовательность (если надо)
void combination::save_and_print()
{
	// если надо выводить
	if (printFlag)
	{
		// выводим все элементы вектора
		for (int & item : current)
			std::cout << item << ' ';
		std::cout << '\n';
	}
	// если надо сохранять
	if (saveFlag)
	{
		data.push_back(current);
	}
}

// функция расчета с таймером
void combination::timer()
{
	// начало отмера времени
	std::clock_t clock_start = std::clock();
	auto time_start = std::chrono::high_resolution_clock::now();

	// расчет
	run();

	// конец отмера времени
	std::clock_t clock_end = std::clock();
	auto time_end = std::chrono::high_resolution_clock::now();

	// вывод времени
	std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
		<< 1000.0 * (clock_end - clock_start) / CLOCKS_PER_SEC << " ms\n"
		<< "Wall clock time passed: "
		<< std::chrono::duration<double, std::milli>(time_end - time_start).count()
		<< " ms\n";
}

// проверяем количество последовательностей
bool combination::check_count()
{
#ifdef _DEBUG
	std::cout << "true_count = " << true_count << std::endl;
	std::cout << "count = " << count << std::endl;
#endif
	if (count == true_count)
		return true;
	else
		return false;
}

// функция для расчета количества разбиений
int combination::calculate_count(int n, int m, int k)
{
	if ((n >= m) and (m > 0) /*and (n >= k)*/ and (k > 0))
	{
		return calculate_count(n, m, k - 1) + calculate_count(n - k, m - 1, k);
	}
	else if ((n == 0) and (m == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// проверяем последовательность с номером item
bool combination::check_combination(int item)
{
	return true;
}
