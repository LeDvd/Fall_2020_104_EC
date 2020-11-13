#include <memory>
#include <algorithm>
using namespace std;


struct Node {    
    int val;    
    std::shared_ptr<Node> left;    
    std::shared_ptr<Node> right;      
  };


int tree_diameter(shared_ptr<Node> head);