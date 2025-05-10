#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> seminar;

	seminar["Algorithm"] = "204";
	seminar["DataAnalysis"] = "207";
	seminar["ArtificialIntelligence"] = "302";
	seminar["CyberSecurity"] = "B101";
	seminar["Network"] = "303";
	seminar["Startup"] = "501";
	seminar["TestStrategy"] = "105";

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string subject;
		cin >> subject;

		cout << seminar.find(subject)->second << endl;
	}

	return 0;
}