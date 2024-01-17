#ifndef CPP_SECOND_LAB_51SIRIUS_MAIN_H
#define CPP_SECOND_LAB_51SIRIUS_MAIN_H

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class File_to_read {
private:
    ifstream file;
    string file_name;
    string current_string;
    int current_index_word = 0;

    void set_vector_with_words();

    vector<string> current_words;
public:
    explicit File_to_read(const string &path);

    File_to_read();
    ~File_to_read();

    int Open_file(const string &path);

    bool is_open();

    void close_file();

    string get_next_line();

    string get_file_stream_name();

    bool is_end_file();

    string get_next_word();
};


#endif //CPP_SECOND_LAB_51SIRIUS_MAIN_H