class Solution {
public:
    string reorganizeString(string s) {
        int a[26]={0};
        for(int i=0;i<s.size();i++){
            a[s[i]-97]++;
        }
        int mf=INT_MIN;
        char mfc;
        for(int i=0;i<26;i++){
            if(a[i]>=mf){mf=a[i]; mfc=i+'a';}
        }
        int index =0;
        while(index<s.size() && mf>0){
            s[index]=mfc;
            mf--;
            index+=2;
        }
        a[mfc-97]=0;
        if(mf!=0){return "";}

        for(int i=0;i<26;i++){
            while(a[i]>0){
                if(index>=s.size()){index=1;}
                s[index]=i+'a';
                a[i]--;
                index+=2;
            }
        }
        return s;
        /*else{
            int j=0;
            for(int i=0;i<26;i++){
                if(a[i]>0){
                    while(a[i]!=0){
                        if(s[j]!=mfc){
                        s[j]=i+'a';
                        a[i]--;
                        }
                        j++;
                    }
                }
            }
        }
        return s;*/
    }
};
