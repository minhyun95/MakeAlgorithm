#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode()
{
	BTreeNode* nd = new BTreeNode;
	nd->left = nullptr;
	nd->right = nullptr;
	return nd;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != nullptr)
		delete main->left;
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != nullptr)
		delete main->right;
	main->right = sub;
}

typedef void(*VisitFuncPtr)(BTData data);

void ShowData(BTData data)
{
	cout << data << endl;
}

// 중위순회
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

// 전위순회
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

// 후위순회
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
#endif // !__BINARY_TREE_H__