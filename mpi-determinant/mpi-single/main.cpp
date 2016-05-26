//���������� ����� �� ������� ���������
//����� ��������: 
//1) ���� ����� ������, �� ���� ��� �������� ������, ����� �� 2 � ������� ��������� 2
//2) ��� ������ ����� ��������, �� ��������� �� ��������� ��� ������� �� �������� ����� ������� � 3
//3) ��������� ��������� ������� � ����� �� ��� ���� �����, ���� ��� �� ������ ��������

#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include  <chrono>

using namespace std;
using namespace std::chrono;

//������� ���������, ������ �� �����
unsigned long long isEven(unsigned long long number)
{
	if (number % 2 == 0) return number / 2;
	else return 0;
}


int main()
{
	unsigned long long t, backup_t;
	cout << "vvedite chislo\nhint: try 8789451874165\n";
	cin >> t;
	backup_t = t;
	cout << t << " = ";
	auto start = system_clock::now();
	unsigned long long temp = 1;
	//�������� �� �������� ����������� �� ����, ��� � ��� ����� �������, 2^59 ����������� �� 15 ��
	while (temp != 0)
	{
		temp = isEven(t);
		if (temp != 0)
		{
			t = temp;
			cout << 2;
			if (t > 1) cout << "*";
		}
	}
	unsigned long long i = 3;

	while (i <= t)
	{
		if (t % i == 0)
		{
			cout << i;
			t /= i;
			if (t > 1) cout << "*";
		}
		else i += 2;
	}
	auto end = system_clock::now();
	auto delta = duration_cast<milliseconds>(end - start).count();
	clog << endl << "Total: " << delta << " ms" << endl;

	return 0;
}