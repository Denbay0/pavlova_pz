#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, m;

    cout << "Введите количество строк n: ";
    cin >> n;

    cout << "Введите количество столбцов m: ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Ошибка: размеры матрицы должны быть положительными." << endl;
        return 1;
    }

    vector<vector<double>> a(n, vector<double>(m));

    cout << "Введите элементы матрицы построчно:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    cout << endl;
    cout << "Элементы матрицы по столбцам:" << endl;

    for (int j = 0; j < m; ++j) {
        cout << "Столбец " << j + 1 << ": ";

        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2) << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}