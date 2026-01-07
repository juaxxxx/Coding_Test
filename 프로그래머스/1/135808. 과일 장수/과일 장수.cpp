#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    int count = 0;
    int minApple = 9;
    
    for (int i = 0; i < score.size(); i++)
    {
        minApple = min(score[i], minApple);
        count++;
        if (count == m)
        {
            answer += minApple * m;
            count = 0;
            minApple = 9;
        }
    }
    
    return answer;
}