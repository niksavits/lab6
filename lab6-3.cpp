#include<iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>

using namespace std;

const float E = 0.001; // ����������� ��������� E ��� ��������� ��������
const int n = 4; // ����������� ��������� n ��� ������� ������� � ��������

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	// ����������� ������� A �������� n x n
	float A[n][n] = {
		1.09, -0.04, 0.21, -18.00,
		0.25, -1.23, -0.16, -0.09,
		-0.21, -0.16, 0.8, -0.13,
		0.15, -1.31, 0.06, 0.84
	};
	float L[n][n], U[n][n]; // ���������� ������ L � U ��� LU-����������
	float B[n] = { -1.24,  0.84, 2.56, 1.09 }; // ���������� ������� ��������� ������ B
	float sum = 0; // ������������� ���������� sum ��� ���������� �����

	// LU-���������� ������� A
	for (int i = 0; i < n; i++) { // ���� �� �������
		for (int j = 0; j < n; j++) { // ���� �� ��������
			if (i <= j) { // ���������� ������� ����������� ������� U
				L[i][j] = 0; // �������� ���� ������� ��������� � L ����� 0
				if (i == j) {
					L[i][j] = 1; // �������� �� ������� ��������� � L ����� 1
				}
				for (int k = 0; k < i; k++) { // ���������� ����� ������������
					sum += (L[i][k] * U[k][j]);
				}
				U[i][j] = (A[i][j] - sum); // ���������� �������� ������� U
			}
			else if (i > j) { // ���������� ������ ����������� ������� L
				U[i][j] = 0; // �������� ���� ������� ��������� � U ����� 0
				for (int k = 0; k < j; k++) { // ���������� ����� ������������
					sum += L[i][k] * U[k][j];
				}
				L[i][j] = (A[i][j] - sum) / U[j][j]; // ���������� �������� ������� L
			}
			sum = 0; // ��������� �����
		}
	}

	// ����� ������� L
	cout << " L: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << fixed << setprecision(3) << L[i][j] << "  ";
		}
		cout << endl;
	}

	// ����� ������� U
	cout << endl << " U: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << fixed << setprecision(3) << U[i][j] << "  ";
		}
		cout << endl;
	}

	// ������� ������� ��������� ������� LU-����������
	float x[n], y[n]; // ���������� �������� x � y ��� ������������� ����������
	for (int k = 0; k < n; k++) { // ������ ���
		for (int j = 0; j < k; j++) {
			sum += L[k][j] * y[j]; // ���������� ����� ������������
		}
		y[k] = B[k] - sum; // ���������� �������� ������� y
		sum = 0; // ��������� �����
	}
	for (int k = n - 1; k >= 0; k--) { // �������� ���
		for (int j = k + 1; j < n; j++) {
			sum += U[k][j] * x[j]; // ���������� ����� ������������
		}
		x[k] = (y[k] - sum) / U[k][k]; // ���������� �������� ������� x
		sum = 0; // ��������� �����
	}

	cout << endl;
	for (int k = 0; k < n; k++) {
		cout << " X" << k + 1 << " : " << fixed << setprecision(3) << x[k] << "	Y" << k + 1 << " : " << fixed << setprecision(3) << y[k] << endl;
	}
	cout << endl;

	// ����� ������� ��������
	float xIter[n], C[n][n], f[n]; // ���������� �������� xIter � f � ������� C
	int iter = 0;
	// ������������� ��������� �������� ������� xIter
	for (int k = 0; k < n; k++) {
		xIter[k] = 0; // ��������� �������� ����� 0
	}
	float xTime[n]; // ������ ��� ���������� �������� �������� xIter

	cout << setw(10) << " N	" << setw(20) << " x1 " << setw(12) << " x2 " << setw(12) << " x3 " << setw(10) << " x4 " << setw(25) << " En " << endl;

	// ���� ��������
	while (true) {
		for (int i = 0; i < n; i++) { // ���� �� �������
			for (int j = 0; j < n; j++) { // ���� �� ��������
				if (i == j) {
					C[i][j] = 0; // �������� �� ������� ��������� � C ����� 0
				}
				else {
					// ������������� ����
					C[i][j] = -A[i][j] / A[i][i]; // ���������� ��������� ������� C
					sum += C[i][j]; // ���������� ����� ��������� C
				}
			}
			xTime[i] = xIter[i]; // ���������� ������� �������� xIter
			f[i] = B[i] / A[i][i]; // ���������� ��������� ������� f
			xIter[i] = f[i] + sum * xIter[i]; // ���������� ����� �������� xIter
			sum = 0; // ��������� �����
		}

		// �������� ������� ����������
		if (abs(xIter[0] - xTime[0]) < E) {
			cout << "�������� " << endl;
			cout << endl;
			for (int k = 0; k < n; k++) {
				cout << " X" << k + 1 << " : " << fixed << setprecision(3) << xIter[k] << endl;
			}
			break;
		}
		if (iter > 16) { // �������� �� ������������ ���������� ��������
			cout << "����������. �������: ������������ ������������: ������� ������������� ������� �������� ��������� ������ ���� ����������� ������������. ��� ��������, ��� ������ �������� �� ������� ��������� ������� ������ ���� ������ ����� ������� ���� ��������� ��������� � ��������������� ������ (��� �������)." << endl;
			cout << "����� ������� ������ 1: ����� �������, �������� � ������� ������������� �������, ������ ���� ������ 1. ��� ������������ ���������� ������������� ��������." << endl;
			break;
		}
		iter++;

		cout << setw(10) << iter << setw(25) << xIter[0] << setw(15) << xIter[1] << setw(10) << xIter[2] << setw(10) << xIter[3] << setw(25) << xIter[0] - xTime[0] << endl;
	}
}
