#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
int arr[9];
int selected[9];
bool check[9];

int result;

void get_max(){
	int sum=0;
	for(int i=0; i<n-1; i++){
		sum += abs(selected[i] - selected[i+1]); // 절댓값  
	}
	result = max(sum, result);
}

void find(int depth){
	// 탈출 조건  
	if(depth == n){
		get_max();
		return;
	}
	
	for(int i=0; i<n; i++){
		if(check[i]) continue;
		
		check[i] = true;
		// 각 depth에 대해 요소들을 집어넣으며 진행  
		selected[depth] = arr[i];
		find(depth+1);
		check[i] = false;
	}
}

int main(void){
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	
	find(0);
	
	cout << result;
	
	return 0;
}
