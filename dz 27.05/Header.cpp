#include <iostream>
#include"Header.h"

void Game()        //по сути дл€ создани€ игры не нужно забивать пам€ть создава€ чар массив, знаки не €вл€ютс€ переменными.
{                 //значит нет необходимости забивать п€м€ть тем что нам известно и мен€тьс€ не будет.
    static int jack = 0;//в рамках игры нам посто€нно понадоб€тс€ только значени€ джекпота и вносимой суммы.
    int cash = 0;//джекпот статичен - это нужно что бы при возврате к игре можно было выйграть ранее потраченную сумму.

    void(*pPrintG)(short);
    pPrintG = PrintG;
    void(*pPrice)(short, int, int);
    pPrice = Price;

    do {
        if (cash)
        {
            jack += cash; //джекпот накапливаетс€ отдельно.
            short x1 = rand() % 6;
            short x2 = rand() % 6;
            short x3 = rand() % 6;
         
            std::cout << "\n-----\n";
            for (int i = 0; i < 3; i++)//вывод знаков
            {
                pPrintG(x1+i);
                pPrintG(x2+i);
                pPrintG(x3+i);
                std::cout << "\n-----\n";
            }
            if (x1 == x2 && x2 == x3) pPrice(x1+1,jack, cash);//сообщение о выигрыше,+1 нужен что бы выводить награду по числу указанному в центре, а не сверху.
        }
        std::cout << "ƒл€ попытки введите сумму ";
        std::cin >> cash;
        std::cout << "\n";

    } while (cash);

}

void Program()
{
    int size{ 1 }; //должен быть хот€бы 1
    int* arrayP = new int[size];//массив приоритетов
    int* arrayV = new int[size];//массив значений

    void (*pZapros)(int*,int*,int);
    pZapros = Zapros;
    void (*pArrayH)(int*, int);
    pArrayH = ArrayH;
    void (*pPrint)(int*, int*, int);

    std::cout << "¬ведите отрицательное значени€ дл€ остановки записи !\n";
    do {
        pZapros(arrayP, arrayV, size);
        if (arrayP[size - 1] < 0 || arrayV[size - 1] < 0) { arrayP[size - 1] = 0; break; }//нужно не только проверить на отрицательность, но и предотвратить вывод числа если приоритет был выше 0
        size++;
        pArrayH(arrayP, size);
        pArrayH(arrayV, size);
    } while (size);//просто условие дл€ бесконечности, сюда можно было вставить if сверху, но увеличивать размер хотелось бы только после проверки.

    pPrint(arrayP, arrayV, size);
}

void Zapros(int* arrayP, int* arrayV, int size)
{
    std::cout << "¬ведите приоритет ";
    std::cin >> arrayP[size - 1];
    std::cout << "\n";
    if (arrayP[size - 1] >= 0)arrayP[size - 1] += 1;//значение измен€етс€ что бы приоритет можно было мен€ть на 0 при этом не затрагива€ отрицательные значени€.
    std::cout << "¬ведите значение ";
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
        arrayP[maxI] = 0;   //значение вывел, его приоритет обнулил.
    }
}

void ArrayH(int* arrayOld, int size)  //просто создание массива по больше и замена.
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
    x = x % 6;//нужно дл€ ситуаций когда из-за прибавлени€ i число перевалило за диапазон.

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
    x = x % 6;         //нужно дл€ ситуаций когда из-за прибавлени€ i число перевалило за диапазон.
    std::cout <<"¬аш выигрыш ";
    switch (x)
    {
    case (0):
        std::cout << cash<<"\n";
        jack -= cash;              //при победе выигрыш должен быть вычтен из джекпота, дабы не приводить к отрицательным значени€м, они всЄ ещЄ могут быть, но веро€тность ниже.
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