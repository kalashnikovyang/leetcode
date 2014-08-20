class Solution {
public:
    void reverseWords(string &s) {
        if(s.length() == 0) //空或者空格
        {
            return;
        }
        int len = s.length();
        string finalOutput(s); //字符操作存储
        
        int front = len - 1, behind = len - 1;
        int i,j;
        int resultLen = 0; //final output string length
        
        //处理尾部可能有多余的字符
        while(s[behind] == ' ')
        {
            behind--;
        }
        i = behind;
        
        while(i>=0)
        {
            if(s[i] == ' ')
            {
                front = i + 1;
                // copy word:s[front]~s[behind] to finalOutput
                for(j=front;j<=behind;j++)
                {
                    finalOutput[resultLen++] = s[j];
                }
                finalOutput[resultLen++] = ' '; //添加一个空格
                // behind: find the former word's tail
                behind = i;
                while(behind != -1 && s[behind] == ' ')
                {
                    behind--;
                }
                i = behind;
                continue;
            }
            // words, continue
            i--; 
        }
        
        // in case the head of string s is not space, store the first word
        for(i=0;i<=behind;i++)
        {
            finalOutput[resultLen++] = s[i];
        }

        
        // check whether the last element of final is space
        if(finalOutput[resultLen-1] == ' ')
        {
            resultLen--;
        }
        
        //re-assign string s
        s.assign(finalOutput, 0, resultLen);
    }
};