#include <iostream>


using std::cout;
using std::cin;
using std::endl;

void addPath(int (&graph)[5][5],int node1, int node2, int weight) {
    //Adds path to graph for both possible variations of the path
    graph[node1][node2] = weight;
    graph[node2][node1] = weight;

}
//displays graph
void displayGraph(int (&graph)[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(graph[i][j] != 0) {
                cout << i+1 << " to " << j+1 << " has a weight " << graph[i][j] << endl;
            }
        }
    }
}
// from node 1 to node 2 shoutouts to Dijkstra
void shortestPath(int (&arr)[5][5], int node1, int node2) {
    int graph[5][5];
    int leastVal = 0;
    int currNode = node1;
    int nextNode = 0;
    int visited[5] = {0};

    cout << "The Shortest Path Using Dijkstra's Algorithm is as Follows" << endl;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            graph[i][j] = arr[i][j];
        }
    }
    //if not at the end
    while(currNode != node2){
        //iterate throughout the current node that you're on
        for(int i = 0; i < 5; i++) {
            //check to see if the path exists and the next node hasn't been visited
            if(graph[currNode][i] != 0 && visited[i] == 0){
                //check for a least value
                if(leastVal == 0) {
                    leastVal = graph[currNode][i];
                    nextNode = i;
                } //actual check for smallest weight
                else if(graph[currNode][i] < leastVal) {
                    leastVal = graph[currNode][i];
                    nextNode = i;
                }
            }
        }
        //update values
        visited[currNode] = 1;
        //delete path for future
        graph[currNode][nextNode] = 0;
        graph[nextNode][currNode] = 0;
        cout << "We went from " << currNode+1 << " to " << nextNode+1 << endl;
        currNode = nextNode;
        leastVal = 0;
    }
}


void minimumSpanningTree(int (&arr)[5][5], int start) {
    int graph[5][5];
    bool done = false;
    int visited[5] = {0};
    visited[start] = 1;

    int leastVal = 0, leastValNode = 0;
    int currNode = start, nextNode = 0;
    // int temp = 0;

    cout << "The Minimal Spanning Tree is as Follows" << endl;

    //copy the array to delete paths without problem
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {
            graph[i][j] = arr[i][j];
        }
    }
    while(!done) {
        //iterate through all paths a single node has
        for(int i = 0; i < 5; i++) {
            //checks for the current nodes path to not be zero and that the node that you're visiting is zero
            //and that the curernt node that you are at is not equalt to zero
            if(graph[currNode][i] != 0 && visited[i] == 0 && visited[currNode] != 0){
                //check for a least value to be found at all
                if(leastVal == 0) {
                    leastVal = graph[currNode][i];
                    leastValNode = currNode;
                    nextNode = i;
                } 
                else if(graph[currNode][i] < leastVal) {
                    leastVal = graph[currNode][i];
                    leastValNode = currNode;
                    nextNode = i;
                }
            }
        }
        // temp = currNode;
        // cout << currNode;
        if(currNode >= 4) {
            graph[leastValNode][nextNode] = 0;
            graph[nextNode][leastValNode] = 0;

            visited[nextNode] = 1;

            cout << "We went from " << leastValNode+1 << " to " << nextNode+1 << endl;

            leastValNode = 0;
            nextNode = 0;
            leastVal = 0;
            currNode = 0;
        }
        else {
            currNode++;
        }


        // Old Jank Code
        // else {
        //     temp++;
        //     while(visited[temp] != 1 && temp < 4) {
        //         temp++;
        //     }
        //     currNode = temp;
        //     temp = 0;
        // }
        // // currNode++;
        done = true;
        for(int j = 0; j < 5; j++){
            if(visited[j] == 0){
                done = false;
            }
        }
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
    //minimumSpanningTree(graph, 2);
    //minimumSpanningTree(graph, 0);
    minimumSpanningTree(graph, 2);

    // displayGraph(graph);



    // displayGraph(graph);
    return 0;
}