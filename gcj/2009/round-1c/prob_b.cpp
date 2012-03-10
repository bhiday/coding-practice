#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int cases,casecount=1;
	cin>>cases;	
	
	while(cases!=0)
	{
		int flies;
		cin>>flies;
		
		vector<int> x,y,z,vx,vy,vz;
		for(int i=0;i<flies;i++)
		{
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			x.push_back(a);
			y.push_back(b);
			z.push_back(c);
			vx.push_back(d);
			vy.push_back(e);
			vz.push_back(f);	
		}
		
		long double xsum,ysum,zsum,vxsum,vysum,vzsum;
		xsum=0;
		ysum=0;
		zsum=0;
		vxsum=0;
		vysum=0;
		vzsum=0;
		
		for(int i=0;i<flies;i++)
		{
			xsum+=x.at(i);
			ysum+=y.at(i);
			zsum+=z.at(i);
			vxsum+=vx.at(i);
			vysum+=vy.at(i);
			vzsum+=vz.at(i);
		}

		xsum = xsum/flies;
		ysum = ysum/flies;
		zsum = zsum/flies;
		vxsum = vxsum/flies;
		vysum = vysum/flies;
		vzsum = vzsum/flies;
		
		//cout<<xsum<<" "<<ysum<<" "<<zsum<<endl;
		//cout<<vxsum<<" "<<vysum<<" "<<vzsum<<endl;
		
		long double t;
		
		if(vxsum==0 && vysum==0 && vzsum==0) t=0;
		else
		t = -((xsum*vxsum)+(ysum*vysum)+(zsum*vzsum))/(((vxsum*vxsum)+(vysum*vysum)+(vzsum*vzsum)));
		if(t<=0) t=0;
		
		
		long double d= sqrt(
						(xsum+vxsum*t)*(xsum+vxsum*t)+
						(ysum+vysum*t)*(ysum+vysum*t)+
						(zsum+vzsum*t)*(zsum+vzsum*t)
						);
		
		printf("Case #%d: %.8Lf %.8Lf\n",casecount,d,t);
		
		//cout<<"Case #"<<casecount<<": "<<t<<endl;
		
		cases--;
		casecount++;
	}
	return 0;
}