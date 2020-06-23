#include <bits/stdc++.h>

using namespace std;

string convert(int num, int deno) {
    long long int num = numerator;
    long long int deno = denominator;

    bool isNeg = false;
    if (num < 0 && deno > 0 || num > 0 && deno < 0) {
        isNeg = true;
    }

    num = abs(num);
    deno = abs(deno);

    long long int firstPart = num / deno;
    long long int remainder = num % deno;
    unordered_map < long long int, long long int > hmap;
    string secondPart = "";
    long long int dividend = 0;
    long long int i = 0;
    while (remainder != 0) {
        hmap[remainder] = i;
        dividend = remainder * 10;
        // cout<<"dividend = "<<dividend<<endl;
        if (dividend >= deno) {
            long long int temp = dividend / deno;
            secondPart.push_back(char(temp) + '0');
            remainder = dividend % deno;
        } else {
            secondPart.push_back('0');
            remainder = dividend % deno;

        }
        // cout<<"remainder = "<<remainder<<endl;

        if (hmap.find(remainder) != hmap.end()) {
            break;
        }

        i++;
    }
    string result = "";

    if (remainder == 0) {
        if (secondPart.length() == 0) {
            result = to_string(firstPart);
        } else {
            result = to_string(firstPart) + "." + secondPart;
        }
    } else {
        // cout<<"index of repeating remainder = "<<hmap[remainder]<<endl;
        // cout<<"i = "<<i<<endl;
        // cout<<secondPart.substr(0, hmap[remainder] - 0)<<" == "<<secondPart.substr(hmap[remainder], i - hmap[remainder] + 1);

        result = to_string(firstPart) + "." + secondPart.substr(0, hmap[remainder] - 0) + "(" + secondPart.substr(hmap[remainder], i - hmap[remainder] + 1) + ")";

    }

    if (isNeg == true) {
        result = "-" + result;
    }

    return result;

}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int num;
        int deno;
        cin >> num;
        cin >> deno;
        cout << convert(num, deno) << endl;
    }
    return 0;
}
