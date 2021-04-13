#include <iostream>
#include <algorithm> 

using namespace std;

int N, S;
int arr[20] = {};
int cnt = 0;

void jaegui(int idx, int sum){
	
	// Ż�� 
	if(N <= idx) return;
	
	if(sum == S) cnt++;
	cout << sum << " ";
	
	jaegui(idx+1, sum); // ���� ����  
	jaegui(idx+1, sum+arr[idx]); // �� ���� 
}

int main(void){
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	 
	cin >> N >> S;
	
	for(int i=0; i<N; i++)
		cin >> arr[i];
	
	jaegui(0, 0);
	
	cout << cnt << endl;
	
	return 0;
}
