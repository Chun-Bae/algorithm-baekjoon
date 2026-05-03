#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    
    // 스테이지, 힌트 번틀 개수
    int n = cost.size();
    int m = hint.size();
    int k = hint[0].size() - 1;
    // printf("스테이지 개수: %d, 힌트 번들 개수: %d, 힌트권 개수: %d\n",n,m,k);
    
    // 가장 큰 값
    long long min_cost = LLONG_MAX;
    
    for (int mask = 0; mask < (1 << m); mask++) {
        long long total_cost = 0;
        long long hint_bundle_cost = 0;
        
        vector<int> hint_count(n, 0);
        
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                hint_bundle_cost += hint[i][0];
                
                for(int number = 1; number <= k; number++){
                    if(hint_count[hint[i][number] - 1] < n-1){
                        hint_count[hint[i][number] - 1]++;
                    }
                }
            }
        }
        
        // printf("힌트 번들 총 가격: %d\n",hint_bundle_cost);
        // printf("힌트권 총 개수: ");
        // for (int i=0; i<n; i++){
        //     printf("%d ",hint_count[i]);
        // }
        // printf("\n");
        
        total_cost += hint_bundle_cost;
        
        for (int i=0; i< n; i++) {
            total_cost += cost[i][hint_count[i]];
        }
        
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
        
    }
    answer = min_cost;
    
    return answer;
}