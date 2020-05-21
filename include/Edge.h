#ifndef EDGE_H
#define EDGE_H

#include<opencv2/core/core.hpp>
#include"Node.h"

namespace FNA{
	class Node;
	class Edge{
	public:
		// Edge();
		Edge(Node* firstNode, Node* secondNode);
		cv::Mat GetMean();
		cv::Mat GetConvariance();
		void SetMean(cv::Mat newMean);
		void SetConvariance(cv::Mat newConvariance);
		std::pair<Node*,Node*> GetPoints();
	private:
		void CalADMatrix();
		std::pair<Node*,Node*> endpoints;
		cv::Mat mean;
		cv::Mat covariance;
		cv::Mat adMatrix;
	};
}

#endif