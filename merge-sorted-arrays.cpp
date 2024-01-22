//@mtbstn24

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1,pos2 = 0;
        int len = m;
        while(pos1<len && pos2<n){
            if(nums1[pos1]>=nums2[pos2]){
                for(int i=len; i>pos1; i--){
					nums1[i] = nums1[i-1];
                }
                len = len + 1;
				nums1[pos1] = nums2[pos2];
                pos2 = pos2 + 1;
            }
            pos1 = pos1 + 1;
        }
        if(len < m+n){
            for(int i=len; i<m+n; i++){
                nums1[i] = nums2[pos2];
                pos2++;
                for(int j=0; j<6; j++){
						cout<<nums1[j]<<" ";
					}
					cout<<endl;
            }
        }
    }

int main(){

	int array[] = { 1, 2, 3, 0, 0, 0 };
	int array2[] = {2, 5, 6};
	vector<int> one (array, array + sizeof(array)/ sizeof(int));
	vector<int> two (array2, array2 + sizeof(array2)/ sizeof(int));
	
	merge(one, 3, two, 3);
	
	cout<<endl;
	
	for(int i=0; i<6; i++){
		cout<<one[i]<<" ";
	}
	
	return 0;
}
