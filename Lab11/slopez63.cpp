
#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Graph{
    
        int count;
        stack<int> Stack;
        list<int> *listofNumbers;
    
public:
    
    vector<int> *finalNumbers;
    
    Graph(int n){
        this->count = n;
        listofNumbers = new list<int>[n];
        finalNumbers = new vector<int> (n, 0);
    }
    
    void newEdge(int count, int number){
        listofNumbers[count].push_back(number);
    }
    
    
    void DFS(int count, bool visitedNodes[], vector<int> &temp){
    
        visitedNodes[count] = true;
        
        if (temp.empty()){
            temp.push_back(count);
        } else {
            bool black = false;
            for (int i = 0; i < temp.size(); i++){
                if (count <= temp.at(i)){
                    black = true;
                    temp.insert(temp.begin() + i, count);
                    i++;
                }
            }
            
            if (!black){
                temp.push_back(count);
            }
        }
        
        
            for (list<int>::iterator i = listofNumbers[count].begin(); i != listofNumbers[count].end(); ++i){
                if (!visitedNodes[*i]){
                    DFS(*i, visitedNodes, temp);
                }
            }
    
    }

    
    
    Graph transpose(){
        Graph transposedGraph(count);
        for (int i = 0; i < count; i++){
            for(list<int>::iterator j = listofNumbers[i].begin(); j != listofNumbers[i].end(); ++j){
                transposedGraph.listofNumbers[*j].push_back(i);
            }
        }
        return transposedGraph;
    }

    

    void organizeNodes(int count, bool visitedNodes[], stack<int> &Stack){
        visitedNodes[count] = true;
    
        list<int>::iterator i;
        for(list<int>::iterator i = listofNumbers[count].begin(); i != listofNumbers[count].end(); i++){
            if(!visitedNodes[*i]){
                organizeNodes(*i, visitedNodes, Stack);
            }
        }
    
        Stack.push(count);
    }
    
    

    void StronglyConnectedComponents(){
        
        bool *visitedNodes = new bool[count];
        
        for(int i = 0; i < count; i++){
            visitedNodes[i] = false;
        }
        
        for(int i = 0; i < count; i++){
            if(visitedNodes[i] == false){
                organizeNodes(i, visitedNodes, Stack);
            }
        }
        
        Graph transposedGraph = transpose();
        
        for(int i = 0; i < count; i++){
            visitedNodes[i] = false;
        }
        
        while (Stack.empty() == false){
            int count = Stack.top();
            
            Stack.pop();
            
            vector<int> *temp = new vector<int>;
            
            if (visitedNodes[count] == false){
                transposedGraph.DFS(count, visitedNodes, *temp);
                
                int leastN = temp->at(0);
                
                for (int i = 0; i < temp->size(); i++){
                    finalNumbers->at(temp->at(i)) = leastN;
                }
            }
        }
    }
    
    
};


void printSCC(Graph graph){
    for (int i = 0; i < graph.finalNumbers->size(); i++){
        cout << graph.finalNumbers->at(i) << endl;
    }
}


int main(int argc, char **argv){
    int verticeCount;
    int edgeCount;
    
    cin >> verticeCount;
    cin >> edgeCount;
    
    Graph graph(verticeCount);
    
    int vertice;
    int vertice2;
    
    for (int i = 0; i < edgeCount; i++){
        cin >> vertice;
        cin >> vertice2;
        
        graph.newEdge(vertice, vertice2);
    }
    
    graph.StronglyConnectedComponents();
    
    printSCC(graph);
    
    return 0;
}
