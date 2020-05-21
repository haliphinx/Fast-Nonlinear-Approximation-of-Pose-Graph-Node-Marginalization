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
		UpdateScaleFactor();
		// cout<<"MarginalizeNode"<<endl;
		vector<Edge*> tEdges = tTop->GetAllEdges();
		for(auto eg:tEdges){
			eg->SetMean((eg->GetPoints().first->GetPose().inv())*(eg->GetPoints().second->GetPose()));
			// cv::Mat adMatrix = cv::determinant(eg->GetMean().inv())*(eg->GetMean());	
			cv::Mat adMatrix = (cv::Mat_<float>(3,3)<<1,0,0,0,2,0,0,0,1);
			cv::Mat mCov = adMatrix*(eg->GetPoints().first->GetCov())*(adMatrix.t())+(eg->GetPoints().second->GetCov());
			cout<<mCov<<endl;
		}
		
	}

	void Topology::UpdateScaleFactor(){
		//TODO
		for(auto item:eStore){
			scaleMap[item] = 1;
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

	cv::Mat Topology::CalculateMarginalCov(Edge* cEdge){
		// TODO
		return cEdge->GetMean();
	}
}