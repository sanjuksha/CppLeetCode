/**
 * @file GraphBfsDfs.cpp
 * @author Sanjuksha Nirgude
 * @brief These are generic representation of BFS and DFS
 * traversal of a simple graph in C++. This is not a LeetCode problem.
 * @date 2024-02-07
 * 
 */

#include <iostream>
#include <list>
#include <vector>

class Graph
{
public:

    Graph(int vertices);

    //Add an edge to the graph
    void addEdge(int v, int w);

    //Print the BFS traversal of the graph
    void printGraphBFS(int startVertex);

    //DFS helper function
    void DFS(int startVertex, std::vector<bool>& visited);

    //Print the DFS traversal of the graph
    void printGraphDFS(int startVertex);

private:
    int m_vertices;
    std::vector<std::list<int>> adjList;
};

Graph::Graph(int vertices)
:m_vertices(vertices)
{
    adjList.resize(vertices);
}

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
}

void Graph::printGraphBFS(int startVertex)
{
    // Create a queue for BFS
    std::list<int> queue;
    // Create a bool vector to track visited vertices
    std::vector<bool> visited(m_vertices, false);

    // Mark the origin vertex as visited and enqueue it
    visited[startVertex] = true;
    queue.push_back(startVertex);

    while(!queue.empty())
    {
        // Dequeue the first vertex from the queue and print it- 
        // remember after the first iteration the queue will have its neighbors in it
        // therefore pop front
        startVertex = queue.front();
        std::cout<<startVertex<<" -> ";
        // Remove from queue as we already processed it
        queue.pop_front();

        //Get all the neighbors of the current vertex from the adjacency list
        // If an adjacent vertex has not been visited, mark it visited
        for(auto& neighbor : adjList[startVertex])
        {
            if (!visited[neighbor])
            {
                queue.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }

}

void Graph::DFS(int startVertex, std::vector<bool>& visited)
{
    // Mark the current vertex as visited and print it
    visited[startVertex] = true;
    std::cout<<startVertex<<" -> ";

    // Recur for all adjacent vertices of the current vertex
    for(const auto& neighbor : adjList[startVertex])
    {
        if(!visited[neighbor])
        {
            DFS(neighbor, visited);
        }
    }
}


void Graph::printGraphDFS(int startVertex)
{
    // Create a boolean array to track visited vertices
    std::vector<bool> visited(m_vertices, false);
    // Call the recursive DFS function
    DFS(startVertex, visited);
   

}


//Implementation example

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Breadth First Traversal (starting from vertex 2): ";
    g.printGraphBFS(0);
    std::cout<<std::endl;
    std::cout << "Depth First Traversal (starting from vertex 2): ";
    g.printGraphDFS(0);

    return 0;


}

