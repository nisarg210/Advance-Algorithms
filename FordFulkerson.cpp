#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int bfs(vector<vector<int>> &rGraph, int source, int sink, vector<int> &parent)
{
	int vertices=rGraph.size();
	int visited[vertices]= {0};
	q.push(source);
	visited[source]=1;
	parent[source]=-1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=0; v<vertices; v++)
		{
			if(visited[v]==0 && rGraph[u][v]>0)
			{
				if(v==sink)
				{
					parent[v]=u;
					return 1;
				}
				q.push(v);
				parent[v]=u;
				visited[v]=1;
			}
		}
	}

	return 0;
}

int FordFulkerson(vector<vector<int>> rGraph, int source, int sink)
{
	int v=rGraph.size();
	vector<int> parent(v,0);
	int max_flow=0;
	while(bfs(rGraph,source,sink,parent))
	{
		int pflow=INT_MAX;
		for(v=sink; v!=source; v=parent[v])
		{
			int u=parent[v];
			pflow=min(pflow,rGraph[u][v]);
		}

		max_flow+=pflow;

		for(v=sink; v!=source; v=parent[v])
		{
			int u=parent[v];
			rGraph[u][v]-=pflow;
			rGraph[v][u]+=pflow;
		}

	}
	return max_flow;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

	int v;
	cin>>v;
	vector<vector<int>> rGraph( v , vector<int> (v, 0));
	for(int i=0; i<v; i++)
		for(int j=0; j<v; j++)
			cin>>rGraph[i][j];
	
	int source, sink;
	cin>>source>>sink;
	cout<<"Maximum flow: "<<FordFulkerson(rGraph,source,sink);
	
	return 0;
}