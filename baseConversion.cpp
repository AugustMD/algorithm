#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int a, b, m, input[26];
string output;

int toTen(int i) {
    if(i == 0) {
        return input[0];
    } else {
        return input[i]*pow(a,i) + toTen(i-1);
    }
}

string fromTen(int t) {
    int quo = t/b;
    int mod = t%b;
    if(quo == 0) {
        output += to_string(mod);
        return output;
    } else {
        output = fromTen(quo) + " " + to_string(mod);
        return output;
    }
}


int main() {
    scanf("%d %d",&a,&b);
    scanf("%d\n",&m);
    for(int i = m-1; i >= 0; i--) {
        scanf("%d",&input[i]);
    }
    cout << fromTen(toTen(m-1)) << "\n";
    return 0;
}