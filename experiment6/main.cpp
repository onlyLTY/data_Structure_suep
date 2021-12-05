#include "BinaryTree.h"

int main() {
    int a;
    BinaryTree<int> binaryTree;
    binaryTree.PreOrder(binaryTree.root);//前序遍历
    std::cout<<std::endl;
    binaryTree.InOrder(binaryTree.root);   //中序遍历
    std::cout<<std::endl;
    binaryTree.PostOrder(binaryTree.root);  //后序遍历
    std::cout<<std::endl;
    binaryTree.LeverOrder(binaryTree.root);   //层次遍历
    std::cout<<std::endl;
    a = binaryTree.GetBTreeDepth(binaryTree.root);
    std::cout<<a<<std::endl;
    a = binaryTree.GetBTreeNodesTotal(binaryTree.root);
    std::cout<<a<<std::endl;
    a = binaryTree.GetBTreeLeafNodesTotal(binaryTree.root);
    std::cout<<a<<std::endl;
    getchar();
    BinaryTree<int> binaryTree1;
    a=binaryTree.isSymmetrical(binaryTree.root,binaryTree1.root);
    std::cout<<a<<std::endl;


    return 0;
}
