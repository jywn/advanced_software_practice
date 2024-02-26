#include <bits/stdc++.h>
using namespace std;

bool compare_desc(const pair<double, double>& a, const pair<double, double>& b) //내림차순
{
  if(a.first == b.first)
    return a.second > b.second;
  return a.first > b.first;
}
bool compare_incr(const pair<double, double>& a, const pair<double, double>& b) //오름차순
{
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*
  입력 받고 -> 사분면 별 parsing -> sort
  */
  int n;
  cin >> n;
  pair<double, double> arr_1[n], arr_2[n], arr_3[n], arr_4[n];//1_x, y
  for(int i = 0; i < n; i++) {
    arr_1[i].first = 0;
    arr_1[i].second = 0;
    arr_2[i].first = 0;
    arr_2[i].second = 0;
    arr_3[i].first = 0;
    arr_3[i].second = 0;
    arr_4[i].first = 0;
    arr_4[i].second = 0;
  }

  int i, j, k, l, m;
  double r;
  for(i = 0, j = 0, k = 0, l = 0, m = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    if(i == 0) {
      r = sqrt(x*x + y*y);
    }
    if(x >= 0 && y >= 0) {
      arr_1[j].first = x;
      arr_1[j++].second = y;
    }
    else if(x <= 0 && y >= 0) {
      arr_2[k].first = x;
      arr_2[k++].second = y;
    }
    else if(x <= 0 && y <= 0) {
      arr_3[l].first = x;
      arr_3[l++].second = y;
    }
    else {
      arr_4[m].first = x;
      arr_4[m++].second = y;
    }
  }
  sort(arr_1, arr_1 + j, compare_desc);
  sort(arr_2, arr_2 + k, compare_desc);
  sort(arr_3, arr_3 + l, compare_incr);
  sort(arr_4, arr_4 + m, compare_incr);
  int i_3 = 0;
  pair<double, double> arr[n];
  for(int j_2 = 0; j_2 < j; j_2++) {
    arr[i_3++] = arr_1[j_2]; // 0 - j-1
  }
    for(int k_2 = 0; k_2 < k; k_2++) {
    arr[i_3++] = arr_2[k_2];
  }
    for(int l_2 = 0; l_2 < l; l_2++) {
    arr[i_3++] = arr_3[l_2];
  }
    for(int m_2 = 0; m_2 < m; m_2++) {
    arr[i_3++] = arr_4[m_2];
  }
  double half_circle = M_PI *  r;
  cout << endl;
  double sum = 0;
  double max = 0;
  for(int i_2 = 0; i_2 < i; i_2++) {
    int sec = (i_2 + 1) % i;
    int flag = 0;
    double dot = arr[i_2].first * arr[sec].first + arr[i_2].second * arr[sec].second ;
    double cross = arr[i_2].first * arr[sec].second - arr[i_2].second * arr[sec].first;
    if(cross < 0) flag = 1;
    double cos_ang = dot / (sqrt(arr[i_2].first * arr[i_2].first + arr[i_2].second * arr[i_2].second) * sqrt(arr[sec].first * arr[sec].first + arr[sec].second * arr[sec].second));
    double ang = acos(cos_ang);
    if(flag)  ang = 2*M_PI - ang;
    double arc = ang * r;
    if(max < arc) max = arc;
    sum += arc;
  }
  sum -= max;
  if(sum > half_circle) cout << "NO HCP\n";
  else  cout << "HCP\n";
}
