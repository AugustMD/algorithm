#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // sort(a.begin(), a.end());
    // printf("%d\n",a[k-1]);
    
    k -= 1;
    nth_element(a.begin(),a.begin()+k,a.end());
    for(int i = 0; i < n; i++) {
        printf("%d\n",a[i]);
    }
    // printf("%d\n",a[k]);
    return 0;
}