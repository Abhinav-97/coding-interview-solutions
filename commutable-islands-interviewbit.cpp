int find_parent(int parent[], int s)
{
    if(parent[s] == -1) return s;
    return find_parent(parent, parent[s]);
}
void Union(int parent[], int x, int y)
{
    int xp = find_parent(parent, x);
    int yp = find_parent(parent, y);
    parent[xp] = yp; 
}
bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), cmp);
    int parent[A];
    fill_n(parent, A, -1);
    int ans = 0;
    for(int i=0;i<B.size();i++)
    {
        int src = B[i][0] - 1;
        int dest = B[i][1] - 1;
        int srcp = find_parent(parent, src);
        int destp = find_parent(parent, dest);
        if(srcp != destp){
            Union(parent, srcp, destp);
            ans += B[i][2];
        }
    }
    return ans;
}