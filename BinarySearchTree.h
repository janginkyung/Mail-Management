#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};
/* @brief  정렬된 bst*/
template<class T>
class BinarySearchTree
{
public:
	BinarySearchTree();//생성자
	~BinarySearchTree();//소멸자

	/**
	*  @brief	: BST가 비어있는지 아닌지 확인한다
	*  @pre		:
	*  @post	: 비어있으면 true, 아닌경우 false를 리턴한다.
	*/
	bool IsEmpty();

	/**
	*  @brief	: BST가 꽉 차있는지 아닌지 확인한다.
	*  @pre		: 
	*  @post	: 차있으면 true, 아닌경우 false를 리턴한다.
	*/
	bool IsFull();
	/**
	*  @brief	: BST를 비어있게 만든다.
	*  @pre		:
	*  @post	: 노드가 전부 삭제된다.
	*/
	void MakeEmpty();
	/**
	*  @brief	: BST의 노드의 갯수를 돌려준다
	*  @pre		:
	*  @post	:
	*/
	int GetLength();
	/**
	*  @brief	:  BST에 아이템을 추가한다
	*  @pre		: 아이템이 입력받아져야 한다.
	*  @post	: 
	*/
	void Additem(T item);
	/**
	*  @brief	:  BST의 아이템을 삭제한다
	*  @pre		: 키아이템이 먼저 입력받아져야 한다.
	*  @post	: 키아이템을 찾으면 삭제하고 그렇지 않으면 삭제하지 않는다.
	*/
	void Deleteitem(T item);
	/**
	*  @brief	: BST에서 아이템을 찾아서 찾는다.
	*  @pre		: 키아이템이 먼저 입력받아져야 한다. 
	*  @post	: 찾은 경우 found를 true로 반환한다.
	*/
	void Retrieveitem(T &item, bool&found);
	/**
	*  @brief	: 트리를 InOrder, PreOrder, PostOrder의 방법으로 출력한다. 
	*  @pre		: 트리에 아이템이 저장되어있어야한다. 
	*  @post	: 3가지 방법 줗 한개를 골라 저장한다. 
	*/
	void PrintTree(ostream&out) const;
private:
	BinaryTreeNode<T> *root;// 처음 노드를 가리키는 주소이다. 
};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	Destroy(root);
}

template<class T>
bool BinarySearchTree<T>::IsEmpty()
{
	return root == NULL;
}
template<class T>
bool BinarySearchTree<T>::IsFull()
{
	BinaryTreeNode* location;
	try// 에러가 나면 catch 구문으로 넘어간다
	{
		location = new BinaryTreeNode;//동적할당을 했을 때 주소를 제대로 주지 못하면 catch 구문으로 넘어간다
		delete location;//에러가 발생시 catch 구문으로
		return false;

	}
	catch (std::bad_alloc exception)//메모리를 잘못 잡았을 경우 
	{
		return true;
	}
}


template<class T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}
template<class T>
int BinarySearchTree<T>::GetLength()
{
	return CountNodes(root);
}

template<class T>
void BinarySearchTree<T>::Retrieveitem(T &item, bool&found)
{
	Retrieve(root, item, found);
}
template<class T>
void BinarySearchTree<T>::Additem(T item)
{
	Add(root, item);
}

template<class T>
void BinarySearchTree<T>::Deleteitem(T item)
{

	Delete(root, item);

}
template<class T>
void BinarySearchTree<T>::PrintTree(ostream&out) const
{
	cout << endl ;

	PrintInOrderTraversal(root, out);


}

// 전역함수로 선언한다. 
//////////////////////////////////////////////////////////////////////////
template<class T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	root = NULL;			// root 노드를 Null로 함
}
template<class T>
int CountNodes(BinaryTreeNode<T> *tree)
{
	if (tree == NULL)//root가 아무것도 없을 땐 1개도 없는 것 
		return 0;
	else// 그렇지 않을 경우에는 왼쪽과 오른쪽으로 재귀함수로 이용해 센다
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;// 이경우에는 자기자신을 카운트해 1을 더하고 그 아래 자식노드로 이동해서 또 숫자를 센다. 

}

