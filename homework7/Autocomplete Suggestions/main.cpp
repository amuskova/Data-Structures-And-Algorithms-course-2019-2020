#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
char c;
struct Node
{
    int pref;
    bool endWord;
    map<char,Node*> child;
    Node()
    {
        pref=0;
        endWord=false;
    }
    Node(int newpref, bool newEnd)
    {
        pref=newpref;
        endWord=newEnd;
    }
};
void insert(Node* r, string word)
{
    Node* cur=r;
    for(int i = 0 ; i < word.size();i++)
    {
        c=word[i];
        Node *newNode=cur->child[c];
        if(!newNode)
        {
            newNode=new Node();
            cur->child[word[i]]=newNode;
        }
        cur=newNode;
        cur->pref+=1;
    }
    cur->endWord=true;
}
int numberogPref(Node *r, string word)
{
    Node *cur=r;
    for(int i = 0 ; i < word.size() ; i++)
    {
        c=word[i];
        Node *newNode=cur->child[c];
        if(!newNode)
        {
            return 0;
        }
        cur=newNode;
    }
    return cur->pref;
}
int main()
{
    Node *root=new Node();
    int n,q;
    cin>>n>>q;
    string word;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>word;
        insert(root,word);
    }
    vector<int> v;
    for(int i = 0 ; i < q ; i++)
    {
        cin>>word;
        v.push_back(numberogPref(root,word));
    }
    for(int i = 0 ; i < q ; i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
