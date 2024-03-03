#include <iostream>

using namespace std;

int getGCD(int a, int b){   //a와 b의 최대공약수는 a%b와 b의 최대공약수와 같음 
    
    if (a < b){
        swap(a, b);
    }

    while(b){               //b가 0일 때까지, 다 나누어 떨어져서 a에 최대공약수만 남게 됨
        a %= b;             //a%b 를 구함, b로 나눈 나머지니까 b보다 작은 값이 됨
        swap(a, b);         //a에 큰 값 , b에 작은 값이 오도록 함
    }

    return a;
}

int main(){


    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 두 분수의 합
    int denom = b*d;                //분모
    int numer = a*d + c*b;          //분자

    int g = getGCD(numer, denom);   //최대공약수

    //기약분수 출력 - 분자와 분모를 최대공약수로 약분하면 기약분수
    cout << numer/g << ' ' << denom/g << '\n';

    return 0;
}