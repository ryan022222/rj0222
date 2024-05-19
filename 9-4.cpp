#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

// 檢查一個字是否為字母
bool isLetter(char c) {
    return isalpha(c);
}

// 替換四個字母的單詞
string replaceFourLetterWords(const string& text) {
    istringstream iss(text);
    ostringstream oss;
    string word;

 
    while (iss >> word) {
        // 檢查單字長度是否為四個字母
        if (word.length() == 4) {
            // 檢查單字的第一個字母是否為大寫
            if (isupper(word[0])) {
                word = "Love";
            }
            else {
                word = "love";
            }
        }
        // 添加單字到輸出字符串
        oss << word << " ";
    }

    // 去除最後一個多餘的空格
    string result = oss.str();
    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string input;

    // 讀取用戶輸入，直到用戶輸入"quit"
    while (true) {
        cout << "輸入一行文本 (輸入 'quit' 結束): ";
        getline(cin, input);

        // 檢查是否需要結束程序
        if (input == "quit") {
            break;
        }

        // 替換四個字母的單字並輸出結果
        string result = replaceFourLetterWords(input);
        cout << "結果: " << result << "\n";
    }

    return 0;
}
