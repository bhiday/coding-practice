#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(vector<int> i, vector <int> j){
	return (i.at(0)<j.at(0));
}

int main()
{
	int cases = 0;
	int casecount = 0;
	int answer=0;
	cin >> cases;
	
	do
	{
		vector <vector <int> > wins;
		int wires;
		cin >> wires;

		for(int i=0;i<wires;i++)
		{
			int t1,t2;
			cin>>t1>>t2;
			vector <int> temp;
			temp.push_back(t1);
			temp.push_back(t2);
			wins.push_back(temp);
		}
		
		//logic 
		sort(wins.begin(),wins.end(),func);
		int count = 0;
		for (int i=0;i<wins.size();i++)
		{
			for (int j=0;j<i;j++)
			{
				if(wins.at(i).at(1)<wins.at(j).at(1)) count++;
			}
		}

		
		/*or (int i=0;i<wins.size();i++)
		{
			cout<<wins.at(i).at(0)<<" "<<wins.at(i).at(1)<<endl;
		}*/
		answer = count;
		casecount++;
		cout << "Case #" << casecount << ": "<< answer << endl;
		answer=0;
		
	} while (casecount != cases);

	return 0;
}
