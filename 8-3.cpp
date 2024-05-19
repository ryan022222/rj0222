#include <iostream>

using namespace std;

// ﹚竡狡计摸
class Complex {
public:
    // Θ跑秖
    double real;        // 龟场
    double imaginary;   // 店场

    // 盿ㄢ把计篶硑ㄧ计
    Complex(double r, double i) : real(r), imaginary(i) {}

    // 盿把计篶硑ㄧ计
    Complex(double realPart) : real(realPart), imaginary(0) {}

    // 纐粄篶硑ㄧ计
    Complex() : real(0), imaginary(0) {}

    // == 笲衡才更ノゑ耕ㄢ狡计琌单
    bool operator==(const Complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    // + 笲衡才更ノ璸衡ㄢ狡计㎝
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // * 笲衡才更ノ璸衡ㄢ狡计縩
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    // >> 笲衡才更ノ眖块弄狡计
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "块龟场: ";
        in >> c.real;
        cout << "块店场: ";
        in >> c.imaginary;
        return in;
    }

    // << 笲衡才更ノ盢狡计块
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imaginary << "*i";
        return out;
    }
};

int main() {
    // 代刚篶硑ㄧ计
    Complex c1(3, 4); // 3 + 4*i
    Complex c2(2);    // 2 + 0*i
    Complex c3;       // 0 + 0*i

    // 陪ボ﹍
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    // 代刚 == 笲衡才
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;

    // 代刚 + 笲衡才
    Complex c4 = c1 + c2;
    cout << "c1 + c2: " << c4 << endl;

    // 代刚 * 笲衡才
    Complex c5 = c1 * c2;
    cout << "c1 * c2: " << c5 << endl;

    // 代刚 >> 笲衡才
    Complex c6;
    cin >> c6;
    cout << "c6: " << c6 << endl;

    return 0;
}
