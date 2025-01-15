#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fstream>

#define SIZE 100000

#define hashsize(n) ((unsigned long)1 << n)
#define hashmask(n) (hashsize(n) -1)

const char* sampleInputFileName = "SnowflakeSample_0000.txt";

//We need a hash function
unsigned long oaat(char* key, unsigned long len, unsigned long bits)
{
    
    unsigned long hash, i;
    //we want to iterate through our key/dnowflake data to determine generate our hashcode
    for( hash = 0, i = 0; i < len; i++)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash & hashmask(bits);
}
//We need to create a linked list to create a chaining scheme
typedef struct snowflake_n
{
    //in a linked list we need a pointer to the next node and data to be stored in this node
    int data[6];
    snowflake_n* next = NULL;
} snowflake_n;



int main()
{
    std::ifstream fin;
    fin.open(sampleInputFileName, std::ifstream::in);
    //read our first line to etermine how many snowflakes we will need
    static snowflake_n* snowflakes[SIZE] = {NULL}; //initializes our array of nodes to NULL
    snowflake_n* snow;
    printf("Starting Program\n");
    int N, i, j;
    unsigned long snowflakeCode;
    fin >> N;
    printf("%d\n", N);
    for (i = 0; i < N; i++)
    {
        //printf("Snowflake %d\n", i);
        snow = (snowflake_n*)malloc(sizeof(snowflake_n)); // casting here removes some of the warnings
        printf("Snow variable created\n");
        for(j =0; j < 6; j++)
        {
            printf("Writting to snow->data\n");
            fin >> snow->data[j];
            printf("%d | %d\n", j, snow->data[j]);
        }
        snowflakeCode = oaat((char*)snow, SIZE, 17);
        snow->next = snowflakes[snowflakeCode];
        snowflakes[snowflakeCode] = snow;
        printf("%d | %lu\n", i, snowflakeCode);
    }
    fin.close(); //make sure to close the file for completeness
    
    return 0;
}