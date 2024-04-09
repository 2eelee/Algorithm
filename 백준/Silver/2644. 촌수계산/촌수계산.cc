#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> relations;
vector<int> chon;

int calChonSu(int person1, int person2) {
    vector<bool> visited(chon.size(), false);
    queue<int> q;

    q.push(person1);
    visited[person1] = true;

    while (!q.empty()) {
        int cur_p = q.front();
        q.pop();

        for (int i = 0; i < relations[cur_p].size(); i++) {
            int ilchon = relations[cur_p][i];

            if (!visited[ilchon]) {
                chon[ilchon] = chon[cur_p] + 1;
                visited[ilchon] = true;
                q.push(ilchon);

                if (ilchon == person2) {
                    return chon[ilchon];
                }
            }
        }
    }

    return -1;
}

int main()
{
    int n, person1, person2, m;
    cin >> n;
    cin >> person1 >> person2;
    cin >> m;
    
    relations.resize(n+1);
    chon.resize(n+1,0);
    
    while(m--){
        
        int parent, child;
        
        cin >> parent >> child;
        relations[parent].push_back(child);
        relations[child].push_back(parent);
    }
    
    cout << calChonSu(person1, person2);
}