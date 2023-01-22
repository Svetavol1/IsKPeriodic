#include<iostream>
#include<string>
#include"functions.h"
using namespace std;

int indx(string str) //���������� ������ ������������� ������
{
	for (int i = 0; i < size(str); i++)
	{
		for (int j = 0; j < i; j++) 
		{
			if (str[i] == str[j]) //�������� �� ���������� ������� ����
			{
				return i;
			}
		}
	}
	return size(str);
}

bool IsKPeriodic(string strr, int K) //��������� ������ �� ��������� ����� K
{
	string repeating; //������ ���������
	int count = 0; //������ ���-�� �������� � �������� ������
	for (int i = 0; i < indx(strr); i++)
	{
		repeating += strr[i];
	}
	if (size(strr) % size(repeating) != 0) //�������� �� ����������� ������
	{
		return false;
	}
	for (int i = 0; i < size(strr); i += size(repeating)) //������� ���-�� ��������
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
	if (size(strr) / size(repeating) == count && K != 0 && K > 0 && count % K == 0) //�������� ������� �������� ������ � ������ ����� K
	{
		return true;
	}
	return false;
}