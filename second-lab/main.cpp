#include "main.h"

File_to_read::File_to_read(const string &path) {
    this->Open_file(path);
}

File_to_read::File_to_read() {
    this->file = nullptr;
}
File_to_read::~File_to_read() {
    this->file.close();
    cout << "Clear" << endl;
}

int File_to_read::Open_file(const string &path) {
    try {
        this->file.open(path);
        this->file_name = path;
        if (!this->file) {
            cout << "Cant find this file\n";
            this->file.close();
            return -1;
        }
        cout << "File " << path << " was opened " << "\n";
        return 0;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
        cout << "Error with opened file!\n";
        this->file.close();
        return -1;
    }
}

bool File_to_read::is_open() {
    return this->file.is_open();
}

void File_to_read::close_file() {
    this->file.close();
}

string File_to_read::get_next_line() {
    if(!file.is_open()){
        cout << "File dont open!" << endl;
        return "";
    }
    if (!this->is_end_file()) {
        string s;
        getline(this->file, s);
        this->current_string = s;
        set_vector_with_words();
        this->current_index_word = 0;
        return s;
    } else {
        cout << "File is end!"<< endl;
    }
}

string File_to_read::get_file_stream_name() {
    stringstream ss(this->file_name);
    string s;
    string last;
    while (getline(ss, s, '\\')) {
        last = s;
    }
    return last;
}

bool File_to_read::is_end_file() {
    return this->file.eof();
}

void File_to_read::set_vector_with_words() {
    this->current_words.clear();
    stringstream ss(this->current_string);
    string s;
    while (getline(ss, s, ' ')) {
        this->current_words.push_back(s);
    }
}

string File_to_read::get_next_word() {
    if(!file.is_open()){
        cout << "File dont open!"<< endl;
        return "";
    }
    if (this->current_string.empty()) {
        get_next_line();
    }
    int ind = this->current_index_word;
    this->current_index_word++;
    try {
        return this->current_words[ind];
    }
    catch (const exception &e) {
        if (!this->is_end_file()) {
            this->get_next_line();
            return this->get_next_word();
        } else { cout << "File is end!"<< endl; }
    }
}