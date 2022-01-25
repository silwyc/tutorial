#include <iostream>
using namespace std;

/*Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если все диагональные элементы матрицы положительны и содержат 
цифры 3 или 5, заменить минимальные элементы столбцов на суммы квадратов элементов соответствующих столбцов.*/

void read(int n, int m, int matrix[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void write(int n, int m, int matrix[100][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool positive (int n, int m, int matrix[100][100]) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] <= 0)
            return false;
    }
    return true;
}

bool number(int num, int neednum) {
    while (num > 0) {
        int lastnum = num % 10;
        if (lastnum == neednum)
            return true;
        num = num / 10;
    }
    return false;
}

bool threeorfive(int n, int m, int matrix[100][100]) {
    for (int i = 0; i < n; i++) {
        if (number(matrix[i][i], 3) || number(matrix[i][i], 5))
            return true;
     }
    return false;
}

int sumsqrt(int n, int m, int matrix[100][100], int index_j) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + matrix[i][index_j] * matrix[i][index_j];
    }
    return sum;
}

void replace(int n, int m, int matrix[100][100]) {
    for (int j = 0; j < m; j++) {
        int min_i = matrix[0][j];
        int index_i = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < min_i)
                min_i = matrix[i][j];
                index_i = i;
        }
        matrix[min_i][j] = sumsqrt(n, m, matrix, j);
    }
}

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