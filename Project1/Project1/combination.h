#pragma once
#include <vector>
class combination
{

	//
	//  ПОЛЯ
	//

private:

	// параметры последовательности
	int n, k;

	// флаг печати
	bool printFlag;

	// флаг сохранения последовательности
	bool saveFlag;

	// количество последовательностей
	int count;

	// последовательности ( если надо сохранять )
	std::vector<std::vector<int>> data;

	// текущая последовательность
	std::vector<int> current;

	//
	// МЕТОДЫ
	//

public:

	// конструктор
	combination(int _n, int _k);

	// деструктор
	~combination();

	// задание флага сохранения
	inline bool set_saveFlag(bool param) { saveFlag = param; }

	// задание флага печати
	inline bool set_printFlag(bool param) { printFlag = param; }

	// функция расчета
	void run();

private:

	// сохраняем и выводим текущую последовательность (если надо)
	void save_and_print();
};

