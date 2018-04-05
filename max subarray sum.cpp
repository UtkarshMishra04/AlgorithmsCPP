#include<iostream>
#include<limits.h>
using namespace std;

long max(long a, long b) { return (a > b)? a : b; }

long max(long a, long b, long c) { return max(max(a, b), c); }

long maxCrossingSum(long arr[], long l, long m, long h)
{
	long sum = 0;
	long left_sum = INT_MIN;
	for (long i = m; i >= l; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum)
		left_sum = sum;
	}

	sum = 0;
	long right_sum = INT_MIN;
	for (long i = m+1; i <= h; i++)
	{
		sum = sum + arr[i];
		if (sum > right_sum)
		right_sum = sum;
	}

	return left_sum + right_sum;
}

long maxSubArraySum(long arr[], long l, long h)
{
if (l == h)
	return arr[l];

long m = (l + h)/2;

return max(maxSubArraySum(arr, l, m),
			maxSubArraySum(arr, m+1, h),
			maxCrossingSum(arr, l, m, h));
}

int main()
{
	long T,N,K;
	long * A;
	long * B;
	cin>>T;
	for(long j=0;j<T;j++){
	cin>>N>>K;
	A=new long[N];
	B=new long[N*K];
	for(long i=0;i<N;i++)
	{
		cin>>A[i];
	}
	for(long i=0;i<N*K;)
	{
		for(long j=0;j<N;j++)
		{
		B[i]=A[j];
		i++;
		}
	}
	
	long max_sum=maxSubArraySum(B,0,N*K-1);
	cout<<max_sum<<endl;
}
	
}
