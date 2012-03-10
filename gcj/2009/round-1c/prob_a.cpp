#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

long long tobase(vector<int> v,int base)
{
	long long a=0;
	//reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		a=a*base+v.at(i);
	}
	return a;
}	


int main()
{
	int cases,casecount=1;
	cin>>cases;	
	
	while(cases!=0)
	{
		string s;
		cin>>s;
		string temp = s;
		string::iterator s1;
		sort(temp.begin(),temp.end());
		s1=unique(temp.begin(),temp.end());
		
		int base=s1-temp.begin();
		//cout<<base;
		vector<int> vals;
		for (int i=0;i<s.length();i++) vals.push_back(0);
		
		int counter=0;
		int put=1;
		for(int i=0;i<base;i++)
		{
			while(s[counter]=='A') counter++;
			char c=s[counter];
			for(int j=0;j<s.length();j++)
			{
				if(c==s[j])
				{
					s[j]='A';
					vals.at(j)=put;
					
				}	
			}
			if(put==1) put=0;
			else if(put==0) put=2;
			else put++;
		}
		
		//for(int i=0;i<vals.size();i++) cout<<vals.at(i)<<endl;
		if (base==1) base++;
		long long answer=tobase(vals,base);
		
		cout<<"Case #"<<casecount<<": "<<answer<<endl;
		cases--;
		casecount++;
	}
	return 0;
}