#include <bits/stdc++.h>
#include "matrix.h"

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long long

using namespace std;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;

using namespace std;

signed main() {
    system("chcp 65001");

    // размеры матрицы, где n - кол-во строк, m - столбцов
    cout << "Введите размеры матрицы, первое число - кол-во строк, второе - столбов\n";
    int n, m; cin >> n >> m;
    cout << "Заполните матрицу, у которой размер, который Вы ввели выше\n";
    Matrix matr(n, m);
    // заполните матрицу
    cin >> matr;

    // аналогично размеры второй матрицы
    cout << "Введите размеры матрицы, первое число - кол-во строк, второе - столбов\n";
    int n1, m1; cin >> n1 >> m1;
    cout << "Заполните матрицу, у которой размер, который Вы ввели выше\n";
    Matrix matr1(n1, m1);
    // заполните вторую матрицу
    cin >> matr1;

    // Введите коэффициет на который надо умножить матрицу
    cout << "Введите коэффициет на который надо умножить матрицу\n";
    int k; cin >> k;

    // введите степень, в которую надо возвести первую матрицу
    cout << "Введите степень, в которую надо возвести первую матрицу\n";
    int deg; cin >> deg;

    cout << "First matrix:\n" << matr;
    cout << "Second matrix:\n" << matr1;

    cout << "Addition of two matrices:\n" << matr + matr1;
    cout << "Product first matrix and num\n" << matr * k;
    cout << "Product of two matrices:\n" << matr * matr1;
    cout << "Exponentiation first matrix:\n" << matr.fastexponentiation(deg);
    matr.transposition();
    cout << "Transposition of first matrix:\n";
    cout << matr;
}

/*
2 3
10 9 4
1 3 -1
3 2
30 10
1 1
2 2
2
1

2 2
10 1
5 3
2 2
8 100
4 6
5
3

2 2
10 1
5 3
2 2
8 100
4 6
5
4
*/