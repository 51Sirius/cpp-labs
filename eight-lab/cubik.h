#ifndef CPP_EIGHTH_LAB_51SIRIUS_CUBIK_H
#define CPP_EIGHTH_LAB_51SIRIUS_CUBIK_H


#include <fstream>
#include <iostream>
#include <random>
#include <system_error>
#include <filesystem>


struct Face {
    int colors[12];
};

class Cubik {
public :
    Cubik() {
        count_rotates = 0;
        rotates = std::vector<std::pair<int, int>>();
    }

    void import_f(const std::string &file_name) {
        std::ifstream file;
        file.open(file_name);
        std::string line;
        if (file.is_open()) {
            for (int j = 0; j < 6; ++j) {
                file >> line;
                for (int i = 0; i < 12; ++i) {
                    data[j].colors[i] = (int) line[i] - 48;
                }
            }

        } else throw std::system_error();
        file >> count_rotates;
        file >> line;
        for (int i = 0; i < count_rotates*2; i+=2) {
            int u= (int) line[i] - 48, v= (int) line[i+1] - 48;
            std::pair<int, int> a= {u, v};
            rotates.push_back(a);
        }
        file.close();
    }

    void export_f(const std::string &file_name) {
        std::ofstream file;
        file.open(file_name);
        std::string line;
        if (file.is_open()) {
            for (auto &j: data) {
                for (int color: j.colors) {
                    file << color;
                }
                file << std::endl;
            }
        } else throw std::system_error();
        file << count_rotates << "\n";
        for (auto tmp: rotates) {
            file << tmp.first << tmp.second;
        }
        file.close();
    }

    bool is_done() {
        for (auto &j: data) {
            for (int i = 0; i < 12; i += 3) {
                if (j.colors[i] != j.colors[i + 1] or j.colors[i] != j.colors[i + 2] or
                    j.colors[i + 2] != j.colors[i + 1]) {
                    return false;
                }
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 6; i += 3) {
                if (data[i + 2].colors[j] != data[i].colors[j] or data[i + 2].colors[j] != data[i + 1].colors[j] or
                    data[i].colors[j] != data[i + 1].colors[j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void show() {
        for (int i = 0; i < 3; ++i) {
            for (int color: data[i].colors) {
                std::cout << color;
            }
            std::cout << data[i + 3].colors[0] << data[i + 3].colors[1] << data[i + 3].colors[2];
            std::cout << data[i + 3].colors[6] << data[i + 3].colors[7] << data[i + 3].colors[8] << std::endl;
        }
    }

    void rotate(int face, int to) {
        std::pair<int, int> a = {face, to};
        rotates.push_back(a);
        int temp[12];
        for (int i = 0; i < 12; ++i) {
            temp[i] = data[face].colors[i];
        }

        if (to == 0) {
            for (int i = 0; i < 3; ++i) {
                data[face].colors[i] = temp[i + 9];
                data[face].colors[i + 3] = temp[i];
                data[face].colors[i + 6] = temp[i + 3];
                data[face].colors[i + 9] = temp[i + 6];
            }
            if (face <= 2) {
                for (int i = 3; i < 6; ++i) {
                    data[i].colors[face + 3] = data[face].colors[i - 3];
                }
                for (int i = 3; i < 6; ++i) {
                    data[i].colors[face + 9] = data[face].colors[i + 3];
                }
            } else {
                for (int i = 0; i < 3; ++i) {
                    data[i].colors[face - 3] = data[face].colors[i + 3];
                }
                for (int i = 0; i < 3; ++i) {
                    data[i].colors[face + 3] = data[face].colors[i + 6];
                }
            }

        } else if (to == 1) {
            for (int i = 0; i < 3; ++i) {
                data[face].colors[i] = temp[i + 3];
                data[face].colors[i + 3] = temp[i + 6];
                data[face].colors[i + 6] = temp[i + 9];
                data[face].colors[i + 9] = temp[i];
            }
            if (face <= 2) {
                for (int i = 3; i < 6; ++i) {
                    data[i].colors[face + 3] = data[face].colors[i - 3];
                }
                for (int i = 3; i < 6; ++i) {
                    data[i].colors[face + 9] = data[face].colors[i + 3];
                }
            } else {
                for (int i = 0; i < 3; ++i) {
                    data[i].colors[face - 3] = data[face].colors[i + 3];
                }
                for (int i = 0; i < 3; ++i) {
                    data[i].colors[face + 3] = data[face].colors[i + 6];
                }
            }
        }
    }

    void generate() {
        std::copy(std::begin(done_cube), std::end(done_cube), std::begin(data));
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> counts(1, 100);
        std::uniform_int_distribution<std::mt19937::result_type> faces(0, 5);
        std::uniform_int_distribution<std::mt19937::result_type> rot(0, 1);
        rotates.clear();
        int count = counts(rng);
        count_rotates = count;
        for (int i = 0; i < count; ++i) {
            int face = faces(rng);
            int rot1 = rot(rng);
            rotate(face, rot1);
        }
    }

    void solve_cubik() {
        for (int i = 0; i < count_rotates; ++i) {
            auto tmp = rotates.back();
            if (tmp.second == 0) tmp.second = 1;
            else tmp.second = 0;
            std::cout << tmp.first << ":" << tmp.second << "\n";
            rotates.pop_back();
        }
        std::copy(std::begin(done_cube), std::end(done_cube), std::begin(data));
        count_rotates = 0;
    }


private :
    Face data[6]{};
    Face done_cube[6] = {{1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4},
                         {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4},
                         {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4},
                         {5, 5, 5, 1, 1, 1, 6, 6, 6, 3, 3, 3},
                         {5, 5, 5, 1, 1, 1, 6, 6, 6, 3, 3, 3},
                         {5, 5, 5, 1, 1, 1, 6, 6, 6, 3, 3, 3}};
    int count_rotates;
    std::vector<std::pair<int, int>> rotates;
};


#endif