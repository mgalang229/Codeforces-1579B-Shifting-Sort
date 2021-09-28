#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// view the images in this repository for better understanding
		// first create a copy of the original sequence and sort it in non-decreasing order
		vector<int> copy_a = a;
		vector<bool> visited(n, false);
		sort(copy_a.begin(), copy_a.end());
		vector<array<int, 3>> vec(n);
		int index = 0;
		for (int i = 0; i < n; i++) {
			// there is pattern in sorting the elements:
			// check every element of the original sequence if it matches the element in the sorted sequence
			// if it doesn't, then follow the cyclic shift visualization (image) in this repository
			
			// find the element that is out of its position and calculate the distance between
			// its current position and its correct position (this will be the number of cyclic shifts)
			// don't forget to store its correct position (this will be 'l'), current position 
			// (this will be 'r') and distance (cyclic shifts to the left)
			
			// apply the cyclic shifts to the left within the chosen interval and break the inner loop
			
			// it is also important to check if we have already visited a particular element
			// because this might lead to problems if it encounters duplicate elements but if we
			// mark it as visited, then the elements that are placed in its correct position will be ignored
			// to do this, mark every i-th turn since the element at this position will be placed correctly
			if (a[i] != copy_a[i]) {
				for (int j = 0; j < n; j++) {
					if (a[j] == copy_a[i] && !visited[j]) {
						//cout << i + 1 << " " << j + 1 << " " << (j + 1) - (i + 1);
						vec[index][0] = i + 1;
						vec[index][1] = j + 1;
						vec[index][2] = (j + 1) - (i + 1);
						index += 1;
						for (int k = j; k - 1 >= i; k--) {
							swap(a[k], a[k - 1]);
						}
						break;
					}
				}
			}
			visited[i] = true;
		}
		cout << index << '\n';
		for (int i = 0; i < index; i++) {
			cout << vec[i][0] << " " << vec[i][1] << " " << vec[i][2] << '\n';
		}
	}
	return 0;
}
