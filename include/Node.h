#ifndef NODE_H
#define NODE_H

#include<opencv2/core/core.hpp>
#include<math.h>

namespace FNA{
	class Node{
	public:
		Node(int cIdx, cv::Mat cPose, cv::Mat cov);
		cv::Mat GetPose();
		void SetPose(cv::Mat &newPose);
		int GetIdx();
		void SetIdx(int newIdx);
		void SetCov(cv::Mat &newCov);
		cv::Mat GetCov();
	private:
		cv::Mat pose;
		int idx;
		cv::Mat covariance;
	};
}

#endif