#include <bits/stdc++.h>
using namespace std;

//approach is correct but you can reduce these hell lot of if else to just few lines 

string toRoman(int num) {
  string s = to_string(num);
  int n = s.length();
  int i = 0;
  string result = "";
  while (i < n) {
    if (n - i == 4) {
      if (s[i] == '1') {
        result += "M";
      } else if (s[i] == '2') {
        result += "MM";
      } else if (s[i] == '3') {
        result += "MMM";
      }
    } else if (n - i == 3) {
      if (s[i] == '1') {
        result += "C";
      } else if (s[i] == '2') {
        result += "CC";
      } else if (s[i] == '3') {
        result += "CCC";
      } else if (s[i] == '4') {
        result += "CD";
      } else if (s[i] == '5') {
        result += "D";
      } else if (s[i] == '6') {
        result += "DC";
      } else if (s[i] == '7') {
        result += "DCC";
      } else if (s[i] == '8') {
        result += "DCCC";
      } else if (s[i] == '9') {
        result += "CM";
      }
    } else if (n - i == 2) {
      if (s[i] == '1') {
        result += "X";
      } else if (s[i] == '2') {
        result += "XX";
      } else if (s[i] == '3') {
        result += "XXX";
      } else if (s[i] == '4') {
        result += "XL";
      } else if (s[i] == '5') {
        result += "L";
      } else if (s[i] == '6') {
        result += "LX";
      } else if (s[i] == '7') {
        result += "LXX";
      } else if (s[i] == '8') {
        result += "LXXX";
      } else if (s[i] == '9') {
        result += "XC";
      }
    } else if (n - i == 1) {
      if (s[i] == '1') {
        result += "I";
      } else if (s[i] == '2') {
        result += "II";
      } else if (s[i] == '3') {
        result += "III";
      } else if (s[i] == '4') {
        result += "IV";
      } else if (s[i] == '5') {
        result += "V";
      } else if (s[i] == '6') {
        result += "VI";
      }else if (s[i] == '7') {
        result += "VII";
      }else if (s[i] == '8') {
        result += "VIII";
      }else if (s[i] == '9') {
        result += "IX";
      }
    }
    i++;
  }

  return result;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int num;
    cin>>num;
    cout<<toRoman(num)<<endl;
  }
  return 0;
}
