class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0;
        while(i<n || j<m)
        {
            string s1="";
            string s2="";
            while(i<n and version1[i]!='.')
            {
                s1+=version1[i];
                i++;
            }
            while(j < m and version2[j]!='.')
            {
                s2+=version2[j];
                j++;
            }
            int a1=0;
            int a2=0;
            if(s1!="")a1=stoi(s1);
            if(s2!="")a2=stoi(s2);
            if(a1>a2)return 1;
            if(a2>a1)return -1;
            i++;
            j++;
        }
        return 0;
    }   
};