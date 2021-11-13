//112-Чудновский-Леонид
//Подсчёт единичных битов числа
int count_bit(int num){
    int count = 0;
    for( int i = 0; i < 32; i++){
        count += num & 1;
        num >>= 1;
    }
    return count;
}