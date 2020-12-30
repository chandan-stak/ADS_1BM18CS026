#include<bits/stdc++.h> 
using namespace std; 
  
vector<int> uniqueNumbers(int L,int R)
{
      
        vector<int> res;
        for (int i=L ; i<=R ; i++) 
    	{ 
        	int num = i; 
        	bool visited[10] = {false}; 
  
        	while (num) 
        	{ 
            		if (visited[num % 10]) 
                		break; 
  
            		visited[num%10] = true; 
  
            		num = num/10; 
        	} 
        	if (num == 0) 
            		res.push_back(i); 
    	} 
    	return res;
}
  
int main() 
{ 
	int l,r;
	cout<<"L = ";
	cin>>l;
	cout<<"R = ";
	cin>>r;
    	vector<int> res = uniqueNumbers(l, r); 
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<" ";
	cout<<endl;
    	return 0; 
} 
