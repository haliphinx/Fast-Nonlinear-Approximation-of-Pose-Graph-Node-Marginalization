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
		void SetScaleFactor(Edge* gEdge, float nScale);
		
		//Calculate the marginal covariance
		cv::Mat CalculateMarginalCov(Edge* cEdge);
	private:
		//Calculate the scale factor beta for each edge
		void UpdateScaleFactor(Topology* tTop);

		//Convert vector to mat for UpdateScaleFactor function
		void vector2mat(std::vector<std::vector<int>> vec, cv::Mat& vMat);

		//Count the number of spinning tree following the Kirchoff theorem
		int CalSpinningTreeNum(std::vector<std::vector<int>> dVec, std::vector<std::vector<int>> aVec);
		std::unordered_set<Node*> nStore;
		std::unordered_set<Edge*> eStore;
		std::unordered_map<Edge*, float> scaleMap;

	};
}

#endif