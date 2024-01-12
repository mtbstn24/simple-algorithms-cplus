#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Write C++ code here
	
	char *a = (char *)malloc(sizeof(char)*3);
	a[0] = 'e';
	a[1] = 'f';
	a[2] = 'b';
	
	int a_length = sizeof(a)/sizeof(char);
	a_length = 3;
	int final_length = 0;
	
	for(int i=0; i<a_length; i++){
	    cout<<a[i];
	}
	cout<<endl;
	
	for(int i=1; i<=a_length; i++){
	    int alpha_pos = a[i-1]-'a'+1;
	    cout<<a[i-1]<<'-'<<alpha_pos<<endl;
	    final_length += alpha_pos;
	}
	
	a = (char *)realloc(a, final_length*sizeof(char));
	
// 	int current_pos = final_length;
// 	for(int i=a_length; i>0; i--){
// 	    char x = a[i-1];
// 	    for(int j=current_pos; j>current_pos-i; j--){
// 	        a[j-1] = x;
// 	    }
// 	    current_pos-=i;
// 	}

	int i=0;
	int length=a_length;
	int alpha_pos = 0;
	while(i<length){
	    int a_pos = length-1;
	    alpha_pos = a[i]-'a'+1;
	    for(int j=length+alpha_pos-1; j>i+alpha_pos-1; j--){
	        a[j-1] = a[a_pos];
	        a_pos--;
	    }
	    length = length + alpha_pos-1;
	    for(int j=i+1; j<i+alpha_pos-1; j++){
	        a[j] = a[i];
	    }
	    i = i + alpha_pos;
	}
	
	for(int i=0; i<final_length; i++){
	    cout<<a[i];
	}


    return 0;
}
