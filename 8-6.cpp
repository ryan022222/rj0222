#include <iostream>
#include <string>

using namespace std;

// �w�q MyInteger ���O
class MyInteger {
private:
    int value;  // �s��ƭ�

public:
    
    MyInteger(int v = 0) : value(v) {}

    // �����ƭ�
    int getValue() const {
        return value;
    }

    // �]�m��ƭ�
    void setValue(int v) {
        value = v;
    }

    // ���� [] �B��šA��^���w��m���Ʀr
    int operator[](int index) const {
        // �N����ഫ���r�Ŧ�H�B�z�ӧO�Ʀr
        string strValue = to_string(value);

        // ����r�Ŧ�A�ϱo index 0 ������̤p���Ħ�
        reverse(strValue.begin(), strValue.end());

        // �ˬd���ެO�_�W�X�d��
        if (index >= 0 && index < strValue.length()) {
            // ��^������m���Ʀr
            return strValue[index] - '0';
        }
        else {
            // �p�G�S���Ӧ�m���Ʀr�A��^ -1
            return -1;
        }
    }
};


int main() {
    MyInteger num(12345);  // �Ы� MyInteger ��H�A��l�Ƭ� 12345

    // ��������M�]�m��ƭȪ����
    cout << "��l��: " << num.getValue() << endl;
    num.setValue(67890);
    cout << "�s��: " << num.getValue() << endl;

    // ���� [] �B��ŭ���
    cout << "num[0] (�̤p���Ħ�): " << num[0] << endl;
    cout << "num[1]: " << num[1] << endl;
    cout << "num[2]: " << num[2] << endl;
    cout << "num[3]: " << num[3] << endl;
    cout << "num[4]: " << num[4] << endl;
    cout << "num[5] (�W�X�d��): " << num[5] << endl;

    return 0;
}