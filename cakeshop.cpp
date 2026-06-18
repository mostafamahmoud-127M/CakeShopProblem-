#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;
double RandNum(double low, double high)
{
	double r = (double)rand() / (double)(RAND_MAX + 1);
	double rawVal (low + (r * (high - low)));
	return round(rawVal * 100.0) / 100.0;
}

int main()
{
	double p = 8.5, c = 5, s = 2.5, r;
	double z = 0, total_z = 0;
	int x, d, day;
	double maxx = 0;
	int idx = 0;
	int daily_dem[9] = { 0,10,20,30,40,50,60,70,80 };
	double cdf[10] = { 0,0.05  , 0.15 , 0.2 , 0.3 , 0.45 , 0.75 , 0.9 , 0.95 , 1 };
	srand((unsigned)time(0));
	for (x = 50; x <= 80; x += 10)
	{
		total_z = 0;
		for (day = 1; day <= 10; day++)
		{
			r = RandNum(0, 1);
			//cout<<"The random number is :" << r << endl;
			for (int i = 0; i < 10; i++)
			{
				if (r >= cdf[i] && r < cdf[i + 1])
				{
					d = daily_dem[i];
					//cout<<"And its daily demand :" << d << endl;
					//cout << "=================================\n";
					break;
				}
			}
			if (x > d)
			{
				z = (6 * d) - (2.5 * x);  //z = d(p-c) + (x-d)(s-c)
			}
			else if(x>=d)
			{
				z = 3.5 * x;              // z = (p-c)x
			}
			total_z += z;
			
		}
		cout << "The total_profit when the quatitiy equal " << x << " is :" << total_z << endl;
		cout << "=============================================================================\n";
		if (total_z > maxx)
		{
			maxx = total_z;
			idx = x;
		}

	}
	cout << "The max profit is :" << maxx << " At quantity equal " << idx << endl;

	return 0;
}