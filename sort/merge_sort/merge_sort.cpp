/*
 * 参考Acwing网站的合并排序代码, 简洁优雅地实现合并排序
 *
 * @link: https://www.acwing.com/problem/content/789/
 */
#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l;
    int mid = (l + r) >> 1;
    int j = mid + 1;
    merge_sort(q, i, mid);
    merge_sort(q, mid + 1, r);

    int k = 0;
    int temp[r - l + 1];
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = q[i++];
    }
    while (j <= r) {
        temp[k++] = q[j++];
    }

    for (int i = 0, j = l; j <= r; i++, j++) {
        q[j] = temp[i];
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    return 0;
}
