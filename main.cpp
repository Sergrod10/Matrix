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

using namespace std;

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

    // быстрое возведение в степень, если матрица не квадратная, то вернет саму матрицу
    Matrix fastexponentiation(int k) {
        if (x.size() != x[0].size()) {
            return *this;
        }
        if (k == 0) {
            return Matrix(x.size(), x[0].size(), 1);
        }
        if (k == 1) {
            return *this;
        }
        if (k % 2) {
            return fastexponentiation(k - 1) * *this;
        }
        return fastexponentiation(k / 2) * fastexponentiation(k / 2);
    }
};


// Сложение матриц. Если матрицы не одного размера, то вернет первую матрицу
Matrix Matrix::operator+(Matrix a)  {
    if (x.size() != a.x.size() || x[0].size() != a.x[0].size()) {
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

signed main() {

    // размеры матрицы, где n - кол-во строк, m - столбцов
    int n, m; cin >> n >> m;
    Matrix matr(n, m);
    // заполните матрицу
    cin >> matr;

    // аналогично размеры второй матрицы
    int n1, m1; cin >> n1 >> m1;
    Matrix matr1(n1, m1);
    // заполните вторую матрицу
    cin >> matr1;

    // введите коэффициет на который надо умножить матрицу
    int k; cin >> k;

    // введите степень, в которую надо возвести первую матрицу
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