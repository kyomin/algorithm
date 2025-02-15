#include <vector>
#include <string>

using namespace std;

class OrderedStream {
public:
	vector<string> arr;
	int cur_point;
	int len;

	OrderedStream(int n) {
		cur_point = 0;
		arr.resize(n);
		len = n;

		for (int i = 0; i < n; i++)
			arr[i] = "";
	}

	vector<string> insert(int idKey, string value) {
		vector<string> out;
		arr[idKey - 1] = value;

		if (arr[cur_point] == "")
			return out;
		else {
			while (cur_point < len) {
				if (arr[cur_point] == "")
					break;

				out.push_back(arr[cur_point]);

				cur_point++;
			}
		}

		return out;
	}
};