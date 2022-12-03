#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

int find(vector<int>& settledCities, int city) {
    bool found = false;

    for (int i = 0; i < settledCities.size(); ++i) {
        if (settledCities.at(i) == city) {
            found = true;
            return i;
        }
    }
    return 1;
}

void FindDist(vector<vector<pair<int,int>>>& graph, vector<int>& tentativeDistances, int start, int desired, int maxWeight) {
    vector<int> settledCities;
    vector<tuple<int, int, int>> Q;
    tentativeDistances.at(start) = 0;
    tuple<int, int, int> curr;
    get<0>(curr) = tentativeDistances.at(start); 
    get<1>(curr) = start; 
    get<2>(curr) = -1; 
    Q.push_back(curr);
    tuple<int, int, int> neighbor;
    get<0>(neighbor) = 0;
    get<1>(neighbor) = 0;
    get<2>(neighbor) = 0;
    int min = 0;

    while (!Q.empty()) {
        min = 0;
        for (int i = 0; i < Q.size(); ++i){ 
            if (get<0>(Q.at(i)) < get<0>(Q.at(min))) {
                min = i;
            }
        }
        curr = Q.at(min);
        Q.erase(Q.begin()+min);
        settledCities.push_back(get<1>(curr));
        tentativeDistances.at(get<1>(curr)) = get<0>(curr);

        for (int i = 0; i < graph.at(get<1>(curr)).size(); ++i) {
            if (find (settledCities, graph.at(get<1>(curr)).at(i).first) != -1) {
                continue;
            }
            if (tentativeDistances.at(graph.at(get<1>(curr)).at(i).first) != maxWeight) {
                int possDist = get<0>(curr) + graph.at(get<1>(curr)).at(i).second;
                if (possDist < tentativeDistances.at(graph.at(get<1>(curr)).at(i).first)) {
                    tentativeDistances.at(graph.at(get<1>(curr)).at(i).first) = possDist;
                    int want = 0;
                    int looking = graph.at(get<1>(curr)).at(i).first;

                    for (int j = 0; j < Q.size(); ++j) {
                        want = get<1>(Q.at(j));
                        if (want == looking) {
                            get<0>(Q.at(j)) = possDist;
                            get<2>(Q.at(j)) = get<1>(curr);
                        }
                    }
                }
            }
            else {
                get<0>(neighbor) = get<0>(curr) + graph.at(get<1>(curr)).at(i).second; 
                tentativeDistances.at(graph.at(get<1>(curr)).at(i).first) = get<0>(neighbor); 
                get<1>(neighbor) = graph.at(get<1>(curr)).at(i).first; 
                get<2>(neighbor) = get<1>(curr); 
                Q.push_back(neighbor);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(0);
    int numCities;
    int numEdges;
    int currCity;
    int destination;
    
    cin >> numCities;
    cin >> numEdges;
    cin >> currCity;
    cin >> destination;

    vector<vector<pair<int, int>>> graph;
    vector<pair<int, int>> connections;

    for (int i = 0; i < numCities; ++i) {
        graph.push_back(connections);
    }

    int cityA;
    int cityB;
    int weight = 0;
    pair<int, int> edge;
    edge.first = 0;
    edge.second = 0;
    int maxWeight = 0;
    for (int i = 0; i < numEdges; ++i) {
        cin >> cityA;
        cin >> cityB;
        cin >> weight;

        if (weight > maxWeight) {
            maxWeight = weight;
        }

        edge.first = cityB;
        edge.second = weight;
        graph.at(cityA).push_back(edge);
        edge.first = cityA;
        edge.second = weight;
        graph.at(cityB).push_back(edge);
    }


    vector<int> tentativeDistances;
    for (int i = 0; i < graph.size(); ++i) {
        tentativeDistances.push_back(numeric_limits<int>::max());
    }
    
    FindDist(graph, tentativeDistances, currCity, destination, numeric_limits<int>::max());

    cout << tentativeDistances.at(destination) << endl;

    return 0;
}