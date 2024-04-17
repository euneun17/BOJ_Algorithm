#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    int a, b;
    while (pq.size() >= 2 && pq.top() < K){
        a = pq.top(); 
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + 2*b);
        answer++;
    }
    
    if (pq.top() < K) answer = -1;
        
    return answer;
}