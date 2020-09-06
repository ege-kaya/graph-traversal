#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
// weight first, then destination vertex
typedef pair<long long, int> edge;
typedef vector<edge> adjlistrow;
typedef vector<adjlistrow> adjlist;
#define MAX 1e14;

class HelpStudents{
private:
    int nodes, edges, target;
    adjlist adjacencyList;
    vector<bool> notFinal;
    vector<long long> distances;

public:
    HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();

    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
