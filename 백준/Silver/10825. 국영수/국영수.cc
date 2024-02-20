#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student{
    string name;
    int kor;
    int eng;
    int math;
} student;

bool compare(student& a, student& b){
    if(a.kor != b.kor){
        return a.kor > b.kor;
    }
    if(a.eng != b.eng){
        return a.eng < b.eng;
    }
    if(a.math != b.math){
        return a.math > b.math;
    }
    return a.name < b.name;
}

int main()
{
    int n;
    cin >> n;
    vector<student> st(n);
    
    for(int i=0; i<n; i++){
        cin >> st[i].name >> st[i].kor >> st[i].eng >> st[i].math ;
    }
    
    sort(st.begin(), st.end(), compare);
    
    for(int i=0; i<n; i++){
        cout << st[i].name << "\n";
    }
    
}