#include <iostream>

using namespace std;

int n, m, k; 
int arr[100][10] = {}; 
bool skill_set[21] = {}; 
int max_cnt = 0; // 최대로 깬 퀘스트 수  

void find_set(int current_depth, int next_start){
	
	// skill_set이 만들어졌다면 몇 개의 스킬을 사용하는지 검사 & 최댓값 갱신  
	if(current_depth >= n){
		int cnt=0;
		for(int i=0; i<m; i++){
			
			bool check=true;
			for(int j=0; j<k; j++){
				if(!skill_set[ arr[i][j] ]) check = false;
			}
			if(check) ++cnt;
		}
		
		if(max_cnt < cnt) max_cnt = cnt;
		return;
	}
	
	// skill_set이 만들어지지 않았다면, 생성  
	// 1번 키부터 시작  
	for(int i = next_start+1; i <= n * 2; i++){
		skill_set[i] = true;
		find_set(current_depth+1, i); 
		skill_set[i] = false;
	}
}

int main(void){
	
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m >> k;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<k; j++) cin >> arr[i][j];
	}
	
	find_set(0, 0);
	
	cout << max_cnt;
	
	return 0;
}
