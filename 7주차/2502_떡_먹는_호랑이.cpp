#include <iostream>

using namespace std;

int D, K;
 int arr[31]; // 진행되는 모든 수열의 값 저장 

int main(void){
	
	freopen("input.txt", "r", stdin);	
	cin >> D >> K; // D -> 넘어온 날, K -> 떡 갯수  
	
	// arr --> 1, 1, 2, 3, 5, 8, ...
	arr[1] = arr[2] = 1;
	// D인 날짜까지만 계수 계산을 위한 피보나치 수 형성  
	for(int i=3; i<=D; i++)
		arr[i] = arr[i-2] + arr[i-1];
	
	// a -> b -> a+b -> a+2b -> 2a+3b -> 3a+5b -> ...
	// 점화식: K = arr[D-2]*a + arr[D-1]*b
	
	// D의 넘어온 날을 통해 a와 b의 계수를 찾아 저장, 계수의 값은 D가 어떤 값이든 항상 일치함  
	int a_ = arr[D-2];
	int b_ = arr[D-1];
	
	int a, b;
	int i=0;
	while(1){
		// a는 1부터 
		a = ++i;
		 
		// a의 값을 뺀 K의 값이 b의 계수에 대해 나누어 떨어짐 --> 0 --> 답: 해당 i번째의 값이 a의 값임  
		if((K - a_ * a) % b_) continue; 
		
		// 이 때 찾은 b로 실제 b 값을 지정  
		b = (K - a_ * a) / b_;
		break; // 해당 지점에서 break가 걸리면서 a 값 지정 완료  
		
	}
	
	cout << a << endl << b << endl;
	
	return 0;
}
