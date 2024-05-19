#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Television {
private:
    string displayType;
    double dimension;
    vector<string> connectivitySupport;

public:
    // Constructor
    Television(string type, double dim, const vector<string>& connectivity) {
        displayType = type;
        dimension = dim;
        connectivitySupport = connectivity;
    }

    // Copy constructor
    Television(const Television& other) {
        displayType = other.displayType;
        dimension = other.dimension;
        connectivitySupport = other.connectivitySupport;
    }

    // Mutator functions
    void setDisplayType(string type) {
        displayType = type;
    }

    void setDimension(double dim) {
        dimension = dim;
    }

    void setConnectivitySupport(const vector<string>& connectivity) {
        connectivitySupport = connectivity;
    }

    // Accessor functions
    string getDisplayType() const {
        return displayType;
    }

    double getDimension() const {
        return dimension;
    }

    vector<string> getConnectivitySupport() const {
        return connectivitySupport;
    }
};

int main() {
    // Ū���w�]�q���ݩ�
    string displayType;
    double dimension;
    vector<string> connectivitySupport;

    cout << "��J�q�������G";
    getline(cin, displayType);

    cout << "��J�q���ؤo�]�^�T�^�G";
    cin >> dimension;

    cout << "��J�䴩���s���覡�]�H�r�����j�^�G";
    cin.ignore(); // �����e�@��cin�A�H�K�v�Tgetline��Ū��
    string connectivityInput;
    getline(cin, connectivityInput);

    // �s�Jvector
    size_t pos = 0;
    string delimiter = ",";
    while ((pos = connectivityInput.find(delimiter)) != string::npos) {
        string connectivity = connectivityInput.substr(0, pos);
        connectivitySupport.push_back(connectivity);
        connectivityInput.erase(0, pos + delimiter.length());
    }
    // �N�̫�@�ӳs���覡�s�Jvector
    connectivitySupport.push_back(connectivityInput);

    // �إ߹q������
    Television defaultTV(displayType, dimension, connectivitySupport);

    // Ū���q���ƶq
    int numTelevisions;
    cout << "��J�q���ƶq�G";
    cin >> numTelevisions;

    // �إ߹q�����󪺰ʺA�}�C
    Television* televisions = new Television[numTelevisions];

    // �ϥ�copy constructor�ƻs�q������
    for (int i = 0; i < numTelevisions; ++i) {
        televisions[i] = defaultTV;

        // �ˬd�O�_�ݭn�ۭq�q���ݩ�
        char choice;
        cout << "�O�_�ݭn�ۭq�q�� #" << (i + 1) << " ���ݩʡH(Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "�Цۭq�q�� #" << (i + 1) << " ���ݩʡG" << endl;
            cout << "��J�q�������G";
            cin.ignore(); // �����e�@��cin�A�H�K�v�Tgetline��Ū��
            getline(cin, displayType);
            televisions[i].setDisplayType(displayType);

            cout << "��J�q���ؤo�]�^�T�^�G";
            cin >> dimension;
            televisions[i].setDimension(dimension);

            cout << "��J�䴩���s���覡�]�H�r�����j�^�G";
            cin.ignore(); // �����e�@��cin�A�H�K�v�Tgetline��Ū��
            getline(cin, connectivityInput);

            // �ѪR�s���覡�æs�Jvector
            connectivitySupport.clear();
            pos = 0;
            while ((pos = connectivityInput.find(delimiter)) != string::npos) {
                string connectivity = connectivityInput.substr(0, pos);
                connectivitySupport.push_back(connectivity);
                connectivityInput.erase(0, pos + delimiter.length());
            }
            // �N�̫�@�ӳs���覡�s�Jvector
            connectivitySupport.push_back(connectivityInput);
            televisions[i].setConnectivitySupport(connectivitySupport);
        }
    }

    // ��ܨC�x�q�����ݩ�
    cout << "\n�q���ݩʡG" << endl;
    for (int i = 0; i < numTelevisions; ++i) {
        cout << "�q�� #" << (i + 1) << "�G" << endl;
        cout << "�����G" << televisions[i].getDisplayType() << endl;
        cout << "�ؤo�]�^�T�^�G" << televisions[i].getDimension() << endl;
        cout << "�䴩���s���覡�G";
        vector<string> support = televisions[i].getConnectivitySupport();
        for (size_t j = 0; j < support.size(); ++j) {
            cout << support[j];
            if (j != support.size() - 1)
                cout << ", ";
        }
        cout << endl << endl;
    }

    // ����ʺA�t�m���O����
    delete[] televisions;

    return 0;
}
