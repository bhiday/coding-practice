#include<iostream>
#include<vector>

using namespace std;

class sorty
{
	public:int alt,x,y;
};

bool sorty_sort(sorty *a,sorty *b)
{
	if(a->alt > b->alt) return true; else return false;	
};

char mini(int n, int w, int e, int s, int me)
{
	if(n<me && n<=w && n<=e && n<=s) return 'n';
	if(w<me && w<n  && w<=e && w<=s) return 'w';
	if(e<me && e<n  && e<w  && e<=s) return 'e';
	if(s<me) return 's';
	return '\0';
}

int main()
{
	int cases,casecount=1;
	cin>>cases;
	while (cases!=0)
	{
		int h,w,i,j;
		cin>>h>>w;
		int alt[100][100];
		char label[100][100];
		char letter = 'A';		
		vector <sorty*> sorted;
		
		for(i = 0; i < h; i++)
			{
				for(j = 0; j < w; j++)
				{					 
					cin>>alt[i][j];
					label[i][j]='\0';
					sorty* temp = new(sorty);
					temp->alt=alt[i][j];
					temp->x=i;
					temp->y=j;
					sorted.push_back(temp);
				}
			}
		
		sort(sorted.begin(),sorted.end(),sorty_sort);
		//reverse(sorted.begin(),sorted.end());
		
		int k;
		for(k=0;k<sorted.size();k++)
		{
			//debug
			//cout<<sorted.at(k)->alt<<" "<<sorted.at(k)->x<<" ";
			//cout<<sorted.at(k)->y<<"\n";
			//enddebug
			
			if(label[sorted.at(k)->x][sorted.at(k)->y]=='\0')
			{
				i=sorted.at(k)->x;
				j=sorted.at(k)->y;
				
				vector <int> itx,ity;
				itx.push_back(i);
				ity.push_back(j);
				
				label[i][j]=letter;
				letter++;
				
				int n,we,e,s;
				if (i-1>=0) n=alt[i-1][j]; else n=12000;
				if (j-1>=0) we=alt[i][j-1]; else we=12000;
				if (j+1<w) e=alt[i][j+1]; else e=12000;
				if (i+1<h) s=alt[i+1][j]; else s=12000;
				//debug
				//cout<<n<<w<<e<<s<<mini(n,w,e,s,alt[i][j])<<"\n";
				//cout<<i<<" "<<j<<"\n";
				
				while(mini(n,we,e,s,alt[i][j])!='\0')
				{
					
					
					//char decide=mini(n,w,e,s,alt[i][j]);
					
					switch (mini(n,we,e,s,alt[i][j]))
					{
						case 'n':
						i = i - 1;
						break;
						case 'w':
						j = j - 1;
						break;
						case 'e':
						j = j + 1;
						break;
						case 's':	
						i = i + 1;
						break;
					}
					
					//cout<<i<<" "<<j<<"\n";
					
					itx.push_back(i);
					ity.push_back(j);
					
					if(label[i][j]=='\0')
						{label[i][j]=label[itx.at(0)][ity.at(0)];
						//debug
						//cout<<"\t"<<i<<" "<<j<<" "<<char(letter-1)<<"\n";
						}else
					{
						for (int v=0;v<itx.size();v++)
						{
							label[itx.at(v)][ity.at(v)]=label[i][j];
						}	
						letter--;
						break;
					}
					
				if (i-1>=0) n=alt[i-1][j]; else n=12000;
				if (j-1>=0) we=alt[i][j-1]; else we=12000;
				if (j+1<w) e=alt[i][j+1]; else e=12000;
				if (i+1<h) s=alt[i+1][j]; else s=12000;
				//debug
				//cout<<n<<w<<e<<s<<mini(n,w,e,s,alt[i][j])<<"\n";
				}
			
			}
		}
		
		vector<char> lastone,lett;
		for(i = 0; i < h; i++)
			{	
				for(j = 0; j < w; j++)
				{
		//			lastone.push_back(label[i][j]);
					lett.push_back(label[i][j]);
				}
			}
		/*	
		sort(lastone.begin(),lastone.end());
		vector<char>::iterator it;
		it=unique(lastone.begin(),lastone.end());
		lastone.resize( it - lastone.begin() ); 
		//cout<<lastone.size()<<endl;
		*/
		for(i = 1;i<lett.size();i++)
			/*if(lett.at(i)==lett.at(i-1)) 
			{
				lett.erase(lett.begin()+i);
				i--;
			}*/
			for(int lk=0;lk<i;lk++)
				if(lett.at(lk)==lett.at(i))
				{
					lett.erase(lett.begin()+i);
					i--;
					break;
				}
			
		
		char curlet=label[0][0];
		char replet='a';
		for(int uff=0;uff<lett.size();uff++)
		{
			for(i = 0; i < h; i++)
			{	
				for(j = 0; j < w; j++)
				{
					if(label[i][j]==lett.at(uff)) label[i][j]=replet;
					//if(label[i][j]==curlet) label[i][j]=replet;
					//else
					//{
					//	replet++;
					//	curlet=label[i][j];
					//	label[i][j]=replet;
					//}
				}
			}
		replet++;
		}	
		
		cout<<"Case #"<<casecount<<":\n";
		for(i = 0; i < h; i++)
		{	
			for(j = 0; j < w; j++)
			{
				cout<<label[i][j];
				if (j!=w-1) cout<<" ";
			}
			cout<<"\n";
		}

		
		
		casecount++;
		cases--;
	}
	return 0;	
}