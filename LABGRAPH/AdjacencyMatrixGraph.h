// AdjacencyMatrixGraph.h

#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H

#include "DirectedGraph.h"
#include <vector>

class AdjacencyMatrixGraph : public DirectedGraph {
protected:
    std::vector<Vertex*> vertices;
    std::vector<std::vector<bool>> matrixRows;
   
public:    
    virtual ~AdjacencyMatrixGraph() {
        for (Vertex* vertex : vertices) {
            delete vertex;
        }
    }

    // Creates and adds a new vertex to the graph
    virtual Vertex* AddVertex(std::string newVertexLabel) override {
        if (GetVertex(newVertexLabel)) {
            return nullptr; // Vertex already exists
        }
        Vertex* newVertex = new Vertex(newVertexLabel);
        vertices.push_back(newVertex);
        // Resize the matrix to accommodate the new vertex
        for (auto& row : matrixRows) {
            row.push_back(false);
        }
        matrixRows.push_back(std::vector<bool>(vertices.size(), false));
        return newVertex;
    }
    
    // Adds a directed edge from the first to the second vertex
    virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
        int fromIndex = -1, toIndex = -1;
        for (size_t i = 0; i < vertices.size(); i++) {
            if (vertices[i] == fromVertex) fromIndex = i;
            if (vertices[i] == toVertex) toIndex = i;
        }
        if (fromIndex == -1 || toIndex == -1 || matrixRows[fromIndex][toIndex]) {
            return false; // Invalid vertices or edge already exists
        }
        matrixRows[fromIndex][toIndex] = true;
        return true;
    }
    
    // Returns a vector of edges with the specified fromVertex
    virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
        std::vector<Edge> edges;
        int fromIndex = -1;
        for (size_t i = 0; i < vertices.size(); i++) {
            if (vertices[i] == fromVertex) {
                fromIndex = i;
                break;
            }
        }
        if (fromIndex != -1) {
            for (size_t j = 0; j < matrixRows[fromIndex].size(); j++) {
                if (matrixRows[fromIndex][j]) {
                    edges.push_back(Edge(fromVertex, vertices[j]));
                }
            }
        }
        return edges;
    }
    
    // Returns a vector of edges with the specified toVertex
    virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
        std::vector<Edge> edges;
        int toIndex = -1;
        for (size_t i = 0; i < vertices.size(); i++) {
            if (vertices[i] == toVertex) {
                toIndex = i;
                break;
            }
        }
        if (toIndex != -1) {
            for (size_t i = 0; i < vertices.size(); i++) {
                if (matrixRows[i][toIndex]) {
                    edges.push_back(Edge(vertices[i], toVertex));
                }
            }
        }
        return edges;
    }
    
    // Returns a vertex with a matching label
    virtual Vertex* GetVertex(std::string vertexLabel) override {
        for (Vertex* vertex : vertices) {
            if (vertex->GetLabel() == vertexLabel) {
                return vertex;
            }
        }
        return nullptr;
    }
    
    // Returns true if this graph has an edge from fromVertex to toVertex
    virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
        int fromIndex = -1, toIndex = -1;
        for (size_t i = 0; i < vertices.size(); i++) {
            if (vertices[i] == fromVertex) fromIndex = i;
            if (vertices[i] == toVertex) toIndex = i;
        }
        return fromIndex != -1 && toIndex != -1 && matrixRows[fromIndex][toIndex];
    }
};

#endif
