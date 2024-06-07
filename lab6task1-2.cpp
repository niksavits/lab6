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
    cout << "������� ������ ����� N ��� ������� ���������� �������: ";
    int N;
    cin >> N;

    if (N % 2 != 0) {
        cout << "����� ������ ���� ������.\n";
        return 1;
    }

    // ������������� ���������� ��������� �����
    srand(time(nullptr));

    // �������� ������� N x N
    vector<vector<int>> matrix(N, vector<int>(N));

    // ���������� ������� ���������� ������� � ��������� [10, 30]
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 21 + 10;
        }
    }

    cout << "�������� �������:\n";
    printMatrix(matrix);

    // �������� �������� � ������� ��������� ������� ��� ������������� swap
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][j + N / 2];
            matrix[i][j + N / 2] = temp;
        }
    }

    // ��������� ����� ������ �������� �������
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            matrix[i][j] = 0;
        }
    }

    // ���������� ������ ������ �������� ������� ������ 10
    for (int i = N / 2; i < N; i++) {
        for (int j = N / 2; j < N; j++) {
            matrix[i][j] = 10;
        }
    }

    cout << "���������������� �������:\n";
    printMatrix(matrix);

    return 0;
}
