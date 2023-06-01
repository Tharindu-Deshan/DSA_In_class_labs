#include <iostream>
#include <vector>

using namespace std;

int find_min(vector<int>&short_dist,vector<bool>&visited){
    int min=INT_MAX;
    int min_index=-1;
    for(int i=0;i<short_dist.size();i++){
        if(short_dist[i]!=0 && !visited[i] && short_dist[i]<= min){
            min =short_dist[i];
            min_index=i;
        }
    }
    return min_index;
}



void Short_Paths(vector<vector<int>>&Graph,int s) {
    int num_cities = Graph.size();
    vector<bool> visited(num_cities, false);
    vector<int> short_dist(num_cities, INT_MAX);

    ///////////////////////////////////////////////////////////
    visited[s] = true;
    short_dist[s] = 0;
    for (int i = 0; i < num_cities; i++) {
        if (visited[i] == false && Graph[s][i] != 0) {
            short_dist[i] = Graph[s][i];
        }
    }
    cout << endl;
    ///////////////////////////////////////////////////////////

    for (int i = 0; i < num_cities - 1; i++) {
        int min = find_min(short_dist, visited);
        visited[min] = true;

        for (int i = 0; i < num_cities; i++) {
            if (!visited[i] && Graph[min][i] != 0 && short_dist[i] > short_dist[min] + Graph[min][i]) {
                short_dist[i] = short_dist[min] + Graph[min][i];
            }
        }
    }
    for(int i=0;i<short_dist.size();i++){
        cout<< "Time taken to travel from city  "<< s<< " to city  " <<i<< " is "<<  short_dist[i]<<endl;
    }
}
int main() {
    vector<vector<int>> graph = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };
   Short_Paths(graph,5);
    return 0;
}
