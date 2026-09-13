int devolverMayorPosV(int *v, int n){
    int pos = 0;
    for (int i = 1; i<n; i++){
        if (v[i]>v[pos]){
            pos = i;
        }
    }
    return pos;
}
