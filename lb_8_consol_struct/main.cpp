#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;


struct Student {
    string fio;
    string birthYear;
    string group;

    string physicsScore;
    string mathsScore;
    string informaticsScore;
    string chemistryScore;

    string averageScore;
};

vector<Student> stud_list;
string pathToFile, fileName;


void help_func();

void display_all_students();

void display_search_student();

void delete_student();

void add_student_to_temp();

void serialization();

void deserialization();

void clear_temp_list();

void open_file();

void make_file();

void remove_file();

void clear_file();

void close_file();


int main()
{
    string command;
    fileName = "";
    pathToFile = "../files/";
    help_func();

    while (true) {
        cout << "(" << fileName << ") " << ">>> ";
        getline(cin, command);


        // выводит все существующие комманды //
        if (command == "help")
            help_func();

        // выводит список всех студентов (в структуре) //
        else if (command == "display all students" || command == "all")
            display_all_students();

        // выводит студентов определённой группы и баллом выше введённого  //
        else if (command == "search student" || command == "srch" || command == "search")
            display_search_student();

        // добавляет студентов в список (в структуру) //
        else if (command == "add student" || command == "add st")
            add_student_to_temp();

        // сохраняет структуру в файл//
        else if (command == "save list" || command == "sv" || command == "save")
            serialization();

        // десериализация //
        else if (command == "upload" || command == "upload list")
            deserialization();

        // очистить список (структуру) //
        else if (command == "clear list" || command == "cll")
            clear_temp_list();

        // открывает файл //
        else if (command == "open file" || command == "open")
            open_file();

        // новый файл //
        else if (command == "make file"  || command == "make")
            make_file();

        // удалить открытый файл //
        else if (command == "remove file" || command == "rm")
            remove_file();

        // очистить файл //
        else if (command == "clear file" || command == "clf")
            clear_file();

        // закрыть файл //
        else if (command == "close file" || command == "close")
            close_file();

        // удаляет нужного студента //  ;
        else if (command == "delete student" || command == "del st")
            delete_student();

        // список созданных файлов (списков) //
        else if (command == "ls")
            system("ls -l ../files | grep ^-");

        // путь к файлу/каталогу //
        else if (command == "pwd")
            cout << pathToFile << endl;

        // выход //
        else if (command == "quit" || command == "q")
            return 0;
    }
}


void help_func()
{
    cout << "All existing commands: " << endl << endl;
    cout <<
         " working with a file:\n - - - - - - - - - - -" << endl <<
         " open file            (open)" << endl <<
         " close file           (close)" << endl <<
         " make file            (make)" << endl <<
         " remove file          (rm)" << endl <<
         " clear file           (clf)" << endl <<
         endl <<
         " working with a list:\n - - - - - - - - - - -" << endl <<
         " upload list          (upload)" << endl <<
         " save list            (save/sv)" << endl <<
         " display all students (all)" << endl <<
         " add student          (add st)" << endl <<
         " delete student       (del st)"  << endl <<
         " clear list           (cll)" << endl <<
         " search student       (srch/search)" << endl <<

         endl <<
         " other commands:\n - - - - - - - - - - -" << endl <<
         " help" << endl <<
         " pwd" << endl <<
         " ls" << endl <<
         " quit                 (q)" << endl << endl;
}


void display_all_students()
{
    int counter = 0;

    if (stud_list.empty()) {
        cout << "Список пуст" << endl;
        return;
    }

    for (const auto &i : stud_list) {
        counter++;
        cout << counter << " Фамилия: " << i.fio << ", год рождения: " << i.birthYear <<
             ", математика: " << i.mathsScore << ", физика: " << i.physicsScore <<
             ", информатика: " << i.informaticsScore << ", химия: " << i.chemistryScore <<
             ", средний балл: " << i.averageScore << ", группа: " << i.group << endl;

    }
    cout << endl;
}


void display_search_student()
{
    if (stud_list.empty()) {
        cout << "Список пуст" << endl;
        return;
    }

    float inputScore, inputGroup;

    cout << "Enter grade:\n>>> ";
    cin >> inputScore;
    cout << "Enter group number:\n>>> ";
    cin >> inputGroup;

    cout << endl;

    for (const auto &i : stud_list) {
        if ((inputScore <= stof(i.averageScore)) && inputGroup == stof(i.group))
            cout << "Фамилия:" << i.fio << ", год рождения:" << i.birthYear <<
                 ", математика:" << i.mathsScore << ", физика:" << i.physicsScore <<
                 ", информатика:" << i.informaticsScore << ", химия:" << i.chemistryScore <<
                 ", средний балл:" << i.averageScore << ", группа:" << i.group << "," << endl;
    }
    cout << endl;
    cin.ignore();
}


void delete_student()
{
    if (stud_list.empty()) {
        cout << "Список пуст" << endl;
        return;
    }

    int lineNumber=0;
    string deleteStud, press_f;

    cout << "Введите имя студента:\n>>> ";
    getline(cin, deleteStud);

    for (auto &i : stud_list) {
        if (deleteStud == i.fio) {
            stud_list.erase(stud_list.begin() + lineNumber);
            return;
        }
        lineNumber++;
    }
}


