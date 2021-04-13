#include <iostream>
#include <algorithm> 

using namespace std;
 
string A, B; // A ���� <= B ����  
int maximum = 50; // �� ���ڿ��� �ִ�� �ٸ� ���� ����  

int main(void){
	// �Է� 
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B;
	
	// ���� ���ϱ� 
	int A_len = A.length(); 
	int B_len = B.length(); 
	int diff = B_len - A_len;
	
	/*
	���̳� �ڴ� �ڵ����� ���� ���ڰ� ä�����ٰ� ���� 
	front ���� 0���� ���̰����� ���� ä�����鼭 �ּҸ� ���� 
	A ũ���� �������� �ְ� �� �������� �����̸鼭 B ���ϸ� ����  
	*/
	for(int front=0; front<=diff; front++){
		int count = 0;
		
		for(int i=0; i<A_len; i++){
			if(A[i] != B[front+i]) count ++;
		}
		
		maximum = min(maximum, count);
	}
	cout << maximum << "\n";
	
	return 0;
}
