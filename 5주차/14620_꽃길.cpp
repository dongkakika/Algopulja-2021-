#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> visited;
int cost[10][10];
int result = 999999999;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
// (-1,0), (1,0), (0,-1), (0,1) 하상좌우  

// 확인해본 땅 체크 
bool check(int y, int x){
	if(visited[y][x]) return true;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(visited[ny][nx]) return true;
	}
	return false;
}

// 사용 중인 땅을 표시  
int used(int y, int x){
	int tmp = 0; // 사용한 땅의 비용 
	visited[y][x] = true;
	tmp += cost[y][x];
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = true;
		// 상하좌우의 모든 땅 값 합 
		tmp += cost[ny][nx];
	}
	return tmp;
}

void dfs(int y, int x, int val, int depth){
	// 탈출: 깊이 3일 때, 
	if(depth == 3){
		result = min(result, val);
		return;
	}
	// 복구 위한 임시 저장 벡터  
	vector<vector<bool>> temp = visited;
	
	int i=y, j=x; 
	int c; // 사용한 땅 수 저장  
	for(i; i<N-1; i++){
		for(j; j<N-1; j++){
			// 방문했던 곳(true)이라면 continue
			if(check(i,j)) continue;
			// 사용한 땅 수  
			c = used(i, j);
			dfs(i, j+1, val+c, depth+1);
			// 재귀 마친 후 방문 초기화  
			visited = temp; 
		}
		j=1;
	}
}

int main(void){
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	vector <bool> temp(N, false);
	visited.resize(N, temp);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &cost[i][j]);
		}
	}
	
	// (1,1)부터 호출하는 이유? --> 씨앗이 자라 꽃잎이 장외로 벗어나면 안됨  
	dfs(1,1,0,0);
	printf("%d", result);
	
	
	return 0;
}
