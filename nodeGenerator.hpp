#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class nodeGenerator
{
    public:
    int numNodes;
    int numEdges;

    nodeGenerator(std::string fname){
        std::fstream ifstream;
        ifstream.open(fname);
        ifstream>>numNodes;
        ifstream>>numEdges;
        std::cout<<numNodes<<std::endl;


    }

};
