#include <iostream>
#include"Header.h"

void Game()        //�� ���� ��� �������� ���� �� ����� �������� ������ �������� ��� ������, ����� �� �������� �����������.
{                 //������ ��� ������������� �������� ������ ��� ��� ��� �������� � �������� �� �����.
    static int jack = 0;//� ������ ���� ��� ��������� ����������� ������ �������� �������� � �������� �����.
    int cash = 0;//������� �������� - ��� ����� ��� �� ��� �������� � ���� ����� ���� �������� ����� ����������� �����.

    void(*pPrintG)(short);
    pPrintG = PrintG;
    void(*pPrice)(short, int, int);
    pPrice = Price;

    do {
        if (cash)
        {
            jack += cash; //������� ������������� ��������.
            short x1 = rand() % 6;
            short x2 = rand() % 6;
            short x3 = rand() % 6;
         
            std::cout << "\n-----\n";
            for (int i = 0; i < 3; i++)//����� ������
            {
                pPrintG(x1+i);
                pPrintG(x2+i);
                pPrintG(x3+i);
                std::cout << "\n-----\n";
            }
            if (x1 == x2 && x2 == x3) pPrice(x1+1,jack, cash);//��������� � ��������,+1 ����� ��� �� �������� ������� �� ����� ���������� � ������, � �� ������.
        }
        std::cout << "��� ������� ������� ����� ";
        std::cin >> cash;
        std::cout << "\n";

    } while (cash);

}

void Program()
{
    int size{ 1 }; //������ ���� ������ 1
    int* arrayP = new int[size];//������ �����������
    int* arrayV = new int[size];//������ ��������

    void (*pZapros)(int*,int*,int);
    pZapros = Zapros;
    void (*pArrayH)(int*, int);
    pArrayH = ArrayH;
    void (*pPrint)(int*, int*, int);

    std::cout << "������� ������������� �������� ��� ��������� ������ !\n";
    do {
        pZapros(arrayP, arrayV, size);
        if (arrayP[size - 1] < 0 || arrayV[size - 1] < 0) { arrayP[size - 1] = 0; break; }//����� �� ������ ��������� �� ���������������, �� � ������������� ����� ����� ���� ��������� ��� ���� 0
        size++;
        pArrayH(arrayP, size);
        pArrayH(arrayV, size);
    } while (size);//������ ������� ��� �������������, ���� ����� ���� �������� if ������, �� ����������� ������ �������� �� ������ ����� ��������.

    pPrint(arrayP, arrayV, size);
}

void Zapros(int* arrayP, int* arrayV, int size)
{
    std::cout << "������� ��������� ";
    std::cin >> arrayP[size - 1];
    std::cout << "\n";
    if (arrayP[size - 1] >= 0)arrayP[size - 1] += 1;//�������� ���������� ��� �� ��������� ����� ���� ������ �� 0 ��� ���� �� ���������� ������������� ��������.
    std::cout << "������� �������� ";
    std::cin >> arrayV[size - 1];
    std::cout << "\n";
}

void Print(int* arrayP, int* arrayV, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int max = 0;
        int maxI = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (arrayP[i] > max) { max = arrayP[i]; maxI = i; }
        }
        std::cout << arrayV[maxI] << " ";
        arrayP[maxI] = 0;   //�������� �����, ��� ��������� �������.
    }
}

void ArrayH(int* arrayOld, int size)  //������ �������� ������� �� ������ � ������.
{
    int* arrayNew = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
        arrayNew[i] = arrayOld[i];
    }

    int* del = arrayOld;
    arrayOld = arrayNew;
    delete[] del;
}

void PrintG(short x)
{
    x = x % 6;//����� ��� �������� ����� ��-�� ����������� i ����� ���������� �� ��������.

    switch (x)
    {
    case (0):
        std::cout << "! ";
        break;
    case (1):
        std::cout << "@ ";
        break;
    case (2):
        std::cout << "# ";
        break;
    case (3):
        std::cout << "$ ";
        break;
    case (4):
        std::cout << "% ";
        break;
    case (5):
        std::cout << "* ";
        break;
    }
}

void Price(short x, int jack, int cash)
{
    x = x % 6;         //����� ��� �������� ����� ��-�� ����������� i ����� ���������� �� ��������.
    std::cout <<"��� ������� ";
    switch (x)
    {
    case (0):
        std::cout << cash<<"\n";
        jack -= cash;              //��� ������ ������� ������ ���� ������ �� ��������, ���� �� ��������� � ������������� ���������, ��� �� ��� ����� ����, �� ����������� ����.
        break;
    case (1):
        std::cout << cash*3 << "\n";
        jack -= cash * 3;
        break;
    case (2):
        std::cout << cash*5 << "\n";
        jack -= cash * 5;
        break;
    case (3):
        std::cout << cash*10 << "\n";
        jack -= cash * 10;
        break;
    case (4):
        std::cout << cash*100 << "\n";
        jack -= cash * 100;
        break;
    case (5):
        std::cout << jack << "\n";
        jack = 0;
        break;
    }
}