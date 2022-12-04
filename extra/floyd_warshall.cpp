for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j ,= n; j++){
            if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
        }
    }
}