#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    string str;
    string meaning;
    Node* left;
    Node* right;
    Node(string str,string meaning)
    {
        this->str=str;
        this->meaning=meaning;
        this->left=NULL;
        this->right=NULL;
    }
};
class Tree
{
public:
    Node* insert(Node* &root,string str,string meaning)
    {
        if(root==NULL)
        {
            Node* n=new Node(str,meaning);
            return n;
        }

        else if(str.compare(root->str)<0)
        {
            root->left=insert(root->left,str,meaning);
        }
        else if(str.compare(root->str)>0)
        {
            root->right=insert(root->right,str,meaning);
        }
        return root;
    }
    void dis(Node* &root)
    {
        if(root==NULL)
        {
            return;
        }
        dis(root->left);
        cout<<root->str <<endl;
        dis(root->right);
    }
    void levelorder(Node* &root)
    {
        if(root==NULL){
            cout<<"\t\t\tNo word has been added yet!\n";
            return;
        }
        cout<<"\t\t\tAll the words: "<<endl;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(curr!=NULL)
            {
                cout<<"\t\t\t"<<curr->str<<endl;
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            else
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                else
                {
                    break;
                }
            }
        }
    }
    Node* search(Node* &root,string word)
    {
        if(root==NULL)
        {

            return NULL;
        }
        if(root->str==word)
        {
            return root;
        }
        else if(root->str>word)
        {
            return search(root->left,word);
        }
        else if(root->str<word)
        {
            return search(root->right,word);
        }


    }
    void notfound(Node* &root,string word)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->str[0]==word[0])
        {
            cout<<root->str<<" ";
        }
        notfound(root->left,word);
        notfound(root->right,word);
    }
    Node* findnode(Node* &root)
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
    Node* del(Node* &root,string word)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->str==word)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                Node* temp=root;
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                Node* temp=root;
                delete temp;
                return root->right;
            }
            else if(root->right==NULL)
            {
                Node* temp=root;
                delete temp;
                return root->left;
            }
            else
            {
                Node* l=findnode(root);
                root->str=l->str;
                root->right=del(root->right,l->str);
            }
        }
        else if(root->str>word)
        {
            root->left=del(root->left,word);
        }
        else if(root->str<word)
        {
            root->right=del(root->right,word);
        }
        return root;
    }
    void findsimilarmeaningword(Node* &root,string str)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->meaning==str)
        {
            cout<<"\t\t\t"<<root->str<<endl;
        }
        findsimilarmeaningword(root->left,str);
        findsimilarmeaningword(root->right,str);

    }
};
