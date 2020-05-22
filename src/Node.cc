#include"Node.h"

namespace FNA{
	Node::Node(int cIdx, cv::Mat cPose, cv::Mat cov):idx(cIdx), covariance(cov){
		//Convert the pose into SE(2)
		float x = cPose.at<float>(0,0);
		float y = cPose.at<float>(1,0);
		float angle = cPose.at<float>(2,0);
		pose = (cv::Mat_<float>(3,3)<<cos(angle),-sin(angle),x,sin(angle),cos(angle),y,0,0,1);
	}

	cv::Mat Node::GetPose(){
		return pose.clone();
	}

	cv::Mat Node::GetCov(){
		return covariance.clone();
	}

	void Node::SetPose(cv::Mat &newPose){
		newPose.copyTo(pose);
	}

	int Node::GetIdx(){
		return idx;
	}

	void Node::SetIdx(int newIdx){
		idx = newIdx;
	}
}