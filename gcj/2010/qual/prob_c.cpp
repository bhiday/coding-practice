#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

int main()
{
	int cases = 0;
	int casecount = 0;
	long long runs = 0;
	long long capacity = 0;
	long long numgroups = 0;
	long long answer = 0;
	
	cin >> cases;
	
	do
	{
		cin >> runs >> capacity >> numgroups;

		//read groups
		vector <long long> groups;
		map <long long, vector <long long> > memory;
		for (int i=0; i<numgroups; i++) 
		{
			long long temp;
			cin >> temp;
			groups.push_back(temp);
		}

		//input done, start processing
		int currentindex = 0;

		while (runs > 0)
		{
			bool flag = false;
			long long filled = 0;

			vector <long long> mem; //0 = earned, 1 = nextindex
			int tempindex = currentindex;

			if (groups.at(currentindex) <= (capacity - filled))
			{
				mem.push_back(0);
				mem.push_back(0);
			}
			else break;

			map <long long, vector <long long> >::iterator it;

			//new approach
			it=memory.find(currentindex);
			if (it!=memory.end())
			{
				//debug
				//for (map<long long, vector < long long > >::iterator it1=memory.begin() ; it1 != memory.end(); it1++ )
				//{
				//	cout << (*it1).first << " => "<< (*it1).second.at(0) << " "<<  (*it1).second.at(1) << endl;
				//}

				
				int tempindex = currentindex;
				long long cyclewt = 0;
				long long cycleruns = 0;
				//finding complete loop...
				do
				{
					cyclewt += (*it).second.at(0);
					currentindex = (*it).second.at(1);
					cycleruns++;
					it=memory.find(currentindex);
				} while (tempindex!=currentindex);

				long long skips = runs/cycleruns;
				long long left = runs%cycleruns;
				runs -= (skips*cycleruns);
				answer += skips*cyclewt;

				
				while (runs != 0)
				{
					answer += (*it).second.at(0);
					currentindex = (*it).second.at(1);
					it=memory.find(currentindex);
					runs--;	
				}
				flag = true;
				break;
				
				
			}

			
			do
			{
				//old approach
				if (groups.at(currentindex) <= (capacity - filled))
				{
					filled += groups.at(currentindex);
					answer += groups.at(currentindex);
					mem.at(0) += groups.at(currentindex);
				
					currentindex++;
					if (currentindex > groups.size() - 1)
					{
						currentindex = 0;
					}
				
					mem.at(1) = currentindex;

				}
				else
				{
					break;
				}

			} while (filled < capacity && currentindex != tempindex);

			if (flag == false) { memory.insert(pair<long long, vector <long long> >(tempindex,mem)); }
			else break;
			runs--;
		}

		//debug
		//for (map<long long, vector < long long > >::iterator it=memory.begin() ; it != memory.end(); it++ )
    		//{
    		//	cout << (*it).first << " => "<< (*it).second.at(0) << " "<<  (*it).second.at(1) << endl;
		//}
		
		casecount++;
		cout << "Case #" << casecount << ": "<< answer << endl;
		answer = 0;
				
	} while (casecount != cases);

	return 0;
}
