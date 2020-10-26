#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> &nums, int left, int right){

    int temp = nums[left];
    while(left<right){
         while(left<right && nums[right] >= temp)
            right--;
        nums[left] = nums[right];
        while(left<right && nums[left]<=temp)
            left++;
        nums[right] = nums[left];
    }
    
    nums[left] = temp;
    return left;

}

void quickSort(vector<int> &nums, int left, int right){

    if(left < right){
        int q = partition(nums, left, right);
        quickSort(nums, left, q-1);
        quickSort(nums, q+1, right);
    }
}


void merge(vector<int>& nums, vector<int>& temp, int leftStart, int rightStart, int rightEnd){
	

	int leftEnd = rightStart-1;
	int tempPos = leftStart;
	int numCnt = rightEnd-leftStart+1;
	
	while(leftStart<=leftEnd && rightStart<=rightEnd){
		if(nums[leftStart] < nums[rightStart])
			temp[tempPos++] = nums[leftStart++];
		else
			temp[tempPos++] = nums[rightStart++];
	}
	
	while(leftStart<=leftEnd)
		temp[tempPos++] = nums[leftStart++];
	while(rightStart<=rightEnd){
		temp[tempPos++] = nums[rightStart++];
	}
	
	for(int i=0; i<numCnt; i++, --rightEnd)
		nums[rightEnd] = temp[rightEnd];

}


void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right){
	
	if(left<right){
		int mid = left + (right-left)/2; 
		mergeSort(nums, temp, left, mid);
		mergeSort(nums, temp, mid+1, right);
		merge(nums, temp, left, mid+1, right);
	}
	
	
}

void buSort(vector<int>& nums, int left, int right){
	
	for(int i=left; i<right; i++){
		for(int j=left; j<right-i; j++){
			if(nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
			}
		}
	}
	
}

int main(){
	
	vector<int> d = {3, 4, 1, 25, 4, 10000, 9, 1, 4,22, 45, 5};
	
	vector<int> temp(d.size(), 0);
	
	buSort(d, 0, d.size()-1);
	
	for(int i=0; i<d.size(); i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	return 0;
}
