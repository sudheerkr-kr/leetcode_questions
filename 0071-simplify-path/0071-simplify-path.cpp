class Solution {
public:
    void buildAns(stack<string>& s, string& ans) {
        if (s.empty()) {
            return;
        }

        string top = s.top();
        s.pop();

        buildAns(s, ans);

        ans += "/" + top;
    }

    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;

        while (i < path.size()) {

            // Skip all consecutive '/'
            while (i < path.size() && path[i] == '/') {
                i++;
            }

            if (i >= path.size()) {
                break;
            }

            int start = i;

            while (i < path.size() && path[i] != '/') {
                i++;
            }

            string minPath = path.substr(start, i - start);

            if (minPath == ".") {
                continue;
            }

            if (minPath == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            }
            else {
                s.push(minPath);
            }
        }

        string ans = "";

        buildAns(s, ans);

        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};