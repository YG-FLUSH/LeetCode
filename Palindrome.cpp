class Solution {
public:
    int minCut(string s) {
     
    }
    bool isPalindrome(string s)
    {
        
    }
	void Partision(string &s)
	{
		if(isPalindrome(s)) return ;
		num++;
		int right = s.size();
		int middle = right/2;
		int cutpoint = middle;
		for(int i=0;i<middle;i++)
		{
			string sl = s.substr(0,cutpoint-i);
			if(isPalindrome(sl))
			{
				string sr = s.substr(middle+1,right);
				if(isPalindrome(sr)) return;
				else
				{
					Partision(sr);
				}
			}
		}
		
	}
};

int main()
{
	return 0;
}