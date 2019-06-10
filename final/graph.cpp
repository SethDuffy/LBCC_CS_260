#include <iostream>


using std::cout;
using std::cin;
using std::endl;

void addPath(int (&graph)[5][5],int node1, int node2, int weight) {

    graph[node1][node2] = weight;
    graph[node2][node1] = weight;

}

void displayGraph(int (&graph)[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(graph[i][j] != 0) {
                cout << i+1 << " to " << j+1 << " has a weight " << graph[i][j] << endl;
            }
        }
    }
}
// from node 1 to node 2
void shortestPath(int (&arr)[5][5], int node1, int node2) {
    int graph[5][5];
    int leastVal = 0;
    int currNode = node1;
    int nextNode = 0;
    int visited[5] = {0};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            graph[i][j] = arr[i][j];
        }
    }
    while(currNode != node2){
        for(int i = 0; i < 5; i++) {
            if(graph[currNode][i] != 0 && visited[i] == 0){
                if(leastVal == 0) {
                    leastVal = graph[currNode][i];
                    nextNode = i;
                } 
                else if(graph[currNode][i] < leastVal) {
                    leastVal = graph[currNode][i];
                    nextNode = i;
                }
            }
        }

        visited[currNode] = 1;
        graph[currNode][nextNode] = 0;
        graph[nextNode][currNode] = 0;
        cout << "We went from " << currNode+1 << " to " << nextNode+1 << endl;
        currNode = nextNode;
        leastVal = 0;
    }
}




int main(void) {
    int graph[5][5] = {0};
    
    addPath(graph, 0, 1, 2);
    addPath(graph, 0, 4, 1);
    addPath(graph, 1, 2, 5);
    addPath(graph, 1, 3, 1);
    addPath(graph, 1, 4, 4);
    addPath(graph, 2, 3, 7);
    addPath(graph, 3, 4, 3);

    // shortestPath(graph, 0, 3);
    // shortestPath(graph, 0, 2);
    shortestPath(graph, 3, 0);

    // displayGraph(graph);



    // displayGraph(graph);
    return 0;
}