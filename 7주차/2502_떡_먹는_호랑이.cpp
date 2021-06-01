#include <iostream>

using namespace std;

int D, K;
 int arr[31]; // ����Ǵ� ��� ������ �� ���� 

int main(void){
	
	freopen("input.txt", "r", stdin);	
	cin >> D >> K; // D -> �Ѿ�� ��, K -> �� ����  
	
	// arr --> 1, 1, 2, 3, 5, 8, ...
	arr[1] = arr[2] = 1;
	// D�� ��¥������ ��� ����� ���� �Ǻ���ġ �� ����  
	for(int i=3; i<=D; i++)
		arr[i] = arr[i-2] + arr[i-1];
	
	// a -> b -> a+b -> a+2b -> 2a+3b -> 3a+5b -> ...
	// ��ȭ��: K = arr[D-2]*a + arr[D-1]*b
	
	// D�� �Ѿ�� ���� ���� a�� b�� ����� ã�� ����, ����� ���� D�� � ���̵� �׻� ��ġ��  
	int a_ = arr[D-2];
	int b_ = arr[D-1];
	
	int a, b;
	int i=0;
	while(1){
		// a�� 1���� 
		a = ++i;
		 
		// a�� ���� �� K�� ���� b�� ����� ���� ������ ������ --> 0 --> ��: �ش� i��°�� ���� a�� ����  
		if((K - a_ * a) % b_) continue; 
		
		// �� �� ã�� b�� ���� b ���� ����  
		b = (K - a_ * a) / b_;
		break; // �ش� �������� break�� �ɸ��鼭 a �� ���� �Ϸ�  
		
	}
	
	cout << a << endl << b << endl;
	
	return 0;
}
