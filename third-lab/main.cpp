#include "comlex.h"
#include "array.h"
#include "iostream"

using namespace std;


int main(){
    Complex c1;
    c1.set_re(10);
    c1.set_im(10);
    Complex c2(5, 2);
    c1 = c1 * 2;
    c1 = c1.operator*(2);
    cout << c1.get_re() << " + i" << c1.get_im() << endl;
    c1 = c1 + c2;
    c1 = c1.operator+(c2);
    cout << c1.get_re() << " + i" << c1.get_im()<< endl;
    c1 = c1 * c2;
    c1 = c1.operator*(c2);
    cout << c1.get_re() << " + i" << c1.get_im()<< endl;


    int arr[4] = {1, 2, 3, 4};
    Array arr1(arr, 4);
    int arr2[5] = {1, 2, 3, 4, 5};
    Array arr3(arr2, 5);
    if (arr1 < arr3){
        cout << "1 < 3"  << endl;
    } else if (arr1 == arr3){
        cout << "1 == 3"  << endl;
    }
    arr1 = arr1 + arr3;
    for (int i = 0; i < arr1.get_len(); ++i) {
        cout << arr1.get_value(i) << " ";
    }
    arr1 = arr1.operator+(arr3);
    cout << endl;
    for (int i = 0; i < arr1.get_len(); ++i) {
        cout << arr1.get_value(i) << " ";
    }



    return 0;
}