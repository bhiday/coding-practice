#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int cases,casecount=1;
	cin>>cases;	
	int num;
	
	
	int counter;
	
	while(cases!=0)
	{
		cin>>num;
		int occ[10]={0,0,0,0,0,0,0,0,0,0};
		counter=num+1;
		int tmp = num;
		while (tmp != 0)
		{
			int rem = tmp % 10;
			tmp = tmp/10;
			occ[rem]++;	
		}
		
		while(1)
		{
			int newocc[10]={0,0,0,0,0,0,0,0,0,0};
			int tmp = counter;
			while (tmp != 0)
			{
				int rem = tmp % 10;
				tmp = tmp/10;
				newocc[rem]++;	
			}
		
			bool flag = true;
			for(int i = 1;i<=9;i++)
			{	
				if(occ[i]!=newocc[i])
				{
					//cout<<i<<" "<<occ[i]<<endl;
					flag = false;
					break;	
				}
				
			}
		
		if(flag==true) break;
		
		
		counter++;
		
			
		}	
		
		cout<<"Case #"<<casecount<<": "<<counter<<endl;
		
		cases--;
		casecount++;
	}
	return 0;
}