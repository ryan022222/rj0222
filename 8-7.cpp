#include <iostream>

using namespace std;

// ﹚竡 PrimeNumber 摸
class PrimeNumber {
private:
    int prime;  // 纗借计

    // 耞计琌借计徊ㄧ计
    bool isPrime(int num) const {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // т倒﹚计借计
    int nextPrime(int num) const {
        do {
            ++num;
        } while (!isPrime(num));
        return num;
    }

    // т倒﹚计借计
    int prevPrime(int num) const {
        do {
            --num;
        } while (num > 1 && !isPrime(num));
        return (num > 1) ? num : 2; // 程借计琌2
    }

public:
    // 纐粄篶硑ㄧ计盢借计砞竚1
    PrimeNumber() : prime(1) {}

    // す砛砞竚﹍借计
    PrimeNumber(int p) : prime(p) {
        if (!isPrime(p)) {
            prime = 1;  // 狦倒﹚计ぃ琌借计玥砞竚1
        }
    }

    // 莉借计ㄧ计
    int getPrime() const {
        return prime;
    }

    // 玡竚 ++ 笲衡才更借计
    PrimeNumber& operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // 竚 ++ 笲衡才更借计
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    // 玡竚 -- 笲衡才更借计
    PrimeNumber& operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    // 竚 -- 笲衡才更借计
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }
};

// 代刚祘
int main() {
    // 承 PrimeNumber 癸禜﹍て13
    PrimeNumber p1(13);

    // 陪ボ﹍借计
    cout << "﹍借计: " << p1.getPrime() << endl;

    // 代刚玡竚㎝竚 ++ 笲衡才
    cout << "玡竚 ++ 笲衡才: " << (++p1).getPrime() << endl; // 17
    cout << "竚 ++ 笲衡才: " << (p1++).getPrime() << endl; // 17
    cout << "ぇ借计: " << p1.getPrime() << endl;            // 19

    // 代刚玡竚㎝竚 -- 笲衡才
    cout << "玡竚 -- 笲衡才: " << (--p1).getPrime() << endl; // 17
    cout << "竚 -- 笲衡才: " << (p1--).getPrime() << endl; // 17
    cout << "ぇ借计: " << p1.getPrime() << endl;            // 13

    return 0;
}