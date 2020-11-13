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


int tree_diameter(shared_ptr<Node> head){
	if(head == nullptr)
		return 0;
	int d = 0;
	depth(head, d);
	return d;
}

int depth(shared_ptr<Node> head, int& dep){
	if(head == nullptr)
		return 0;
	std::vector<int> heights(head->m);
	for(int i = 0; i < head->children.size(); i++){
		heights[i] = depth(head->children[i], dep);
	}

	for(int i = 0; i < head->children.size(); i++){
		for(int j = i+1; j < head->children.size(); j++){
			dep = max(dep, 1+heights[i]+heights[j]);
		}
	}
	return 1 + *std::max_element(heights.begin(), heights.end());
}

// test code below that was used to see if our solution worked

bool add_node(std::shared_ptr<Node> p, std::shared_ptr<Node> c){
	if(p->children.size() < p->m){
		p->children.push_back(c);
		return true;
	} else{
		return false;
	}
}

int test1(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 20;
	int m = 3;
	shared_ptr<Node> head = make_shared<Node>(0, m);

	nodes.push_back(head);
	for(int i = 1; i < n; i++){
		shared_ptr<Node> newNode = make_shared<Node>(i, m);
		nodes.push_back(newNode);
	}
	for(int i = 1, j = 0; i < n; i++){
		if(!add_node(nodes[j], nodes[i])){
			j++;
			i--;
		}
	}

	return tree_diameter(head);
}

int test2(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 4;
	int m = 2;
	shared_ptr<Node> head = make_shared<Node>(0, m);

	nodes.push_back(head);
	for(int i = 1; i < n; i++){
		shared_ptr<Node> newNode = make_shared<Node>(i, m);
		nodes.push_back(newNode);
	}
	for(int i = 1, j = 0; i < n; i++){
		if(!add_node(nodes[j], nodes[i])){
			j++;
			i--;
		}
	}

	return tree_diameter(head);
}

int test3(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 10;
	int m = 10;
	shared_ptr<Node> head = make_shared<Node>(0, m);

	nodes.push_back(head);
	for(int i = 0; i < n-1; i++){
		shared_ptr<Node> newNode = make_shared<Node>(i, m);
		nodes.push_back(newNode);
	}
	for(int i = 1, j = 0; i < n; i++){
		if(!add_node(nodes[j], nodes[i])){
			j++;
			i--;
		}
	}

	return tree_diameter(head);
}

int test4(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 10;
	int m = 3;
	shared_ptr<Node> head = make_shared<Node>(0, m);

	nodes.push_back(head);
	for(int i = 0; i < n-1; i++){
		shared_ptr<Node> newNode = make_shared<Node>(i, m);
		nodes.push_back(newNode);
	}
	for(int i = 1, j = 0; i < n; i++){
		if(!add_node(nodes[j], nodes[i])){
			j++;
			i--;
		}
	}

	shared_ptr<Node> newHead = make_shared<Node>(100, m);
	add_node(newHead, head);

	return tree_diameter(newHead);
}

int test5(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 10;
	int m = 2;

	for(int i = 0; i < n; i++){
		nodes.push_back(make_shared<Node>(i, m));
	}

	add_node(nodes[0], nodes[1]);
	add_node(nodes[1], nodes[2]);
	add_node(nodes[1], nodes[3]);
	add_node(nodes[2], nodes[4]);
	add_node(nodes[3], nodes[5]);
	add_node(nodes[5], nodes[6]);
	add_node(nodes[6], nodes[7]);
	add_node(nodes[6], nodes[8]);
	add_node(nodes[8], nodes[9]);

	return tree_diameter(nodes[0]);
}

int test6(){
	std::vector<std::shared_ptr<Node> > nodes;
	int n = 15;
	int m = 3;

	for(int i = 0; i < n; i++){
		nodes.push_back(make_shared<Node>(i, m));
	}

	add_node(nodes[0], nodes[1]);
	add_node(nodes[1], nodes[2]);
	add_node(nodes[1], nodes[3]);
	add_node(nodes[1], nodes[4]);
	add_node(nodes[3], nodes[5]);
	add_node(nodes[5], nodes[6]);
	add_node(nodes[6], nodes[7]);
	add_node(nodes[6], nodes[8]);
	add_node(nodes[8], nodes[9]);
	add_node(nodes[3], nodes[10]);
	add_node(nodes[3], nodes[11]);
	add_node(nodes[10], nodes[12]);
	add_node(nodes[12], nodes[13]);
	add_node(nodes[12], nodes[14]);

	return tree_diameter(nodes[0]);
}

int main(){
	// 6 4 3 5 8 8
	cout << test1() << endl;
	cout << test2() << endl;
	cout << test3() << endl;
	cout << test4() << endl;
	cout << test5() << endl;
	cout << test6() << endl;
}