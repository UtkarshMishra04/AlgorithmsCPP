#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
vector<int> v;
vector<int> v1;
vector<char> v2;
float number(string s,int a,int b)
{
	float num=0;
	for(int i=a;i<=b;i++)
	{
		num=num*10+(s[i]-48);
	}
	return num;
}
float operate(float &num1,float num2,char a)
{
	switch(a){
		case '+':num1=num1+num2;
			break;
			case '-':num1=num1-num2;
			break;
				case '*':num1=num1*num2;
			break;
				case '/':num1=num1/num2;
			break;
	}
}
string breakstring(string s,int a,int b)
{
	string Z;
	for(int i=a+1;i<=b-1;i++)
	Z+=s[i];
	cout<<endl<<Z<<endl;
	return Z;
}
int countSign(string s)
{
	int count=0;
	for(int i=0;i<=s.size();i++)
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
	{
	count++;
	v.push_back(i);
	}

	return count;
}
int countbracket(string s)
{
	int count=0;
	for(int i=0;i<=s.size();i++)
	if(s[i]=='('||s[i]==')')
	{
	count++;
	}
	return count;
}
int countmul(string s)
{
	int count=0;
	for(int i=0;i<=s.size();i++)
	if(s[i]=='*')
	{
	count++;
	}
	return count;
}
int countdiv(string s)
{
	int count=0;
	for(int i=0;i<=s.size();i++)
	if(s[i]=='/')
	{
	count++;
	}
	return count;
}
string multiplyfirst(string &s)
{
	vector<int> addv,allv,x,y,p;
	int k,l,j;
	while(countmul(s)!=0)
	{
	double num[]={0,0};
	k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		allv.push_back(i);
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='*')
		addv.push_back(i);
	}
	int m=0;
	for(int i=0;i<allv.size();i++)
	{
		if(addv[m]==allv[i])
		{
		x.push_back(allv[i]);
		if(i>=1)
		y.push_back(allv[i-1]);
		m++;
		}
	}
	cout<<endl;
	int v=0;
	int n=0;
		for(j=addv[n]+1;(s[j]!='+'&&s[j]!='-'&&s[j]!='*'&&s[j]!='/'&&j<s.size());j++)
		{num[0]=num[0]*10+double(int(s[j])-48);
		v++;
		}
		cout<<endl<<j<<endl;
		for(l=addv[n]-1;(s[l]!='+'&&s[l]!='-'&&s[l]!='*'&&s[l]!='/'&&l>=0);l--)
		{
			num[1]=num[1]+double(int(s[l])-48)*pow(10,k);
			k++;
		}
		cout<<endl<<l<<endl;
		cout<<num[0]<<endl;
		cout<<num[1]<<endl;
		double numx=num[1]*num[0];
		cout<<numx<<endl;
		ostringstream ss1;
			ss1 <<numx;
			string r1=ss1.str();
			s.erase(addv[n]-k,k+v+1);
			s.insert(addv[n]-k,r1);
			cout<<s;
			addv.clear();
			allv.clear();
			x.clear();
			y.clear();
			p.clear();
			n++;
}

	return s;
}
string dividefirst(string &s)
{
	vector<int> addv,allv,x,y,p;
	int k,l,j;
	while(countdiv(s)!=0)
	{
	double num[]={0,0};
	k=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		allv.push_back(i);
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='/')
		addv.push_back(i);
	}
	int m=0;
	for(int i=0;i<allv.size();i++)
	{
		if(addv[m]==allv[i])
		{
		x.push_back(allv[i]);
		if(i>=1)
		y.push_back(allv[i-1]);
		m++;
		}
	}
	cout<<endl;
	int v=0;
	int n=0;
		for(j=addv[n]+1;(s[j]!='+'&&s[j]!='-'&&s[j]!='*'&&s[j]!='/'&&j<s.size());j++)
		{num[0]=num[0]*10+double(int(s[j])-48);
		v++;
		}
		cout<<endl<<j<<endl;
		for(l=addv[n]-1;(s[l]!='+'&&s[l]!='-'&&s[l]!='*'&&s[l]!='/'&&l>=0);l--)
		{
			num[1]=num[1]+double(int(s[l])-48)*pow(10,k);
			k++;
		}
		cout<<endl<<l<<endl;
		cout<<num[0]<<endl;
		cout<<num[1]<<endl;
		double numx=num[1]/num[0];
		cout<<numx<<endl;
		ostringstream ss1;
			ss1 <<numx;
			string r1=ss1.str();
			s.erase(addv[n]-k,k+v+1);
			s.insert(addv[n]-k,r1);
			cout<<s;
			addv.clear();
			allv.clear();
			x.clear();
			y.clear();
			p.clear();
			n++;
}

	return s;
}
string bracketfirst(string &s)
{
		if(countbracket(s)%2==0){
	while(countbracket(s)!=0)
	{
		float num[2];
		for(int h=0;h<=s.size();h++)
			{
				if(s[h]=='(')
				{
					
					v1.push_back(h);
					v2.push_back('(');
				}
				else if(s[h]==')')
				{
					v1.push_back(h);
					v2.push_back(')');
				}
			}
				for(int p=0;p<v1.size();p++)
				cout<<v1[p]<<" ";
				cout<<endl;
					for(int p=0;p<v1.size();p++)
				cout<<v2[p]<<" ";
				cout<<endl;
		for(int p=0;p<v1.size();p+=2)
		{
			int a=0,b,i,j,k=0,z=0,x;
			string Z=breakstring(s,v1[p],v1[p+1]);
				for(j=1;j<=countSign(Z)+1;j++)
				{
					
					for(i=a;i<=Z.size();i++)
						{
							if(Z[i]=='+'||Z[i]=='-'||Z[i]=='*'||Z[i]=='/')	
								{	x=i;
									b=x-1;
									break;
								}
							if(i>v[v.size()-1])
								{
									b=Z.size()-1;
									break;
								}
						}
				num[k]=number(Z,a,b);
				k++;
			
				if(k==2)
				{
					operate(num[0],num[1],Z[v[z]]);
					z++;
					k=1;
				}
				a=x+1;
				
				}
			ostringstream ss;
			ss <<num[0];
			string r=ss.str();
			s.erase(v1[p],Z.size()+2);
			s.insert(v1[p],r);
			v1.clear();
			v2.clear();
			v.clear();
						
		}
	}
}
	else
	{
		cout<<endl<<"incomplete expression";
		exit(0);
	}
return s;
}
int main()
{
	string s;
	ut:
	cout<<"enter a string:\t";
	cin>>s;
	cout<<endl;
	
	s=bracketfirst(s);
	s=dividefirst(s);
	s=multiplyfirst(s);
 int a=0,b,i,j,k=0,z=0,x;	
 float num[2];	
	for(j=1;j<=countSign(s)+1;j++)
	{
		
	for(i=a;i<=s.size();i++)
	{
	if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')	
	{	x=i;
		b=x-1;
		break;
	}
	if(i>v[v.size()-1])
	{
	b=s.size()-1;
	break;
	}
	}
	num[k]=number(s,a,b);

	k++;

	if(k==2)
	{
		operate(num[0],num[1],s[v[z]]);
		z++;
		k=1;
	}
	a=x+1;
	
	}
	cout<<endl<<endl<<num[0];
	char ch;
	cout<<endl<<"try again? (y/n):\t";
	cin>>ch;
	cout<<endl;
	if(ch=='y')
	goto ut;
	return 0;
}
