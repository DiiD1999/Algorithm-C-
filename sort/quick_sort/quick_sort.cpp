/*
 * 参考Acwing网站的快速排序代码, 简洁优雅地实现快速排序
 * 
 * @link: https://www.acwing.com/problem/content/787/
 */
#include<iostream>

using namespace std;

const int N = 1000010;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l - 1;
    int j = r + 1;
    int x = q[(l + r) >> 1];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}
