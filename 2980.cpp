#include <iostream>
#include <queue>

using namespace std;

typedef struct light {
	int R;
	int G;
} Light;

// 해당 위치에 신호등이 있는가?
bool isTrafficLights[1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<Light> trafficLights;

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int D, R, G;
		cin >> D >> R >> G;

		isTrafficLights[D] = true;

		Light light;
		light.R = R;
		light.G = G;

		trafficLights.push(light);
	}

	int curPos = 0;
	int time = 0;

	while (true) {
		// 목적지에 도달했다면
		if (curPos == L)
			break;

		// 신호등을 마주쳤다면
		if (isTrafficLights[curPos]) {
			Light light = trafficLights.front();
			trafficLights.pop();

			// 해당 신호등의 사이클
			int cycle = light.R + light.G;

			// 현재 불의 상태를 계산한다.
			int status = time % cycle;

			// 빨간불이라면
			if (status < light.R) {
				time += (light.R - status);
			}
		}

		curPos++;
		time++;
	}

	cout << time << endl;

	return 0;
}