#include"Edge.h"

namespace FNA{

	Edge::Edge(Node* firstNode, Node* secondNode){
		endpoints = std::make_pair(firstNode,secondNode);
	}


	cv::Mat Edge::GetMean(){
		return mean.clone();
	}

	cv::Mat Edge::GetConvariance(){
		return covariance.clone();
	}

	void Edge::SetMean(cv::Mat newMean){
		newMean.copyTo(mean);
	}

	void Edge::SetConvariance(cv::Mat newConvariance){
		newConvariance.copyTo(covariance);
	}

	void Edge::CalADMatrix(){
		//TODO
		adMatrix = mean.clone();
	}

	std::pair<Node*,Node*> Edge::GetPoints(){
		return endpoints;
	}
}