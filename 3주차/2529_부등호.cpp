#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int k;
int visited[10]; // ���� ������ �湮 ����  

int arr[10] = {0,1,2,3,4,5,6,7,8,9};
char carr[10]; // �ε�ȣ ����  
vector<char> V; // ������ ���� �ӽ� ����  
vector<string> res; // ��� ����  

bool check(int i, char c){
	if(c == '<'){
		// ���� ������ �յ� �� �ϳ��� ������ ��  
		if(V[i] - '0' < V[i+1] - '0') return true;
		else return false; 
	}
	else if(c == '>'){
		// ���� ������ �յ� �� �ϳ��� ������ ��  
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
	// ������ ���̰� 10���� �� á�� �� �� ����  
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
	
	// ������ ��������� ����  
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
	// �Է�  
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
