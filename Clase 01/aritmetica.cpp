#include <iostream>
using namespace std;

int main(){
    int vec[5] = {10, 20, 30, 40, 50};
    int *p;
    p = vec;

    for (int i=0; i<5; i++){
        cout << *p << endl;
        p++;
    }
    //cout << vec[0] << endl;
    //cout << *vec << endl;

    return 0;
}
