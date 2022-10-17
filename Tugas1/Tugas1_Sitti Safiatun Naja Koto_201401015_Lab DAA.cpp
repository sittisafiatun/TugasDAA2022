#include <iostream>
using namespace std;

const int c = 10;
struct BST
{
	int data;
	BST* kiri;
	BST* kanan;
};

BST* InsertNode(int data, BST* tree)
{
	if (tree == NULL)
	{
		BST* NewNode = new BST;
		NewNode->data = data;
		NewNode->kiri = NULL;
		NewNode->kanan = NULL;
		tree = NewNode;
	}
	else if (tree->data > data)
	{
		tree->kiri = InsertNode(data, tree->kiri);
	}
	else
	{
		tree->kanan = InsertNode(data, tree->kanan);
	}
	return tree;
}

bool SearchNode(int data, BST* tree)
{
	if (tree == NULL) return false;
	else if (tree->data == data) return true;
	else if (tree->data > data) return SearchNode(data, tree->kiri);
	else return SearchNode(data, tree->kanan);
}

void PrintTreeNodes(BST* tree, int s)
{
    if (tree == NULL) return;
    s += c;
    PrintTreeNodes(tree->kanan, s);
    
    for (int i = c; i < s; i++) 
	cout << " ";
	
    cout << tree->data << endl;
    
    PrintTreeNodes(tree->kiri, s);
}

int main(){
	int a[10] = {4, 1, 9, 6, 2, 5, 3, 8, 7, 0};
	BST* Pohon = NULL;
	
	for (int i=0; i<10; i++)
	{
		Pohon = InsertNode(a[i], Pohon);
	}
	
	if(!SearchNode(7, Pohon)) cout << "Tidak ";
	cout << "Ada 7" << endl;
	
	if(!SearchNode(11, Pohon)) cout << "Tidak ";
	cout << "Ada 11" << endl;
	
	PrintTreeNodes(Pohon, 0);
}
