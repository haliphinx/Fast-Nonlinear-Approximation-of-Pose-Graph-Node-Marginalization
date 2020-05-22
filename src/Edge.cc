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
		// std::cout<<newMean<<std::endl;
		newMean.copyTo(mean);
		// mean = (cv::Mat_<float>(3,3)<<0,-1,0,1,0,1,0,0,1);
		CalADMatrix();
	}

	void Edge::SetConvariance(cv::Mat newConvariance){
		newConvariance.copyTo(covariance);
	}

	void Edge::CalADMatrix(){
		//TODO
		cv::Mat temp = cv::Mat::eye(3, 3, mean.type());
		cv::Mat invMean = mean.inv();
		// std::cout<<invMean<<std::endl;
		temp.at<float>(0,0) = invMean.at<float>(0,0);
		temp.at<float>(0,1) = invMean.at<float>(0,1);
		temp.at<float>(1,0) = invMean.at<float>(1,0);
		temp.at<float>(1,1) = invMean.at<float>(1,1);

		temp.at<float>(0,2) = invMean.at<float>(1,2);
		temp.at<float>(1,2) = -invMean.at<float>(0,2);

		// std::cout<<temp<<std::endl;
		adMatrix = temp.clone();
	}

	std::pair<Node*,Node*> Edge::GetPoints(){
		return endpoints;
	}

	cv::Mat Edge::GetADMat(){
		return adMatrix.clone();
	}
}