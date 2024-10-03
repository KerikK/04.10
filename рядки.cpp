

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

string** delete_row(string** arr, int& row, int col, int del_row) {
    string** new_arr = new string * [row - 1];
    for (int i = 0, new_i = 0; i < row; i++) {
        if (i != del_row) {
            new_arr[new_i] = new string[col];
            for (int j = 0; j < col; j++) {
                new_arr[new_i][j] = arr[i][j];
            }
            new_i++;
        }
    }
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    row--;
    return new_arr;
}

int main() {
    system("chcp 1251 > null");

    int row = 3, col = 3;
    string** arr = new string * [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new string[col];
    }

    cout << "Введіть дані для матриці (" << row << "x" << col << "):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    int del_row;
    cout << "Введіть номер рядка для видалення (0-" << row - 1 << "): ";
    cin >> del_row;
    if (del_row >= 0 && del_row < row) {
        arr = delete_row(arr, row, col, del_row);
    }
    else {
        cout << "Невірний номер рядка!" << endl;
        return 0;
    }

    cout << "Матриця після видалення рядка:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
