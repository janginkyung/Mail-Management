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
/* @brief  ���ĵ� bst*/
template<class T>
class BinarySearchTree
{
public:
	BinarySearchTree();//������
	~BinarySearchTree();//�Ҹ���

	/**
	*  @brief	: BST�� ����ִ��� �ƴ��� Ȯ���Ѵ�
	*  @pre		:
	*  @post	: ��������� true, �ƴѰ�� false�� �����Ѵ�.
	*/
	bool IsEmpty();

	/**
	*  @brief	: BST�� �� ���ִ��� �ƴ��� Ȯ���Ѵ�.
	*  @pre		: 
	*  @post	: �������� true, �ƴѰ�� false�� �����Ѵ�.
	*/
	bool IsFull();
	/**
	*  @brief	: BST�� ����ְ� �����.
	*  @pre		:
	*  @post	: ��尡 ���� �����ȴ�.
	*/
	void MakeEmpty();
	/**
	*  @brief	: BST�� ����� ������ �����ش�
	*  @pre		:
	*  @post	:
	*/
	int GetLength();
	/**
	*  @brief	:  BST�� �������� �߰��Ѵ�
	*  @pre		: �������� �Է¹޾����� �Ѵ�.
	*  @post	: 
	*/
	void Additem(T item);
	/**
	*  @brief	:  BST�� �������� �����Ѵ�
	*  @pre		: Ű�������� ���� �Է¹޾����� �Ѵ�.
	*  @post	: Ű�������� ã���� �����ϰ� �׷��� ������ �������� �ʴ´�.
	*/
	void Deleteitem(T item);
	/**
	*  @brief	: BST���� �������� ã�Ƽ� ã�´�.
	*  @pre		: Ű�������� ���� �Է¹޾����� �Ѵ�. 
	*  @post	: ã�� ��� found�� true�� ��ȯ�Ѵ�.
	*/
	void Retrieveitem(T &item, bool&found);
	/**
	*  @brief	: Ʈ���� InOrder, PreOrder, PostOrder�� ������� ����Ѵ�. 
	*  @pre		: Ʈ���� �������� ����Ǿ��־���Ѵ�. 
	*  @post	: 3���� ��� �G �Ѱ��� ��� �����Ѵ�. 
	*/
	void PrintTree(ostream&out) const;
private:
	BinaryTreeNode<T> *root;// ó�� ��带 ����Ű�� �ּ��̴�. 
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
	try// ������ ���� catch �������� �Ѿ��
	{
		location = new BinaryTreeNode;//�����Ҵ��� ���� �� �ּҸ� ����� ���� ���ϸ� catch �������� �Ѿ��
		delete location;//������ �߻��� catch ��������
		return false;

	}
	catch (std::bad_alloc exception)//�޸𸮸� �߸� ����� ��� 
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

// �����Լ��� �����Ѵ�. 
//////////////////////////////////////////////////////////////////////////
template<class T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}
template<class T>
int CountNodes(BinaryTreeNode<T> *tree)
{
	if (tree == NULL)//root�� �ƹ��͵� ���� �� 1���� ���� �� 
		return 0;
	else// �׷��� ���� ��쿡�� ���ʰ� ���������� ����Լ��� �̿��� ����
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;// �̰�쿡�� �ڱ��ڽ��� ī��Ʈ�� 1�� ���ϰ� �� �Ʒ� �ڽĳ��� �̵��ؼ� �� ���ڸ� ����. 

}

