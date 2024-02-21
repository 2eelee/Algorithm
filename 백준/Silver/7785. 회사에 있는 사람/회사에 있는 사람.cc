#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> employee;

    for (int i = 0; i < n; i++) {
        string name;
        string e_or_l;
        cin >> name >> e_or_l;

        if (e_or_l == "enter") {
            employee.insert(name);
        } else if (e_or_l == "leave") {
            employee.erase(name);
        }
    }

    // set은 기본적으로 오름차순으로 정렬되므로 내림차순으로 출력하기 위해 반대로 출력합니다.
    vector<string> employeeVector(employee.rbegin(), employee.rend());

    for (const auto& iter : employeeVector) {
        cout << iter << "\n";
    }

    return 0;
}