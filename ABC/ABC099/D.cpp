#include <iostream>
#include <vector>

int main () {
    int n, c;
    std::cin >> n >> c;

    std::vector d(c, std::vector(c, 0));
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            std::cin >> d[i][j];
        }
    }

    std::vector cnt(3, std::vector(c, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int c;
            std::cin >> c;
            cnt[(i+j)%3][c-1]++;
        }
    }

    int ans = INT_MAX;
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            if (i==j) continue;
            for (int k=0; k<c; k++) {
                if (i==k || j==k) continue;
                int tmp = 0;
                for (int l=0; l<c; l++) {
                    tmp += d[l][i]*cnt[0][l] + d[l][j]*cnt[1][l] + d[l][k]*cnt[2][l];
                }
                ans = std::min(ans, tmp);
            }
        }
    }

    std::cout << ans << std::endl;
}