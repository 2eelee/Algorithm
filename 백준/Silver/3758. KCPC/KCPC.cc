#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int id; // 팀 번호
    int score; // 최종 점수 (모든 문제의 최고 점수 합)
    int submit_cnt; // 제출 횟수
    int last_submit; // 마지막 제출 시간
};

// cmp 함수: 점수 -> 제출 횟수 -> 마지막 제출 시간 기준으로 비교
bool cmp(const Team &a, const Team &b) {
    if (a.score != b.score) return a.score > b.score; // 점수는 내림차순
    if (a.submit_cnt != b.submit_cnt) return a.submit_cnt < b.submit_cnt; // 제출 횟수는 오름차순
    return a.last_submit < b.last_submit; // 마지막 제출 시간은 오름차순
}

int main() {
    int tc;
    cin >> tc;
    
    while(tc--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        
        // 팀별 문제별 최고 점수 저장 배열 [팀 번호][문제 번호]
        vector<vector<int>> problem_scores(n+1, vector<int>(k+1, 0));
        
        // 각 팀의 정보를 저장할 구조체 배열
        vector<Team> teams(n+1);
        for (int i = 1; i <= n; i++) {
            teams[i] = {i, 0, 0, 0}; // 팀 번호, 최종 점수, 제출 횟수, 마지막 제출 시간 초기화
        }

        for(int time = 1; time <= m; time++) {
            int i, j, s;
            cin >> i >> j >> s;
            
            // 최고 점수 갱신
            if (problem_scores[i][j] < s) {
                teams[i].score += (s - problem_scores[i][j]); // 점수 차이만큼 총점에 반영
                problem_scores[i][j] = s;
            }
            
            // 제출 횟수 증가 및 마지막 제출 시간 갱신
            teams[i].submit_cnt++;
            teams[i].last_submit = time;
        }
        
        // 팀들을 정렬
        sort(teams.begin() + 1, teams.end(), cmp);
        
        // 정렬된 결과에서 당신 팀의 순위 출력
        for(int i = 1; i <= n; i++) {
            if (teams[i].id == t) {
                cout << i << '\n'; // 순위는 1부터 시작하므로 i 그대로 출력
                break;
            }
        }
    }
    return 0;
}
