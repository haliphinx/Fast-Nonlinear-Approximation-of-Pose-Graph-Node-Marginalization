#ifndef EDGE_H
#define EDGE_H

#include<opencv2/core/core.hpp>
#include"Node.h"

namespace FNA{
	class Node;
	class Edge{
	public:
		Edge(Node* firstNode, Node* secondNode);

		//Get the SE(2) of the edge
		cv::Mat GetMean();

		//Get the convariance of the edge
		cv::Mat GetConvariance();

		//Set the SE(2) of edge
		void SetMean(cv::Mat newMean);

		//Set the convariance
		void SetConvariance(cv::Mat newConvariance);

		//Return the pointers of the endpoints of the edge
		std::pair<Node*,Node*> GetPoints();
	private:
		//Calculate the adjoint map matrix 
		void CalADMatrix();

		//The pointers of the endpoints of the edge
		std::pair<Node*,Node*> endpoints;

		//SE(2)
		cv::Mat mean;

		cv::Mat covariance;

		//The adjoint map matrix
		cv::Mat adMatrix;
	};
}

#endif