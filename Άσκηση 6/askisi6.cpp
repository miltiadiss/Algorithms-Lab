#include<iostream>
#include<list>
#include<iterator>
#include <algorithm>
#include <vector>
using namespace std;
6
void displayGraph(list<int> graph[], int v) // display 
the Graph
{
 for(int i = 1; i<v; i++) {
 cout << i << "--->";
 list<int> :: iterator it;
 for(it = graph[i].begin(); it != graph[i].end(); 
++it) {
 cout << *it << " ";
 }
 cout << endl;
 }
}
void insert_edge(list<int> graph[], int u, int v) //add 
vertices (u v), (v u)
{
 graph[u].push_back(v);
}
void create_arrays(int v, list<int> graph[])
{
 vector<int> graphOutEdges;
 vector<int> nodeOutEdges;
 list<int> :: iterator it;
 int i;
 int j = 0;
 nodeOutEdges.push_back(-1);
 while(i<v)
 {
 for(i=1; i<v; i++)
 {
 nodeOutEdges.push_back(j);
 for(it = graph[i].begin(); it != 
graph[i].end(); ++it) graphOutEdges.push_back(*it);
 j=graphOutEdges.size();
 }
 }
 nodeOutEdges[0]=j-1;
 cout << "\nnodeOutEdges : ";
 for (i = 0; i < nodeOutEdges.size(); i++) cout << 
nodeOutEdges[i] << " ";
 cout << "\ngraphOutEdges : ";
 for (i = 0; i < graphOutEdges.size(); i++) cout << 
graphOutEdges[i] << " ";
}
main(int argc, char* argv[])
{
 int v = 9; //number of vertices in graph +1
 //create an array of lists whose size is v
 list<int> graph[v];
 insert_edge(graph, 1, 2);
 insert_edge(graph, 1, 3);
 insert_edge(graph, 1, 4);
 insert_edge(graph, 1, 5);
 insert_edge(graph, 2, 3);
 insert_edge(graph, 3, 1);
 insert_edge(graph, 3, 5);
 insert_edge(graph, 4, 5);
 insert_edge(graph, 5, 2);
 insert_edge(graph, 6, 7);
 insert_edge(graph, 7, 8);
 insert_edge(graph, 8, 6);
 insert_edge(graph, 8, 7);
 displayGraph(graph, v);
 create_arrays(v,graph);
}
