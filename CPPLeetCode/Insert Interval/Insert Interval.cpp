#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:	
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
		Interval sIn(newInterval.start,newInterval.end);
		Interval eIn(newInterval.start,newInterval.end);		
		int n = intervals.size();
		int spos = 0;
		int epos = n-1;
		for(int i =0; i<n ;i++ )
		{
			if(intervals[i].start<=newInterval.start)
			{
				if(intervals[i].end >= newInterval.start)
				{
					sIn = intervals[i];
					spos=i;
					break;
				}
				spos=i+1;
			}
		}
		for(int i =n-1; i>=spos ;i-- )
		{
			if(intervals[i].end>=newInterval.end)
			{
				if(intervals[i].start <= newInterval.end )
				{
					eIn = intervals[i];	
					epos = i;
					break;		
				}			
				epos=i-1;
			}
		}

		cout << spos<< epos <<endl;
		if(spos<=epos)
		intervals.erase(intervals.begin()+spos,intervals.begin()+epos+1);
		sIn.end = eIn.end;
		intervals.insert(intervals.begin()+spos,sIn);
		return intervals;
	}
		void show(	vector<Interval > &out)
	{
		vector<Interval>::iterator itend = out.end();
		for(vector<Interval>::iterator it = out.begin();it!=itend;it++)
		{
			if(it!= itend-1)
			cout <<"["<< (*it).start<<"," <<(*it).end<<"]" << ",";
			else
			cout <<"["<< (*it).start<<"," <<(*it).end<<"]" << endl;
		}
	}
};
	

int main()
{
	vector<Interval > in;
		in.push_back(Interval(0,1));	
	in.push_back(Interval(2,6));	

	Solution s;
	vector<Interval > out = s.insert(in,Interval(0,0));
	s.show(out);
	return 0;
}

