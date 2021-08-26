~~~c
//1.读取不确定数量的数据

//避免死循环，先清空缓冲区
// while(rewind(stdin), scanf("%d, &i") ! = EOF)

// ctrl+d 表示EOF
#include <stdio.h>
int main(){
    int i;
    while(scanf("%d", &i) != EOF){
        printf("%d ", i);
    }
    printf("\n......\n");
    return 0;
}

//2.读取一行字符
#include <stdio.h>
int main(){
    char ch;
    while(scanf("%c", &ch) != EOF){
        if('\n' == ch){
            printf("\n");
            break;
        }
        printf("%c ", ch);
    }
    return 0;
}

~~~

