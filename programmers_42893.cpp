#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Page {
	int idx;	// �������� �ε���
	int basic;	// �⺻����
	int link;	// �ܺ� ��ũ ��
	double score;	// ��Ī ����
};

bool comp(Page& a, Page& b) {
	if (a.score == b.score)
		return a.idx < b.idx;

	return a.score > b.score;
}

int solution(string word, vector<string> pages) {
	map<string, int> pageHash;
	vector<Page> pageList;
	int wsize = word.length();

	// �˻� Ű���� �ҹ��� ��ȯ
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	for (int i = 0; i < pages.size(); i++) {
		string& page = pages[i];

		// ��� ���Ǹ� ���� �������� ��� ���ĺ� �ҹ��� ��ȯ
		transform(page.begin(), page.end(), page.begin(), ::tolower);

		int mid = 0;
		int posLeft = 0;
		int posRight;

		// meta �±� ���� �ִ� url ���� ã�´�
		while (mid <= posLeft) {
			posLeft = page.find("<meta", posLeft + 1);
			posRight = page.find(">", posLeft);
			mid = page.rfind("https://", posRight);
		}

		// url�� ������ġ mid�� ã������ ���� ū����ǥ������ url�̴�
		posRight = page.find("\"", mid);
		string url = page.substr(mid, posRight - mid);

		// �⺻���� ���ϱ�
		posLeft = page.find("<body>", posRight);
		int basic = 0;
		for (int start = posLeft; ;) {
			start = page.find(word, start + 1);

			// ã�� ���� ���
			if (start == string::npos) break;
			
			// ã�� �ܾ� �յڰ� ��� ���ĺ��� �ƴϾ�� ��ȿ�ϴ�
			if (!isalpha(page[start - 1]) && !isalpha(page[start + wsize])) {
				basic++;

				start += wsize;
			}
		}

		// �ܺ� ��ũ �� ���ϱ�
		int link = 0;
		for (int start = posLeft; ;) {
			start = page.find("<a href", start + 1);

			// ã�� ���� ���
			if (start == string::npos) break;

			link++;
		}

		pageHash[url] = i;
		pageList.push_back({ i, basic, link, (double)basic });
	}

	// ��Ī���� ����ϱ�
	for (int i = 0; i < pages.size(); i++) {
		string& page = pages[i];

		for (int posLeft = 0, posRight = 0; ;) {
			posLeft = page.find("<a href", posRight);

			if (posLeft == string::npos) break;

			posLeft = page.find("https://", posLeft);
			posRight = page.find("\"", posLeft);

			string linkUrl = page.substr(posLeft, posRight - posLeft);

			auto iter = pageHash.find(linkUrl);

			// Key�� ã�� ���
			if (iter != pageHash.end()) {
				Page currentPage = pageList[i];

				// ��ũ�� �ɸ� �������� ��Ī������ �� �������� ��ũ ������ �ο��Ѵ�
				pageList[iter->second].score += (double)currentPage.basic / currentPage.link;
			}
		}
	}

	sort(pageList.begin(), pageList.end(), comp);

	return pageList.begin()->idx;
}