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
	inline bool set_saveFlag(bool param) { saveFlag = param; }

	// задание флага печати
	inline bool set_printFlag(bool param) { printFlag = param; }

	// функци¤ расчета
	void run();

	// функция расчета с таймером
	void run_and_timer();

private:

	// сохран¤ем и выводим текущую последовательность (если надо)
	void save_and_print();

	// генерируем первую последовательность
	void generate_first();

	// генерируем следующую последовательность
	bool generate_next();

	// очищаем память
	void clear();
};

