/*����Ч�����������ж��Ƿ�Ϊ������*/ 
#include <iostream>
#include <algorithm>
using namespace std;
string s;
void add(string t) {
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry!=0) s += '1';
    //�±�С��λ�����赹�� 
    reverse(s.begin(), s.end());
}
int main() {
    int count, i;
    cin >> s >> count;
    for(i = 0; i <= count; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == count) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}
