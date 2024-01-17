#ifndef CPP_EIGHTH_LAB_51SIRIUS_INTERFACE_H
#define CPP_EIGHTH_LAB_51SIRIUS_INTERFACE_H

#include "cubik.h"

class Interface {
public:
    Interface() {
        a = Cubik();
    }

    void start_programm() {
        bool flag = true;
        while (flag) {
            std::cout
                    << "Choice operation:\n1.Import\n2.Export\n3.Show\n4.Check\n5.Generate\n6.Solve(You need subscribe for this)\n7.Rotate\n8.Exit\n";
            int choice = 0;
            std::cin >> choice;
            if (choice == 1) {
                import_func();
            } else if (choice == 2) {
                export_func();
            } else if (choice == 3) {
                a.show();
            } else if (choice == 4) {
                if (a.is_done()) {
                    std::cout << "Cubik was done!\n";
                } else std::cout << "Cubik wasnt done(\n";
            } else if (choice == 5) {
                a.generate();
                std::cout << "Cubik was generate!";
            } else if (choice == 6) {
                std::cout << "If you have sub.\n";
                a.solve_cubik();
            }else if (choice == 7){
                std::cout << "Choice numb of your face: ";
                int face, to;
                std::cin >> face;
                std::cout << "Choice numb of your rotate: ";
                std::cin >> to;
                a.rotate(face, to);
                std::cout << "Cubik was rotate!\n";
            } else if (choice == 8) {
                flag = false;
            }
        }

    };

    void import_func() {
        std::cout << "Enter file name:";
        std::string name;
        std::cin >> name;
        a.import_f(name);
        std::cout << "Done import!\n";
    }

    void export_func() {
        std::cout << "Enter file name:";
        std::string name;
        std::cin >> name;
        a.export_f(name);
        std::cout << "Done export!\n";
    }

private:
    Cubik a;
};

#endif