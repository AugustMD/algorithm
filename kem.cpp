#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int kor;
    int en;
    int math;
};

bool cmp(const Person &u, const Person &v) {
    if(u.kor == v.kor) {
        if(u.en == v.en) {
            if(u.math == v.math) {
                return u.name < v.name;
            }
            return u.math > v.math;
        }
        return u.en < v.en;
    }
    return u.kor > v.kor;

    // return make_tuple(-u.kor, u.en, -u.math, u.name) < make_tuple(-v.kor, v.en, -v.math, v.name)
}

int main() {
    int n;
    scanf("%d",&n);
    vector<Person> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].kor >> a[i].en >> a[i].math;
    }

    stable_sort(a.begin(),a.end(),cmp);

    for(int i = 0; i < n; i++) {
        cout << a[i].name << '\n';
    }

    return 0;
}