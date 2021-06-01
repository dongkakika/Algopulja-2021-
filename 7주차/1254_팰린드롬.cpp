#include <iostream>

using namespace std;

string S;
int lth;

int solution(int idx){
	
	for(int i=0; idx+i < lth-i-1; i++)
		if(S[idx+i] != S[lth-1 -i]) return false;
		
	return true;
}


int main(void){
	//freopen("input.txt", "r", stdin);
	
	cin >> S;
	
	int rst = 0;
	lth = S.length();
	
	for(int i=0; i<lth; i++)
		if(solution(i)){
			rst = lth+i;
			break;
		}
	
	cout << rst;
	
	return 0;
}
