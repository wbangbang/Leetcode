class Solution {
public:
    int compareVersion(string version1, string version2) {
        return compare(version1, version2, 0, 0);
    }
    
    int compare(string version1, string version2, int start1, int start2) {
        int n1 = version1.size(), n2 = version2.size(), pos1 = start1, pos2 = start2;
        if(start1 >= n1 && start2 >= n2) return 0;
        while(version1[pos1] != '.' && pos1 < n1) {
            pos1++;
        }
        while(version2[pos2] != '.' && pos2 < n2) {
            pos2++;
        }
        int v1 = 0, v2 = 0;
        if(start1 < n1) {
            stringstream s1(version1.substr(start1, pos1)); 
            s1 >> v1; 
        }
        if(start2 < n2) {
            stringstream s2(version2.substr(start2, pos2));
            s2 >> v2;
        }
        if(v1 == v2) {
            return compare(version1, version2, pos1 + 1, pos2 + 1);
        }
        else if(v1 > v2) {
            return 1;
        }
        else return -1;
    }
};