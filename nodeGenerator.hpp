

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Node.hpp"
class nodeGenerator
{
    public:
    int numNodes;
    int numEdges;
    std::string sNode;
    std::string eNode;

    nodeGenerator(std::string fname, std::vector<Node> &nodes, std::string &start, std::string &end){

        std::fstream ifstream;
        ifstream.open(fname);
        ifstream>>numNodes;
        ifstream>>numEdges;

        ifstream>>start;
        ifstream>>end;
        std::string tmp;
        std::string tmp2;
        std::string tmp3;
        std::string tmp4;


        while(ifstream>>tmp){
            ifstream>>tmp2;
            ifstream>>tmp3;
            ifstream>>tmp4;
            Node n(tmp,tmp2,tmp3,tmp4);
            nodes.push_back(n);
            Node n2(tmp2,tmp,tmp3,tmp4);
            nodes.push_back(n2);
        }
    }

};
