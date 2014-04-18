/* Sample program illustrating input and output */

#include<iostream>
using namespace std;
int main(){

//Helpers for input and output

	int N, M;
	cin >> N, M;
	
	int A[M], B[M], C[M];
	for(int i = 0; i < M; i++){
		cin >> A[i] >> B[i] >> C[i];
	}
	
	int min[M], max[M];
	
	int result1, result2;
	cout << result1 << " " << result2 << "\n";
	
	return 0;
}