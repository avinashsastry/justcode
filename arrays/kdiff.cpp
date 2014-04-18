
// use a hash table approach to speed things up
// Approach:
// 1. enter numbers into a pseudo-hashtable
// 2. for each number, look up the two possibilities in our table = O(2n)
int main() {
	
	int n = 0;
	scanf("%d", &n);
	
	unsigned int k = 0;
	scanf("%d", &k);
	
	// Allocate memeory
	hashTable hashMap = hashTable();
	
	// Fill numbers
	int x = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		hashMap.addValue(x);
	}
	
	unsigned int answer = hashMap.getDiffPairs(k);
	printf("%d\n", answer);
	
	return 0;
}