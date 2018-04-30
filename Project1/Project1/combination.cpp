#include "combination.h"
#include <algorithm>
#include <numeric>
#include <iostream>

//����������� � �����������, ������ ���������� � ������ �� ��������� true
combination::combination(int _n, int _k):saveFlag(true),printFlag(true)
{
	n = _n;
	k = _k;

	// ������ ������ ������������������� - k
	current.resize(k);

	//���������� ������ ������������������ (1, ..., k)
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
		// ���������� ��������� ������������������
		for (int i = k - 1; i >= 0; i--)
		{
			if (current[i] < n - k + i + 1)
			{
				current[i]++;
				for (int j = i + 1; j < k; j++)
					current[j] = current[j - 1] + 1;
				// �������������, ���������
				count++;
				save_and_print();
				break;
			}
		}
	}
	
}

// ��������� � ������� ������� ������������������ (���� ����)
void combination::save_and_print()
{
	// ���� ���� ��������
	if (printFlag)
	{
		// ������� ��� �������� �������
		for (int & item : current)
			std::cout << item << ' ';
		std::cout << '\n';
	}
	// ���� ���� ���������
	if (saveFlag)
	{
		data.push_back(current);
	}
}
