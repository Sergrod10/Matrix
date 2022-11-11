#pragma once

#include <bits/stdc++.h>

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

void Divide(vvi &a, int str, int x) {
    for (int i = 0; i < a[str].size(); i++) {
        a[str][i] /= x;
    }
}

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

    Matrix (vi &a, int k = 1) {
        x.resize(1);
        for (auto u : a) {
            x[0].pb(u * k);
        }
    }

    Matrix operator+(Matrix);
    Matrix operator*(int);
    Matrix operator*(Matrix);
    vi &operator[](int);
    friend ostream& operator<<(ostream &fout, const Matrix&);
    friend istream& operator>>(istream &in, Matrix&);

    void transposition() {
        vvi a(x[0].size());
        for (int i = 0; i < x[0].size(); i++) {
            for (int j = 0; j < x.size(); j++) {
                a[i].pb(x[j][i]);
            }
        }
        *this = Matrix(a); // ???
    }

    vvi getMatrix() {
        return (*this).x;
    }

    // быстрое возведение в степень, если матрица не квадратная, то вернет саму матрицу
    Matrix fastexponentiation(int k) {
        if (x.size() != x[0].size()) {
            cout << "Wrong data\n";
            return *this;
        }
        if (k == 0) {
            return Matrix(x.size(), x[0].size(), 1);
        }
        if (k == 1) {
            return *this;
        }
        if ((long long) k % 2) {
            return fastexponentiation(k - 1) * *this;
        }
        Matrix now = fastexponentiation(k / 2);
        return now * now;
    }

    Matrix getwithoutcolstr(int col) {
        int n = x.size();
        vvi ans(n - 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    ans[i - 1].pb(x[i][j]);
                }
            }
        }
        return Matrix(ans);
    }

    int getDeterminant() {
        if (x.size() != x[0].size()) {
            cout << "Wrong data!\n";
            return 0;
        }
        if (x.size() == 2) {
            return (x[0][0] * x[1][1] - x[0][1] * x[1][0]);
        }
        int ans = 0;
        for (int i = 0; i < x.size(); i++) {
            Matrix nw = getwithoutcolstr(i);
            ans += ((long long) i % 2 ? -1 : 1) * getwithoutcolstr(i).getDeterminant() * x[0][i];
        }
        return ans;
    }

    Matrix getInverse() {
        if (x.size() != x[0].size()) {
            cout << "Wrong data\n";
            return *this;
        }
        int n = x.size();
        vvi now = x;
        vvi inv(x.size(), vi(x[0].size(), 0));
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
                    }
                }
                if (!ok) {
                    cout << "Wrong data\n";
                    return *this;
                }
            }
            int xx = now[i][i];
            //cout << now[i][i] << endl;
            Divide(now, i, xx);
            Divide(inv, i, xx);
            //cout << Matrix(inv) << endl;
            for (int j = i + 1; j < n; j++) {
                int xx = -now[j][i];
                Matrix nw(now[j]);
                Matrix fir(now[i], xx);
                now[j] = (nw + fir).getMatrix()[0];

                Matrix nw2(inv[j]);
                Matrix fir2(inv[i], xx);
                inv[j] = (nw2 + fir2).getMatrix()[0];
            }
            //cout << Matrix(inv) << endl;
        }
        //return Matrix(inv);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (now[i][j]) {
                    int xx = -now[i][j];
                    Matrix deleter(now[j], xx);
                    Matrix nw(now[i]);
                    now[i] = (nw + deleter).getMatrix()[0];

                    Matrix nw2(inv[i]);
                    Matrix deleter2(inv[j], xx);
                    inv[i] = (nw2 + deleter2).getMatrix()[0];
                }
            }
        }
        return Matrix(inv);
    }
};


// Сложение матриц. Если матрицы не одного размера, то вернет первую матрицу
Matrix Matrix::operator+(Matrix a)  {
    if (x.size() != a.x.size() || x[0].size() != a.x[0].size()) {
        cout << "Wrong data\n";
        return *this;
    }
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

// умножение матриц. Если кол-во столбцов первой матрицы будет не равно кол-во строк второй матрицы, то вернет просто первую матрицу
Matrix Matrix::operator*(Matrix a) {
    if (x[0].size() != a.x.size()) {
        cout << "Wrong data\n";
        return *this;
    }
    Matrix tmp(x.size(), a.x[0].size());
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < a.x[0].size(); j++) {
            int nw = 0;
            for (int k = 0; k < x[i].size(); k++) {
                nw += x[i][k] * a.x[k][j];
            }
            tmp.x[i][j] = nw;
        }
    }

    return tmp;
}

vi &Matrix::operator[](int a) {
    return x[a];
}

ostream& operator<<(ostream &fout, const Matrix &a) {
    for (int i = 0; i < a.x.size(); i++) {
        for (int j = 0; j < a.x[0].size(); j++) {
            fout << a.x[i][j] << " ";
        }
        fout << "\n";
    }
    return fout;
}

istream& operator>>(istream &in, Matrix &a) {
    for (int i = 0; i < a.x.size(); i++) {
        for (int j = 0; j < a.x[i].size(); j++) {
            in >> a.x[i][j];
        }
    }
    return in;
}
