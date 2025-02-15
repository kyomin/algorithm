#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	unordered_map<string, vector<string>> umap;

	umap["init"] = { "0","1" };
	umap["0"] = { "X", "01" };
	umap["1"] = { "10", "X" };
	umap["01"] = { "0", "1" };
	umap["10"] = { "100", "X" };
	umap["100"] = { "100~", "100~1" };
	umap["100~"] = { "100~", "100~1" };
	umap["100~1"] = { "0", "100~1~" };
	umap["100~1~"] = { "10 or 0", "100~1~" };
	umap["10 or 0"] = { "100", "01" };

	string state = "init";
	for (int i = 0; i < str.length(); i++) {
		int nextChar = str[i] - '0';
		state = umap[state][nextChar];

		if (state == "X") 
			break;
	}

	if (state == "100~1" || state == "100~1~" || state == "01")
		cout << "SUBMARINE" << endl;
	else
		cout << "NOISE" << endl;

	return 0;
}