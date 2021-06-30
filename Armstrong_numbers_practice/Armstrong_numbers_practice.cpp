/*
Файл: Практическая_работа.2021.cpp
Тип работы: Практическая работа.
Автор: Слесарев Д. В. Группа: 515в
Дата создания: 25.06.2021
Тема работы: Числа Армстронга в заданом диапазоне.
*/
#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

/*
Назначение: Поиск и вывод всех чисел Армстронга в заданом диапазоне.
Параметры: min - начальное значение диапазона поиска,
max - конечное значение диапазона поиска.
*/
void armstrong(unsigned long long min, unsigned long long max);
/*
Назначение: Возведение в степень.
Параметры: Are[] - массив с цифрами проверяемого числа,
k - индек цифры для возведения в степень, count -  степень в которую необходимо возвести.
return num - возведенная цифра в степень count.
*/
int poww(unsigned long long Are[], int k, unsigned long long count);

void main()
{
	unsigned long long max, min;
	setlocale(LC_CTYPE, "rus");
	printf(" Введите нижний предел: ");
	scanf_s("%llu", &min);
	printf(" Введите верхний предел: ");
	scanf_s("%llu", &max);
	armstrong(min, max);
}
void armstrong(unsigned long long min, unsigned long long max)
{
	unsigned long long sum = 0, temp, count = 0, arey[40] = { 0 };
	for (unsigned long long i = min; i <= max; i++)
	{
		temp = i;
		for (int j = 0; temp != 0; j++) // Запись проверяемого числа в массив, и подсчет количества цифр в числе.
		{
			count++;
			arey[j] = temp % 10;
			temp /= 10;
		}
		for (int k = count - 1; k >= 0; k--)
		{
			if (sum > i) // Проверка. Если успешно, то пропускаем проверяемое число.
			{
				goto metka;
			}
			sum += poww(arey, k, count);
		}
		if (sum == i)
		{
			printf(" %llu\n", i);
		}
	metka:
		count = 0; sum = 0;
	}
}
int poww(unsigned long long Are[], int k, unsigned long long count)
{
	int num = 1;
	for (size_t i = 0; i < count; i++)
	{
		num *= Are[k];
	}
	return num;
}

