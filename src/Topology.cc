#include"Topology.h"

using namespace std;

namespace FNA{
	Topology::Topology(){

	}

	void Topology::AddEdge(Edge* newEdge){
		eStore.insert(newEdge);
	}

	void Topology::AddNode(Node* newNode){
		nStore.insert(newNode);
	}

	void Topology::MarginalizeNode(Node* mNode, Topology* tTop){
		UpdateScaleFactor(tTop);
		vector<Edge*> tEdges = tTop->GetAllEdges();
		for(auto eg:tEdges){
			eg->SetMean((eg->GetPoints().first->GetPose().inv())*(eg->GetPoints().second->GetPose()));
			// cv::Mat adMatrix = cv::determinant(eg->GetMean().inv())*(eg->GetMean());	
			cv::Mat adMatrix = (cv::Mat_<float>(3,3)<<1,0,0,0,2,0,0,0,1);
			cv::Mat mCov = adMatrix*(eg->GetPoints().first->GetCov())*(adMatrix.t())+(eg->GetPoints().second->GetCov());
			// cout<<mCov<<endl;
		}
		
	}

	void Topology::UpdateScaleFactor(Topology* tTop){

		//construct the degree matrix and the adjacency matrix
		vector<vector<int>> degVec (nStore.size()-1, vector<int>(nStore.size()-1,0));
		vector<vector<int>> adjVec (nStore.size()-1, vector<int>(nStore.size()-1,0));
		
		for(auto eg:tTop->GetAllEdges()){
			int fIdx = eg->GetPoints().first->GetIdx()-1;
			int sIdx = eg->GetPoints().second->GetIdx()-1;
			degVec[fIdx][fIdx]++;
			degVec[sIdx][sIdx]++;
			adjVec[fIdx][sIdx] = 1;
			adjVec[sIdx][fIdx] = 1;
		}
		
		//Total number of spinning trees
		int totalTree = CalSpinningTreeNum(degVec, adjVec);
		

		for(auto eg:tTop->GetAllEdges()){
			int fIdx = eg->GetPoints().first->GetIdx()-1;
			int sIdx = eg->GetPoints().second->GetIdx()-1;
			degVec[fIdx][fIdx]--;
			degVec[sIdx][sIdx]--;
			adjVec[fIdx][sIdx] = 0;
			adjVec[sIdx][fIdx] = 0;

			//The number of spinning trees without the edge
			int exceptEg = CalSpinningTreeNum(degVec, adjVec);
			tTop->SetScaleFactor(eg, totalTree/(totalTree-exceptEg));
			degVec[fIdx][fIdx]++;
			degVec[sIdx][sIdx]++;
			adjVec[fIdx][sIdx] = 1;
			adjVec[sIdx][fIdx] = 1;
		}
	}

	void Topology::DeleteEdge(Edge* newEdge){
		eStore.erase(newEdge);
	}

	void Topology::DeleteNode(Node* newNode){
		nStore.erase(newNode);
	}

	std::vector<Node*> Topology::GetAllNodes(){
		return std::vector<Node*>(nStore.begin(),nStore.end());
	}

	std::vector<Edge*> Topology::GetAllEdges(){
		return std::vector<Edge*>(eStore.begin(),eStore.end());
	}

	float Topology::GetScaleFactor(Edge* gEdge){
		return scaleMap[gEdge];
	}

	void Topology::SetScaleFactor(Edge* gEdge, float nScale){
		scaleMap[gEdge] = nScale;
	}

	cv::Mat Topology::CalculateMarginalCov(Edge* cEdge){
		// TODO
		return cEdge->GetMean();
	}

	void Topology::vector2mat(vector<vector<int>> vec, cv::Mat& vMat){
		cv::Mat temp(vec.size()-1,vec.at(0).size()-1,5);
		for(int i=0; i<temp.rows; ++i)
			for(int j=0; j<temp.cols; ++j)
				temp.at<float>(i, j) = vec.at(i).at(j);
		temp.copyTo(vMat);
	}

	int Topology::CalSpinningTreeNum(vector<vector<int>> dVec, vector<vector<int>> aVec){
		cv::Mat degMatrix;
		vector2mat(dVec,degMatrix);

		cv::Mat adjMatrix;
		vector2mat(aVec, adjMatrix);
		cv::Mat temp = degMatrix-adjMatrix;
		return cv::determinant(temp);
	}
}