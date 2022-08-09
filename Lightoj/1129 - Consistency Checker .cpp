#include<bits/stdc++.h>
using namespace std;

bool compare (string a,string b){

	return a>b;
}

struct trie{

	trie* child[12];
	//map<char,trie*>child;
	bool check;
	trie(){
		check=false;
		for(int i=0;i<12;i++)child[i]=NULL;
	}
};

bool Insert (trie* head,string s){

	trie* cur=head;

	for(int i=0;i<s.size();i++){

		int id=s[i]-'0';
		//char id=s[i];

		if(cur->child[id]==NULL){
			cur->child[id]=new trie();
		}
		cur=cur->child[id];
		if(i==s.size()-1){
			if(cur->check)return 1;
			else {
				cur->check=true;
				return 0;
			}
		}
		cur->check=1;
	}
}

//void del(trie* cur)
//{
//    for (auto it:cur->child)
//        if (it.second){
//            cur=it.second;
//            del(cur);
//        }
//    cur->child.clear();
//}

void del(trie* cur)
{
    for (int i = 0; i < 12; i++)
        if (cur->child[i])
            del(cur->child[i]);
    delete (cur);
}

int main(){

	int t;
	scanf("%d",&t);

	for(int c=1;c<=t;c++){
		int n;
		scanf("%d",&n);
		char s[106];
		vector<string>V;
		for(int i=0;i<n;i++){
			scanf("%s",s);
			string ns=s;
			V.push_back(ns);
		}
		sort(V.begin(),V.end(),compare);
		trie* root=new trie();int check=0;
		for(int i=0;i<n;i++){
			bool ans=Insert(root,V[i]);
			if(ans){
				printf("Case %d: NO\n",c);
				check=1;break;
			}

		}
		if(!check)printf("Case %d: YES\n",c);
		del(root);
	}

}
