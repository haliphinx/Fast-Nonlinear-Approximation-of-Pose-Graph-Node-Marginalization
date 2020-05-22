#ifndef NODE_H
#define NODE_H

#include<opencv2/core/core.hpp>
#include<math.h>

namespace FNA{
	class Node{
	public:
		Node(int cIdx, cv::Mat cPose, cv::Mat cov);

		// Return the SE(2) fo Node
		cv::Mat GetPose();

		// Set the SE(2) fo Node
		void SetPose(cv::Mat &newPose);

		//Get the Node index
		int GetIdx();

		//Set the Node index
		void SetIdx(int newIdx);

		//Set the convariance of Node (equals to the convariance of Z0i)
		void SetCov(cv::Mat &newCov);

		//Get the convariance of Node
		cv::Mat GetCov();
	private:
		//SE(2) of Node
		cv::Mat pose;

		//Node index
		int idx;

		//Node pose convariance
		cv::Mat covariance;
	};
}

#endif