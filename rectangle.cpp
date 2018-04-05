#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int n[4];
	for(int i=0;i<N;i++){
		for(int j=0;j<4;j++)
		{
			cin>>n[j];
		}
		sort(n,n+4);
		if(n[0]==n[1] && n[2]==n[3])
		cout<<"YES\n";
		else
		cout<<"NO\n";	
	}
}
