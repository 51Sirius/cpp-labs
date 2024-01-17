#include "main.h"


int main() {
    string path; // C:\\txt1.txt
    cout << "Enter your path: ";
    cin >> path;
    cout << endl;
    auto *file1 = new File_to_read(path);
    cout << "Status open is: " << file1->is_open() << endl;
    cout << file1->get_file_stream_name() << endl;
    if (file1->is_open()) {
        while (!file1->is_end_file()) {
            cout << file1->get_next_line() << endl;
        }
    }
    cout << "Is file1 end? " << file1->is_end_file() << endl;
    file1->close_file();
    cout << "Status open is: " << file1->is_open() << endl;
    delete file1;
    File_to_read file2;
    file2.Open_file(path);
    if (file2.is_open()) {
        while (!file2.is_end_file()) {
            cout << file2.get_next_word() << endl;
        }
    }
    return 0;
}