#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

// �ˬd�@�Ӧr�O�_���r��
bool isLetter(char c) {
    return isalpha(c);
}

// �����|�Ӧr�������
string replaceFourLetterWords(const string& text) {
    istringstream iss(text);
    ostringstream oss;
    string word;

 
    while (iss >> word) {
        // �ˬd��r���׬O�_���|�Ӧr��
        if (word.length() == 4) {
            // �ˬd��r���Ĥ@�Ӧr���O�_���j�g
            if (isupper(word[0])) {
                word = "Love";
            }
            else {
                word = "love";
            }
        }
        // �K�[��r���X�r�Ŧ�
        oss << word << " ";
    }

    // �h���̫�@�Ӧh�l���Ů�
    string result = oss.str();
    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string input;

    // Ū���Τ��J�A����Τ��J"quit"
    while (true) {
        cout << "��J�@��奻 (��J 'quit' ����): ";
        getline(cin, input);

        // �ˬd�O�_�ݭn�����{��
        if (input == "quit") {
            break;
        }

        // �����|�Ӧr������r�ÿ�X���G
        string result = replaceFourLetterWords(input);
        cout << "���G: " << result << "\n";
    }

    return 0;
}
