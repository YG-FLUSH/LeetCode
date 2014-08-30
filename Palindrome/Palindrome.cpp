#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) 
	{
		//����һ��matrix[size][size] matrix[i][j]= true ��ʾ s.substr(i,j)�ǻ���
		//matrix[i][j] = (i+1>j-1||matrix[i+1][j-1])&&s[i]==s[j]

		int size=s.size();

		vector<vector<bool> > matrix;
		matrix.resize(size);
		for(int i =0;i<size;i++)
		{
			matrix[i].resize(size);
			matrix[i][i] =true;
		}
		for(int i =size-1;i>=0;i--)
		{
			for(int j=i;j<size;j++)
			{
				matrix[i][j]=((j-i<2)||matrix[i+1][j-1])&&s[i]==s[j];
			}
		}		
	//	showM(matrix,s);
		int *cuts = new int[size+1];
		for(int i=size;i>=0;i--)	cuts[i] =size-i;
		
		for(int i = size-1; i>=0;i--)
		{
			for(int j=i;j<size;j++)
			{
				if(matrix[i][j])
				{
					cuts[i]=cuts[i]<(cuts[j+1]+1)?cuts[i]:(cuts[j+1]+1);		//ÿ�ζ�����С��cut����������ʹ����һ���Ӵ��±��ﱣ��Ķ�����ͬ��cut��
																			//��ԭ�����Ӵ���������Ӵ�����������ȡcuts[j+1]+1��j�����ҵ��ַ���
																			//������Ӵ�ǰ��cut��+1��Ϊ�µ�cut����
				}
			}
		}
		int c =cuts[0]-1;
		delete [] cuts;
		return c;
    }
	void showM(vector<vector<bool> > matrix,string s)
	{
		for(int i=0;i<matrix.size();i++)
			cout << s[i]<<" ";
			cout <<endl;
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix.size();j++)
			{
			
				if(matrix[i][j])
				cout << "1 ";
				else
				cout << "0 ";
			}
			cout <<endl;
		}
	}
};

int main()
{
	Solution s;
	string str = "cdd";
	cout << s.minCut(str);
	return 0;
}