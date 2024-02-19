#include <iostream> 
#include <vector>

using namespace std;
vector<int> sorted;

void merge(vector<int> &arr, int l, int mid, int r){
    int lp = l, rp = mid+1, idx = l;
    
    while(lp <= mid && rp<= r){
        if (arr[lp] < arr[rp]){
            sorted[idx++] = arr[lp++];
        } else {
            sorted[idx++] = arr[rp++];
        }
    }

    while(lp <= mid){
        sorted[idx++] = arr[lp++];
    }

    while(rp <= r){
        sorted[idx++] = arr[rp++];    
    }

    for(int i = l; i <= r; i++){
        arr[i] = sorted[i];
    }

}

void MergeSort(vector<int>& arr, int l, int r){
    if (l < r) { // 원소 하나로까지 쪼개졌을 때
        int mid = (l + r)/2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    
}


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    sorted.assign(n, 0);

    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
    }

    MergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
    
    return 0;
}