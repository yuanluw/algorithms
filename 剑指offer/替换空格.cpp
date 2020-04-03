#include <iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL || length==0)
            return;
        int new_length=0, raw_length=0; 
        int i=0;
        while(str[i] != '\0'){
            if(str[i] == ' ')
                new_length += 3;
            else
                new_length ++;
            raw_length++;
            i++;
        }

        if(new_length > length) //数组空间不够
            return;
        
        int new_index = new_length;
        int index = raw_length;
        while(new_index>=0 && new_index>index){

            if(str[index] == ' '){
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
            }
            else
                str[new_index--] = str[index];
            index--;
        }
            
	}
};
int main()
{
   Solution solution;
   char str[100] = "we are";
   solution.replaceSpace(str, 100);
   printf("\n");
   printf(str); 
   return 0;
}
