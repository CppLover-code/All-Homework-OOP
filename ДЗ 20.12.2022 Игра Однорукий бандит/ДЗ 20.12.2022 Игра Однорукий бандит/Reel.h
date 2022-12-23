#pragma once

class Reel
{
	int* Line;																	// ������ ��� �������� �������
	
	int MaxReelLength;															//������������ ������ �������
	
	int ReelLength;																//������� ������ �������

public:

	Reel(int m);																//�����������
	
	~Reel();																	//����������
	
	bool IsEmpty();																//�������� ������������� ��������� � �������

	bool IsFull();																//�������� �� ������������ �������

	void Add(int c);															//���������� ��������
	
	int Extract();																// ���������� ��������

	int reelRandom(int& n);														// ������ ��� �������� � ������� 1 ����� ��� ����������

	void Clear();																//������� �������
	
	int GetCount();																//���������� ��������� � �������
	
	void Show();																//������������ �������

};
