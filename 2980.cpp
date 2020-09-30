#include <iostream>
#include <queue>

using namespace std;

typedef struct light {
	int R;
	int G;
} Light;

// �ش� ��ġ�� ��ȣ���� �ִ°�?
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
		// �������� �����ߴٸ�
		if (curPos == L)
			break;

		// ��ȣ���� �����ƴٸ�
		if (isTrafficLights[curPos]) {
			Light light = trafficLights.front();
			trafficLights.pop();

			// �ش� ��ȣ���� ����Ŭ
			int cycle = light.R + light.G;

			// ���� ���� ���¸� ����Ѵ�.
			int status = time % cycle;

			// �������̶��
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