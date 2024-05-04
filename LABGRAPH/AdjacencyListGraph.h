// AdjacencyListGraph.h

#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H

#include "DirectedGraph.h"
#include "AdjacencyListVertex.h"
#include <vector>
#include <algorithm>

class AdjacencyListGraph : public DirectedGraph {
protected:
    std::vector<AdjacencyListVertex*> vertices;
   
public:    
    virtual ~AdjacencyListGraph() {
        for (AdjacencyListVertex* vertex : vertices) {
            delete vertex;
        }
    }

    // Creates and adds a new vertex to the graph
    virtual Vertex* AddVertex(std::string newVertexLabel) override {
        if (GetVertex(newVertexLabel)) {
            return nullptr; // Vertex already exists
        }
        AdjacencyListVertex* newVertex = new AdjacencyListVertex(newVertexLabel);
        vertices.push_back(newVertex);
        return newVertex;
    }
    
    // Adds a directed edge from the first to the second vertex
    virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
        AdjacencyListVertex* from = dynamic_cast<AdjacencyListVertex*>(fromVertex);
        if (!from || !toVertex || HasEdge(fromVertex, toVertex)) {
            return false; // Invalid vertex or edge already exists
        }
        from->adjacent.push_back(toVertex);
        return true;
    }
    
    // Returns a vector of edges with the specified fromVertex
    virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
        std::vector<Edge> edges;
        AdjacencyListVertex* from = dynamic_cast<AdjacencyListVertex*>(fromVertex);
        if (from) {
            for (Vertex* to : from->adjacent) {
                edges.push_back(Edge(from, to));
            }
        }
        return edges;
    }
    
    // Returns a vector of edges with the specified toVertex
    virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
        std::vector<Edge> edges;
        for (AdjacencyListVertex* from : vertices) {
            if (std::find(from->adjacent.begin(), from->adjacent.end(), toVertex) != from->adjacent.end()) {
                edges.push_back(Edge(from, toVertex));
            }
        }
        return edges;
    }
    
    // Returns a vertex with a matching label
    virtual Vertex* GetVertex(std::string vertexLabel) override {
        for (AdjacencyListVertex* vertex : vertices) {
            if (vertex->GetLabel() == vertexLabel) {
                return vertex;
            }
        }
        return nullptr;
    }
    
    // Returns true if this graph has an edge from fromVertex to toVertex
    virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
        AdjacencyListVertex* from = dynamic_cast<AdjacencyListVertex*>(fromVertex);
        return from && std::find(from->adjacent.begin(), from->adjacent.end(), toVertex) != from->adjacent.end();
    }
};

#endif
