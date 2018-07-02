#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int arr[2][3] = {{1,2,3},{4,5,6}};
    // the original array address
    cout<< "Array addr : arr=" << arr << endl;
    cout<< "Array addr : arr[0]=" << arr[0] << endl;
    cout<< "Array addr : &arr[0]=" << &arr[0] << endl;
    cout<< "Array addr : &arr[0][0]=" << &arr[0][0] << endl;
    
    // the offset array address
    cout<< "sizeof(int) : " << sizeof(int) << endl;
    cout<< "Array addr : (arr + 1)=" << arr + 1 << "==" << **(arr + 1) <<", sizeof(arr) : " << sizeof(arr)<< endl;
    cout<< "Array addr : (arr[0] + 1)=" << arr[0] + 1 << "==" << *(arr[0] + 1) <<", sizeof(arr[0]) : " << sizeof(arr[0]) << endl;
    cout<< "Array addr : (&arr[0] + 1)=" << &arr[0] + 1 << "==" << **(&arr[0] + 1) <<", sizeof(&arr[0]) : " << sizeof(&arr[0]) << endl;
    cout<< "Array addr : (&arr[0][0] + 1)=" << &arr[0][0] + 1 << "==" << *(&arr[0][0] + 1) <<", sizeof(&arr[0][0]) : " << sizeof(&arr[0][0]) << endl;

    // int* a,b ; is the same effect, a is a pointer and b is int
    int *a,b;
    b=5;
    a=&b;
    cout << "a = " << *a << endl; 
    
    // reference
    int aa=6;
    int &bb = aa;
    aa =7;
    cout << "aa = " << aa << ", bb=" << bb << endl;
    return 0;
}
