#include <iostream>

using namespace std;

int N; // ������ �� 
int A, B; // A=������, B=���Ѽ� 

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int round = 1;
	
	cin >> N >> A >> B;
	
	while(N){
		// �ش� ���忡 ��� ���� 
		if( (A+1)/2 == (B+1)/2) break; // �������Ƿ� ���� 
		
		round++;
		A = (A+1) / 2;
		B = (B+1) / 2;
		
		N = N/2; // ������: 16 --> 8 --> 4 --> 2 
	}
	
	if(!N) cout << -1 << endl; 
	else cout << round << endl;
	
	return 0;
}
