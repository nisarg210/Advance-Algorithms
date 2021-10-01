#include<bits/stdc++.h>

using namespace std;

int Partition(vector<int> &arr, int p, int r){
	int x= arr[r];
	int i=p-1;
	int j;
	for(int j=p; j<=r-1; j++){
		arr[0]++;
		if(arr[j]<=x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

int Randomized_Partition(vector<int> &arr, int p, int r){
	srand(time(0));
	int random= (rand()%(r-p+1)) + p;
	swap(arr[random],arr[r]);
	return (Partition(arr,p,r));
}

void Randomized_Quicksort(vector<int> &arr, int p, int r)
{
	if(p<r)
	{
		int q=Randomized_Partition(arr,p,r);
		Randomized_Quicksort(arr,p,q-1);
		Randomized_Quicksort(arr,q+1,r);
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n+1);
	arr[0]=0; //stores number of comparisons
	int case_num=0;
	cin>>case_num;
	srand(rand());
	int random=0;
	if(case_num==1){
		random=rand()%int(1e9);
		for(int i=1; i<=n; i++)
			arr[i]=random+i;
	}
	else if(case_num==2){
		random=rand()%int(1e9);
		for(int i=1; i<=n; i++)
			arr[i]=random-i;
	}
	else
	{
		for(int i=1; i<=n; i++)
			arr[i]=rand()%int(1e9);
	}

	Randomized_Quicksort(arr,1,n);

	cout<<"\nTotal comparisions for case "<<case_num<<": "<< arr[0]<<endl;

	for(int i=1; i<=n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//input
//3
//1000 1
//1000 2
//1000 3
	
	int t=0;
	srand(time(0));
	cin>>t;
	while(t--){
		solve();
	} 
	
}
