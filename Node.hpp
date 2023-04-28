
#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <unordered_set>

struct Node
{
   std::string from;
   std::string to;
   std::string color;
   std::string type; 
   std::string prev;
   Node *parent;
   bool visited=false;
   //constructor for node
   Node(std::string fromi,std::string toi,std::string colori,std::string typei){
    from=fromi;
    to=toi;
    color=colori;
    type=typei;
   }
   //ptr to a node
   std::unordered_set<Node*> aList;
   std::unordered_set<Node*> parents;
};
#endif // NODE_HPP