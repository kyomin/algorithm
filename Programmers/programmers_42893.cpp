#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Page {
	int idx;	// 페이지의 인덱스
	int basic;	// 기본점수
	int link;	// 외부 링크 수
	double score;	// 매칭 점수
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

	// 검색 키워드 소문자 변환
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	for (int i = 0; i < pages.size(); i++) {
		string& page = pages[i];

		// 계산 편의를 위해 페이지의 모든 알파벳 소문자 변환
		transform(page.begin(), page.end(), page.begin(), ::tolower);

		int mid = 0;
		int posLeft = 0;
		int posRight;

		// meta 태그 내에 있는 url 값을 찾는다
		while (mid <= posLeft) {
			posLeft = page.find("<meta", posLeft + 1);
			posRight = page.find(">", posLeft);
			mid = page.rfind("https://", posRight);
		}

		// url의 시작위치 mid를 찾았으면 다음 큰따옴표까지가 url이다
		posRight = page.find("\"", mid);
		string url = page.substr(mid, posRight - mid);

		// 기본점수 구하기
		posLeft = page.find("<body>", posRight);
		int basic = 0;
		for (int start = posLeft; ;) {
			start = page.find(word, start + 1);

			// 찾지 못한 경우
			if (start == string::npos) break;
			
			// 찾은 단어 앞뒤가 모두 알파벳이 아니어야 유효하다
			if (!isalpha(page[start - 1]) && !isalpha(page[start + wsize])) {
				basic++;

				start += wsize;
			}
		}

		// 외부 링크 수 구하기
		int link = 0;
		for (int start = posLeft; ;) {
			start = page.find("<a href", start + 1);

			// 찾지 못한 경우
			if (start == string::npos) break;

			link++;
		}

		pageHash[url] = i;
		pageList.push_back({ i, basic, link, (double)basic });
	}

	// 매칭점수 계산하기
	for (int i = 0; i < pages.size(); i++) {
		string& page = pages[i];

		for (int posLeft = 0, posRight = 0; ;) {
			posLeft = page.find("<a href", posRight);

			if (posLeft == string::npos) break;

			posLeft = page.find("https://", posLeft);
			posRight = page.find("\"", posLeft);

			string linkUrl = page.substr(posLeft, posRight - posLeft);

			auto iter = pageHash.find(linkUrl);

			// Key를 찾은 경우
			if (iter != pageHash.end()) {
				Page currentPage = pageList[i];

				// 링크가 걸린 페이지의 매칭점수에 현 페이지의 링크 점수를 부여한다
				pageList[iter->second].score += (double)currentPage.basic / currentPage.link;
			}
		}
	}

	sort(pageList.begin(), pageList.end(), comp);

	return pageList.begin()->idx;
}