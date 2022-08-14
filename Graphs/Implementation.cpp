#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

//Graph implementation using node->list
class graph{
    public:
        unordered_map<T,list<T>> g;
    
    void graphinsert(T u,T v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    void print(){
        for (auto i:g){
            cout<<i.first<<"->";
            for (auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int n,e;
    cout<<"Enter number of Nodes: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter number of Edges: ";
    cin>>e;
    cout<<endl;
    cout<<"Enter nodes with Edges between them: ";
    graph<int> g;
    for (int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.graphinsert(u,v);
    }
    g.print();
    return 0;
}