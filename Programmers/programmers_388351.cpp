#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int N = schedules.size();
    
    for (int i = 0; i < N; i++) {
        int schedule = schedules[i];

        // ��� ���� �ð� ���
        int hour = schedule / 100;
        int minutes = schedule % 100;

        minutes += 10;

        if (minutes >= 60) {
            hour += 1;
            minutes = minutes % 60;
        }

        hour *= 100;
        schedule = hour + minutes;

        vector<int> timelog = timelogs[i];
        
        bool flag = true;
        int curDay = startday - 1;

        for (int j = 0; j < 7; j++) {
            curDay += 1;

            if (curDay > 7)
                curDay %= 7;

            // �ָ��� ����
            if (curDay == 6 || curDay == 7) continue;

            int curTimelog = timelog[j];

            // �ð��� �������� ���� �����
            if (curTimelog > schedule) {
                flag = false;
                break;
            }
        }

        if (flag)
            answer++;
    }

    return answer;
}