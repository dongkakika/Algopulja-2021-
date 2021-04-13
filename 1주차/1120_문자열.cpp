#include <iostream>
#include <algorithm> 

using namespace std;
 
string A, B; // A 길이 <= B 길이  
int maximum = 50; // 두 문자열이 최대로 다를 때의 갯수  

int main(void){
	// 입력 
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B;
	
	// 길이 구하기 
	int A_len = A.length(); 
	int B_len = B.length(); 
	int diff = B_len - A_len;
	
	/*
	앞이나 뒤는 자동으로 같은 문자가 채워진다고 가정 
	front 값을 0부터 차이값까지 각각 채워보면서 최소를 구함 
	A 크기의 프레임이 있고 그 프레임을 움직이면서 B 비교하면 쉬움  
	*/
	for(int front=0; front<=diff; front++){
		int count = 0;
		
		for(int i=0; i<A_len; i++){
			if(A[i] != B[front+i]) count ++;
		}
		
		maximum = min(maximum, count);
	}
	cout << maximum << "\n";
	
	return 0;
}
