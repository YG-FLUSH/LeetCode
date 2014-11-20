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
	bool cmp(Interval first,Interval second)
	{
		return first.start < second.end;
	}
class Solution {
public:	

	
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
		Interval newone(newInterval.start,newInterval.end);
		bool Scross = false, Ecross = false;
		for(vector<Interval>::iterator it = intervals.begin();it!= intervals.end();)
		{	
				
			if((*it).start <= newInterval.start && newInterval.end <= (*it).end)
			{
				return intervals;
			}	
			
			if((*it).start> newInterval.start && (*it).end < newInterval.end)
			{
				intervals.erase(it);
				continue;
			}	
			if((*it).start <= newInterval.start && newInterval.start <= (*it).end && (*it).end < newInterval.end )
			{
				Scross =true;
				newone.start = (*it).start;
				intervals.erase(it);
				continue;				
			}
			
			if((*it).start > newInterval.start && newInterval.end >= (*it).start && (*it).end >= newInterval.end )
			{
				Ecross = true;
				newone.end = (*it).end;
				intervals.erase(it);
				continue;				
			}
			if((*it).end <= newInterval.start)
			{
				if(Scross);
				else
				newone.start = newInterval.start;
				it++;
			}
			if((*it).start >= newInterval.end)
			{
				if(Ecross);
				else
				newone.end = newInterval.end;	
				it++;				
			}
					
		}

		intervals.push_back(newone);
		sort(intervals.begin(),intervals.end(),cmp);		
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

	in.push_back(Interval(0,9));			
	Solution s;
	vector<Interval > out = s.insert(in,Interval(14,15));
	s.show(out);
	return 0;
}

