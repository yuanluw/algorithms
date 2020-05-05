/*
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,
���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
����˼·:
ʹ��˫ָ��left right, ����¼��ǰ���cnt, ���cnt����sum������ָ��left���ƣ�cntС��sum����ָ������; ������ָ�����ʱ���˳�ѭ��  
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int left=1, right=2;
        vector<vector<int>> result;
        while(left<right){
        	//������� 
        	int cnt = (left+right)*(right-left+1)/2;
        	if(cnt == sum){
        		vector<int> l;
        		for(int i=left; i<=right;i++)
        			l.push_back(i);
        		result.push_back(l);
        		left++;
			}
			else if(cnt > sum){
				left++;
			}
			else{
				right++;
			}
		}
        return result;
    }
    
    vector<vector<int> > FindContinuousSequence2(int sum) {
        
        int left=1, right=2, cnt=3;
        vector<vector<int>> result;
        while(left<right){
        	if(cnt>sum){
        		cnt -= left;
        		left += 1;
			}
			else{
				if(cnt == sum){
					vector<int> l;
	        		for(int i=left; i<=right;i++)
	        			l.push_back(i);
	        		result.push_back(l);
				}
				right += 1;
				cnt += right;
			}
		}
		return result;
    }
    
    
};


int main(){
	
	Solution s;
	
	vector<vector<int>> result = s.FindContinuousSequence2(100);
	for(int i=0; i<result.size();i++){
		for(int j=0; j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
		
		
	return 0;
	
}

