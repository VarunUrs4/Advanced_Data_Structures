public class DisjointSets_Main {
    public static void main(String[] args){
        int[][] a = new int[][] {
                                    {1, 1, 0, 0, 0},
                                    {0, 1, 0, 0, 1},
                                    {1, 0, 0, 1, 1},
                                    {0, 0, 0, 0, 0},
                                    {1, 0, 1, 0, 1}
                                };
        System.out.println("Number of Islands is: " + countIslands(a));
    }

    // Returns number of islands in a[][]
    static int countIslands(int a[][]){
        int n = a.length;
        int m = a[0].length;

        DisjointUnionSets dus = new DisjointUnionSets(n*m);

        for (int row=0; row<n; row++){
            for (int col=0; col<m; col++){
                if (a[row][col] == 0)
                    continue;
                
                //down
                if (row+1 < n && a[row+1][col]==1)
                    dus.union(row*(m)+col, (row+1)*(m)+col);
                
                //up
                if (row-1 >= 0 && a[row-1][col]==1)
                    dus.union(row*(m)+col, (row-1)*(m)+col);
                
                //right
                if (col+1 < m && a[row][col+1]==1)
                    dus.union(row*(m)+col, (row)*(m)+col+1);
                
                //left
                if (col-1 >= 0 && a[row][col-1]==1)
                    dus.union(row*(m)+col, (row)*(m)+col-1);
                
                //diagonally right-bottom
                if (row+1<n && col+1<m && a[row+1][col+1]==1)
                    dus.union(row*(m)+col, (row+1)*(m)+col+1);

                //diagonally left-bottom
                if (row+1<n && col-1>=0 && a[row+1][col-1]==1)
                    dus.union(row*m+col, (row+1)*(m)+col-1);

                //diagonally right-up
                if (row-1>=0 && col+1<m && a[row-1][col+1]==1)
                    dus.union(row*m+col, (row-1)*m+col+1);

                //diagonally left-up
                if (row-1>=0 && col-1>=0 && a[row-1][col-1]==1)
                    dus.union(row*m+col, (row-1)*m+col-1);
            }
        }

        // Array to note down frequency of each set
        int[] c = new int[n*m];
        int numberOfIslands = 0;
        for (int row=0; row<n; row++){
            for (int col=0; col<m; col++){
                if (a[row][col]==1){
                    int x = dus.find(row*m+col);

                    if (c[x]==0) {
                        numberOfIslands++;
                        c[x]++;
                    }

                    else
                        c[x]++;
                }
            }
        }
        return numberOfIslands;
    }
}

// Class to represent Disjoint Set Data structure
class DisjointUnionSets{
    int[] rank, parent;
    int n;

    public DisjointUnionSets(int n){
        rank = new int[n];
        parent = new int[n];
        this.n = n;
        makeSet();
    }

    void makeSet(){
        for (int i=0; i<n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x]=find(parent[x]);

        return parent[x];
    }
    void union(int x, int y){

        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;

        else if(rank[yRoot]<rank[xRoot])
            parent[yRoot] = xRoot;

        else{
            parent[yRoot] = xRoot;
            rank[xRoot] = rank[xRoot] + 1;
        }
    }
}
