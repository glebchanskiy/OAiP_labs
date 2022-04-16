#include <iostream>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"Russian");
    while (true) {
        char a = 'а';
        char array[100], char_q;
        //char alfo[] = "А,Б,В,Г,Д,Е,Ё,Ж,З,И,Й,К,Л,М,Н,О,П,Р,С,Т,У,Ф,Х,Ц,Ч,Ш,Щ,Ъ,Ы,Ь,Э,Ю,Я,а,б,в,г,д,е,ё,ж,з,и,й,к,л,м,н,о,п,р,с,т,у,ф,х,ц,ч,ш,щ,ъ,ы,ь,э,ю,я";
        int lens = 0, lens_min = 100, words_counter = 0, word_min_counter = 0;

        cout << "Введите строку: ";
        cin.getline(array, 100);
        strcat(array, " ");
        cout << endl;

        for (int i = 0; array[i]; i++) {
            if (array[i] == ' ') {
                words_counter++;
                if (lens_min > lens) {
                    lens_min = lens;
                    word_min_counter = words_counter;
                }
                lens = 0;
            } else {
                if (array[i] >= 'A' && array[i] <= 'z')
                    lens += 2;
                else
                    lens++;
            }
        }

        cout << "Колличество символов в слове: " << lens_min / 2
             << ";    Порядковый номер слова: " << word_min_counter << endl;

        cout << "Желаете продолжить? y/n" << endl;
        cin >> char_q;

        if (char_q != 'y') {
            break;
        }
        cin.ignore();
    }
}
