#include <iostream>
#include <limits.h>
using namespace std;

bool negative = true;

struct Edge{
    int source, destination, weight;
};

struct Graph{

    int numberVertex, numberEdges;
    struct Edge* edge;
};

struct Graph* createGraph(int numberVertex, int numberEdges){
    
    struct Graph* graph = new Graph;
    
    graph->numberVertex = numberVertex;
    graph->numberEdges = numberEdges;
    graph->edge = new Edge[numberEdges];
    
    return graph;
}

void printBelmanFord(int dist[], int n){
    
    if(negative == true){
    cout << "TRUE" << endl;
    for (int i = 0; i < n; ++i){
        if(dist[i] == INT_MAX){
          cout << "INFINITY" << endl;
        }
        else
          cout << dist[i] << endl;
        }
    }
}

void bellmanFord(struct Graph* graph, int source){

    int numberVertex = graph->numberVertex;
    int numberEdges = graph->numberEdges;
    int dist[numberVertex];

    for (int i = 0; i < numberVertex; i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 1; i <= numberVertex-1; i++){
        for (int j = 0; j < numberEdges; j++){
            
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < numberEdges; i++){
        
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
          cout << "FALSE" << endl;
          negative = false;
          return;
        }
    }

    printBelmanFord(dist, numberVertex);
}


int main(){
    
    int numberVertex;
    int numberEdges;
    int tmpVertex, tmpEdge, weight;
    
    cin >> numberVertex;
    cin >> numberEdges;

    struct Graph* graph = createGraph(numberVertex, numberEdges);

    for(int x = 0; x < numberEdges; x++){
        
      cin >> tmpVertex;
      cin >> tmpEdge;
      cin >> weight;
        
      graph->edge[x].source = tmpVertex;
      graph->edge[x].destination = tmpEdge;
      graph->edge[x].weight = weight;
    }

    bellmanFord(graph, 0);

    return 0;
}
