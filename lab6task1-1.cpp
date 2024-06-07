#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const int M = 5; // ���������� �����
const int N = 4; // ���������� ��������

void printMatrix(const vector<vector<int>>& matrix) { // ����� ������� �� �����
    for (const auto& row : matrix) { // ������� ������ ������ �������
        for (int elem : row) { // ������� ������� �������� � ������
            cout << elem << "\t"; // ����� �������� �� �����
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr)); // ������������� ���������� ��������� �����

    vector<vector<int>> matrix(M, vector<int>(N));

    // ���������� ������� ���������� ������� �� -10 �� 40
    for (int i = 0; i < M; ++i) { // ������� ����� �������
        for (int j = 0; j < N; ++j) { // ������� �������� �������
            matrix[i][j] = rand() % 51 - 10;
        }
    }

    cout << "�������� �������:" << endl;
    printMatrix(matrix);

    vector<vector<int>> selectedRows; // ������ ��� �������� ����� � ����� � ����� �������������� ����������

    for (int i = 0; i < M; ++i) { // ������� ����� �������
        int negCount = 0;
        for (int j = 0; j < N; ++j) { // ������� �������� ������� � ������� ������
            if (matrix[i][j] < 0) {
                negCount++;
            }
        }
        if (negCount >= 3) {
            selectedRows.push_back(matrix[i]);
        }
    }

    cout << "������ �����, ���������� ���� �� ��� ������������� ��������:" << endl;
    for (size_t i = 0; i < matrix.size(); ++i) { // ������� �������� ����� �������
        int negCount = 0;
        for (int j = 0; j < N; ++j) { // ������� �������� ������� � ������� ������
            if (matrix[i][j] < 0) {
                negCount++;
            }
        }
        if (negCount >= 3) {
            cout << i + 1 << " "; // ������� ����� ������
        }
    }
    cout << endl;

    vector<int> negativeElements; // ������ ��� �������� ���� ������������� ���������
    for (const auto& row : selectedRows) { // ������� �����
        for (int elem : row) { // ������� ��������� � ������� ������
            if (elem < 0) {
                negativeElements.push_back(elem);
            }
        }
    }

    cout << "������������� �������� �� ��������� �����:" << endl;
    for (int elem : negativeElements) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
