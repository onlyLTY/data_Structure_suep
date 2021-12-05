//
// Created by lieyi on 2021/12/4.
//

#ifndef EXPERIMENT6_BINARYTREE_H
#define EXPERIMENT6_BINARYTREE_H

#include "iostream"
#include<queue>

template<class T>
class BinaryTree {
    struct Node{
        T data;
        Node *lchild=nullptr,
             *rchild=nullptr;
    };
    public:
        BinaryTree();//构造函数，按前序初始化一棵二叉树，其前序序列由键盘输入
        ~BinaryTree(); //析构函数，释放二叉链表中各结点的存储空间
        void PreOrder(Node *temp);//前序遍历    　　　
        void InOrder(Node *temp);   //中序遍历
        void PostOrder(Node *temp);  //后序遍历
        void LeverOrder(Node *temp);   //层次遍历
        int GetBTreeDepth(Node *temp);
        int GetBTreeNodesTotal(Node *temp);
        int GetBTreeLeafNodesTotal(Node *temp);
        int isSymmetrical(Node *root1,Node *root2);
        //其它操作暂略
        Node *root=nullptr;//指向根结点的头指针
    private:
        //Node *root=nullptr;//指向根结点的头指针
        std::queue<Node **> q;

};

template<typename T>
BinaryTree<T>::BinaryTree() {
    T a;
    Node **temp;
    q.push(&root);
    std::cout<<"开始创建二叉树，输入回车结束输入"<<std::endl;
    while (std::cin.peek() != '\n'){
        std::cin>>a;
        temp = q.front();
        *temp = new Node;
        q.pop();
        (*temp)->data=a;
        /*temp->lchild = new Node;
        temp->rchild = new Node;*/
        q.push(&(*temp)->lchild);
        q.push(&(*temp)->rchild);
    }


}

template<typename T>
BinaryTree<T>::~BinaryTree() {

}

template<typename T>
void BinaryTree<T>::PreOrder(Node *temp) {
    if(temp == nullptr)
        return;
    std::cout << temp->data << " ";  /*显示结点数据，可以更改为其他对结点操作*/
    PreOrder(temp->lchild);    /*再先序遍历左子树*/
    PreOrder(temp->rchild);    /*最后先序遍历右子树*/

}

template<typename T>
void BinaryTree<T>::InOrder(Node *temp) {
    if (temp == nullptr) return;
    InOrder(temp->lchild);
    std::cout<<temp->data<< " ";
    InOrder(temp -> rchild);

}

template<typename T>
void BinaryTree<T>::PostOrder(Node *temp) {
    if (temp == nullptr) return;
    InOrder(temp->lchild);
    InOrder(temp -> rchild);
    std::cout<<temp->data<< " ";
}

template<typename T>
void BinaryTree<T>::LeverOrder(Node *temp) {
    if (temp == nullptr) return; // 如果root是空的直接return掉
    std::queue<Node*> childs; // 创建节点队列
    childs.push(temp); // 先把root节点加入套餐
    while (childs.size() != 0) // 队列空了就结束
    {
        Node *current = childs.front(); // 取出队列前端的节点
        printf("%d ",current -> data); // 提取数据
        if (current -> lchild != nullptr) childs.push(current -> lchild); // 如果不是空的，就加入套餐
        if (current -> rchild != nullptr) childs.push(current -> rchild); // 同上
        childs.pop(); // 去掉队列前端的节点
    }
}

template<class T>
int BinaryTree<T>::GetBTreeDepth(BinaryTree::Node *temp) {
    if( temp == nullptr )
        return 0;

    int lDepth = GetBTreeDepth( temp->lchild);
    int rDepth = GetBTreeDepth( temp->rchild);

    return ((( lDepth > rDepth )? lDepth: rDepth) + 1 );
}

template<class T>
int BinaryTree<T>::GetBTreeNodesTotal(BinaryTree::Node *temp) {
    if( temp == nullptr )
        return 0;

    return ( GetBTreeNodesTotal( temp->lchild) + GetBTreeNodesTotal( temp->rchild) + 1);
}

template<class T>
int BinaryTree<T>::GetBTreeLeafNodesTotal(BinaryTree::Node *temp) {
    if( temp == nullptr )
        return 0;
    if( temp->lchild == nullptr && temp->rchild == nullptr )
        return 1;

    return ( GetBTreeLeafNodesTotal( temp->lchild) + GetBTreeLeafNodesTotal( temp->rchild) );
}

template<class T>
int BinaryTree<T>::isSymmetrical(BinaryTree::Node *root1, BinaryTree::Node *root2) {
    if(root1 == nullptr && root2== nullptr)    //两个结点都为空
        return 1;
    else if(root1 == nullptr || root2 == nullptr)  //有一个结点不为空
        return 0;
    else
    {
        int leftS = isSymmetrical(root1->lchild,root2->lchild);  //递归左子树
        int rightS = isSymmetrical(root1->rchild,root2->rchild);  //递归右子树
        return leftS && rightS ;  //返回两个子树的信息
    }
}


#endif //EXPERIMENT6_BINARYTREE_H
