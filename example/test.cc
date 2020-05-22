#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>

#include<opencv2/core/core.hpp>

#include<Topology.h>
#include<Node.h>
#define PI 3.1415926535

using namespace FNA;
using namespace std;

int main(int argc, char **argv){
	cv::Mat cov = (cv::Mat_<float>(3,3)<<2,1,0,1,2,1,0,1,2);

	Node* n0 = new Node(0,(cv::Mat_<float>(3,1)<<0,0,0), cov);
	
	Node* n1 = new Node(1,(cv::Mat_<float>(3,1)<<0,0,-PI/2), cov);
	
	Node* n2 = new Node(2,(cv::Mat_<float>(3,1)<<1,0,0), cov);
	// cout<<n2->GetPose()<<endl;

	// Edge* e01 = new Edge(n0,n1);
	// Edge* e02 = new Edge(n0,n2);
	Edge* e12 = new Edge(n1,n2);

	Topology* cTop = new Topology();
	Topology* tTop = new Topology();

	// cTop->AddEdge(e01);
	// cTop->AddEdge(e02);

	cTop->AddNode(n0);
	cTop->AddNode(n1);
	cTop->AddNode(n2);


	tTop->AddEdge(e12);
	cTop->MarginalizeNode(n0, tTop);
	
	return 0;
}