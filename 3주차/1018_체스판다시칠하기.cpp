#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
// πª∑Œ πﬁ¡“?  
char type1[8][8] = {
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};
char type2[8][8] = {
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

char board[50][50];

int checkCount(int h, int w, char(*checkBoard)[8]){
	int cnt=0;
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(board[h+i][w+j] != checkBoard[i][j]) ++cnt;
		}
	}
	return cnt;
}

int main(void){
	//freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	
	string temp;
	
	for(int i=0; i<N; i++){
		cin >> temp;
		for(int j=0; j<M; j++)
			board[i][j] = temp[j];
	}
	
	int res = 50*50*10;
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			int cnt1 = checkCount(i, j, type1);
			int cnt2 = checkCount(i, j, type2);
			res = min(cnt1, res);
			res = min(cnt2, res);
		}
	}
	
	cout << res;
	
	return 0;
}
