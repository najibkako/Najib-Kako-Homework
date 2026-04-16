#include <iostream>
using namespace std;

void findSame(int a[], int b[], int size) {
    cout << "same #'s: "; 

    for (int i = 0; i < size; i++ ) { 
        for (int j = 0; j < size; j++) { 
            if (a[i] == b[j]) { 
                cout << a[i] << " ";
                break;  
            }
        }
    }
}

int main() {
    int data[] = {1, 3, 6, 7, 9};
    int data1[] = {2, 3, 5, 7, 11}; 

    int temp;

    for (int i = 0; i < 5; i++) { 
        temp = data[i];
        data[i] = data1[i];
        data1[i] = temp; 
    }

    cout << "data: ";
    for (int i = 0; i < 5; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "data1: ";
    for (int i = 0; i < 5; i++) {
        cout << data1[i] << " ";
    }
    cout << endl;

    findSame(data, data1, 5);

    return 0;

}