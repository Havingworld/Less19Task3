/*
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:

имя и фамилия человека;
количество денег, которые были выплачены лицу;
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.

Пример данных ведомости

Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019
*/

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
using namespace std;

int main()
{
    ifstream statement("statement.txt");
    if (statement.is_open())
    {
        string firstname, secendname, data,
                bigFirstname, bigSecendname;
        float cash, bigCash = 0, summ = 0;
        
        while (!statement.eof())
        {
            statement >> firstname >> secendname >> cash >> data;
            if (cash > bigCash) {
                bigCash = cash;
                bigFirstname = firstname;
                bigSecendname = secendname;
            }
            summ += cash;
        }

        cout << "Summ of cash: " << summ << "$" << endl
            << "Bigger payment: " << bigFirstname << " "
            << bigSecendname << " - "
            << bigCash << "$";

    }
    else
    {
        // show message:
        cout << "Error opening file";
    }

    statement.close();
}