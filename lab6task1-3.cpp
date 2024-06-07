#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 40;

// ������� ��� ������ �������� ��������� ���������� �������� � �������
void printGrid(vector<vector<bool>>& grid) {
    system("cls");
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            cout << (grid[y][x] ? " 0 " : " . "); // ����� ������ - 0, ������� - ������
        }
        cout << endl;
    }
}

// ������� ��� �������� ���������� ������� � ������ � ������������ (x, y)
int countNeighbors(vector<vector<bool>>& grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // ������� ������� ������
            int nx = x + i;
            int ny = y + j;
            // ��������� ��������� ���������
            nx = (nx + WIDTH) % WIDTH;
            ny = (ny + HEIGHT) % HEIGHT;
            if (grid[ny][nx]) count++;
        }
    }
    return count;
}

// ������� ��� ���������� ��������� ���������� �������� �� ��������� ���������
void updateGrid(vector<vector<bool>>& grid) {
    vector<vector<bool>> newGrid = grid; // ����� ��������� ������

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int neighbors = countNeighbors(grid, x, y);
            // ������� ���������� ��������
            if (grid[y][x]) { // ����� ������
                if (neighbors < 2 || neighbors > 3) newGrid[y][x] = false; // ������� �� ����������� ��� �������������
            } else { // ������ ������
                if (neighbors == 3) newGrid[y][x] = true; // ������������, ���� ����� ����� 3 ����� ������
            }
        }
    }

    grid = newGrid; // ����������
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ������������� ���������� ��������� ����
    vector<vector<bool>> grid(HEIGHT, vector<bool>(WIDTH, false));

    // �����
    grid[5][5] = true;
    grid[6][6] = true;
    grid[7][4] = true;
    grid[7][5] = true;
    grid[7][6] = true;

    // ��������
    while (true) {
        printGrid(grid);
        updateGrid(grid);
        Sleep(200); // ��������
    }

    return 0;
}
