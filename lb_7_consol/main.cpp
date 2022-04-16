#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        int lens = 0, lens_min = 100, words_counter = 0, word_min_counter = 0, leng;
        string line;
        char char_q;

        cout << "Если строка будет на русском введитe - 1, если на английском введитe - 2:\n>>> ";
        cin>> leng; cin.ignore();

        cout << "Введите строку:\n>>> ";
        getline(cin, line);

        line += " ";

        for (int i = 0; line[i]; i++) {
            if (line[i] == ' ') {
                words_counter++;
                if (lens_min > lens) {
                    lens_min = lens;
                    word_min_counter = words_counter;
                }
                lens = 0;
            } else {
                lens++;
            }
        }

        if (leng == 1)
            lens_min /= 2;

        cout << "Колличество символов в слове: " << lens_min
             << ";    Порядковый номер слова: " << word_min_counter << endl;


        cout << "Желаете продолжить? y/n" << endl;
        cin >> char_q;

        if (char_q != 'y') {
            break;
        }
        cin.ignore();
    }
    return 0;
}
