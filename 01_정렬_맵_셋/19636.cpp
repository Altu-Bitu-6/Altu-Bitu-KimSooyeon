#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int w, I, T, D, DI, A;
    cin >> w >> I >> T >> D >> DI >> A;

    int w1 = w + (DI - I - A)*D;
    int w2 = w, meta = I;
    
    for(int i=0; i<D; i++){

        w2 += DI - meta - A;
        if(abs(DI - meta - A)>T){
            meta += floor((DI - meta - A)/2.0);
        }

    }

    if (w1<=0){
        cout << "Danger Diet\n";
    }
    else{
        cout << w1 << " " << I << "\n";
    }
    
    if(w2 <=0 || meta <= 0){
            cout << "Danger Diet\n";
            return 0;
    }

    if (I - meta > 0){
        cout << w2 << " " << meta << " " << "YOYO";
    }
    else{
        cout << w2 << " " << meta << " " << "NO";
    }

    return 0;
}