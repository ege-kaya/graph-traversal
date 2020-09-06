/*
Student Name: EGE CAN KAYA
Student Number: 2018400018
Project Number: 4
Compile Status: SUCCESS
Running Status: SUCCESS
Notes: only 1 & 3 work
*/
#include "HelpStudents.h"

using namespace std;

HelpStudents::HelpStudents(int N, int M, int K, vector<pair<pair<int, int>, int> > ways) {
    nodes = N;
    edges = M;
    target = K;
    adjacencyList.resize(nodes + 1);
    // initially set all distances to something very large
    distances.resize(nodes + 1, 1e14);
    notFinal.resize(nodes + 1, true);
    // sets up the adjacency list going both ways (since it is an undirected graph).
    for (int i = 0; i < edges; i++) {
        int origin = ways[i].first.first;
        int destination = ways[i].first.second;
        int weight = ways[i].second;
        adjacencyList[origin].push_back({weight, destination});
        adjacencyList[destination].push_back({weight, origin});
    }
}

long long int HelpStudents::firstStudent() {
    // just a standard dijkstra implementation
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, 1});
    distances[1] = 0;
    notFinal[1] = false;
    while (!pq.empty()) {
        int thisNode = pq.top().second;
        notFinal[thisNode] = false;
        pq.pop();

        vector<edge>::iterator i;
        for (i = adjacencyList[thisNode].begin(); i != adjacencyList[thisNode].end(); i++) {
            int neighbor = i->second;
            int weight = i->first;

            if (notFinal[neighbor] && distances[neighbor] > distances[thisNode] + weight) {
                distances[neighbor] = distances[thisNode] + weight;
                pq.push({distances[neighbor], neighbor});
            }
            if (!notFinal[target]) {
                goto finish;
            }
        }
    }
    finish:
    if(distances[target] == 1e14) return -1;
    return distances[target];
}

long long int HelpStudents::secondStudent() {
    // used the dijkstra implementation in the 1st type but distance to each node is the max edge weight on the path
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, 1});
    distances[1] = -1;
    notFinal[1] = false;
    while (!pq.empty()) {
        int thisNode = pq.top().second;
        notFinal[thisNode] = false;
        pq.pop();
        int max = -1;
        vector<edge>::iterator i;
        for (i = adjacencyList[thisNode].begin(); i != adjacencyList[thisNode].end(); i++) {
            int neighbor = i->second;
            int weight = i->first;
            if (weight > max) max = weight;
            if (notFinal[neighbor] && max > distances[neighbor]) {
                distances[neighbor] = max;
                pq.push({distances[neighbor], neighbor});
            }
            if (!notFinal[target]) {
                goto finish;
            }
        }
    }
    finish:
    if(distances[target] == 1e14) return -1;
    return distances[target];
}

long long int HelpStudents::thirdStudent() {
    // used the dijkstra implementation in the 1st type but every edge has weight 1
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, 1});
    distances[1] = 0;
    notFinal[1] = false;
    while (!pq.empty()) {
        int thisNode = pq.top().second;
        notFinal[thisNode] = false;
        pq.pop();

        vector<edge>::iterator i;
        for (i = adjacencyList[thisNode].begin(); i != adjacencyList[thisNode].end(); i++) {
            int neighbor = i->second;
            int weight = 1;

            if (notFinal[neighbor] && distances[neighbor] > distances[thisNode] + weight) {
                distances[neighbor] = distances[thisNode] + weight;
                pq.push({distances[neighbor], neighbor});
            }
            if (!notFinal[target]) {
                goto finish;
            }
        }
    }
    finish:
    if(distances[target] == 1e14) return -1;
    return distances[target];
}

long long int HelpStudents::fourthStudent() {
    long long lowest = MAX;
    int currentNode = 1;
    adjlistrow* currentRow = &adjacencyList[1];
    int nextNode = -1;
    int sum = 0;
    int remove = -1;
    int reverseRemove = -1;
    while (currentNode != target) {
        adjlistrow::iterator i;
        for (i = currentRow->begin(); i != currentRow->end(); i++) {
            if (i->second == reverseRemove) {
                i->first = 2*MAX;
            }
            if (i->first < lowest) {
                lowest = i->first;
                nextNode = i->second;
                remove = i - currentRow->begin();
            }
        }
        if (currentNode == nextNode) break;
        sum += lowest;
        auto deleteit = currentRow->begin() + remove;
        deleteit->first = 2*MAX;
        reverseRemove = currentNode;
        currentNode = nextNode;
        currentRow = &adjacencyList[currentNode];
        lowest = MAX;
    }

    if (currentNode != target) return -1;
    return sum;
}

long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS