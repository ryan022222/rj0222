#include <iostream>
#include <string>

using namespace std;

// 定義 MyInteger 類別
class MyInteger {
private:
    int value;  // 存整數值

public:
    
    MyInteger(int v = 0) : value(v) {}

    // 獲取整數值
    int getValue() const {
        return value;
    }

    // 設置整數值
    void setValue(int v) {
        value = v;
    }

    // 重載 [] 運算符，返回指定位置的數字
    int operator[](int index) const {
        // 將整數轉換為字符串以處理個別數字
        string strValue = to_string(value);

        // 反轉字符串，使得 index 0 對應於最小有效位
        reverse(strValue.begin(), strValue.end());

        // 檢查索引是否超出範圍
        if (index >= 0 && index < strValue.length()) {
            // 返回對應位置的數字
            return strValue[index] - '0';
        }
        else {
            // 如果沒有該位置的數字，返回 -1
            return -1;
        }
    }
};


int main() {
    MyInteger num(12345);  // 創建 MyInteger 對象，初始化為 12345

    // 測試獲取和設置整數值的函數
    cout << "初始值: " << num.getValue() << endl;
    num.setValue(67890);
    cout << "新值: " << num.getValue() << endl;

    // 測試 [] 運算符重載
    cout << "num[0] (最小有效位): " << num[0] << endl;
    cout << "num[1]: " << num[1] << endl;
    cout << "num[2]: " << num[2] << endl;
    cout << "num[3]: " << num[3] << endl;
    cout << "num[4]: " << num[4] << endl;
    cout << "num[5] (超出範圍): " << num[5] << endl;

    return 0;
}