#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    for (int i = 0; i < players.size(); i++){
        m.insert(make_pair(players[i], i));
    }
    
    for (int i = 0; i < callings.size(); i++){
        string called_player = callings[i];
        int rank = m[called_player];
        
        swap(players[rank-1], players[rank]);
        
        m[called_player] = rank -1;
        m[players[rank]] = rank;
    }
    
    return players;
}