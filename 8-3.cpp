#include <iostream>

using namespace std;

// �w�q�Ƽ����O
class Complex {
public:
    // �����ܶq
    double real;        // �곡
    double imaginary;   // �곡

    // �a��ӰѼƪ��c�y���
    Complex(double r, double i) : real(r), imaginary(i) {}

    // �a�@�ӰѼƪ��c�y���
    Complex(double realPart) : real(realPart), imaginary(0) {}

    // �q�{�c�y���
    Complex() : real(0), imaginary(0) {}

    // == �B��ŭ����A�Ω�����ӽƼƬO�_�۵�
    bool operator==(const Complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    // + �B��ŭ����A�Ω�p���ӽƼƪ��M
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // * �B��ŭ����A�Ω�p���ӽƼƪ��n
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    // >> �B��ŭ����A�Ω�q��JŪ���Ƽ�
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "��J�곡: ";
        in >> c.real;
        cout << "��J�곡: ";
        in >> c.imaginary;
        return in;
    }

    // << �B��ŭ����A�Ω�N�Ƽƿ�X
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "*i";
        return out;
    }
};

int main() {
    // ���պc�y���
    Complex c1(3, 4); // 3 + 4*i
    Complex c2(2);    // 2 + 0*i
    Complex c3;       // 0 + 0*i

    // ��ܪ�l��
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    // ���� == �B���
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;

    // ���� + �B���
    Complex c4 = c1 + c2;
    cout << "c1 + c2: " << c4 << endl;

    // ���� * �B���
    Complex c5 = c1 * c2;
    cout << "c1 * c2: " << c5 << endl;

    // ���� >> �B���
    Complex c6;
    cin >> c6;
    cout << "c6: " << c6 << endl;

    return 0;
}
