#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


struct Node {    
    int val;    
    int m;
    std::vector<std::shared_ptr<Node> > children;

    Node(int v, int m): val(v), m(m){}
};


int tree_diameter(shared_ptr<Node> head);
int depth(shared_ptr<Node> head, int& dep);
