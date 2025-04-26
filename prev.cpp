#include<bits/stdc++.h>
#include "BST.h"
using namespace std;
void Menu(){
    cout<<"\n\n\t\t\tPress 1 to add word"<<endl;
    cout<<"\t\t\tPress 2 to print all words"<<endl;
    cout<<"\t\t\tPress 3 delete a word"<<endl;
    cout<<"\t\t\tPress 4 words with same meaning"<<endl;
    cout<<"\t\t\tPress 5 to find meaning of a word"<<endl;
    cout<<"\t\t\tEnter 'menu' to see the menu"<<endl;
    cout<<"\t\t\tPress 0 to exit"<<endl<<endl;
}
void convertString(string &s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
}
void ReadFile(Node* &root,Tree &t){
    ifstream inp("words.txt");
    string line;
    while(getline(inp,line)){
        istringstream iss(line);
        string w,m;
        if(getline(iss,w,':')&&getline(iss,m)){
            convertString(w);
            convertString(m);
            root=t.insert(root,w,m);
        }
    }
    inp.close();
}
int main()
{
    cout<<"\t\t\t__        __   _                           \n";
    cout<<"\t\t\t\\ \\      / /__| | ___ ___  _ __ ___   __  \n";
    cout<<"\t\t\t \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ \n";
    cout<<"\t\t\t  \\ V  V /  __/ | (_| (_) | | | | | |  __/ \n";
    cout<<"\t\t\t   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| \n";
    cout<<"\t\t\t\t _                           \n";
    cout<<"\t\t\t\t| |_ ___     ___  _   _ _ __ \n";
    cout<<"\t\t\t\t| __/ _ \\   / _ \\| | | | '__|\n";
    cout<<"\t\t\t\t| || (_) | | (_) | |_| | |   \n";
    cout<<"\t\t\t\t \\__\\___/   \\___/ \\__,_|_|   \n";
    cout<<"\t\t\t ____  _      _   _                              \n";
    cout<<"\t\t\t|  _ \\(_) ___| |_(_) ___  _ __   __ _ _ __ _   _ \n";
    cout<<"\t\t\t| | | | |/ __| __| |/ _ \\| '_ \\ / _` | '__| | | |\n";
    cout<<"\t\t\t| |_| | | (__| |_| | (_) | | | | (_| | |  | |_| |\n";
    cout<<"\t\t\t|____/|_|\\___|\\__|_|\\___/|_| |_|\\__,_|_|   \\__, |\n";
    cout<<"\t\t\t                                           |___/ \n";
    Node* root=NULL;
    Tree t;
    vector<string>v;
    string choice;
    string str,meaning,p;
    Menu();
    ReadFile(root,t);
    while(true)
    {
        cout<<"\t\t\tEnter your choice: ";

        cin>>choice;
        if(choice=="1")
        {
            cout<<"\t\t\tEnter word: ";
            cin>>ws;
            getline(cin,str);
            if(t.search(root,str)){
                cout<<"\t\t\tWord already exists."<<endl<<endl;
                continue;
            }
            cout<<"\t\t\tEnter meaning: ";
            cin>>ws;
            getline(cin,meaning);
            convertString(str);
            convertString(meaning);
            root=t.insert(root,str,meaning);
            fstream o;
            o.open("words.txt",ios::app);
            if(o.is_open()){
                o<<str<<':'<<meaning<<endl;
                o.close();
            }
            cout<<"\t\t\tWord added successfully"<<endl<<endl;
        }
        else if(choice=="2")
        {
            t.levelorder(root);
            cout<<endl;
        }
        else if(choice=="3")
        {
            cout<<"\t\t\tEnter a word to delete: ";
            cin>>ws;
            getline(cin,str);
            if(!t.search(root,str)){
                cout<<"\t\t\tWord is not in the dictionary\n\n";
                continue;
            }
            root=t.del(root,str);
            convertString(str);
            cout<<"\t\t\tDeleted successfully"<<endl<<endl;
        }
        else if(choice=="4")
        {
            cout<<"\t\t\tEnter the meaning: ";
            cin>>ws;
            getline(cin,p);
            convertString(p);
            t.findsimilarmeaningword(root,p);
            cout<<endl;
        }
        else if(choice=="5")
        {
            cout<<"\t\t\tEnter the word you want to search: ";
            cin>>ws;
            getline(cin,str);
            convertString(str);
            Node* f=t.search(root,str);
            if(f!=NULL)
            {
                cout<<"\t\t\tThe word is found: ";
                cout<<f->str<<endl;
                cout<<"\t\t\tMeaning: ";
                cout<<f->meaning<<endl;

            }
            else
            {
                cout<<"\t\t\tWord not found: "<<endl;
                cout<<"\t\t\tDid you mean ";
                t.notfound(root,str);
                cout<<" ?";
            }
            cout<<endl;
        }
        else if(choice=="menu")Menu();
        else if(choice=="0")exit(1);
        else cout<<"\n\t\t\tPlease enter a valid command\n\n";
    }
    return 0;
}



