#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		string morse[26] = {
			".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
		};

		set<string> s;
		
		for (auto word : words) {
			int len = word.length();
			string temp = "";

			for (int i = 0; i < len; i++) {
				int morse_idx = (int)(word[i] - 97);
				temp += morse[morse_idx];
			}

			s.insert(temp);
		}

		return s.size();
	}
};