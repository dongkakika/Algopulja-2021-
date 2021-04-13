#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int res[8];

void arrToRes(int cnt, int start){
	
	// cnt가 m개만큼 카운팅됐다면, 
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	} 
	
	// 직전에 고른 수 
	int priv = -1;
	
	// start부터 N-1까지의 idx에서 M개만 선택 
	for(int i=start; i<N; i++){
		// 중복을 피하기 위해 이전 수를 res에 저장X  
		if(priv != arr[i]){
			res[cnt] = arr[i];
			priv = arr[i];
			// start 지점은 현재 시점의 i로 갱신 
			arrToRes(cnt+1, i);  
		}
	} 
}

int main(void){
	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> arr[i];
	
	// 비내림차순을 위한 정렬  
	sort(arr, arr+N);
	
	arrToRes(0,0);
	return 0;
}
