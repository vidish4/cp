//https://www.geeksforgeeks.org/sum-triangle-from-array/

#include <iostream>
#include<vector>
using namespace std;

void solve (vector<vector<int>> &ans,int n)
{
    if (n==0)
        return;
    vector<int> v;
    for (int i=0;i<ans[ans.size()-1].size()-1;i++)
    {
        v.push_back(ans[ans.size()-1][i] + ans[ans.size()-1][i+1] );
    }
    ans.push_back(v);
    solve(ans,n-1);
    return;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
	vector<vector<int>> ans;
	ans.push_back(v);
	solve(ans,n);
	
	for (int i=0;i<ans.size();i++)
	{
	    for (int j=0;j<ans[i].size();j++)
	    {
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}