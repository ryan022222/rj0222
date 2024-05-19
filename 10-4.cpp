#include <iostream>
#include <string>

using namespace std;

// �w�q Subscriber ���O
class Subscriber {
private:
    string name;            // �x�s�q�\�̩m�W
    int numChannels;        // �q�\���W�D�ƶq
    string* channelList;    // �ʺA�ƲաA�x�s�q�\���W�D�W��

public:
    // �q�{�c�y���
    Subscriber() : name(""), numChannels(0), channelList(nullptr) {}

    // �a�Ѽƪ��c�y���
    Subscriber(const string& name, int numChannels, string* channelList)
        : name(name), numChannels(numChannels) {
        this->channelList = new string[numChannels];
        for (int i = 0; i < numChannels; ++i) {
            this->channelList[i] = channelList[i];
        }
    }

    // �ƻs�c�y���
    Subscriber(const Subscriber& other)
        : name(other.name), numChannels(other.numChannels) {
        this->channelList = new string[other.numChannels];
        for (int i = 0; i < other.numChannels; ++i) {
            this->channelList[i] = other.channelList[i];
        }
    }

    // ������ȹB���
    Subscriber& operator=(const Subscriber& other) {
        if (this != &other) {
            delete[] channelList;

            name = other.name;
            numChannels = other.numChannels;
            channelList = new string[other.numChannels];
            for (int i = 0; i < other.numChannels; ++i) {
                channelList[i] = other.channelList[i];
            }
        }
        return *this;
    }

   
    ~Subscriber() {
        delete[] channelList;
    }

    // ��J�Ҧ��Ȫ����
    void inputValues() {
        cout << "�п�J�q�\�̪��m�W: ";
        getline(cin, name);

        cout << "�п�J�q�\���W�D�ƶq: ";
        cin >> numChannels;
        cin.ignore();

        delete[] channelList;
        channelList = new string[numChannels];

        for (int i = 0; i < numChannels; ++i) {
            cout << "�п�J�� " << (i + 1) << " ���W�D���W��: ";
            getline(cin, channelList[i]);
        }
    }

    // ��X�q�\�̩m�W�M�W�D�C�����
    void outputValues() const {
        cout << "�q�\�̩m�W: " << name << endl;
        cout << "�q�\���W�D�ƶq: " << numChannels << endl;
        for (int i = 0; i < numChannels; ++i) {
            cout << "�W�D " << (i + 1) << ": " << channelList[i] << endl;
        }
    }

    // ���m�q�\�ƶq�M�W�D�C�����
    void resetChannels() {
        numChannels = 0;
        delete[] channelList;
        channelList = nullptr;
    }

    // �]�m�q�\�̩m�W�����
    void setName(const string& name) {
        this->name = name;
    }

    // ����q�\�̩m�W�����
    string getName() const {
        return name;
    }

    // �]�m�q�\���W�D�ƶq�����
    void setNumChannels(int numChannels) {
        this->numChannels = numChannels;
    }

    // ����q�\���W�D�ƶq�����
    int getNumChannels() const {
        return numChannels;
    }

    // �]�m�W�D�C�����
    void setChannelList(const string* channelList, int numChannels) {
        delete[] this->channelList;
        this->numChannels = numChannels;
        this->channelList = new string[numChannels];
        for (int i = 0; i < numChannels; ++i) {
            this->channelList[i] = channelList[i];
        }
    }

    // ����W�D�C�����
    string* getChannelList() const {
        return channelList;
    }
};

// ���յ{��
int main() {
    // �Ы� Subscriber ��H
    Subscriber subscriber1;

    // ���տ�J�ȥ\��
    subscriber1.inputValues();

    // ���տ�X�ȥ\��
    cout << "�q�\�� 1 ���H��:" << endl;
    subscriber1.outputValues();

    // ���խ��m�W�D�\��
    subscriber1.resetChannels();
    cout << "���m��q�\�� 1 ���H��:" << endl;
    subscriber1.outputValues();

     
    string channels[] = { "Channel A", "Channel B" };
    Subscriber subscriber2("John Doe", 2, channels);
    cout << "�q�\�� 2 ���H��:" << endl;
    subscriber2.outputValues();

    // ���խ�����ȹB���
    subscriber1 = subscriber2;
    cout << "������ȹB��ū�q�\�� 1 ���H��:" << endl;
    subscriber1.outputValues();

    return 0;
}