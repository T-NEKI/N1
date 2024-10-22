#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}


int daysInMonth(int month, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}
int calculateDaysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2) {

    if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
        swap(d1, d2);
        swap(m1, m2);
        swap(y1, y2);
    }


    int days = 0;

    days += daysInMonth(m1, y1) - d1;

    m1++;
    if (m1 > 12) {
        m1 = 1;
        y1++;
    }

    while (y1 < y2 || (y1 == y2 && m1 < m2)) {
        days += daysInMonth(m1, y1);
        m1++;
        if (m1 > 12) {
            m1 = 1;
            y1++;
        }
    }


    days += d2;

    return days;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int day1, month1, year1;
    int day2, month2, year2;

    cout << "Введите первую дату (дд мм гггг): ";
    cin >> day1 >> month1 >> year1;

    cout << "Введите вторую дату (дд мм гггг): ";
    cin >> day2 >> month2 >> year2;

    int days = calculateDaysBetweenDates(day1, month1, year1, day2, month2, year2);
    cout << "Разность в днях между датами: " << days << endl;

    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

double calculateAverage(int arr[], int size) {
    if (size == 0) return 0; 

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите количество элементов в массиве: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    double average = calculateAverage(arr, size);
    cout << "Среднее арифметическое элементов массива: " << average << endl;

    delete[] arr;
}


//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

void countElements(const int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else { 
            zeroCount++;
        }
    }
}

int main() {
    const int size = 8;
    int arr[size] = { 1, -2, 0, 4, -5, 0, 3, -1 };
    int positiveCount, negativeCount, zeroCount;

   
    countElements(arr, size, positiveCount, negativeCount, zeroCount);


    cout << "Положительных: " << positiveCount << endl;
    cout << "Отрицательных: " << negativeCount << endl;
    cout << "Нулевых: " << zeroCount << endl;

    return 0;
}











