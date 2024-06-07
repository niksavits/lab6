#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const int M = 5; // количество строк
const int N = 4; // количество столбцов

void printMatrix(const vector<vector<int>>& matrix) { // вывод матрицы на экран
    for (const auto& row : matrix) { // перебор каждой строки матрицы
        for (int elem : row) { // перебор каждого элемента в строке
            cout << elem << "\t"; // вывод элемента на экран
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr)); // инициализация генератора случайных чисел

    vector<vector<int>> matrix(M, vector<int>(N));

    // заполнение матрицы случайными числами от -10 до 40
    for (int i = 0; i < M; ++i) { // перебор строк матрицы
        for (int j = 0; j < N; ++j) { // перебор столбцов матрицы
            matrix[i][j] = rand() % 51 - 10;
        }
    }

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    vector<vector<int>> selectedRows; // вектор для хранения строк с тремя и более отрицательными элементами

    for (int i = 0; i < M; ++i) { // перебор строк матрицы
        int negCount = 0;
        for (int j = 0; j < N; ++j) { // перебор столбцов матрицы в текущей строке
            if (matrix[i][j] < 0) {
                negCount++;
            }
        }
        if (negCount >= 3) {
            selectedRows.push_back(matrix[i]);
        }
    }

    cout << "Номера строк, содержащих хотя бы три отрицательных элемента:" << endl;
    for (size_t i = 0; i < matrix.size(); ++i) { // перебор индексов строк матрицы
        int negCount = 0;
        for (int j = 0; j < N; ++j) { // перебор столбцов матрицы в текущей строке
            if (matrix[i][j] < 0) {
                negCount++;
            }
        }
        if (negCount >= 3) {
            cout << i + 1 << " "; // выводим номер строки
        }
    }
    cout << endl;

    vector<int> negativeElements; // вектор для хранения всех отрицательных элементов
    for (const auto& row : selectedRows) { // перебор строк
        for (int elem : row) { // перебор элементов в текущей строке
            if (elem < 0) {
                negativeElements.push_back(elem);
            }
        }
    }

    cout << "Отрицательные элементы из выбранных строк:" << endl;
    for (int elem : negativeElements) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
