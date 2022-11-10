#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int editDistance(vector<int> vector1, vector<int> vector2, int n1, int n2) {
    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 0;
    
    for(int i = 1; i <= n1; i++) {
        dp[i][0] = vector1.at(i-1) + dp[i-1][0];
    }
    
    for(int j = 1; j <= n2; j++) {
        dp[0][j] = vector2.at(j-1) + dp[0][j-1];
    }
    
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            
            dp[i][j] = 0;
            dp[i][j] = min(dp[i][j-1] + vector2.at(j-1),dp[i-1][j] + vector1.at(i-1)); 
            dp[i][j] = min(dp[i][j] ,dp[i-1][j-1] + abs(vector1.at(i-1) - vector2.at(j-1)));
        
        }
    }
    return dp[n1][n2];
}



int main() {
    int n1, n2;
    int x, y;
    
    cin >> n1 >> n2;
    vector<int> vector1(n1, -1);
    vector<int> vector2(n2, -1);


    for (int i = 0; i < n1; ++i) {
        cin >> x;
        vector1.at(i) = x;
    }

    for(int i = 0; i < n2; ++i) {
        cin >> y;
        vector2.at(i) = y;
    }

    cout << editDistance(vector1, vector2, n1, n2);




}