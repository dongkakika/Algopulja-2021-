#include <iostream>

using namespace std;

int N; // 참가자 수 
int A, B; // A=김지민, B=임한수 

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int round = 1;
	
	cin >> N >> A >> B;
	
	while(N){
		// 해당 라운드에 경기 진행 
		if( (A+1)/2 == (B+1)/2) break; // 만났으므로 종료 
		
		round++;
		A = (A+1) / 2;
		B = (B+1) / 2;
		
		N = N/2; // 참가자: 16 --> 8 --> 4 --> 2 
	}
	
	if(!N) cout << -1 << endl; 
	else cout << round << endl;
	
	return 0;
}
