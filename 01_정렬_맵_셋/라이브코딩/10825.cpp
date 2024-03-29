#include <iostream>


using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

bool comp(const student& s1, const student& s2){
    if (s1.kor != s2.kor){
        return s1.kor > s2.kor;
    }
    if (s1.eng != s2.eng){
        return s1.eng < s2.eng;
    }
    if(s1.math != s2.math){
        return s1.math > s2.math;
    }
    return s1.name < s2.name;
 
}

int main(){

    int n;
    cin >> n;

    vector<student> students (n);

    for(int i=0 ; i<n; i++){
        cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
    }

    sort(students.begin(), students.end(), comp);

    for(int i=0; i<n; i++){
        cout << students[i].name << '\n';
    }

    return 0;
}