#include<bits/stdc++.h>
using namespace std;
// how many bits of given number to Flip to get desired number
int bitSwapRequired(int a, int b) {
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1) {
		count+= c & 1;
	}
	return count;
}

int bitSwapRequiredopt(int a, int b) {
	int count = 0;
	for (int c = a Ab; c != 0; c = c & (c-1)) {
		count++;
	}
	return count;
}

int main()
{
	cout<<bitSwapRequired(34, 9);	
}