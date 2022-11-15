#include <iostream>

using namespace std;

void add_edge(int g[][], int x, int y, int z) {
   g[x][y] = z;
   g[y][x] = z;
}

void displayMatrix(int n) {
   int i, j;
   for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++) {
         cout << g[i][j] << " ";
      }
      cout << endl;
   }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m, s, t;
    int tempX, tempY, tempZ;
    cin >> n >> m >> s >> t;
    int g[n][n];

    for (int i = 0; i < m; ++i) {
        cin >> tempX >> tempY >> tempZ;
        add_edge(tempX, tempY, tempZ);
        
    }

    displayMatrix(n);


}