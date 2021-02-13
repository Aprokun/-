#include <stdio.h>

int main() {
    //ввод строки
    char str[255];
    printf("Input string:\n");
    fflush(stdin);
    gets(str);
    printf("Inputted string: %s\n",str);

    //ввод символа
    unsigned char c;
    printf("Input symbol:\n");
    c = getchar();
    printf("Inputted symbol: %c\n",c);

    //ввод и вывод значений каждого из базовых типов
    float cel = 0.0f,far;
    double speedKMH = 0.0,speedMS;
    int val = 0, val2;

    printf("Input your age:\n");
    scanf("%d",&val);
    val2 = val + 10;
    printf("In 10 years you will be %d years old\n",val2);

    printf("Input temperature (Celsius):\n");
    scanf("%f",&cel);
    far = 1.8f * (cel + 32);
    printf("Inputted temperature in Fahrenheits: %f\n",far);

    printf("Input speed (km/h):\n");
    scanf("%lf",&speedKMH);
    speedMS = speedKMH / 3.6;
    printf("Speed in m/s: %lf\n",speedMS);

    //ввод и вывод значений модиф.базовых типов
    short int sval = 0;
    unsigned long int bigval = 0;

    printf("Input short int:\n");
    scanf("%hd",&sval);
    printf("Inputted short int: %hd\n",sval);

    printf("Input very big int:\n");
    scanf("%lu",&bigval);
    printf("Inputted very big int: %lu\n",bigval);

    //ввод и вывод значений с использованием флагов, точности и ширины
    unsigned short int s2num = 0;
    long int plusnum = 0;
    char str2[255];
    double num = 0.0;

    printf("Input num (0..99)\n");
    scanf("%2hd",&s2num);
    printf("Inputted num: %2hd\n",s2num);

    printf("Input unsigned num. It will be output in format \"+num\"\n");
    scanf("%ld",&plusnum);
    printf("Inputted num: %+ld\n",plusnum);

    printf("Input string\n");
    fflush(stdin);
    gets(str2);
    printf("%20s\n",str2);

    printf("Input real num. It will be output in format \"nnn.nn\"\n");
    scanf("%lf",&num);
    printf("Inputted num: %5.2lf\n",num);

}
