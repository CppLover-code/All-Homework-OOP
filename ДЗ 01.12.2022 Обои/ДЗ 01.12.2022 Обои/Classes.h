#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Roll
{
    char* roll_name = nullptr;
    float  roll_length = 0;
    float  roll_width = 0;
    float  price = 0;

public:
    Roll()
    {
        cout << "�������� ����������� Roll\n";
        if (std::cin.peek() == '\n') std::cin.get();                                        // ���� �� ���������� �������� ������� ������ \n, �� ������� ���

        if (roll_name != nullptr) delete[] roll_name;
        char tmp[20];
        cout << "������� �������� �����: ";
        cin.getline(tmp, 20);
        roll_name = new char[strlen(tmp) + 1];
        strcpy_s(roll_name, strlen(tmp) + 1, tmp);

        cout << "������� ����� �����: ";
        cin >> roll_length;

        cout << "������� ������ �����: ";
        cin >> roll_width;

        cout << "������� ���� 1 ������ �����: ";
        cin >> price;
    }

    float getRollL() { return roll_length; }
    float getRollW() { return roll_width; }
    float getRollP() { return price; }

    void rollOutput();
    
    ~Roll()
    {
        cout << "�������� ���������� Roll\n";
        if (roll_name != nullptr)
        {
            delete[] roll_name;
        }
    }
};
class Room
{
    char* room_name = nullptr;
    float room_length = 0;
    float room_width = 0;
    float room_height = 0;
    bool room_ceil = 0;
    Roll* roll = nullptr;

public:

    Room()
    {
        cout << "�������� ����������� Room\n";
        if (std::cin.peek() == '\n') std::cin.get();                                        // ���� �� ���������� �������� ������� ������ \n, �� ������� ���

        char tmp[20];
        cout << "\n������� �������� �������: ";
        cin.getline(tmp, 20);
        createName(tmp);

        std::cout << "������� ����� �������: ";
        cin >> room_length;

        std::cout << "������� ������ �������: ";
        cin >> room_width;

        std::cout << "������� ������ �������: ";
        cin >> room_height;

        std::cout << "������ �������: 1 - �� / 0 - ��� ";
        cin >> room_ceil;
        std::cout << "\n";

        roll = new Roll[1]{};
    }

    void createName(const char* name);
    void Output();
    float priceCalculation();

    ~Room()
    {
        cout << "�������� ���������� Room\n";
        if (room_name != nullptr) delete[] room_name;

        delete[] roll;
    }
};
class Flat
{
    Room* rooms = nullptr;
    int rooms_count = 0;

public:
    Flat(int count) : rooms{ new Room[count] {} }, rooms_count{ count }                                       // ���������� ��������� ������ � ������������� (���������)
    {
        cout << "�������� ����������� Flat ��� ��������� ������ ��� ������ ��������"
             << rooms_count << "\n";
        system("cls");
    }

    float getPrice();
    void flatOutput();

    ~Flat()
    {
        cout << "�������� ���������� Flat\n";
        delete[] rooms;
    }
};
