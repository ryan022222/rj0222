#include <iostream>
#include <string>

using namespace std;

// ﹚竡 Subscriber 摸
class Subscriber {
private:
    string name;            // 纗璹綷﹎
    int numChannels;        // 璹綷繵笵计秖
    string* channelList;    // 笆篈计舱纗璹綷繵笵嘿

public:
    // 纐粄篶硑ㄧ计
    Subscriber() : name(""), numChannels(0), channelList(nullptr) {}

    // 盿把计篶硑ㄧ计
    Subscriber(const string& name, int numChannels, string* channelList)
        : name(name), numChannels(numChannels) {
        this->channelList = new string[numChannels];
        for (int i = 0; i < numChannels; ++i) {
            this->channelList[i] = channelList[i];
        }
    }

    // 狡籹篶硑ㄧ计
    Subscriber(const Subscriber& other)
        : name(other.name), numChannels(other.numChannels) {
        this->channelList = new string[other.numChannels];
        for (int i = 0; i < other.numChannels; ++i) {
            this->channelList[i] = other.channelList[i];
        }
    }

    // 更结笲衡才
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

    // 块┮Τㄧ计
    void inputValues() {
        cout << "叫块璹綷﹎: ";
        getline(cin, name);

        cout << "叫块璹綷繵笵计秖: ";
        cin >> numChannels;
        cin.ignore();

        delete[] channelList;
        channelList = new string[numChannels];

        for (int i = 0; i < numChannels; ++i) {
            cout << "叫块材 " << (i + 1) << " 繵笵嘿: ";
            getline(cin, channelList[i]);
        }
    }

    // 块璹綷﹎㎝繵笵ㄧ计
    void outputValues() const {
        cout << "璹綷﹎: " << name << endl;
        cout << "璹綷繵笵计秖: " << numChannels << endl;
        for (int i = 0; i < numChannels; ++i) {
            cout << "繵笵 " << (i + 1) << ": " << channelList[i] << endl;
        }
    }

    // 竚璹綷计秖㎝繵笵ㄧ计
    void resetChannels() {
        numChannels = 0;
        delete[] channelList;
        channelList = nullptr;
    }

    // 砞竚璹綷﹎ㄧ计
    void setName(const string& name) {
        this->name = name;
    }

    // 莉璹綷﹎ㄧ计
    string getName() const {
        return name;
    }

    // 砞竚璹綷繵笵计秖ㄧ计
    void setNumChannels(int numChannels) {
        this->numChannels = numChannels;
    }

    // 莉璹綷繵笵计秖ㄧ计
    int getNumChannels() const {
        return numChannels;
    }

    // 砞竚繵笵ㄧ计
    void setChannelList(const string* channelList, int numChannels) {
        delete[] this->channelList;
        this->numChannels = numChannels;
        this->channelList = new string[numChannels];
        for (int i = 0; i < numChannels; ++i) {
            this->channelList[i] = channelList[i];
        }
    }

    // 莉繵笵ㄧ计
    string* getChannelList() const {
        return channelList;
    }
};

// 代刚祘
int main() {
    // 承 Subscriber 癸禜
    Subscriber subscriber1;

    // 代刚块
    subscriber1.inputValues();

    // 代刚块
    cout << "璹綷 1 獺:" << endl;
    subscriber1.outputValues();

    // 代刚竚繵笵
    subscriber1.resetChannels();
    cout << "竚璹綷 1 獺:" << endl;
    subscriber1.outputValues();

     
    string channels[] = { "Channel A", "Channel B" };
    Subscriber subscriber2("John Doe", 2, channels);
    cout << "璹綷 2 獺:" << endl;
    subscriber2.outputValues();

    // 代刚更结笲衡才
    subscriber1 = subscriber2;
    cout << "更结笲衡才璹綷 1 獺:" << endl;
    subscriber1.outputValues();

    return 0;
}