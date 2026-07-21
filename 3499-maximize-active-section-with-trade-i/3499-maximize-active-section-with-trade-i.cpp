class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones=0;

        for(char ch:s){
            if(ch=='1')
                ones++;
        }

        int ans=ones;

        string t="1"+s+"1";

        vector<pair<char,int>> blocks;

        int i=0;

        while(i<t.size()){

            char ch=t[i];
            int cnt=0;

            while(i<t.size() && t[i]==ch){
                cnt++;
                i++;
            }

            blocks.push_back({ch,cnt});
        }

        for(int i=1;i<blocks.size()-1;i++){

            if(blocks[i].first=='1' && blocks[i-1].first=='0' && blocks[i+1].first=='0'){

                int leftZero=blocks[i-1].second;
                int oneLen=blocks[i].second;
                int rightZero=blocks[i+1].second;

                int mergedZero=leftZero+oneLen+rightZero;

                int newOnes=ones-oneLen+mergedZero;

                if(i-1==0)
                    newOnes--;

                if(i+1==blocks.size()-1)
                    newOnes--;

                ans=max(ans,newOnes);
            }
        }

        return ans;
    }
};