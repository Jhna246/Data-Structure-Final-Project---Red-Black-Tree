#include "stdc++.h"
using namespace std;

enum Color { RED, BLACK };

class RBT
{
	struct node
	{
		std::string data;
		bool color;
		node *left, *right, *parent;

		node(std::string data)
		{
			this->data = data;
			left = right = parent = NULL;
		}
	};

	node* root;

	int getColor(node *&node) {
		if (node == nullptr)
			return BLACK;

		return node->color;
	}

	void setColor(node *&node, int color) {
		if (node == nullptr)
			return;

		node->color = color;
	}

	void inorder(node* root)
	{
		if (root == NULL)
		{
			return;
		}

		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void leftrotation(node* pt)
	{
		if (pt->right == NULL)
			return;
		else
		{
			node *y = pt->right;
			if (y->left != NULL)
			{
				pt->right = y->left;
				y->left->parent = pt;
			}
			else
				pt->right = NULL;

			if (pt->parent != NULL)
				y->parent = pt->parent;
			if (pt->parent == NULL)
				root = y;
			else
			{
				if (pt == pt->parent->left)
					pt->parent->left = y;
				else
					pt->parent->right = y;
			}
			y->left = pt;
			pt->parent = y;
		}
	}

	void rightrotation(node* pt)
	{
		if (pt->left == NULL)
			return;
		else
		{
			node *y = pt->left;
			if (y->right != NULL)
			{
				pt->left = y->right;
				y->right->parent = pt;
			}
			else
				pt->left = NULL;
			if (pt->parent != NULL)
				y->parent = pt->parent;
			if (pt->parent == NULL)
				root = y;
			else
			{
				if (pt == pt->parent->left)
					pt->parent->left = y;
				else
					pt->parent->right = y;
			}
			y->right = pt;
			pt->parent = y;
		}
	}

	void fixInsertRBTree(node* pt)
	{
		node *uncle;
		if (root == pt)
		{
			pt->color = BLACK;
			return;
		}
		while (pt->parent != NULL && pt->parent->color == RED)
		{
			node *grandpa = pt->parent->parent;
			if (grandpa->left == pt->parent)
			{
				if (grandpa->right != NULL)
				{
					uncle = grandpa->right;
					if (uncle->color == RED)
					{
						pt->parent->color = BLACK;
						uncle->color = BLACK;
						grandpa->color = RED;
						pt = grandpa;
					}
				}
				else
				{
					if (pt->parent->right == pt)
					{
						pt = pt->parent;
						leftrotation(pt);
					}
					pt->parent->color = BLACK;
					grandpa->color = RED;
					rightrotation(grandpa);
				}
			}
			else
			{
				if (grandpa->left != NULL)
				{
					uncle = grandpa->left;
					if (uncle->color == RED)
					{
						pt->parent->color = BLACK;
						uncle->color = BLACK;
						grandpa->color = RED;
						pt = grandpa;
					}
				}
				else
				{
					if (pt->parent->left == pt)
					{
						pt = pt->parent;
						rightrotation(pt);
					}
					pt->parent->color = BLACK;
					grandpa->color = RED;
					leftrotation(grandpa);
				}
			}
			root->color = BLACK;
		}
	}

	node* deleteBST(node* root, std::string data) {

		node* p = root;

		if (root == NULL)
			return root;

		if (data < root->data)
		{
			root->left = deleteBST(root->left, data);

		}
		else if (data > root->data)
		{
			root->right = deleteBST(root->right, data);
		}

		else
		{
			if (root->left == NULL)
			{
				node *temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				node *temp = root->left;
				free(root);
				return temp;
			}
			node* temp = minValueNode(root->right);

			root->data = temp->data;

			root->right = deleteBST(root->right, temp->data);
		}

		return root;
	}

	node* minValueNode(node *root) {

		node *ptr = root;

		while (ptr->left != NULL)
			ptr = ptr->left;

		return ptr;
	}

	void fixDeleteRBTree(node* pt)
	{
		while (pt != root && pt->color == BLACK)
		{
			if (pt == pt->parent->left)
			{
				node* w = pt->parent->right;
				if (w->color == RED)
				{
					w->color = BLACK;
					pt->parent->color = RED;
					leftrotation(pt->parent);
					w = pt->parent->right;
				}
				else if (w->left->color == BLACK && w->right->color == BLACK)
				{
					w->color = RED;
					pt = pt->parent;
				}
				else
				{
					if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						rightrotation(w);
						w = pt->parent->right;
					}
					else
					{
						w->color = pt->parent->color;
						pt->parent->color = BLACK;
						w->right->color = BLACK;
						leftrotation(pt->parent);
						pt = root;
					}
				}
			}
			else
			{
				node* w = pt->parent->left;
				if (w->color == RED)
				{
					w->color = BLACK;
					pt->parent->color = RED;
					rightrotation(pt->parent);
					w = pt->parent->left;
				}
				else if (w->right->color == BLACK && w->left->color == BLACK)
				{
					w->color = RED;
					pt = pt->parent;
				}
				else
				{
					if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						leftrotation(w);
						w = pt->parent->left;
					}
					else
					{
						w->color = pt->parent->color;
						pt->parent->color = BLACK;
						w->right->color = BLACK;
						rightrotation(pt->parent);
						pt = root;
					}
				}
			}
		}
	}