template<class T>
void Retrieve(BinaryTreeNode<T>*ptr, T &item, bool&found)
{
	if (ptr == NULL)//�ƹ��͵� ����Ǿ����� ���� ��� 
		found = false;
	else if (ptr->data>item)// ã�� �������� ó�� ����� �����ۺ��� �������� �������� ����ȴ�
		Retrieve(ptr->left, item, found);
	else if (ptr->data<item)// ã�� �������� ó�� ����� �����ۺ��� Ŭ���� ���������� ����ȴ�
		Retrieve(ptr->right, item, found);
	else // ã���� ���
	{
		item = ptr->data;
		found = true;// found �� true �� �������ش�. 
	}

}
template<class T>
void Add(BinaryTreeNode<T>*&ptr, T &item)
{
	if (ptr == NULL)//root���� ���� �־��ָ� �ȴ�
	{
		ptr = new BinaryTreeNode<T>;
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->data = item;

	}
	else if (ptr->data<item)//�����۰� ���� ���ؼ� ���� ��쿡 ����
		Add(ptr->right, item);//����Լ��� ����
	else if (ptr->data>item)//Ŭ��쿡 ���������� ����
		Add(ptr->left, item);//����Լ��� ���� 
}
template<class T>
void Delete(BinaryTreeNode<T>*&ptr, T &item)
{
	if (item < ptr->data)//�����۰� ��带 ���� �������� ������ ����
		Delete(ptr->left, item);//����Լ��� �����Ͽ� �ٽ� ���ؼ� �����ϴ� ����� ������ ��쿡 delete node�� ����. 
	else if (ptr->data < item)//ũ�� ������
		Delete(ptr->right, item);//����Լ��� �����Ͽ� �ٽ� ���ؼ� �����ϴ� ����� ������ ��쿡 delete node�� ����. 
	else
		DeleteNode(ptr);//����� ã�� ��� ������ �� ��带 �����Ѵ�. 
}

template<class T>
void DeleteNode(BinaryTreeNode<T>*&ptr)
{
	T data;
	BinaryTreeNode<T> *temptr;
	temptr = ptr;//���� ptr�� �����ؾ��ϹǷ� temptr�� ����ִ´�. 
	if (ptr->left == NULL){
		ptr = ptr->right;// ������ ����ִ� ��쿡�� �ڽ��� �����ʳ�带 �����ѳ�忡 �ø��� .
		delete temptr;
	}
	else if (ptr->right == NULL){
		ptr = ptr->left;//�������� ����ִ� ��쿡�� �ڽ��� ���� ��带 �����ϴ� ��ġ�� �ø���. 
		delete temptr;
	}
	else//�����ʰ� ������ �� �� �ִ� ��� 
	{
		GetPredecessor(ptr->left, data);//������ ��庸�� ���� �ֵ��߿��� ���� ū�ָ� ã�´�. 
		ptr->data = data;
		Delete(ptr->left, data);
	}
}

template<class T>
void GetPredecessor(BinaryTreeNode<T>*ptr, T &item)
{
	while (ptr->right != NULL)//null�� �ƴ� ������ 
		ptr = ptr->right;//��忡�� �ڽĳ��ΰ��� ������ �ڽĳ��� ���Բ� ���ش�. 
	item = ptr->data;

}

 template<class T>
void PrintInOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{
	if (root != NULL)
	{
		PrintInOrderTraversal(root->left, out);//���� ���ʿ� �ִ� ������ ���� �׷��� ������ subtree�� ���� ����Ѵ�. 
		out << root->data;//�״����� ���� subtree�� ����ϰ�
		PrintInOrderTraversal(root->right, out);//�����ʿ� �ִ� subtree�� ���� �������� ����Ѵ�
	}

}
template<class T>
void PrintPreOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{

	if (root != NULL)
	{
		out << root->data;//�������� �ִ� subtree�� ���� ����ϰ� 
		PrintPreOrderTraversal(root->left, out);//���ʿ� �ִ� subtree�� �߰��� ����ϰ� 
		PrintPreOrderTraversal(root->right, out);//�����ʿ� �ִ� subtree�� ���������� ����Ѵ�. 
	}
}
template<class T>
void PrintPostOrderTraversal(BinaryTreeNode<T> *root, ostream&out)
{
	if (root != NULL)
	{
		PrintPostOrderTraversal(root->left, out);//������ subtree�� ������� ����ϰ�
		PrintPostOrderTraversal(root->right, out);//�������� subtree�� �״����� ����Ѵ�����
		out << root->data;//�����ִ� suvtree�� �״������� ����Ѵ�. 
	}
}
template< class T>
void Destroy(BinaryTreeNode<T>* ptr)
{
	if (ptr == NULL)
	{
		Destroy(ptr->right);//�������ڽĳ�忡 �ִ� ��� ��带 �����Ѵ� 
		Destroy(ptr->left);//���� �ڽĳ�忡�ִ� ��� ��带
		delete ptr;
	}

}
