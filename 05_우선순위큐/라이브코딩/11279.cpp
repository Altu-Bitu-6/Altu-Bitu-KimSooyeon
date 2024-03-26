#include <iostream>
#include <vector>

using namespace std;

//heap이 비어있는지 확인
bool isEmpty(vector<int>& heap) {
	return heap.size() == 1;
}

int pop(vector<int> &max_heap){

    int val = max_heap[1];          //리턴할 root node 값 저장
    
    max_heap[1] = max_heap[max_heap.size() - 1];    //마지막 노드를 root node 자리로 가져옴
    max_heap.pop_back();                            //마지막 노드 삭제

    //먼저 자식 노드들끼리 비교해서 큰 자식 노드를 부모 노드랑 비교함  
    int parent = 1, child =2; //일단 부모 노드가 root node 인 경우부터 시작
    int size = max_heap.size();

    while(child < size){ //계속 내려감
        //오른쪽 자식 노드가 존재할 때, 두 개의 자식 노드 중 큰 값 선택
        if (child + 1 < size && max_heap[child + 1] > max_heap[child]) { //오른쪽 자식 노드가 존재하고 더 큰 경우
			child += 1;
		}    //오른쪽 자식 노드가 존재하지 않거나 존재하더라도 왼쪽 자식노드보다 작은 경우 child 는 계속 왼쪽 자식 노드

        if(max_heap[child] > max_heap[parent]){
            swap(max_heap[child], max_heap[parent]);
            //한 레벨 내려감
            parent = child;      
            child = parent * 2;
        }
        else{ //왼전이진트리의 조건 만족
            break;
        }
    }    

    return val;   
}


void push(int x, vector<int> &max_heap){

    int idx = max_heap.size();
    max_heap.push_back(x); // 마지막 노드로 삽입

    while(idx >1 && max_heap[idx] > max_heap[idx/2]){     //부모 노드와 비교해서 더 크면 부모 노드가 됨
        swap(max_heap[idx], max_heap[idx/2]);   //위치 바꿔줌
        idx/=2;                                 //한 레벨 올라감
    }
    
}

int main(){

    //입력
    int n, x;

    vector <int> max_heap;
    max_heap.push_back(0);

    cin >> n;

    while(n--){
        cin >> x;

        // 
        if(x == 0){
            if(isEmpty(max_heap)){
                cout << "0\n";
            }
            else{
                cout << pop(max_heap) << '\n';
            }
        }
        if(x > 0){
            push(x, max_heap);
        }
    }

    return 0;
}