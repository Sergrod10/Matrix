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

/*int domatr(vvi &a, int col, int x) {
    vvi mainmatr(x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            mainmatr[i].pb(a[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        mainmatr[i][col] = a[i][x];
    }
    Matrix ans(mainmatr);
    return ans.getDeterminant();
}*/

signed main() {
    system("chcp 65001");

    /*cout << "Введите размеры матрицы и её саму для нахождения её определителя(работает с целыми числами)\n";
    int n2, m2; cin >> n2 >> m2;
    Matrix matr2(n2, m2);
    cin >> matr2;
    cout << matr2 << endl;
    cout << "Determinant: " << matr2.getDeterminant() << endl;

    cout << "Bведите количество неизвестных в системе уравнений, которую надо решить\n";
    int x; cin >> x;
    cout << "Теперь введите сами уравнения в виде a b c d - это значит, что Вы ввели уравнение ax1+bx2+cx3=d. Количество уравнение должно равнять количеству неизвестных(если какого-то члена нет введите на его месте 0)\n";
    vvi a(x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x + 1; j++) {
            int y; cin >> y;
            a[i].pb(y);
        }
    }
    vvi mainmatr(x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            mainmatr[i].pb(a[i][j]);
        }
    }
    //cout << mainmatr << endl;
    Matrix mtr1(mainmatr);
    int det = mtr1.getDeterminant();
    //cout << det << endl;
    if (!det) {
        cout << "Degenerate case\n";
    }
    else {
        vec<long double> ans;
        for (int i = 0; i < x; i++) {
            int now = domatr(a, i, x);
            ans.pb((long double) now / (long double) det);
        }
        for (int i = 0; i < x; i++) {
            cout << "x" << (i + 1) << ": " << ans[i] << "\n";
        }
        cout << endl;
    }*/
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

3
2 -1 1 1
3 1 5 -3
5 0 3 2
*/
