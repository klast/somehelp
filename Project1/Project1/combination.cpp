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
combination::combination(int _n, int _k):saveFlag(true),printFlag(true)
{
	n = _n;
	k = _k;
	count = 0;

	// numbers - вектор от 1 до n, factorials - факториалы от numbers
	std::vector<int> numbers(n), factorials(n);
	// генерируем numbers от 1 до n
	std::iota(numbers.begin(), numbers.end(), 1);
	//генерируем факториалы
	std::partial_sum(numbers.begin(), numbers.end(), factorials.begin(), std::multiplies<int>());
	// посчитаем количество сочетаний n! / (n-k)! k!  ( помним, что нумерация с 0, так что везде минус 1)
	true_count = factorials[n-1] / (factorials[n-k-1] * factorials[k-1]);
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
}

void combination::run()
{
	// очистим последовательности
	clear();

	// сгенерируем первую последовательность
	generate_first();
	save_and_print();

	// генерируем следующие
	while (true)
	{
		bool is_generated = generate_next();
		if (is_generated)
			save_and_print();
		else
			break;
	}

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

// генерируем первую последовательность
void combination::generate_first()
{
	// задаем размер последовательностей - k
	current.resize(k);

	//генерируем первую последовательность (1, ..., k)
	std::iota(current.begin(), current.end(), 1);
	count = 1;
}

// генерируем следующую последовательность
bool combination::generate_next()
{
	for (int i = k - 1; i >= 0; i--)
	{
		if (current[i] < n - k + i + 1)
		{
			current[i]++;
			for (int j = i + 1; j < k; j++)
				current[j] = current[j - 1] + 1;
			count++;
			return true;
		}
	}
	return false;
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
	if (count == true_count)
		return true;
	else
		return false;
}

// проверяем последовательность с номером item
bool combination::check_combination(int item)
{
	return true;
}
