#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int res[8];

void arrToRes(int cnt, int start){
	
	// cnt�� m����ŭ ī���õƴٸ�, 
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout << res[i] << ' ';
		cout << '\n';
		return;
	} 
	
	// ������ �� �� 
	int priv = -1;
	
	// start���� N-1������ idx���� M���� ���� 
	for(int i=start; i<N; i++){
		// �ߺ��� ���ϱ� ���� ���� ���� res�� ����X  
		if(priv != arr[i]){
			res[cnt] = arr[i];
			priv = arr[i];
			// start ������ ���� ������ i�� ���� 
			arrToRes(cnt+1, i);  
		}
	} 
}

int main(void){
	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> arr[i];
	
	// �񳻸������� ���� ����  
	sort(arr, arr+N);
	
	arrToRes(0,0);
	return 0;
}
