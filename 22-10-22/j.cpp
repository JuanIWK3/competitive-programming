#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void swapLexical(string* str1, string* str2) {
	if ((int) (*str1)[0] > (int) (*str2)[0]) {
		swap(*str1, *str2);
	}
}

int main() {
	// Get number of lines
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		// Get number of words
		int n2;
		cin >> n2;
		string ws[n2];



		// Get words
		for (int j = 0; j < n2; j++ ){
			string w;
			cin >> w;
			ws[j] = w;
		}
		
		// Sort Array By Lexical Value
		for (int j = 0; j < n2 -1; j++) {
			for (int k = 0; k < n2 -1; k++) {
				swapLexical(&ws[k], &ws[k+1]);
			}
		}

		// Print Array
		for (int j = 0; j < n2; j++) {
			cout << ws[j];
		}

		cout << endl;
	}
}

