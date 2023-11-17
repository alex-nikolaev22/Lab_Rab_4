// создать класс, рассчитывающий занчения функции в точке, записывающий это значение в файл
// выводящий значение из файла, выводящий значение в консоль
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class super_func
{
    public:
    int i;//переменная под счетчик
    double massiv_y[21];//массив для значений функции в точке

    double CompositeFunction(int xf) // расчет функции
    {
        double yf;
        if (xf < -3)
        {
            yf = 1;
        }
        if ((xf >= -3) && (xf < -1))
        {
            yf = -pow((4 - pow((xf + 1), 2)), 0.5);
        }
        if ((xf >= -1) && (xf < 2))
        {
            yf = -2;
        }
        if (xf >= 2)
        {
            yf = xf - 4;
        }
        return (yf);
    }

    void write_to_file() // запись значений функции в файл
    {
        ofstream fout("Baza.txt");//открытие файла на запись
        for (i = -10; i <= 10; i++)
        {
            fout << CompositeFunction(i) << endl;//запись значения функции в файл
        }
        fout.close();//закрытие записи в файл
    }

    void read_from_file() // чтение значений функции из файла
    {
        ifstream fin("Baza.txt");//открытие файла на чтение
        for (i = -10; i <= 10; i++)
        {
            fin >> massiv_y[i + 10];//построчное чтение из файла в массив
        }
        fin.close();//закрытипе файла на чтение
    }

    void write_to_console() // вывод значений функции в консоль
    {
        for (i = -10; i <= 10; i++)
        {
           cout << "y(" << i << ")=" << massiv_y[i + 10] << endl;//построчный вывод значений массива в консоль
        }
    }
};

int main()
{
    super_func f1;//объявление переменной f1 класса  super_func
    f1.write_to_file();//запись в файл переменной f1
    f1.read_from_file();//чтение из файла переменной f1
    f1.write_to_console();//вывод в консоль переменной f1
}