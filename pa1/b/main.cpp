#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int temp;
    cin >> n;
    vector<int> departments;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        departments.push_back(temp);
    }

    sort(departments.begin(),departments.end());

    int neededDeps = (n/2)+1;
    int totalVotes = 0;

    for (int i = 0; i < neededDeps; ++i) {
        totalVotes += (departments.at(i)/2)+1;
    }

    cout << totalVotes;





    return 0;
}