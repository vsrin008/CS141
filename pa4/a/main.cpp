#include <iostream>
#include <vector>
using namespace std;

int findLDS(vector<int> list, int n) {
    vector<int> curLDS(n,1);
    int maxLDS = 0;

    for (int i=1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (list.at(i) < list.at(j) && curLDS.at(i) < curLDS.at(j) + 1) {
                curLDS.at(i) = curLDS.at(j) + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (maxLDS < curLDS.at(i)) {
            maxLDS = curLDS.at(i);
        }
    }

    return maxLDS;

}


int main() {
    int n;
    int temp;
    cin >> n;

    vector<int> list(n, -1);
    
    for (int i=0; i < n; ++i) {
        cin >> temp;
        list.at(i) = temp;
    }

    cout << findLDS(list, n);

}