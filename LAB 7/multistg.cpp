
nt countstage(vector<vector<int>>& graph, int n, int i, int count) {
   count++;
   if(i == n) {
       return count;
   } else {
       int j = 1;
       while(graph[i-1][j-1] == 0) {
           j++;
       }
       i = j;
       count = countstage(graph, n, i, count);
       return count;
   }
}


void fcost(vector<vector<int>>& graph, int n, int k) {
   vector<int> fcost(n, INF);
   vector<int> d(n);
   vector<int> p(k);


   fcost[n-1] = 0;


   for(int j = n-2; j>=0; j--) {
       int r = findmin(j, graph, fcost, n);


       fcost[j] = graph[j][r] + fcost[r];
       d[j] = r;
   }
   p[0] = 0;


   p[k-1] = n-1;


   for(int j = 1; j<=k-2; j++) {
       p[j] = d[p[j-1]];
   }


   cout << "Shortest path: ";
   for(int i = 0; i<k; i++) {
       cout << p[i] + 1 << " ";
   }
   cout << "\nShortest path cost: " << fcost[0] << endl;
}
