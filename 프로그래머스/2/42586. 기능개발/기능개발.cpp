#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0; i < progresses.size(); i++){
        int tmp = (100-progresses[i]) % speeds[i] == 0 ? (100-progresses[i]) / speeds[i] : (100-progresses[i]) / speeds[i] + 1;
        days.push_back(tmp);
    }
    
    int previous = days[0]; int count = 1;
    for (int i = 1; i < days.size(); i++){
        if (days[i] <= previous) {
            count++;
            if (i == days.size()-1) {
                answer.push_back(count);
            }
        }
        else {
            answer.push_back(count);
            count = 1;
            if (i == days.size()-1) {
                answer.push_back(count);
                continue;
            }
            previous = days[i];
        }
    }
    
    return answer;
}