
#ifndef CPP_FOURTH_LAB_51SIRIUS_LOGICAL_H
#define CPP_FOURTH_LAB_51SIRIUS_LOGICAL_H

#include "figures.h"
#include "vector"
#include <algorithm>

using namespace std;


class Logical {
private:
    vector<Interface *> figures;
    string command;
public:
    Logical();

    ~Logical();

    void execute(string new_command);

    void add_circle();

    void add_trap();

    void show_all();

    void sumofsquare();

    void sumofperimeter();

    void all_memory();

    void sort_figures();

    void center();
};


#endif //CPP_FOURTH_LAB_51SIRIUS_LOGICAL_H