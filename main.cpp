#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "nodeGenerator.hpp"
#include "Node.hpp"
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool vector_string_less(const vector<string>& a, const vector<string>& b)
{
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

int main(int argc, char* argv[])
{

    std::vector<Node> nodes;
    std::string start;
    std::string end;
    nodeGenerator nodeGen(argv[1],nodes,start,end);
  
   
    unordered_map<string,unordered_set<Node*>> nodeLetterBins;
    for(Node &n:nodes){
        nodeLetterBins[n.from].insert(&n);
    }
    Node startNode(start,start,"","");
    Node endNode(end,end,"","");
    for(Node &n:nodes){

        if(n.from==start){
            startNode.aList.insert(&n);
        }
        if(n.to==end){
            n.aList.insert(&endNode);
        }
        for(Node *n2:nodeLetterBins[n.to]){

            if(n2->color==n.color||n2->type==n.type){
                if(!(n2->from==n.to&&n2->to==n.from&&n2->color==n.color&&n2->type==n.type)){
                n.aList.insert(n2);
                }

            }
           
        }
         
    }
    nodes.push_back(startNode);
  
    //time for bfs
    queue<Node*> q;
 
    q.push(&startNode);
    while(!q.empty()){
        Node *n=q.front();
        q.pop();
        
        n->visited=true;
        for(Node *n2:n->aList){
            if(n2->to==end&&n2!=&endNode){
                endNode.parents.insert(n2);
                
            }
            if(!n2->visited){
                n2->parent=n;
                n2->prev=n->from;
                q.push(n2);
            }
        }
    }
  
    if(endNode.parents.size()==0){
        cout<<"NO PATH"<<endl;
    }
    
    
    
      
        vector<vector<string>> s;
        for(Node *iPar:endNode.parents){
            vector<Node*> tmpn;
            tmpn.push_back(iPar);
            tmpn.push_back(&endNode);
            vector<string> tmp;
          
            while(tmpn.back()->parent!=&startNode){
                tmpn.push_back(tmpn.back()->parent);
                tmp.push_back(tmpn.back()->from);
            }
            s.push_back(tmp);
        }
        for(vector<string> &i:s){
            reverse(i.begin(),i.end());
        }
        auto minmin= min_element(s.begin(),s.end(),vector_string_less);
        for (const auto& str : *minmin) {
            std::cout << str << " ";
            }
            std::cout << endNode.to<<" ";
       
      
    
}