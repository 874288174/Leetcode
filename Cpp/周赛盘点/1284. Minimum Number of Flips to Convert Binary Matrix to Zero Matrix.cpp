static vector<int> dirs={0,1,0,-1,0};
class Solution {
public:
    int m,n;                      
    //Stores #rows and #columns of the matrix.
    int createBitVec(vector<vector<int>>& mat)        
        //Creates bitVector using a matrix of `m` rows and `n` columns.
    {
        int bitvec=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                bitvec<<=1,bitvec|=mat[i][j];
        return bitvec;
    }
    int getFlip(int i,int j,int bitVec)       
        //Get flip of the matrix from position i,j and return it's bit vector representation.
    {
        int x,y,pos=m*n-1-i*n-j;             
        //Get position in bit vector using i,j.
        bitVec^=1<<pos;
        for(int d=0;d<4;d++)
        {
            x=i+dirs[d],y=j+dirs[d+1];
            if(x>=0&&y>=0&&x<m&&y<n)
                pos=m*n-1-x*n-y,bitVec^=1<<pos;             
            //Get position in bit vector using x,y and flip it.
        }
        return bitVec;
    }
    int minFlips(vector<vector<int>>& mat) 
    {
        m=mat.size(),n=mat[0].size();
        int bitvec=createBitVec(mat);                     
        //Bitvec stores initial state of the matrix
        if(!bitvec)
            return 0;
        queue<int> q;
        unordered_set<int> visited;                      
        //To keep track of visited states.
        int distance=0,size;
        q.push(bitvec);						
        //Push intial state to queue as starting state.
        while(!q.empty())                              
            //Regular BFS.
        {
            size=q.size();
            while(size--)
            {
                if(!q.front())
                    return distance;
                for(int i=0;i<m;i++)                   
                    //Flip the matrix from every cell.
                    for(int j=0;j<n;j++)
                    {
                        bitvec=getFlip(i,j,q.front());  
                        //Get bit vector for flip from position i,j.
                        if(!visited.count(bitvec))
                            q.push(bitvec),visited.insert(bitvec);
                    }
                q.pop();
            }
            distance++;
        }
        return -1;   
    }
};