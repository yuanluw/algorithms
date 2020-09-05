#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;



 class Solution {
private:
    bool check(int x){
        if(x <= 2)
            return false;
        for(int i=2; i<sqrt(x);i++)
            if(x%i == 0)
                return false;
        return true;
    }
    
    bool check2(int a, int b){
    	
    	int len = min(a, b);
    	if(len <= 1)
			return false;
    	for(int i=2; i<=len;i++){
    		if(a%i==0 && b%i == 0)
    			return true;
		}
		return false;
	}
	
	long long sum(int a, int b, int c){
		
		long long result = 1;
		if(check2(a, b)){
			do{
				int len = min(a, b);
				if(len <= 1)
					break;
		    	for(int i=2; i<=len;i++){
		    		if(a%i==0 && b%i == 0)
		    			a/=i;
		    			b/=i;
		    			result*=i;
				}
				
			}while(check2(a, b));
		}
		else if(check2(a, c)){
			do{
				int len = min(a, c);
				if(len <= 1)
					break;
		    	for(int i=2; i<=len;i++){
		    		if(a%i==0 && c%i == 0)
		    			a/=i;
		    			c/=i;
		    			result*=i;
				}
				
			}while(check2(a, c));
		}
		else if(check2(b, c)){
			do{
				int len = min(b, c);
				if(len <= 1)
					break;
		    	for(int i=2; i<=len;i++){
		    		if(b%i==0 && c%i == 0)
		    			b/=i;
		    			c/=i;
		    			result*=i;
				}
				
			}while(check2(b, c));
		}
		
		result = result*a*b*c;
		return result;
	}
public:
    /**
     * @param a: Left margin
     * @param b: Right margin
     * @return: return the greatest common multiple
     */
    long long greatestcommonmultiple(int a, int b) {
        // write your code here
        vector<int> result;
        
        for(int i=b; i>=a; i--){
            if(check(i)){
                result.push_back(i);
                if(result.size() == 2)
                    break;
            }
        }
        int temp_a = result[0];
        int temp_b, temp_c=0;
        int right = b;
        int left;
        if(result.size() == 2)
         	left = result[1];
        else
        	left = 1;
        for(int i=right;i>left+1;i--){
        	if(i == temp_a)
        		continue;
        	temp_b = i;
        	for(int j=i-1; j>left;j--){
        		if(j == temp_a)
        			continue;
        		if(!check2(i, j)){
        			temp_c = j;
        			break;
				}
			}
			if(temp_c != 0)
				break;
		}
        if(temp_c == 0){
        	if(result.size() < 3){
	            for(int i=b;i>=a;i--){
	                if(find(result.begin(), result.end(), i) == result.end()){
	                    result.push_back(i);
	                    if(result.size() == 3)
	                        break;
	                }
	            }
        	}
        	
        	temp_b = result[1];
        	temp_c = result[2];
		}
        
        
    	cout<<temp_a<<" "<<temp_b<<" "<<temp_c<<endl;
    	return sum(temp_a, temp_b, temp_c);

    }
};


int main(){
	
	Solution s;
	cout<<s.greatestcommonmultiple(1, 3);
	
	return 0;
	
}
