void swapString (char **c1, char **c2){
    char *tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void swapInt (int *c1, int *c2){
    int tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}
