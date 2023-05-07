#include <random>
using namespace std;
#define int long long

mt19937 rng(random_device{}());
int a[110000], tmp[110000]; // a:原数据    tmp:归并排序辅助数组
int b[110000];   // b:快排数组
int n;  // n:数据量

void mergeSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int k = l, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (int i = l; i <= r; i++) {
        a[i] = tmp[i];
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}

int cntq, cntqq;
void quickSort(int l, int r) {
    int i = l, j = r;
    int x = b[l];
    while (i <= j) {
        while (b[i] < x) { i++; cntqq++; }
        while (b[j] > x) { j--; cntqq++; }
        if (i <= j) {
            swap(b[i], b[j]);
            cntq++;
            i++;
            j--;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    puts("");

    if (i < r) quickSort(i, r);
    if (j > l) quickSort(l, j);
}

void InitIncrease() {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void InitDecrease() {
    for (int i = 1; i <= n; i++) {
        a[i] = n - i + 1;
    }
}

signed main() {

    n = 10 + rng() % 10;

    for (int i = 0; i < 5; i++) {
        cntq = cntqq = 0;
        if (i == 0) {
            printf("本轮数据为增序，本轮排序的信息如下\n");
            InitIncrease();
        }
        else if (i == 1) {
            printf("本轮数据为降序，本轮排序的信息如下\n");
            InitDecrease();
        }
        else {
            printf("本轮数据为无序，本轮排序的信息如下\n");
            random_shuffle(a + 1, a + n + 1);
        }

        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
        }

        printf("归并排序步骤如下:\n");
        mergeSort(1, n);
        printf("快速排序步骤如下:\n");
        quickSort(1, n);


        int cntm = n * log2(n);

        printf("归并排序的交换次数为 %d， 比较次数为 %d \n", cntm, cntm);
        printf("快速排序的交换次数为 %d， 比较次数为 %d \n\n", cntq, cntqq);
    }

    return 0;
}
