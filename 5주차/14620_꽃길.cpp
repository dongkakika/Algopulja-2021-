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
// (-1,0), (1,0), (0,-1), (0,1) �ϻ��¿�  

// Ȯ���غ� �� üũ 
bool check(int y, int x){
	if(visited[y][x]) return true;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(visited[ny][nx]) return true;
	}
	return false;
}

// ��� ���� ���� ǥ��  
int used(int y, int x){
	int tmp = 0; // ����� ���� ��� 
	visited[y][x] = true;
	tmp += cost[y][x];
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = true;
		// �����¿��� ��� �� �� �� 
		tmp += cost[ny][nx];
	}
	return tmp;
}

void dfs(int y, int x, int val, int depth){
	// Ż��: ���� 3�� ��, 
	if(depth == 3){
		result = min(result, val);
		return;
	}
	// ���� ���� �ӽ� ���� ����  
	vector<vector<bool>> temp = visited;
	
	int i=y, j=x; 
	int c; // ����� �� �� ����  
	for(i; i<N-1; i++){
		for(j; j<N-1; j++){
			// �湮�ߴ� ��(true)�̶�� continue
			if(check(i,j)) continue;
			// ����� �� ��  
			c = used(i, j);
			dfs(i, j+1, val+c, depth+1);
			// ��� ��ģ �� �湮 �ʱ�ȭ  
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
	
	// (1,1)���� ȣ���ϴ� ����? --> ������ �ڶ� ������ ��ܷ� ����� �ȵ�  
	dfs(1,1,0,0);
	printf("%d", result);
	
	
	return 0;
}
