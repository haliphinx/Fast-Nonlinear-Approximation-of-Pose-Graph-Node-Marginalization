#include"Nam.h"

namespace FNA{
	Nam::Nam(Topology* nTopology):nTop(nTopology){

	}

	void Nam::StoreTopologyGraph(Topology* top, std::string path){
		//TODO
	}

	void Nam::MarginalizeNode(Node* mNode, Topology* tTop){
		nTop->MarginalizeNode(mNode, tTop);
	}
}