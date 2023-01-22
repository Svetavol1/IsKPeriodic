#include<iostream>
#include<string>
#include"functions.h"
using namespace std;

int indx(string str) //Возвращает длинну повторяющейся строки
{
	for (int i = 0; i < size(str); i++)
	{
		for (int j = 0; j < i; j++) 
		{
			if (str[i] == str[j]) //Проверка на совпадение прошлых букв
			{
				return i;
			}
		}
	}
	return size(str);
}

bool IsKPeriodic(string strr, int K) //Проверяет строку на кратность числу K
{
	string repeating; //Хранит подстроку
	int count = 0; //Хранит кол-во подстрок в основной строке
	for (int i = 0; i < indx(strr); i++)
	{
		repeating += strr[i];
	}
	if (size(strr) % size(repeating) != 0) //Проверка на целостность строки
	{
		return false;
	}
	for (int i = 0; i < size(strr); i += size(repeating)) //Считаем кол-во подстрок
	{
		string temp;
		temp = "";
		for (int j = i, o = 0; o < size(repeating); j++, o++)
		{
			temp += strr[j];
		}
		if (temp == repeating)
		{
			count++;
		}
	}
	if (size(strr) / size(repeating) == count && K != 0 && K > 0 && count % K == 0) //Проверка состава основной строки и самого числа K
	{
		return true;
	}
	return false;
}