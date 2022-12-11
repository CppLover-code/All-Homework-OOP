#include <iostream>
#include <windows.h>
#include "Classes.h"
using namespace std;

void Roll::rollOutput()
{
    cout << "\n" << "�������� �����: " << roll_name << std::endl
        << "����� �����: " << roll_length << std::endl
        << "������ �����: " << roll_width << std::endl
        << "���� 1 ������: " << price << std::endl;
}

void Room::createName(const char* name)
{
    this->room_name = new char[strlen(name) + 1];
    strcpy_s(this->room_name, strlen(name) + 1, name);
}

void Room::Output()
{
    std::cout << "\n" << "�������� �������: " << room_name << std::endl
        << "����� �������: " << room_length << std::endl
        << "������ �������: " << room_width << std::endl
        << "������ �������: " << room_height << std::endl
        << "������ �������: " << ((room_ceil) ? "��" : "���") << std::endl;
    roll[0].rollOutput();
}

float Room::priceCalculation()                                                                             // ��� ����� �������
{
    float P;                                                                                               // ��������
    float strips;                                                                                          // ����� ���-�� ����� ������ ��� ���� �������
    float stripsRoll;                                                                                      // ���-�� ����� � 1 ������
    float rollCountWalls;                                                                                  // ���-�� ������� ����� ��� ���� �� 1 �������
    float rollCountCeiling;                                                                                // ���-�� ������� ����� ��� ������� 1 �������

    P = 2 * (room_length + room_width);
    strips = P / roll->getRollW();
    stripsRoll = roll->getRollL() / room_height;
    rollCountWalls = strips / stripsRoll;

    rollCountCeiling = (room_width / roll->getRollW()) / (roll->getRollL() / room_length);

    if (room_ceil) return roll->getRollP() * (rollCountWalls + rollCountCeiling);                          // ���� ���� ������ �������
    else return roll->getRollP() * rollCountWalls;                                                         // ���� �� ���� ������ �������
}

float Flat::getPrice()                                                                                     // ����� ��� ��������� � ������������ ��� �� ���� ��� ������ �������
{
    float totalCost = 0;
    for (int i = 0; i < rooms_count; ++i)
    {
        totalCost += rooms[i].priceCalculation();
    }
    return totalCost;
}

void Flat::flatOutput()
{
    for (int i = 0; i < rooms_count; ++i)
    {
        cout << "������� " << i + 1 << "\n";
        rooms[i].Output();
    }
    cout << "\n\n";
}