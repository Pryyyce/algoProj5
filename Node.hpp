#include <string>
#include <unordered_set>

struct Node
{
   std::string from;
   std::string to;
   std::string color;
   std::string type; 
   std::string prev;

   //constructor for node

   Node(std::string fromi,std::string toi,std::string colori,std::string typei){
    from=fromi;
    to=toi;
    color=colori;
    type=typei;
   }
   //ptr to a node
   std::unordered_set<Node*> aList;
};
