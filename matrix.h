#ifndef INC_2_MATRIX_H

#include <bits/stdc++.h>

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

#define INC_2_MATRIX_H

class Matrix{
    vvi x;

public:

    Matrix(int n = 0, int m = 0, int val = 0) {
        x.assign(n, vi(m, val));
    }

    Matrix (vvi &a, int k = 1) {
        x.resize(a.size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                x[i].pb(a[i][j] * k);
            }
        }
    }

    Matrix operator+(Matrix);
    Matrix operator*(int);
    Matrix operator*(Matrix);

    void transposition() {
        vvi a(x[0].size());
        for (int i = 0; i < x[0].size(); i++) {
            for (int j = 0; j < x.size(); j++) {
                a[i].pb(x[i][j]);
            }
        }
        for (int i = 0; i < x[0].size(); i++) {
            reverse(all(a[i]));
        }
        *this = Matrix(a); // ???
    }

    Matrix fastexponentiation(Matrix a, int k) {
        if (k == 0) {
            return Matrix(x.size(), x[0].size(), 1);
        }
        if (k == 1) {
            return a;
        }
        if (k % 2) {
            return fastexponentiation(a, k - 1) * a;
        }
        return fastexponentiation(a, k / 2) * fastexponentiation(a, k / 2);
    }
};

Matrix Matrix::operator+(Matrix a)  {
    vvi tmp(x.size());
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x[i].size(); j++) {
            tmp[i].pb(x[i][j] + a.x[i][j]);
        }
    }

    return Matrix(tmp);
}

Matrix Matrix::operator*(int a) {
    return (Matrix(x, a));
}

Matrix Matrix::operator*(Matrix a) {
    Matrix tmp(x.size(), a.x[0].size());
    vi cntstr(x.size());
    for (int i = 0; i < x.size(); i++) {
        int prod = 1;
        for (int j = 0; j < x[i].size(); j++) {
            prod *= x[i][j];
        }
        cntstr[i] = prod;
    }
    vi cntcol(a.x[0].size());
    for (int i = 0; i < a.x[0].size(); i++) {
        int prod = 1;
        for (int j = 0; j < a.x.size(); j++) {
            prod *= a.x[i][j];
        }
        cntcol[i] = prod;
    }
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < a.x[0].size(); j++) {
            tmp.x[i][j] = cntstr[i] * cntcol[j];
        }
    }

    return tmp;
}

#endif//INC_2_MATRIX_H
