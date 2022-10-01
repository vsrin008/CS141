#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void swapVal(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string curName;
    vector<string> Gryffindor;
    vector<string> Slytherin;
    vector<string> Hufflepuff;
    vector<string> Ravenclaw;

    cin >> n;

    for (int i=0; i <= n; ++i) {
        getline(cin,curName);

        if (curName.find("Gryffindor") != string::npos) {
            curName = curName.erase((curName.find("Gryffindor")),curName.length());
            Gryffindor.push_back(curName);
        }
        else if (curName.find("Hufflepuff") != string::npos) {
            curName = curName.erase((curName.find("Hufflepuff")),curName.length());
            Hufflepuff.push_back(curName);
        }
        else if (curName.find("Ravenclaw") != string::npos) {
            curName = curName.erase((curName.find("Ravenclaw")),curName.length());
            Ravenclaw.push_back(curName);
        }
        else if (curName.find("Slytherin") != string::npos) {
            curName = curName.erase((curName.find("Slytherin")),curName.length());
            Slytherin.push_back(curName);
        }

    }

    cout << "Gryffindor" << endl;
    sort(Gryffindor.begin(), Gryffindor.end());
    for (int i=0; i<Gryffindor.size(); ++i) {
        cout<<Gryffindor.at(i) << endl;
    }

    cout << "Hufflepuff" << endl;
    sort(Hufflepuff.begin(), Hufflepuff.end());
    for (int i=0; i<Hufflepuff.size(); ++i) {
        cout<<Hufflepuff.at(i) << endl;
    }

    cout << "Ravenclaw" << endl;
    sort(Ravenclaw.begin(), Ravenclaw.end());
    for (int i=0; i<Ravenclaw.size(); ++i) {
        cout<<Ravenclaw.at(i) << endl;
    }

    cout << "Slytherin" << endl;
    sort(Slytherin.begin(), Slytherin.end());
    for (int i=0; i<Slytherin.size(); ++i) {
        cout<<Slytherin.at(i) << endl;
    }

}