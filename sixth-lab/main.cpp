#include "algos.h"
#include "iostream"
#include "vector"
#include "for_testing.h"


int main() {
    //Any of testing with base type
    std::vector<int> arr = {1, 0, 4, 7};
    std::vector<int> arr2 = {1, 4, 7};
    if (any_of(arr.begin(), arr.end(), is_zero)) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }
    if (any_of(arr2.begin(), arr2.end(), is_zero)) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }

    //Any of testing with Edge type
    std::vector<Edge> arr3 = {{1, 2, 0}, {1, 2, 4},{1, 2, 4},{1, 2, 4}};
    std::vector<Edge> arr4 = {{1, 2, 4}, {1, 2, 4},{1, 2, 4},{1, 2, 4}};
    if (any_of(arr3.begin(), arr3.end(), [](Edge edge) {
        return edge.weight == 0;
    })) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }
    if (any_of(arr4.begin(), arr4.end(), [](Edge edge) {
        return edge.weight == 0;
    })) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }

    // One of testing with base type
    arr = {1, 0, 4, 7};
    arr2 = {1, 0, 0, 7};
    if (one_of(arr.begin(), arr.end(), is_zero)) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }
    if (one_of(arr2.begin(), arr2.end(), is_zero)) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero or with 2 more zeros\n";
    }

    //One of testing with Edge type
    if (one_of(arr3.begin(), arr3.end(), [](Edge edge) {
        return edge.weight == 0;
    })) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero\n";
    }
    arr4 = {{1, 2, 0}, {1, 2, 0},{1, 2, 4},{1, 2, 4}};
    if (one_of(arr4.begin(), arr4.end(), [](Edge edge) {
        return edge.weight == 0;
    })) {
        std::cout << "One element is zero\n";
    } else {
        std::cout << "This is array without zero or with 2 more zeros\n";
    }

    // Find_not testing with base type
    arr = {1, 0, 4, 7};
    arr2 = {1, 0, 0, 7};
    std::cout << *find_not(arr.begin(), arr.end(), 0, [](int a, int b) {
        return a == b;
    }) << std::endl;
    std::cout << *find_not(arr2.begin(), arr2.end(), 7, [](int a, int b) {
        return a == b;
    }) << std::endl;

    //Find_not testing with Edge type
    Edge a = {1, 2, 4};
    Edge b = *find_not(arr3.begin(), arr3.end(), a, [](Edge a, Edge b) {
        return a.u == b.u and a.v == b.v and a.weight == b.weight;
    });
    std::cout << b.weight << std::endl;

    return 0;
}