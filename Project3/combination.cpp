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

//генерируем последовательность
void combination::generate(int num, int val)
{
	// если нельзя сделать шаг
	if (num > k or val > n)
	{
		return;
	}
	int tmp;
	//если надо сохранить значение шага
	if (num >= 0)
	{
		tmp = current[num];
		current[num] = val;
	}
	//если пора печатать последовательность
	if (num == k - 1)
	{
		save_and_print();
		count++;
		return;
	}
	// поставим генерироваться на следующей позиции
	for (int value = val + 1; value <= n; value++)
	{
		generate(num + 1, value);
	}
	// возвращаем предыдущее значение
	if (num >= 0)
	{
		current[num] = tmp;
	}
	
}

void combination::run()
{
	// очистим последовательности
	clear();
	current.resize(k);
	count = 0;

	// сгенерируем первую последовательность
	generate(-1, 0);

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
