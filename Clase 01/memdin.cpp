#include <iostream>
using namespace std;

int main(){
    int elementos;
    float *vec;

    cout << "Ingresar cantidad de elementos: ";
    cin >> elementos;

    vec = new float[elementos];
    if (vec != nullptr){
        cout << "Ok";
        delete vec;
    }
    else{
        cout << "No Ok";
    }

    return 0;
}
