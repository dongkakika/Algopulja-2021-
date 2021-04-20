#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int k;
int visited[10]; // 순열 생성시 방문 조건  

int arr[10] = {0,1,2,3,4,5,6,7,8,9};
char carr[10]; // 부등호 저장  
vector<char> V; // 생성된 순열 임시 저장  
vector<string> res; // 결과 저장  

bool check(int i, char c){
	if(c == '<'){
		// 구한 순열의 앞뒤 값 하나씩 꺼내서 비교  
		if(V[i] - '0' < V[i+1] - '0') return true;
		else return false; 
	}
	else if(c == '>'){
		// 구한 순열의 앞뒤 값 하나씩 꺼내서 비교  
		if(V[i] - '0' > V[i+1] - '0') return true;
		else return false; 
	}
}

bool compNum(){
	for(int i=0; i<k; i++){
		if(check(i, carr[i]) == false) return false;
	}
	return true;
}

void jaegui(int cnt){
	// 순열의 길이가 10으로 다 찼을 때 비교 시작  
	if(cnt == k+1){
		if(compNum() == true){
			string temp = "";
			for(int i=0; i<V.size(); i++){
				temp = temp + V[i];
			}
			res.push_back(temp);
		}
		return;
	}
	
	// 순열을 재귀적으로 생성  
	for(int i=0; i<10; i++){
		if(visited[i] == 1) continue;
		visited[i] = true;
		V.push_back(arr[i] + '0');
		jaegui(cnt+1);
		V.pop_back();
		visited[i] = false;
	}
}

int main(void){
	// 입력  
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> carr[i];
	}
	
	jaegui(0);
	sort(res.begin(), res.end());
	cout << res[res.size()-1] << endl;
	cout << res[0] << endl;

	
	return 0;
}
