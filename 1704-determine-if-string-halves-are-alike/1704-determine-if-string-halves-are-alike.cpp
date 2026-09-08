class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = "";
        string b = "";
        int n = s.size();
        int acount = 0;
        int bcount = 0;

        for (int i = 0; i < n / 2; i++) {
            a = a + s[i];
        }

        for (int i = n / 2; i < n; i++) {
            b = b + s[i];
        }

        for (char &c : a)
            c = tolower(c);

        for (char &c : b)
            c = tolower(c);

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' ||
                a[i] == 'o' || a[i] == 'u') {
                acount++;
            }
        }

        for (int i = 0; i < b.size(); i++) {
            if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' ||
                b[i] == 'o' || b[i] == 'u') {
                bcount++;
            }
        }

        return acount == bcount;
    }
};