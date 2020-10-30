struct Triplet
{
    int val, aPos, vPos;
    Triplet(int v, int ap, int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};

struct myCmp
{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};


int *mergeKArrays(int arr[][N], int k)
{
    int *res = new int[k*k], m = 0;
    
    priority_queue<Triplet, vector<Triplet>, myCmp> pq;
    
    for(int i = 0; i < k; i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }
    
    while(pq.empty() == false)
    {
        Triplet curr = pq.top();
        pq.pop();
        
        res[m++] = curr.val;
        
        int ap = curr.aPos;
        int vp = curr.vPos;
        
        if((vp+1) < k)
        {
            Triplet t(arr[ap][vp+1], ap, vp+1);
            pq.push(t);
        }
    }
    
    return res;
    
}