#include <iostream>
#include <vector>
using namespace std; //cin,cout 사용할 때 앞에 std:: 생략 가능

void BubbleSort(vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++){  //0 ~ n-1 번
        for(int j = 0; j < arr.size() - 1 -i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }

    }
}

int main(){
    
    int n;
    cin >> n;
    vector<int> arr(n);

    // n개의 수 저장
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    BubbleSort(arr);
    
    // 정렬 결과 출력
    for(int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
    
    return 0;
}