#include <iostream>

using namespace std;

int arr[10];

int main(void){
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	
	int n, priv;
	cin >> n;
	
	for(int i=0; i<n; i++){
        // �̸� �� ���� �ʿ� ���� �Ž��� �ϳ���
		cin >> priv;
		
		for(int j=0; j<n; j++){
			if(priv == 0 && arr[j]==0){
				arr[j] = i+1;
				break; 
			}
			else if(arr[j] == 0) --priv;
		}
	}
	
	for (int i=0; i<n; i++) printf("%d ", arr[i]);
	
	return 0;
}
