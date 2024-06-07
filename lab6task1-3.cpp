#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 40;

// функция для вывода текущего состояния клеточного автомата в консоль
void printGrid(vector<vector<bool>>& grid) {
    system("cls");
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            cout << (grid[y][x] ? " 0 " : " . "); // живые клетки - 0, мертвые - пробел
        }
        cout << endl;
    }
}

// функция для подсчёта количества соседей у клетки с координатами (x, y)
int countNeighbors(vector<vector<bool>>& grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // пропуск текущей клетки
            int nx = x + i;
            int ny = y + j;
            // обработка замкнутой плоскости
            nx = (nx + WIDTH) % WIDTH;
            ny = (ny + HEIGHT) % HEIGHT;
            if (grid[ny][nx]) count++;
        }
    }
    return count;
}

// функция для обновления состояния клеточного автомата на следующее поколение
void updateGrid(vector<vector<bool>>& grid) {
    vector<vector<bool>> newGrid = grid; // новое состояние клеток

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int neighbors = countNeighbors(grid, x, y);
            // правила клеточного автомата
            if (grid[y][x]) { // живая клетка
                if (neighbors < 2 || neighbors > 3) newGrid[y][x] = false; // умирает от одиночества или перенаселения
            } else { // мёртвая клетка
                if (neighbors == 3) newGrid[y][x] = true; // возрождается, если рядом ровно 3 живые клетки
            }
        }
    }

    grid = newGrid; // обновление
}

int main() {
    setlocale(LC_ALL, "Russian");
    // инициализация начального состояния поля
    vector<vector<bool>> grid(HEIGHT, vector<bool>(WIDTH, false));

    // ружье
    grid[5][5] = true;
    grid[6][6] = true;
    grid[7][4] = true;
    grid[7][5] = true;
    grid[7][6] = true;

    // анимация
    while (true) {
        printGrid(grid);
        updateGrid(grid);
        Sleep(200); // задержка
    }

    return 0;
}
