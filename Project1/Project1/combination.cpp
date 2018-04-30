#include "combination.h"
#include <algorithm>
#include <numeric>
#include <iostream>

//конструктор с параметрами, задаем сохранение и печать по умолчанию true
combination::combination(int _n, int _k):saveFlag(true),printFlag(true)
{
	n = _n;
	k = _k;

	// задаем размер последовательностей - k
	current.resize(k);

	//генерируем первую последовательности (1, ..., k)
	std::iota(current.begin(), current.end(), 1);

	count = 1;
}


combination::~combination()
{
	current.clear();
	data.clear();
}

void combination::run()
{
	save_and_print();
	while (true)
	{
		// генерируем следующую последовательность
		for (int i = k - 1; i >= 0; i--)
		{
			if (current[i] < n - k + i + 1)
			{
				current[i]++;
				for (int j = i + 1; j < k; j++)
					current[j] = current[j - 1] + 1;
				// сгенерировали, сохраняем
				count++;
				save_and_print();
				break;
			}
		}
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
