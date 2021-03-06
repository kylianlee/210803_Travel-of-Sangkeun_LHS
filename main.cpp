//
// Created by Kylian Lee on 2021/07/29.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>>& route, int countries);

int main(){
  int case_num;
  cin >> case_num;
  for (int i = 0; i < case_num; ++i) {
    int countries, plains;
    cin >> countries >> plains;
    vector<vector<int>> route(countries + 1);
    for (int j = 0; j < countries + 1; ++j) {
      route[j].resize(countries + 1);
    }
    for (int j = 0; j < plains; ++j) {
      int s, d;
      cin >> s >> d;
      route[s][d] = 1;
      route[d][s] = 1;
    }
//    for (int j = 1; j < plains + 1; ++j) {
//      for (int k = 1; k < plains + 1; ++k) {
//        cout << route[j][k];
//      }
//      cout << endl;
//    }
    cout << solution(route, countries) << endl;
  }
}

int solution(vector<vector<int>>& route, int countries){
  vector<bool> visited(countries + 1, false);
  stack<int> s;
  int count = 0;
  s.push(1);
  visited[1] = true;
  while(!s.empty()){
    int i;
    int top = s.top();
    for (i = 1; i <= countries; ++i) {
      if(!visited[i] && route[top][i] == 1){
        s.push(i);
        visited[i] = true;
        count++;
        break;
      }
    }
    if(i == countries + 1)
      s.pop();
  }
  return count;
}