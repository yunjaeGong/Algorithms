#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void Merge_Sort(vector<int>& vec, int first, int last);
void Merge(vector<int>& vec, int first, int mid, int last);

int main() {
    vector<int> vec;
    string buffer;
    int data;
    getline(cin, buffer);
    istringstream iss(buffer);
    while (iss >> data)
        vec.push_back(data);

    Merge_Sort(vec, 0, vec.size()-1);
    for (vector<int>::iterator it = vec.begin(); it!=vec.end(); it++){
        cout << *it << " ";
    }

    return 0;
}

void Merge_Sort(vector<int>& vec, int first, int last) {
    /*
     * base case: first == last일 때 return
     * 반 나누고 Merge_Sort(first, mid), Merge_sort(mid+1, last) 호출
     * base case에서 리턴된 값들 정렬 -> Merge 함수로
     */
    int mid;

    if(first == last) //base case: first == last일 때(더이상 쪼갤 수 없을 때) return
        return;

    mid = (first + last)/2;
    //mid는
    Merge_Sort(vec, first, mid);
    Merge_Sort(vec, mid+1, last);
    //mid +1 -> first이고, first는 배열 첫번째 인덱스!
    //호출 순서: BST traversal
    Merge(vec, first, mid, last);
}

void Merge(vector<int>& vec, int first, int mid, int last) {
    int i = first, j = mid + 1; //mid = 왼쪽 절반 마지막 원소 인덱스
    vector<int> sub_vec;

    while (i <= mid && j <= last) { //i, j 정렬 덜끝남

        if (vec[i] > vec[j]) {
            sub_vec.push_back(vec[j]);
            j++;
        } else if (vec[i] <= vec[j]) {
            sub_vec.push_back(vec[i]);
            i++;
        }//stable 정렬
    }

    while ((i == mid+1) != (j == last +1)) { //2개를 합칠 때?
        if (i == mid + 1 && j <= last) { //왼쪽 부분 배열이 먼저 정렬끝남
            sub_vec.push_back(vec[j]);
            j++;
        } else if (j == last + 1 && i <= mid) { //오른쪽 부분 배열이 먼저 정렬끝남
            sub_vec.push_back(vec[i]);
            i++;
        }
    }// end of while

    for (int k = 0; k < sub_vec.size(); k++) {
        vec[k + first] = sub_vec[k];
        //먼저 부분 배열의 정렬이 끝났을 때 남은 부분배열의 원소는 뒤에 넣어줌.
    }
}
