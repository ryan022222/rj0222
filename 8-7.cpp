#include <iostream>

using namespace std;

// �w�q PrimeNumber ���O
class PrimeNumber {
private:
    int prime;  // �x�s���

    // �P�_�@�ӼƬO�_����ƪ����U���
    bool isPrime(int num) const {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // ���j�󵹩w�ƪ��U�@�ӽ��
    int nextPrime(int num) const {
        do {
            ++num;
        } while (!isPrime(num));
        return num;
    }

    // ���p�󵹩w�ƪ��W�@�ӽ��
    int prevPrime(int num) const {
        do {
            --num;
        } while (num > 1 && !isPrime(num));
        return (num > 1) ? num : 2; // �̤p����ƬO2
    }

public:
    // �q�{�c�y��ơA�N��Ƴ]�m��1
    PrimeNumber() : prime(1) {}

    // ���\�]�m��l���
    PrimeNumber(int p) : prime(p) {
        if (!isPrime(p)) {
            prime = 1;  // �p�G���w�Ƥ��O��ơA�h�]�m��1
        }
    }

    // �����ƪ����
    int getPrime() const {
        return prime;
    }

    // �e�m ++ �B��ŭ����A��^�U�@�ӽ��
    PrimeNumber& operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // ��m ++ �B��ŭ����A��^�U�@�ӽ��
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    // �e�m -- �B��ŭ����A��^�W�@�ӽ��
    PrimeNumber& operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    // ��m -- �B��ŭ����A��^�W�@�ӽ��
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }
};

// ���յ{��
int main() {
    // �Ы� PrimeNumber ��H�ê�l�Ƭ�13
    PrimeNumber p1(13);

    // ��ܪ�l���
    cout << "��l���: " << p1.getPrime() << endl;

    // ���իe�m�M��m ++ �B���
    cout << "�e�m ++ �B���: " << (++p1).getPrime() << endl; // 17
    cout << "��m ++ �B���: " << (p1++).getPrime() << endl; // 17
    cout << "������: " << p1.getPrime() << endl;            // 19

    // ���իe�m�M��m -- �B���
    cout << "�e�m -- �B���: " << (--p1).getPrime() << endl; // 17
    cout << "��m -- �B���: " << (p1--).getPrime() << endl; // 17
    cout << "������: " << p1.getPrime() << endl;            // 13

    return 0;
}