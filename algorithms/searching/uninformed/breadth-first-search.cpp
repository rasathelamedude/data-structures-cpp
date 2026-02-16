/**
 * 
 * Breadth First Search is a search algorithm that starts at the root node and explores all the neighbor nodes at the current depth before moving on to the node at the next depth level. 
 * It's an uninformed search algorithm, meaning it doesn't make any assumptions about the structure of the graph and is unaware of it.
 * It uses a queue to keep track of the nodes to be visited, and it is best suited for unweighted graphs. 
 * 
 * Time Complexity: O(V+E)
 * 
 * Space Complexity: O(V)
 * 
 * 
 * BFS Algorithm:
 *  1. Initialization: Start by putting any one of the graph's vertecies at the back of the queue and mark it as visited.
 *  2. Exploration: While the queue is not empty, dequeue a vertex from the queue and visit it. For each unvisited neighbor of the dequeued vertex, mark it as visited and enqueue it. 
 * 3. Termination: Repeat step two until the queue is empty.
 * 
 */

#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph {
  int numberOfVertices;
  bool *visited;
  list<int> *adjacencyList;

  public:
    Graph(int vertices);
    void addEdge(int source, int destination);
    void BFS(int start);
};

Graph::Graph(int vertices) {
  numberOfVertices = vertices;
  adjacencyList = new list<int>[vertices];
}

void Graph::addEdge(int source, int destination) {
  adjacencyList[source].push_back(destination);
  adjacencyList[destination].push_back(source);
}

void Graph::BFS(int startVertext) {
  visited = new bool[numberOfVertices];
  
  for (int i = 0; i < numberOfVertices; i++)
  {
    visited[i] = false;
  }
  
  list<int> queue;

  visited[startVertext] = true;
  queue.push_back(startVertext);

  list<int>::iterator i;
  while(!queue.empty()) {
    int currentVertex = queue.front();
    cout << "Visited " << currentVertex << " ";
    queue.pop_front();

    for (i = adjacencyList[currentVertex].begin(); i != adjacencyList[currentVertex].end(); ++i) {
      int adjacentVertex = *i;
      
      if (!visited[adjacentVertex]) {
        visited[adjacentVertex] = true;
        queue.push_back(adjacentVertex);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}