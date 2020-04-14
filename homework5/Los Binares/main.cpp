#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int counter=0;
struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node()
    {
        left=right=NULL;
    }
    Node(int value) {
        data = value;
    }

    ~Node() {
        delete left;
        delete right;
    }

    Node(const Node& rhs) {
        data = rhs.data;
        if (rhs.left) {
            left = new Node(*rhs.left);
        }
        if (rhs.right) {
            right = new Node(*rhs.right);
        }
    }

    Node& operator=(const Node& rhs) {
        if (this != &rhs) {
            delete left;
            delete right;

            data = rhs.data;
            if (rhs.left) {
                left = new Node(*rhs.left);
            }
            if (rhs.right) {
                right = new Node(*rhs.right);
            }
        }
        return *this;
    }
};

class BST {
private:
    Node* root = NULL;

    bool _exists(int value, Node* current) const {
        if (current) {
            if (current->data == value) {
                return true;
            } else if (value > current->data) {
                return _exists(value, current->right);
            } else { // value < data
                return _exists(value, current->left);
            }
        } else {
            return false;
        }
    }

    Node* _insert(int value, Node* current) {
        if (!current) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = _insert(value, current->left);
        } else if (value > current->data) {
            current->right = _insert(value, current->right);
        }

        return current;
    }

    void _inorder(Node* current) const {
        if (current) {
            _inorder(current->left);
            cout << current->data << " ";
            _inorder(current->right);
        }
    }
    int _findthedepth(int value, Node* current)
    {
        if(current)
        {
            if(current->data==value)
            {
                return counter;
            }
            else if(current->data<value)
            {
                counter++;
                return _findthedepth(value,current->right);
            }
            else if(current->data>value)
            {
                counter++;
                return _findthedepth(value, current->left);
            }
        }
        else
        {
            counter=-1;
        }
        return counter;
    }


public:
    BST()
    {
        root=NULL;
    }

    BST(const BST& rhs) {
        root = new Node(*rhs.root);
    }

    BST& operator=(const BST& rhs) {
        if (this != &rhs) {
            delete root;
            root = new Node(*rhs.root);
        }
        return *this;
    }

    ~BST() {
        delete root;
    }

    bool exists(int value) const {
        return _exists(value, root);
    }

    void insert(int value) {
        root = _insert(value, root);
    }



    void inorder() const {
        _inorder(root);
        cout << "\n";
    }
    int findthedepth(int value)
    {
        return _findthedepth(value,root);
    }



};

int main() {
    BST s;
    int N,K;
    cin>>N>>K;
    int a;
    for(int i = 0 ; i < N ; i++)
    {
        cin>>a;
        s.insert(a);
    }
    vector<int> v;
    v.reserve(K);
    for(int i = 0 ; i < K ; i++)
    {
        cin>>a;
        if(s.exists(a))
        {
            v.push_back(s.findthedepth(a));
        }
        else
        {
            v.push_back(-1);
        }
            //v.push_back(s.doexist(a));
           //cout<<s.doexist(a)<<endl;
            counter=0;

    }
        for(int i = 0 ; i < K ; i ++ )
        {
            cout<<v[i]<<endl;
        }


    //cout<<s.doexist(5)<<endl;
    //cout<<s.exist(5)<<endl;
   // s.inorder();
    //cout<<s.doexist(4)<<endl;

    return 0;
}
