class Solution {
    public static int strStr(String haystack, String needle) {
        for(int i=0;i<haystack.length()-needle.length()+1;i++){
            if(haystack.substring(i,i+needle.length()).equals(needle)){
                return i;
            }
        }
        return -1;
    }
}

public class FirstOccuranceOfSubString{
    public static void main(String args[]){
        int ans=Solution.strStr("kty", "y");
        System.out.print(ans);
    }
}
