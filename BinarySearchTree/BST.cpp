#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

void BST::AddLeafPrivate(int key, node * Ptr){
	if (root == NULL) {
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key) {
		if (Ptr->left != NULL) {
			AddLeafPrivate(key, Ptr->left);
		}
		else {
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != NULL) {
			AddLeafPrivate(key, Ptr->right);
		}
		else {
			Ptr->right = CreateLeaf(key);
		}
	}
	else {
		cout << "The key has already been added to the tree" << endl;
	}
}

void BST::PrintInorderPrivate(node * Ptr){
	if (root != NULL) {
		if (Ptr->left != NULL) {
			PrintInorderPrivate(Ptr->left);
		}
		cout << Ptr->key << " ";
		if (Ptr->right != NULL) {
			PrintInorderPrivate(Ptr->right);
		}
	}
	else {
		cout << "The tree is empty" << endl;
	}
}

BST::node * BST::ReturnNodePrivate(int key, node * Ptr){
	if (Ptr != NULL) {
		if (Ptr->key == key) {
			return Ptr;
		}
		else {
			if (key < Ptr->key) {
				return ReturnNodePrivate(key, Ptr->left);
			}
			else {
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else {
		return NULL;
	}
}

int BST::FindSmallestPrivate(node * Ptr)
{
	if (root == NULL) {
		cout << "The tree is empty\n";
		return -1000;
	}
	else {
		if (Ptr->left != NULL) {
			return FindSmallestPrivate(Ptr->left);
		}
		else {
			return Ptr->key;
		}
	}
}

BST::BST(){
	root = NULL;
}

BST::node * BST::CreateLeaf(int key){
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	cout << key << " has been added to the tree" << endl;

	return n;
}

void BST::AddLeaf(int key){
	AddLeafPrivate(key, root);
}

void BST::PrintInorder(){
	PrintInorderPrivate(root);
}

BST::node * BST::ReturnNode(int key) {
	return ReturnNodePrivate(key, root);
}

int BST::ReturnRootKey(){
	if (root != NULL) {
		return root->key;
	}
	else {
		return -1000;
	}
}

void BST::PrintChildren(int key){
	node* Ptr = ReturnNode(key);

	if (Ptr != NULL) {
		cout << "Parent Node = " << Ptr->key << endl;

		Ptr->left == NULL ?
			cout << "Left Child = Null \n" :
			cout << "Left Child = " << Ptr->left->key << endl;

		Ptr->right == NULL ?
			cout << "Right Child = Null \n" :
			cout << "Right Child = " << Ptr->right->key << endl;
	}
	else {
		cout << "Key is not in the tree\n";
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}