void add_student_to_temp()
{
    Student st;
    cout << "Adding student, enter information below:\n";


    cout << "(student fio) >>> ";
    getline(cin, st.fio);

    cout << "(birth year) >>> ";
    getline(cin, st.birthYear);

    cout << "(phys ball) >>> ";
    getline(cin, st.physicsScore);

    cout << "(math ball) >>> ";
    getline(cin, st.mathsScore);

    cout << "(info ball) >>> ";
    getline(cin, st.informaticsScore);

    cout << "(chem ball) >>> ";
    getline(cin, st.chemistryScore);

    cout << "(student group) >>> ";
    getline(cin, st.group);

    // подсчёт среднего балла //
    double s_ball;
    s_ball = (stof(st.physicsScore) + stof(st.mathsScore) + stof(st.informaticsScore) +
              stof(st.chemistryScore)) / 4.0;

    // обрезание хвоста у флоат // надо исправить !!
    for (int i=0; i<4; i++) {
        st.averageScore += to_string(s_ball)[i];
    }

    stud_list.push_back(st);

    cout << "Фамилия: " << st.fio << ", год рождения: " << st.birthYear <<
        ", математика: " << st.mathsScore << ", физика: " << st.physicsScore <<
        ", информатика: " << st.informaticsScore << ", химия: " << st.chemistryScore <<
        ", средний балл: " << st.averageScore << ", группа: " << st.group << "  -  was saved //\n" << endl;
}

// сделать нормальное сохранение
void serialization()
{
    ofstream file;
    file.open(pathToFile, ios::out | ios::trunc);

    if (!file.is_open()){
        cout << "file not founded" << endl << "create or select a file" << endl;
    }
    else {
        for (auto &i : stud_list)
            file << "Фамилия:" << i.fio << ", год рождения:" <<i.birthYear <<
                 ", математика:" << i.mathsScore << ", физика:" << i.physicsScore <<
                 ", информатика:" << i.informaticsScore << ", химия:" << i.chemistryScore <<
                 ", средний балл:" << i.averageScore << ", группа:" << i.group << "," << endl;
    }
    file.close();
}


void deserialization()
{
    string lineFromFile;
    int flag;
    char lastChar = ',';

    ifstream file;
    file.open(pathToFile, ios::in);

    if (!file.is_open()){
        cout << "file not founded" << endl << "create or select a file" << endl << endl;
    }
    else {
        stud_list.clear();
        while (getline(file, lineFromFile)) {
            Student st;

            flag = 1;

            for (int i = 0; lineFromFile[i]; i++) {
                if (lineFromFile[i] == ':') {
                    lastChar = ':';
                }
                else if (lineFromFile[i] == ',') {
                    lastChar = ',';
                    flag++;
                }
                else if (lastChar == ':') {
                    switch (flag) {
                        case 1 :
                            st.fio += lineFromFile[i];
                            break;

                        case 2 :
                            st.birthYear += lineFromFile[i];
                            break;

                        case 3 :
                            st.mathsScore += lineFromFile[i];
                            break;

                        case 4 :
                            st.physicsScore += lineFromFile[i];
                            break;

                        case 5 :
                            st.informaticsScore += lineFromFile[i];
                            break;

                        case 6 :
                            st.chemistryScore += lineFromFile[i];
                            break;

                        case 7 :
                            st.averageScore += lineFromFile[i];
                            break;

                        case 8 :
                            st.group+= lineFromFile[i];
                            break;

                        default :
                            break;

                    }
                }
            }
            stud_list.push_back(st);
        }
        file.close();
        cout << "Выполненно" << endl;
    }
}


void clear_temp_list()
{
    char answer;

    cout << "you are sure? y/n" << endl;
    cout << ">>> ";
    cin >> answer;

    if (answer == 'y'){
        stud_list.clear();
    }
    cin.ignore();
}


void open_file()
{
    cout << "Введите название файла:" << endl << ">>> ";
    getline(cin, fileName);

    pathToFile = "../files/"  +  fileName + ".txt";

    ofstream file(pathToFile, ios::in);

    if (file.is_open()){
        cout << "file opened successfully" << endl;
        system("say \"file opened successfully\"");
    }
    else {
        cout << "file not founded" << endl;
        system("say \"file not founded\"");
        fileName = "";
    }
    file.close();
}


void make_file()
{
    cout << "Введите название нового файла:" << endl << ">>> ";
    getline(cin, fileName);

    pathToFile = "../files/"  +  fileName + ".txt";

    ofstream file(pathToFile);

    if (file.is_open()){
        cout << "file created successfully" << endl;
    }
    else {
        cout << "file not created" << endl;
    }
    file.close();
}


void remove_file()
{
    cout << "you are sure? y/n" << endl;
    cout << ">>> ";

    char answer;
    cin >> answer;

    if (answer == 'y'){
        if (remove(pathToFile.c_str())) {
            cout << "removed" << endl;
        }
    }

    fileName = "";
    pathToFile = "../files/";
    cin.ignore();
}


void clear_file()
{
    cout << "you are sure? y/n" << endl;
    cout << ">>> ";

    char answer;
    cin >> answer;

    if (answer == 'y') {
        ofstream file;
        file.open(pathToFile, std::ofstream::out | std::ofstream::trunc);

        if (!file.is_open()){
            cout << "file not founded" << endl;
        }

        file.close();
    }
    cin.ignore();
}


void close_file()
{
    fileName = "";
    pathToFile = "../files/";
}
