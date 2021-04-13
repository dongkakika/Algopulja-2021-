#include <iostream>
#include <vector>

using namespace std;


int N;
int visited[40320];
int arr[40320];
int idx = 0;
//vector<int> v;

void jaegui(){
	
	if(idx == N)
	{
		for(int i=0; i < idx; ++i) printf("%d ", arr[i]);
		printf("\n");
	}
	for(int i=1; i<=N; ++i){
		if(!visited[i]){
			visited[i] = 1;
			arr[idx] = i;
			idx++;
			jaegui();
			visited[i] = 0;
			idx--;
		}
	}
}

int main(void){
	
	freopen("input.txt", "r", stdin);
	//cin.tie(NULL); cout.tie(NULL);
	
	scanf("%d", &N);
	
	jaegui();	
	
	return 0;
}
