Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 For "bbbbb" the longest substring is "b", with the length of 1.
 
 //��Ч������
 //��unordered_map<char,int> ����ĸ����ĸ�����ַ�����λ�ã��ٲ���
 //��Ȼ����һ�Σ�ÿ�α�������map�����
 //�Ҳ������룬�ҵ�ά��һ��max����������˳��ȣ��ٴ��ҵ����ַ�����һ���ַ�λ�����¿�ʼ��
 
 
 //ά���ַ�����ʼλ��bpos
 //ǰ��ָ��������ͬ�ַ�����ʵλ����Խ�����ַ�����bpos++
