#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& n1, const string& n2){
    int len1 = n1.size(), len2 = n2.size();

    if (len1 != len2){
        return  n1.size() < n2.size();
    }
    
    else{

        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < len1; i++){
            if(isdigit(n1[i])){
                sum1 += n1[i] - '0';
            }
        }
        for(int i=0; i < len2; i++){
            if(isdigit(n2[i])){
                sum2 += n2[i] - '0';
            }
        }
    
        if (sum1 != sum2){
            return sum1 < sum2;
        }

        return n1 < n2;

    }
}

int main(){

    int n;
    cin >> n;

    vector<string> serials;
    for(int i = 0; i < n ; i++){
        string serial;
        cin >> serial;
        serials.push_back(serial);
    }

    sort(serials.begin(), serials.end(), cmp);

    for(int i = 0; i < n ; i++){
        cout << serials[i] << '\n';
    }

    return 0;
}