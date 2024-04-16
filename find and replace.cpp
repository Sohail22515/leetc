class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //for pattern
        int arr[160]={0};
        char j=97;
        for(int i=0;i<pattern.size();i++){
            if(arr[int(pattern[i])]==0){
            arr[int(pattern[i])]=j;
            pattern[i]=char(j);
            j++;
            }
            else{pattern[i]=char(arr[pattern[i]]);}
        }
        
        //for vector<string>

        int n=words.size();
        vector<string>str(n,"");

        for(int i=0;i<words.size();i++){
            int ar[160]={0};
            j=97;
            for(int k=0;k<words[i].size();k++){
                if(ar[int(words[i][k])]==0){
                    ar[int(words[i][k])]=j;
                    // words[i][k]=char(j);
                    str[i]+=char(j);
                    j++;
                }
                // else{words[i][k]=char(ar[words[i][k]]);}
                else{str[i]+=char(ar[int(words[i][k])]);}
            }
        }

        vector<string>v;
        for(int i=0;i<words.size();i++){
            if(str[i]==pattern){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};
