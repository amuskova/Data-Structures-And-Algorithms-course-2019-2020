#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else if(b > a)
    {
        return b;
    }
    return 0;
}
struct Node
{
	double value;
	Node *left;
	Node *right;
    int height=0;
    Node()
    {
        this->value=0;
        this->height=0;
        this->left=NULL;
        this->right=NULL;
    }
    Node(double data)
    {
        this->value =data;
        left=NULL;
        right=NULL;
    }
	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
    void calculateHigh()
    {
        height=0;
        if(left)
        {
            height=max(height, left->height + 1);
        }
        if(right)
        {
            height=max(height, right->height + 1);
        }
    }
    int leftHeight()
    {
        if(left)
        {
            return left -> height + 1;
        }
        return 0;
    }
    int rightHeight()
    {
        if(right)
        {
            return right -> height + 1;
        }
        return 0;
    }
    int balance()
    {
        return leftHeight()-rightHeight();
    }
    void rotateRight()
    {
        if(!left)
        {
            return;
        }

        Node *leftright= this->left->right;
        Node *oldRight=this->right;

        swap(this->value, this->left->value);
        this->right=this->left;
        this->left=this->left->left;

        this->right->left=leftright;
        this->right->right=oldRight;
    }
    void rotateLeft()
    {
        if(!right)
        {
            return;
        }

        Node* rightLeft=this->right->left;
        Node* oldLeft=this->left;
        swap(this->value, this->right->value);
        this->left=this->right;
        this->right=this->right->right;
        this->left->left=oldLeft;
        this->left->right=rightLeft;
    }
    void recalculateHight()
    {
        if(left)
        {
            left->calculateHigh();
        }
        if(right)
        {
            right->calculateHigh();
        }
        this->calculateHigh();
    }
    void fixTree()
    {
        if(balance()<-1)
        {
            if(right->balance()<-1)
            {
                this->rotateLeft();
                recalculateHight();
            }
            else if(right->balance()>=1)
            {
                right->rotateRight();
                this->rotateLeft();
                recalculateHight();
            }
        }
        else if(balance()>1)
        {
            if(left->balance()<=-1)
            {

                left->rotateLeft();
                this->rotateRight();
                recalculateHight();
            }
            else if(left->balance()>=1)
            {
                this->rotateRight();
                recalculateHight();
            }
        }
    }

};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}
    Node* _add(Node* cur, double data)
    {
        if(!cur)
        {
            return new Node(data);
        }
        if(data < cur -> value)
        {
            cur->left=_add(cur -> left, data);
        }
        else if(data > cur -> value)
        {
            cur->right=_add(cur -> right, data);
        }
        cur->calculateHigh();
        cur->fixTree();
        return cur;
    }
    Node* _remove(Node* cur, double data)
    {
        if( !cur )
        {
            return NULL;
        }
        if(data < cur->value)
        {
            cur->left=_remove(cur->left,data);
        }
        else if(data > cur-> value)
        {
            cur->right = _remove(cur->right,data);
        }
        else
        {
            if(!cur->left && !cur->right)
            {
                delete cur;
                return NULL;
            }
            else if(!cur->left)
            {
                Node *tmp=cur->right;
                delete cur;
                return tmp;
            }
            else if(!cur->right)
            {
                Node *tmp=cur->left;
                delete cur;
                return tmp;
            }
            else
            {
                Node *swapp=cur->right;
                while(swapp->left)
                {
                    swapp=swapp->left;
                }
                cur -> value = swapp -> value;
                cur->right=_remove(cur->right,swapp->value);
            }
        }

        cur->calculateHigh();
        cur->fixTree();

        return cur;
    }

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double data)
	{
        if(contains(data)== true)
        {
            cout<<data<<" already added"<<endl;
        }
        else
        {
            root=_add(root,data);
        }
	}

	void remove(double data)
	{
        if(contains(data)==false)
        {
            cout<<data<<" not found to remove"<<endl;
        }
        else
        {
           root=_remove(root,data);
        }
	}

bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
        cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
    cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
