#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() { // 간소화한 방법 이용 (인접 리스트 구현x, dfs 간단하게 구현
    int times, n;
    cin >> times;
    vector<int> subgraph;
    vector<int> result;
    while(times) {
        int i, count = 0, v;
        cin >> n;
        int *visited = new int[n+1];
        memset(visited,0,n+1);
        int *Adj_list = new int[n+1]; // 0 ~ n-1까지
        Adj_list[0] = 0;
        for(int i=1;i<=n;i++) {
            cin >> v;
            Adj_list[i] = v;
        }

        for(int i=1;i<=n;++i) {
            cin >> v;
            tmp = Adj_list[i];
            Adj_list[i] = new component(v);
            Adj_list[i]->next = tmp;
        }
        //인접 리스트 입력 끝
        //모든 n개의 정점에 대해 싸이클의 개수 확인
        /*for(int i=0; i<n; i++)
        {
            component *ptr = Adj_list[i];
            cout<<"adjacenyList["<<i<<"]";
            while(ptr)
            {
                cout<<"->"<<ptr->v;
                ptr=ptr->next;
            }
            cout<<endl;
        }*/
        int start_vertex = 0;
        for(i=1;i<=n;++i) {
            if(visited[i] == 0) {
                start_vertex = i;
                dfs_cycle(Adj_list, visited, start_vertex, start_vertex, n, subgraph);
                for (vector<int>::iterator it = subgraph.begin() ; it != subgraph.end(); ++it)
                    cout << *it << "->";
                cout << endl;
                if(subgraph.size()>=2) count++;
                subgraph.clear();
            }
        }
        // 방문 안된 정점이 없으면 -1 출력
        result.push_back(count);
        delete[] Adj_list;
        delete[] visited;
        times--;
    }
    for(int i=0;i<result.size()-1;++i)
        cout << result[i] << endl;
    cout << result.back();
    return 0;
}

vector<int>& dfs_cycle(int arr[], int visited[], int u, const int start_vertex, const int n, vector<int>& subgraph) {

}