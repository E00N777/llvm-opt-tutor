int test_dce(int a, int b) {
    
    int live = a + b;
   
    int dead_1 = a * 10;
    int dead_2 = b - 5;
    
    int dead_3 = dead_1 + dead_2;

    return live;
}