//
// Created by zeronosu77108 on Jan 23, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>
#include <cassert>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

template<class T>
class Matrix {
private:
    int h, w;
public:
    vector<vector<T>> m;
    Matrix(int h, int w) : h(h), w(w), m(vector(h, vector<T>(w))) {}
    Matrix(int h, int w, T x) : h(h), w(w), m(vector(h, vector<T>(w, x))) {}
    explicit Matrix(vector<vector<T>> mat) {
        h = mat.size();
        w = mat.front().size();
        assert(all_of(mat.begin(), mat.end(), [&](const vector<T>& x){return x.size()==w;}));
        m.resize(h);
        for (int i=0; i<h; i++) m[i] = mat[i];
    }
    Matrix(int h, int w, bool identity) : h(h), w(w), m(vector(h, vector<T>(w))) {
        assert(h==w);
        for (int i=0; i<h; i++) m[i][i] = 1;
    }

    vector<T> operator[](const int i) const {return m[i];}
    vector<T>& operator[](const int i){return m[i];}

    Matrix& operator=(const Matrix& a){
        h = a.h; w = a.w;
        m.resize(h); for (auto& i : m) i.resize(w);
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] = a[i][j];
            }
        }
        return *this;
    };
    Matrix& operator+=(const Matrix& a) {
        assert(this->h == a.h && this->w == a.w);
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] += a[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& a) {
        assert(this->h == a.h && this->w == a.w);
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] -= a[i][j];
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& a) {
        assert(this->w == a.h);
        vector res(h, vector<T>(a.w, 0));

        for (int i=0; i<this->h; i++) {
            for (int j=0; j<a.w; j++) {
                for (int k=0; k<w; k++) {
                    res[i][j] += m[i][k] * a[k][j];
                }
            }
        }
        this->w = a.w;
        for (int i=0; i<h; i++) {
            m[i].resize(this->w);
            for (int j=0; j<this->w; j++) {
                m[i][j] = res[i][j];
            }
        }
        return *this;
    }

    Matrix pow(long t) {
        assert(this->h == this->w);
        Matrix res(this->h, this->w);
        for (int i=0; i<h; i++) res[i][i] = 1;
        Matrix n(*this);
        while(t) {
            if (t&1) res *= n;
            n *= n;
            t >>= 1;
        }
        return res;
    }
    Matrix operator+(const Matrix& a) const { return Matrix(*this) += a;}
    Matrix operator-(const Matrix& a) const { return Matrix(*this) -= a;}
    Matrix operator*(const Matrix& a) const { return Matrix(*this) *= a;}

    bool operator==(const Matrix& a) {
        if (this->h != a.h || this->w != a.w) return false;
        bool res = true;
        for (int i=0; i<this->h; i++) {
            for (int j=0; j<this->w; j++) {
                res &= (m[i][j] == a[i][j]);
            }
        }
        return res;
    }

    Matrix& operator+=(const T& x) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] += x;
            }
        }
        return *this;
    }

    Matrix& operator-=(const T& x) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] -= x;
            }
        }
        return *this;
    }

    Matrix& operator*=(const T& x) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] *= x;
            }
        }
        return *this;
    }

    Matrix& operator/=(const T& x) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                m[i][j] /= x;
            }
        }
        return *this;
    }

    Matrix operator+(const T& x) const { return mat(*this) += x;}
    Matrix operator-(const T& x) const { return mat(*this) -= x;}
    Matrix operator*(const T& x) const { return mat(*this) *= x;}
    Matrix operator/(const T& x) const { return mat(*this) /= x;}

    void dump(bool debug=true) {
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                (debug? cerr : cout) << m[i][j] << (j+1==w? "\n" : " ");
            }
        }
        (debug? cerr : cout) << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector mat(n, Matrix(3,1,0L));
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        mat[i][0][0] = x;
        mat[i][1][0] = y;
        mat[i][2][0] = 1;
    }

    int m; cin>>m;
    vector op(m+1, Matrix<long>(3,3, true));

    Matrix<long> _90({{0,1,0}, {-1,0,0}, {0,0,1}});
    Matrix<long> _270({{0,-1,0}, {1,0,0}, {0,0,1}});


    for (int i=1; i<=m; i++) {
        int o; cin >> o;
        if (o == 1) op[i] = _90 * op[i-1];
        if (o == 2) op[i] = _270 * op[i-1];
        if (o == 3) {
            int p; cin >> p;
            op[i] = Matrix<long>({{-1,0,p+p}, {0,1,0}, {0,0,1}}) * op[i-1];
        }
        if (o == 4) {
            int p; cin >> p;
            op[i] = Matrix<long>({{1,0,0}, {0,-1,p+p}, {0,0,1}}) * op[i-1];
        }
    }

    int q;
    cin >> q;
    for (int _=0; _<q; _++) {
        int a, b; cin >> a >> b;
        const auto ans = op[a]*mat[b-1];
        cout << ans[0][0] << " " << ans[1][0] << endl;
    }
}