#pragma once
#include <vector>
class combination
{

	//
	//  ѕќЋя
	//

private:

	// параметры последовательности
	int n, k;

	// флаг печати
	bool printFlag;

	// флаг сохранени¤ последовательности
	bool saveFlag;

	// количество последовательностей
	int count;

	// правильное количество последовательностей
	int true_count;

	// последовательности ( если надо сохран¤ть )
	std::vector<std::vector<int>> data;

	// текуща¤ последовательность
	std::vector<int> current;

	//
	// ћ≈“ќƒџ
	//

public:

	// конструктор
	combination(int _n, int _k);

	// деструктор
	~combination();

	// задание флага сохранени¤
	inline void set_saveFlag(bool param) { saveFlag = param; }

	// задание флага печати
	inline void set_printFlag(bool param) { printFlag = param; }

	// функци¤ расчета
	void run();

	// функция расчета с таймером
	void timer();

private:

	// сохран¤ем и выводим текущую последовательность (если надо)
	void save_and_print();

	// генерируем первую последовательность
	//void generate_first();

	// генерируем следующую последовательность
	//bool generate_next();

	//генерируем последовательность
	void generate(int num, int val);

	// очищаем память
	void clear();

	// проверяем количество последовательностей
	bool check_count();

	// проверяем последовательность с номером item
	bool check_combination(int item);
};

