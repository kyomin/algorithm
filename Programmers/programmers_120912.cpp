#include <string>
#include <vector>
using namespace std;

int solution(vector<int> array) {
	int answer = 0;
	int len = array.size();
	string str = "";

	for (int i = 0; i < len; i++) 
		str += to_string(array[i]);
	
	len = str.length();

	for (int i = 0; i < len; i++)
		if (str[i] == '7')
			answer++;

	return answer;
}