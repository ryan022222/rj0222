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
    // 讀取預設電視屬性
    string displayType;
    double dimension;
    vector<string> connectivitySupport;

    cout << "輸入電視類型：";
    getline(cin, displayType);

    cout << "輸入電視尺寸（英吋）：";
    cin >> dimension;

    cout << "輸入支援的連接方式（以逗號分隔）：";
    cin.ignore(); // 忽略前一個cin，以免影響getline的讀取
    string connectivityInput;
    getline(cin, connectivityInput);

    // 存入vector
    size_t pos = 0;
    string delimiter = ",";
    while ((pos = connectivityInput.find(delimiter)) != string::npos) {
        string connectivity = connectivityInput.substr(0, pos);
        connectivitySupport.push_back(connectivity);
        connectivityInput.erase(0, pos + delimiter.length());
    }
    // 將最後一個連接方式存入vector
    connectivitySupport.push_back(connectivityInput);

    // 建立電視物件
    Television defaultTV(displayType, dimension, connectivitySupport);

    // 讀取電視數量
    int numTelevisions;
    cout << "輸入電視數量：";
    cin >> numTelevisions;

    // 建立電視物件的動態陣列
    Television* televisions = new Television[numTelevisions];

    // 使用copy constructor複製電視物件
    for (int i = 0; i < numTelevisions; ++i) {
        televisions[i] = defaultTV;

        // 檢查是否需要自訂電視屬性
        char choice;
        cout << "是否需要自訂電視 #" << (i + 1) << " 的屬性？(Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "請自訂電視 #" << (i + 1) << " 的屬性：" << endl;
            cout << "輸入電視類型：";
            cin.ignore(); // 忽略前一個cin，以免影響getline的讀取
            getline(cin, displayType);
            televisions[i].setDisplayType(displayType);

            cout << "輸入電視尺寸（英吋）：";
            cin >> dimension;
            televisions[i].setDimension(dimension);

            cout << "輸入支援的連接方式（以逗號分隔）：";
            cin.ignore(); // 忽略前一個cin，以免影響getline的讀取
            getline(cin, connectivityInput);

            // 解析連接方式並存入vector
            connectivitySupport.clear();
            pos = 0;
            while ((pos = connectivityInput.find(delimiter)) != string::npos) {
                string connectivity = connectivityInput.substr(0, pos);
                connectivitySupport.push_back(connectivity);
                connectivityInput.erase(0, pos + delimiter.length());
            }
            // 將最後一個連接方式存入vector
            connectivitySupport.push_back(connectivityInput);
            televisions[i].setConnectivitySupport(connectivitySupport);
        }
    }

    // 顯示每台電視的屬性
    cout << "\n電視屬性：" << endl;
    for (int i = 0; i < numTelevisions; ++i) {
        cout << "電視 #" << (i + 1) << "：" << endl;
        cout << "類型：" << televisions[i].getDisplayType() << endl;
        cout << "尺寸（英吋）：" << televisions[i].getDimension() << endl;
        cout << "支援的連接方式：";
        vector<string> support = televisions[i].getConnectivitySupport();
        for (size_t j = 0; j < support.size(); ++j) {
            cout << support[j];
            if (j != support.size() - 1)
                cout << ", ";
        }
        cout << endl << endl;
    }

    // 釋放動態配置的記憶體
    delete[] televisions;

    return 0;
}
