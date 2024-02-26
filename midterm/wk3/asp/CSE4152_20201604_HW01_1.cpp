#include<iostream>
#include<vector>
using namespace std;
void optimized_Search(int);
int n;
int opt = INT_MAX;
vector<int> stk, fin;
vector<int>::iterator iter;

int main()
{
	cin >> n;
  stk.push_back(1);
	optimized_Search(1);
	cout << fin.size()-1 << " ";
	for (iter=fin.begin(); iter<fin.end(); iter++)	cout << *iter << " ";
}

void optimized_Search(int x)
{
	if(stk.size() >= opt) return;
	if(x==n){
		if(stk.size() < opt){
			opt = stk.size();
			while(!fin.empty())	fin.pop_back();
			for(iter=stk.begin(); iter<stk.end(); iter++)	fin.push_back(*iter);	
		}
	}
		
	for(int i=stk.size()-1; i>=0; i--){
		if(x+stk[i] <= n){
			stk.push_back(x+stk[i]);
			optimized_Search(x+stk[i]);
			stk.pop_back();
		}
	}
}