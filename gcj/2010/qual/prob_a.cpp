#include <iostream>
#include <string>

using namespace std;

long long pow ( int num, int index )
{
	long long ans = 1;
	for (int i = 0; i < index; i++)
	{
		ans *= num;
	}
	return ans;
}

int main()
{
	int cases = 0;
	int casecount = 0;
	int snappers = 0;
	long long snaps = 0;
	long long limit = 0;
	string answer = "";
	
	cin >> cases;
	
	do
	{
		cin >> snappers >> snaps;
		
		limit = pow (2, snappers);
		if ((snaps % limit) == (limit - 1))
		{
			answer = "ON";
		}
		else {
			answer = "OFF";
		}
		
		casecount++;
		cout << "Case #" << casecount << ": "<< answer << endl;
		
	} while (casecount != cases);

	return 0;
}
