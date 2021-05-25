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
		sum += abs(selected[i] - selected[i+1]); // ����  
	}
	result = max(sum, result);
}

void find(int depth){
	// Ż�� ����  
	if(depth == n){
		get_max();
		return;
	}
	
	for(int i=0; i<n; i++){
		if(check[i]) continue;
		
		check[i] = true;
		// �� depth�� ���� ��ҵ��� ��������� ����  
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
