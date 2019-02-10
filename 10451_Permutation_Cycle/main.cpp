#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class component{
public:
    int v;
    component* next;

    component(int v) { this->v = v; this->next = NULL; } //구조체 생성자
    component() { this->v = -1; this->next = NULL; } //맨 마지막 노드 생성용
};
vector<int>& dfs_cycle(component** list, int visited[], int u, const int start_vertex, const int n, vector<int>& subgraph);
int main() {
    int times, n;
    cin >> times;
    component* tmp;
    vector<int> subgraph;
    vector<int> result;
    while(times) {
        int i, count = 0, v;
        cin >> n;
        int *visited = new int[n+1];
        memset(visited,0,n+1);
        component** Adj_list = new component*[n+1]; // 0 ~ n-1까지
        for(int i=0;i<=n;i++) {
            Adj_list[i]=new component();
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

vector<int>& dfs_cycle(component** list, int visited[], int u, const int start_vertex, const int n, vector<int>& subgraph)
{ // 사이클이 존재하는지 확인하는 dfs
    /*
     * list: 인접리스트
     * visited[]: 정점들의 방문 여부를 저장하는 배열
     * u: 시작 정점
     * m: ?
     * n: 정점 개수
     * subgraph: 사이클이 존재하는 부그래프를 저장할 벡터
     * */
    enum ColorType {WHITE = 0, GRAY = 1, BLACK = 2};
    component* next_link = NULL;
    int v;
    //mark v as visited

    visited[u] = GRAY; //시작 정점를 방문했다고 표시
    subgraph.push_back(u);
    v = list[u]->v; //시작 정점 u에 인접한 첫 노드 v의 번호 가져오기
    if(v == start_vertex) {
        subgraph.push_back(v);
        return subgraph;
    }
    next_link = list[u]; //시작노드 u에 인접한 첫 노드 v의 주소
    //시작 위치 u에 인접한 노드들에 대해 탐색
    while(v != -1) {
        //u와 인접한 정점 v들에 대해
        if(visited[v] == WHITE) { //방문하지 않았으면
            //subgraph.push_back(v);
            dfs_cycle(list,visited,v,start_vertex,n,subgraph); //그 노드로 이동해 탐색
        }

        next_link = next_link->next; //다음 링크로 이동
        v = next_link->v; //다음 링크의 노드 번호 가져오기
    }

}