#include <iostream>
#include <vector>

using namespace std;

void updatePan(vector<char>& pan, int& index, int n, int s, char ch) {
    index += s;
    
    if(index >= n) {
        index %= n;
    }
    
    if(pan[index] != '?' && pan[index] != ch) {
        cout << "!";
        exit(0);
    }
    
    for(int j = 0; j < n; j++) {
        if(pan[j] == ch) {
            if(j == index) continue;
            else {
                cout << "!";
                exit(0);
            }
        }
    }
    
    pan[index] = ch;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<char> pan(n, '?');
    int index = 0;
    
    for(int i = 0; i < k; i++) {
        int s;
        char ch;
        cin >> s >> ch;
        
        updatePan(pan, index, n, s, ch);
    }
    
    for(int i = 0; i < n; i++) {
        cout << pan[index];
        index--;
        if(index < 0) index = n - 1;
    }
    
    return 0;
}
