#include <memory>
#include <algorithm>
using namespace std;


struct Node {    
    int val;    
    std::shared_ptr<Node> left;    
    std::shared_ptr<Node> right;      
  };


int tree_diameter(shared_ptr<Node> head);
int depth(shared_ptr<Node> head, int& dep);


int tree_diameter(shared_ptr<Node> head){
	if(head == nullptr)
		return 0;
	int d = 0;
	int diam = depth(head, d);
	return d;
}

int depth(shared_ptr<Node> head, int& dep){
	if(head == nullptr)
		return 0;
	int left_height = depth(head->left, dep);
	int right_height = depth(head->right, dep);
	dep = max(dep, 1+left_height+right_height);
	return 1 + max(left_height, right_height);
}