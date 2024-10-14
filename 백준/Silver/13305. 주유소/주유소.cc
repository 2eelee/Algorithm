#include <iostream>
#include <vector>

using namespace std;

long long minOilCost(int n, vector<int>& road_length, vector<int>& oil_cost) {
    long long total_cost = 0; // 총 비용을 저장하는 변수
    int min_cost = oil_cost[0]; // 첫 번째 주유소의 기름 가격을 최소값으로 초기화

    // 각 도로를 따라 이동하며 최소 비용 계산
    for (int i = 0; i < n - 1; i++) {
        // 현재 최소 기름 가격으로 도로를 지나가는 비용 추가
        total_cost += static_cast<long long>(min_cost) * road_length[i];

        // 다음 주유소의 기름 가격이 더 저렴하면 갱신
        if (oil_cost[i + 1] < min_cost) {
            min_cost = oil_cost[i + 1];
        }
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> road_length(n - 1, 0); // 0 ~ n-2번 도로의 길이
    vector<int> oil_cost(n, 0);        // 0 ~ n-1번 주유소의 기름값

    // 도로 길이 입력
    for (int i = 0; i < n - 1; i++) {
        cin >> road_length[i];
    }
    // 주유소 기름 가격 입력
    for (int i = 0; i < n; i++) {
        cin >> oil_cost[i];
    }

    // 최소 비용 계산 결과 출력
    cout << minOilCost(n, road_length, oil_cost);
}
