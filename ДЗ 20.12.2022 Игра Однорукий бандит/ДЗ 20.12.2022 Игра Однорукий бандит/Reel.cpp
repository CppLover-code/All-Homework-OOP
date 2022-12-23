#include "Reel.h"
#include <iostream>
#include <ctime>

using namespace std;

Reel::Reel(int m)															//�����������
{
	MaxReelLength = m;														//�������� ������

	Line = new int[MaxReelLength];											//������� �������

	ReelLength = 0;															//���������� ������� �����
}

Reel::~Reel()																//����������
{
	delete[] Line;															//�������� �������
}

bool Reel::IsEmpty()														//�������� ������������� ��������� � �������
{
	return ReelLength == 0;													//����?
}

bool Reel::IsFull()															//�������� �� ������������ �������
{
	return ReelLength == MaxReelLength;										// �����? 
}

void Reel::Add(int c)														//���������� ��������
{																			//���� � ������� ���� ��������� �����, 
																			//�� ����������� ����������																		
	if (!IsFull()) Line[ReelLength++] = c;									//�������� � ��������� ����� ������� 
}

int Reel::Extract()															// ���������� ��������
{
	//���� � ������� ���� ��������, �� ���������� ���,
	//������� ����� ������ � �������� ������� 
	if (!IsEmpty())
	{
		int temp = Line[0];													//��������� ������

		for (int i = 1; i < ReelLength; i++)								//�������� ��� ��������
			Line[i - 1] = Line[i];

		Line[ReelLength - 1] = temp;										// ����������� ������ "����������� ������� � �����"
		return temp;                                                        // ������� ������������ ��������
	}
	else return -1;
}

int Reel::reelRandom(int& n)												// ������ ��� �������� � ������� 1 ����� ��� ����������
{
	int l = 1 + rand() % 5;													// ��������� ����� �������� ��������
	//cout << " ��������� ����� �������� ��������  " << l << '\n';
	for (int k = 1; k <= l; k++) n = Extract();
	return n;
}

void Reel::Clear()															//������� �������
{
	ReelLength = 0;															//����������� "�������" �������
}

int Reel::GetCount()														//���������� ��������� � �������
{
	return ReelLength;														//���������� �������������� � ����� ��������� 
}

void Reel::Show()															//������������ �������
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < ReelLength; i++)
	{
		cout << Line[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
