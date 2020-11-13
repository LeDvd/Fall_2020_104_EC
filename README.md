# Fall_2020_104_EC
 Extra Credit for CSCI 104 (David + Bryson).

 For this problem, define the diameter as the maximum distance between two nodes (including both nodes). For example, the following tree has a diameter of 4 (starting with either 3 or 4 --> 1 --> 0 --> 2):

````
 	 0
    / \
   1   2
  / \
 3   4
````


 In diameter.cpp, implement tree_diameter recursively. Specifications:
 	* The function takes the node as an argument.
 	* The function runs in O(n) time, where n is the number of nodes in the tree.
 	* The tree is a binary tree.
 	* You may use helper functions.

  EXTRA: in mdiameter.cpp, implement tree_diameter as before, but instead extend the solution to a m-ary tree. There is no required runtime.