template<class T>
void Retrieve(BinaryTreeNode<T>*ptr, T &item, bool&found)
{
	if (ptr == NULL)//아무것도 저장되어있지 않은 경우 
		found = false;
	else if (ptr->data>item)// 찾는 아이템이 처음 노드의 아이템보다 작을때는 왼쪽으로 가면된다
		Retrieve(ptr->left, item, found);
	else if (ptr->data<item)// 찾는 아이템이 처음 노드의 아이템보다 클때는 오른쪽으로 가면된다
		Retrieve(ptr->right, item, found);
	else // 찾았을 경우
	{
		item = ptr->data;
		found = true;// found 를 true 로 리턴해준다. 
	}

}
template<class T>
void Add(BinaryTreeNode<T>*&ptr, T &item)
{
	if (ptr == NULL)//root에서 부터 넣어주면 된다
	{
		ptr = new BinaryTreeNode<T>;
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->data = item;

	}
	else if (ptr->data<item)//아이템과 값을 비교해서 작을 경우에 왼쪽
		Add(ptr->right, item);//재귀함수로 구현
	else if (ptr->data>item)//클경우에 오른쪽으로 들어간다
		Add(ptr->left, item);//재귀함수로 구현 
}
template<class T>
void Delete(BinaryTreeNode<T>*&ptr, T &item)
{
	if (item < ptr->data)//아이템과 노드를 비교해 아이템이 작으면 왼쪽
		Delete(ptr->left, item);//재귀함수로 구현하여 다시 비교해서 삭제하는 대상을 만나는 경우에 delete node로 간다. 
	else if (ptr->data < item)//크면 오른쪽
		Delete(ptr->right, item);//재귀함수로 구현하여 다시 비교해서 삭제하는 대상을 만나는 경우에 delete node로 간다. 
	else
		DeleteNode(ptr);//대상을 찾은 경우 실제로 그 노드를 삭제한다. 
}

template<class T>
void DeleteNode(BinaryTreeNode<T>*&ptr)
{
	T data;
	BinaryTreeNode<T> *temptr;
	temptr = ptr;//들어온 ptr을 삭제해야하므로 temptr에 집어넣는다. 
	if (ptr->left == NULL){
		ptr = ptr->right;// 왼쪽이 비어있는 경우에는 자식의 오른쪽노드를 삭제한노드에 올린다 .
		delete temptr;
	}
	else if (ptr->right == NULL){
		ptr = ptr->left;//오른쪽이 비어있는 경우에는 자식의 왼쪽 노드를 삭제하는 위치에 올린다. 
		delete temptr;
	}
	else//오른쪽과 왼쪽이 둘 다 있는 경우 
	{
		GetPredecessor(ptr->left, data);//삭제한 노드보다 작은 애들중에서 가장 큰애를 찾는다. 
		ptr->data = data;
		Delete(ptr->left, data);
	}
}

template<class T>
void GetPredecessor(BinaryTreeNode<T>*ptr, T &item)
{
	while (ptr->right != NULL)//null이 아닐 때까지 
		ptr = ptr->right;//노드에서 자식노드로갈때 오른쪽 자식노드로 가게끔 해준다. 
	item = ptr->data;

}

 template<class T>
void PrintInOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{
	if (root != NULL)
	{
		PrintInOrderTraversal(root->left, out);//가장 왼쪽에 있는 노드부터 본다 그래서 왼쪽의 subtree를 먼저 출력한다. 
		out << root->data;//그다음엔 위의 subtree를 출력하고
		PrintInOrderTraversal(root->right, out);//오른쪽에 있는 subtree를 가장 마지막에 출력한다
	}

}
template<class T>
void PrintPreOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{

	if (root != NULL)
	{
		out << root->data;//가장위에 있는 subtree를 먼저 출력하고 
		PrintPreOrderTraversal(root->left, out);//왼쪽에 있는 subtree를 중간에 출력하고 
		PrintPreOrderTraversal(root->right, out);//오른쪽에 있는 subtree를 마지막으로 출력한다. 
	}
}
template<class T>
void PrintPostOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{
	if (root != NULL)
	{
		PrintPostOrderTraversal(root->left, out);//왼쪽의 subtree를 가장먼저 출력하고
		PrintPostOrderTraversal(root->right, out);//오른쪽의 subtree를 그다음에 출력한다음에
		out << root->data;//위에있는 suvtree를 그다음으로 출력한다. 
	}
}
template< class T>
void Destroy(BinaryTreeNode<T>* ptr)
{
	if (ptr == NULL)
	{
		Destroy(ptr->right);//오른쪽자식노드에 있는 모든 노드를 삭제한다 
		Destroy(ptr->left);//왼쪽 자식노드에있는 모든 노드를
		delete ptr;
	}

}