public:
	RBT()
	{
		root = NULL;
	}

	void insert(std::string key)
	{
		node *p, *q;
		node *t = new node(key);
		t->data = key;
		t->left = NULL;
		t->right = NULL;
		t->color = RED;
		p = root;
		q = NULL;
		if (root == NULL)
		{
			root = t;
			t->parent = NULL;
		}
		else
		{
			while (p != NULL)
			{
				q = p;
				if (p->data < t->data)
					p = p->right;
				else
					p = p->left;
			}
			t->parent = q;
			if (q->data<t->data)
				q->right = t;
			else
				q->left = t;
		}
		fixInsertRBTree(t);
	}

	void remove(std::string data)
	{
		node* pt = deleteBST(root, data);
		fixDeleteRBTree(pt);
	}

	void display()
	{
		//Level order traversal
		if (root == NULL)
			return;

		std::queue<node *> q;
		q.push(root);

		while (!q.empty())
		{
			node *temp = q.front();
			cout << temp->data << "  ";
			q.pop();

			if (temp->left != NULL)
				q.push(temp->left);

			if (temp->right != NULL)
				q.push(temp->right);
		}
	}

	void print(std::string data)
	{
		//print when node exists in tree
		node* p = root;
		int flag = 0;

		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			return;
		}
		while (p != NULL && flag == 0)
		{
			if (p->data == data)
				flag = 1;
			if (flag == 0)
			{
				if (p->data < data)
					p = p->right;
				else
					p = p->left;
			}
		}
		if (flag == 0)
		{
			insert(data);
			addprint(data);
			remove(data);
		}

		else
		{
			cout << "---------------------" << endl;

			if (p->left != NULL)
				cout << " " << p->left->data;
			else
				cout << "NIL";

			cout << " " << data;

			if (p != root)
			{
				if (p->parent != NULL)
					cout << " " << p->parent->data << endl;
				else
					cout << " NIL" << endl;
			}
			else
				cout << " NIL" << endl;

		}
	}

	void addprint(std::string data)
	{
		//print when node doesn't exist in tree
		node* p = root;
		std::string arr[5];
		int flag = 0;

		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			return;
		}

		while (p != NULL && flag == 0)
		{
			if (p->data == data)
				flag = 1;
			if (flag == 0)
			{
				if (p->data < data)
					p = p->right;
				else
					p = p->left;
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			arr[i] = data;
		}

		if (!data.empty() && data[0] == '-')
		{
			std::string value;
			value = data;
			value.erase(0, 1);
			remove(value);
			cout << "---------------------" << endl;
			cout << "The " << value << "is deleted" << endl;
		}
		else
		{
			cout << "---------------------" << endl;
			if (p->left != NULL)
				cout << "" << p->left->data;
			else
				cout << "NIL";

			cout << " NIL";

			if (p->left && p->right != NULL)
			{
				if (p->right != NULL)
					cout << " " << p->right->data << endl;
				else
					cout << " NIL" << endl;
			}
			else
			{
				if (p->parent != NULL)
					cout << " " << p->parent->data << endl;
				else
					cout << " NIL" << endl;
			}
		}
	}

	void presuc(std::string data)
	{
		//predecessor and successor
		addprint(data);
	}
	
};




