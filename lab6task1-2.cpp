#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << setw(4) << elem;
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите четное число N для размера квадратной матрицы: ";
    int N;
    cin >> N;

    if (N % 2 != 0) {
        cout << "Число должно быть четным.\n";
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    // Создание матрицы N x N
    vector<vector<int>> matrix(N, vector<int>(N));

    // Заполнение матрицы случайными числами в диапазоне [10, 30]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 21 + 10;
        }
    }

    cout << "Исходная матрица:\n";
    printMatrix(matrix);

    // Поменять значения в верхних четвертях местами без использования swap
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][j + N / 2];
            matrix[i][j + N / 2] = temp;
        }
    }

    // Обнуление левой нижней четверти матрицы
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            matrix[i][j] = 0;
        }
    }

    // Заполнение правой нижней четверти матрицы числом 10
    for (int i = N / 2; i < N; i++) {
        for (int j = N / 2; j < N; j++) {
            matrix[i][j] = 10;
        }
    }

    cout << "Модифицированная матрица:\n";
    printMatrix(matrix);

    return 0;
}
