#include <iostream>

int main() {
    long m, k;
    std::cin >> m >> k;

    if (k >= (1<<m)) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    if (m==1) {
        if (k==0) {
            std::cout << "0 0 1 1" << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
        return 0;
    }

    long max = (1<<m) - 1;
    for (int i=0; i<=max; i++) {
        if (i == k) continue;
        std::cout << i << " ";
    }
    std::cout << k << " ";
    for (int i=max; i>=0; i--) {
        if (i == k) continue;
        std::cout << i << " ";
    }
    std::cout << k << std::endl;
}