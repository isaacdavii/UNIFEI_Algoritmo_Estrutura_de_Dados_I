int main () {
    int x, y, *p;
    y = 0; 
    p = &y; // p aponta para y
    x = *p; // x recebe o valor de y 
    x = 4; // x recebe 4
    (*p)++; // y recebe y + 1
    --x; // x recebe x - 1
    (*p) += x; // y recebe y + x
    printf("%d %d %d\n", x, y, *p); // imprime x, y e o valor apontado por p
    return 0;
}