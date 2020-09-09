class Solution 
{
    public:
    int c2i[26];//把每個字母映射到數字 (確保每個字母只會映射到同1個數字)
    int i2c[10];//把每個數字映射到字母 (確保數字不會被重複使用)
    vector<string> w; //words的全域變數 (純粹為了方便)
    string r; //result的全域變數 (純粹為了方便)
    bool dfs(int index,int l,int s)  
    {
        //遍歷順序是把當前的位數中的所有單字處理完後，才會進展到下一個位數，直到所有位數被處理完為止
        //index代表當前到了words中的哪1個單字 
        //(eg. words[index], index從0~words.length()-1)
        //l代表當前走到了words中單字或result的哪1個位數(因為我們要統計完所有當前位數才能進位) 
        //(eg. words[index][l], result[l], l從0~result.length()-1或是l從0~words[index].length()-1)
        //s是所有單字在當前的位數的總合;s%10是當前位數所有單字合的個位數, s/10就是我們傳遞的進位值
        if(l==r.length()) //如果已經遍歷完所有的位數，就抵達終止條件
            return s==0; //我們要確保當前的s進位值已經是0
        
        if(index==w.size()) //如果對於所有單字words[0]~words[end]，都已經遍歷完當前位數l，就遍歷下個位數
        {
            if(c2i[r[l]-'A']!=-1) //如果result當中，當前位數對應的字母已經被分配過數字
            {
                if(c2i[r[l]-'A']==s%10) //確認此字母映射到的數字是否為s的個位數 (s是所有的單字在當前位數的總合)
                    return dfs(0,l+1,s/10);//因為所有單字的當前位數都遍歷完了，所以我們從下個位數的words[0]開始遍歷，並且傳遞進位值(s/10)
            }
            else if(i2c[s%10]==-1) //如果字母還沒映射過，我們要確認我們該使用的數字(s%10)是否還沒被用過
            {
                if(l==(int)r.length()-1&&s%10==0) //最大位數不能為0
                    return false;
                c2i[r[l]-'A']=s%10; //把所有單字的當前位數的總和之個位數分配給result的當前位數對應的字母
                i2c[s%10]=r[l]-'A'; //確保所有單字當前位數的總和對應的個位數字已經被分配給字母r[l]，避免重複分配
                bool temp=dfs(0,l+1,s/10); //我們先把backtracking的結果存下來，因為此後還要把前面2個操作的結果復原, 而傳遞的index=0代表對於下個位數從words[0]開始遍歷, 把位數l增加1以前進到下個位數,傳遞進位值(s/10)
                c2i[r[l]-'A']=-1; //把前面的操作復原，這是回溯法backtracking的一部份
                i2c[s%10]=-1; //把前面的操作復原，這是回溯法backtracking的一部份
                return temp; //回傳結果
            }
            return false; //如果沒辦法符合以上的if或else if中的條件，代表此路不通，沒辦法形成正確等式
        }
        if(l>=w[index].length()) //如果當前處理的位數已經大於當前單字的長度，就直接跳過此單字
            return dfs(index+1,l,s); //直接跳過words[index]，從words[index+1]繼續遍歷當前的位數，s不會被改變，因為此單字已經被跳過了

        if(c2i[w[index][l]-'A']!=-1) //如果此字母已經分配過數字了
            if(l!=(int)w[index].length()-1||c2i[w[index][l]-'A']!=0) //避免首位數為0
                return dfs(index+1,l,s+c2i[w[index][l]-'A']); //把此字母對應的數字加到s，並且從下個單字words[index+1]繼續遍歷
        
        for(int i=0;i<10;i++) //如果此字母還沒被分配過任何數字
        {
            if(i2c[i]!=-1) //如果此數字已經被用過，就不能重複使用
                continue;
        
            if(i==0&&l==w[index].length()-1) //word[index]的首位數不能是0
                continue;
            
            i2c[i]=w[index][l]-'A'; //我們分配數字i給了字母w[index][l]，因此數字i不能再次被使用
            c2i[w[index][l]-'A']=i; //我們把字母w[index][l]映射的值設成數字i，因此該字母不能再被映射成其他數字
            bool temp=dfs(index+1,l,s+i); //我們先把backtracking的結果存下來，因為此後還要把前面2個操作的結果復原。並且從下個單字words[index+1]開始遍歷此位數(此位數被遍歷完才會再進位)，並且把s加上此操作所分配的數字
            i2c[i]=-1; //把前面的操作復原，這是回溯法backtracking的一部份
            c2i[w[index][l]-'A']=-1; //把前面的操作復原，這是回溯法backtracking的一部份(讓我們能開始嘗試下一種可能)
            if(temp) //如果任何一種單字分配的方式能形成正確等式，就回傳true
                return true;
        }
        return false; //如果所有的數字分配都嘗試過也不能成功，就回傳false
    }
    bool isSolvable(vector<string>& words, string result) 
    {
        for(int i=0;i<words.size();i++)
            if((int)words[i].length()>(int)result.length()) //每個單字的長度都不能長於result的長度
                return false;

        memset(c2i,-1,sizeof(c2i)); //把所有的26個字母的映射初始成-1，代表我們還沒有為此字母分配過數字
        memset(i2c,-1,sizeof(i2c)); //把所有10的數字的映射初始成-1,代表我們還沒有分配過此數字給任何字母
        w=words; //words的全域變數是w
        r=result; //result的全域變數是r
        for(int i=0;i<words.size();i++) //把所有的單字反轉，以便我們能從個位、十位、百位遍歷到最大位數
            reverse(w[i].begin(),w[i].end());
        
        reverse(r.begin(),r.end()); //把結果對應的字串反轉，以便我們能從個位、十位、百位遍歷到最大位數
        return dfs(0,0,0); //我們從words[0]的最小位數(個位數)開始遍歷，個位數的總和初始為0
    }
};