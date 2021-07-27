#Implementing of Range sum query Segment tree
#adapted from https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
class seg:
    def __init__(self,n):
        self.start=0
        self.end=n-1
        self.node=0
        self.tree=[None]*(2*n-1)
    def build(self, array):
        return self.build_sum(array,0,self.start,self.end)
    def build_sum(self,array,node,start,end):
        if start==end:
            self.tree[node]=array[start]
            return
        mid=(start+end)/2
        self.build_sum(array,2*node+1,start,mid)
        self.build_sum(array,2*node+2,mid+1,end)
        self.tree[node]=self.tree[node*2+1]+self.tree[node*2+2]
    def update(self,ind,val):
        self.update_sum(self.start,self.end,0,ind,val)
    def update_sum(self,start,end,node,ind,val):
        if ind<start or ind>end:
            return
        if start==end:
            self.tree[node]=val
            array[start]=val
            return
        mid=(start+end)/2
        self.update_sum(start,mid,2*node+1,ind,val)
        self.update_sum(mid+1,end,2*node+2,ind,val)
        self.tree[node] = self.tree[2 * node + 1]+self.tree[2 * node + 2]
    def query(self,l,r):
        return self.query_sum(self.start,self.end,0,l,r)
    def query_sum(self,start,end,node,l,r):
        if l <= start and r >= end:
            return self.tree[node]
        if l > end or r < start:
            return 0
        mid = (start + end) / 2
        return self.query_sum(start,mid,2 * node + 1,l,r)+self.query_sum(mid+1,end,2 * node + 2,l,r)




array=[2,1,3,5,4]
n=5
s = seg(n)
s.build(array)
print s.tree
s.update(2,6)
print s.tree
print s.query(1,3)
