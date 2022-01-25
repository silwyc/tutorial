#include "inc/functions.hpp"
using namespace std;

/*Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если все диагональные элементы матрицы положительны и содержат 
цифры 3 или 5, заменить минимальные элементы столбцов на суммы квадратов элементов соответствующих столбцов.*/


int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    int matrix[100][100];
    cin >> n >> m;
    read(n, m, matrix);

    if (positive(n, m, matrix) && threeorfive(n, m, matrix)) {
        replace(n, m, matrix);
        write(n, m, matrix);
    }
    else {
        cout << "Все диагональные элементы матрицы отрицательные и не содержат цифры 3 или 5";
    }
}