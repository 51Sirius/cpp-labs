
#include "Logical.h"

Logical::Logical() {
    command = "empty";
}

void Logical::execute(string new_command) {
    command = new_command;
    if (command == "addcircle") {
        add_circle();
    } else if (command == "addtrap") {
        add_trap();
    } else if (command == "showall") {
        show_all();
    } else if (command == "sumofsquare") {
        sumofsquare();
    } else if (command == "sumofperimeter") {
        sumofperimeter();
    } else if (command == "allmemory") {
        all_memory();
    } else if (command == "sort") {
        sort_figures();
    } else if (command == "center") {
        center();
    } else {
        cout << "Wrong input" << endl;
    }
}

Logical::~Logical() {
    for (auto i: figures) {
        delete i;
    }
}

void Logical::add_circle() {
    auto *tmp = new Circle();
    tmp->initFromDialog();
    figures.push_back(tmp);
}

void Logical::add_trap() {
    auto *tmp = new Trapezoid();
    tmp->initFromDialog();
    figures.push_back(tmp);
}

void Logical::show_all() {
    int count = 1;
    for (auto i: figures) {
        cout << "Figure #" << count << endl;
        i->draw();
        count++;
    }
}

void Logical::sumofsquare() {
    double summ = 0;
    for (auto i: figures) {
        summ += i->square();
    }
    cout << "Sum of all square: " << summ << endl;
}

void Logical::sumofperimeter() {
    double summ = 0;
    for (auto i: figures) {
        summ += i->perimeter();
    }
    cout << "Sum of all perimeters: " << summ << endl;
}

void Logical::all_memory() {
    unsigned int summ = 0;
    for (auto i: figures) {
        summ += i->size();
    }
    cout << "Memory of all figures: " << summ << endl;
}

void Logical::sort_figures() {
    sort(figures.begin(), figures.end(), [](Interface *a, Interface *b) { return (a->mass() < b->mass()); });
}

void Logical::center() {
    double Cx;
    double Cy;
    double sm_of_mass = 0;
    double sm_for_x = 0;
    double sm_for_y = 0;
    for (auto i: figures) {
        sm_of_mass += i->mass();
        sm_for_x += i->mass() * i->position().x;
        sm_for_y += i->mass() * i->position().y;
    }
    Cx = sm_for_x / sm_of_mass;
    Cy = sm_for_y / sm_of_mass;
    cout << "Center mass of system (" << Cx << ";" << Cy << ")" << endl;
}
