#pragma once
#include <vector>
class combination
{

	//
	//  ����
	//

private:

	// ��������� ������������������
	int n, k;

	// ���� ������
	bool printFlag;

	// ���� ���������� ������������������
	bool saveFlag;

	// ���������� �������������������
	int count;

	// ������������������ ( ���� ���� ��������� )
	std::vector<std::vector<int>> data;

	// ������� ������������������
	std::vector<int> current;

	//
	// ������
	//

public:

	// �����������
	combination(int _n, int _k);

	// ����������
	~combination();

	// ������� ����� ����������
	inline bool set_saveFlag(bool param) { saveFlag = param; }

	// ������� ����� ������
	inline bool set_printFlag(bool param) { printFlag = param; }

	// ������� �������
	void run();

private:

	// ��������� � ������� ������� ������������������ (���� ����)
	void save_and_print();
};

