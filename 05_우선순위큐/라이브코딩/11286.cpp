#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &x1, const int &x2){

        //절댓값이 다르면 절댓값이 작은 수 앞으로
        if(abs(x1) != abs(x2)){
            return abs(x1)>abs(x2);
        }
        //절댓값이 같으면 작은 수 앞으로
        return x1 > x2;
    }
};

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> absheap;

    while(n--){

        cin >> x;

        if( x==0 ){
            if(absheap.empty()){
                cout << "0\n";
            }
            else{
                cout << absheap.top() << "\n";
                absheap.pop();
            }
        }
        else{
            absheap.push(x);
        }
    }
    return 0;
}