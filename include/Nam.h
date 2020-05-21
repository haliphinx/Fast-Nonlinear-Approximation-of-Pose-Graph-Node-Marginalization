#ifndef NAM_H
#define NAM_H

#include<opencv2/core/core.hpp>
#include"Node.h"
#include"Edge.h"
#include"Topology.h"

namespace FNA{
	class Node;
	class Edge;
	class Topology;
	class Nam{
	public:
		Nam(Topology* nTopology);
		void StoreTopologyGraph(Topology* top, std::string path);
		void MarginalizeNode(Node* mNode, Topology* tTop);
	private:
		Topology* nTop;
	};
}

#endif