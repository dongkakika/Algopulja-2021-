#include <iostream>

using namespace std;

int arr[10];

int main(void){
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	
	int n, priv;
	cin >> n;
	
	for(int i=0; i<n; i++){
        // 미리 다 받을 필요 없이 매시점 하나씩
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
