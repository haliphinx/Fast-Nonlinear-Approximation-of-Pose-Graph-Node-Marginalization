#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include<opencv2/core/core.hpp>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include"Node.h"
#include"Edge.h"

namespace FNA{
	class Node;
	class Edge;
	class Topology{
	public:
		Topology();
		void AddEdge(Edge* newEdge);
		void AddNode(Node* newNode);
		void MarginalizeNode(Node* mNode, Topology* tTop);
		void DeleteEdge(Edge* newEdge);
		void DeleteNode(Node* newNode);
		std::vector<Node*> GetAllNodes();
		std::vector<Edge*> GetAllEdges();
		float GetScaleFactor(Edge* gEdge);
		cv::Mat CalculateMarginalCov(Edge* cEdge);
	private:
		void UpdateScaleFactor();
		std::unordered_set<Node*> nStore;
		std::unordered_set<Edge*> eStore;
		std::unordered_map<Edge*, float> scaleMap;
		
	};
}

#endif