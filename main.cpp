#include <bits/stdc++.h>
#include "matrix.h"

#define st string
#define pb push_back
#define vec vector
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define int long double

using namespace std;
using vi = vec<int>;
using vvi = vec<vi>;
using pi = pair<int, int>;
using vpi = vec<pi>;

using namespace std;

void Divide(vvi &a, int str, int x, int &y) {
    for (int i = 0; i < a[str].size(); i++) {
        a[str][i] /= x;
    }
    y /= x;
}

signed main() {
    system("chcp 65001");

    cout << "Введите n - размер матрицы, далее саму матрицу для получения обратной ей матрицы\n";
    int szz; cin >> szz;
    Matrix forinv(szz, szz); cin >> forinv;
    cout << "Обратная матрица данной:\n" << forinv.getInverse();


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
    vi anses;
    for (int i = 0; i < x; i++) {
        anses.pb(a[i][x]);
    }
    if (mainmatr.size() != mainmatr[0].size()) {
        cout << "Wrong data\n";
        return 0;
    }
    int n = mainmatr.size();
    vvi now = mainmatr;
    vvi inv(mainmatr.size(), vi(mainmatr[0].size(), 0));
    for (int i = 0; i < n; i++) {
        inv[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!now[i][i]) {
            int ok = 0;
            for (int j = i + 1; j < n; j++) {
                if (!now[j][i]) {
                    ok = 1;
                    swap(now[i], now[j]);
                    swap(anses[i], anses[j]);
                }
            }
            if (!ok) {
                cout << "Wrong data\n";
                return 0;
            }
        }
        Divide(now, i, now[i][i], anses[i]);
        for (int j = i + 1; j < n; j++) {
            Matrix nw(now[j]);
            Matrix fir(now[i], -now[j][i]);
            anses[j] -= anses[i] * now[j][i];
            now[j] = (nw + fir).getMatrix()[0];
        }
    }

    vi solves(x, 0);
    for (int i = x - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i + 1; j < x; j++) {
            cnt += now[i][j] * solves[j];
        }
        solves[i] = anses[i] - cnt;
    }

    for (int i = 0; i < x; i++) {
        cout << "x" << (i + 1) << ": " << solves[i] << "\n";
    }
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

3
7 1 9
4 0 5
4 2 10
*/
