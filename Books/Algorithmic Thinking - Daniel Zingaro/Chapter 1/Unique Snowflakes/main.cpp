#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000 //Used in node creation

//These macros are uesed to simplify our oaat function
#define hashsize(n) ((unsigned long)1 << n)
#define hashmask(n) (hashsize(n) -1)

/// @brief This is our hash function that we will use to store similar snowflakes into the same bucke
///         This essntially puts our snowflake through a blender and returns a hashcode (hash & hashmask(bits));
/// @param key the data we want to hash
/// @param len the length of of those data
/// @param bits number of bits we want in the resulting hashcode
/// @return the hashcode that will return our data
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

//Example of using ooat
// unsigned long code = oaat((char*)snowflake, sizeof(snowflake), 17);

/// @brief Our snowflake node for our linked list
typedef struct snowflake_n
{
    long data[6];
    snowflake_n* next = NULL;
}snowflake_n;

/// @brief Scans the nodes from right to left to determine if they are identical
/// @param node1 first node for comparsion (Data of the node technically)
/// @param node2 second node for comparison (Data of the node technically)
/// @param start the initial index at which we will start for node 1
/// @return 1 if identical pair is found 0 if not
int identicalLeft(long* node1, long* node2, int start)
{
    int offset, index;
    for (offset = 0; offset < 6; offset++)
    {
        index = start - offset;
        if(index <0)
            index += 6;
        if(node2[offset] != node2[index])
            return 0;
    }
    return 1;
} 

/// @brief Scans the nodes from left to right to determine if the are identical
/// @param node1 first node for comparison (Data of the node technically)
/// @param node2 second node for comparsion (Data of the node technically)
/// @param start ths intial index at which we will start for node 1
/// @return 1 if identical pair found 0 if not
int identicalRight(long* node1, long* node2, int start)
{
    int offset;
    for (offset = 0; offset < 6; offset++)
    {
        if(node1[offset] != node2[(offset + start)%6]);
            return 0;
    }
    return 1;
}

/// @brief Checks nodes to see i they are identical
/// @param node1 
/// @param node2 
/// @return 1 if identical pair found 0 if not
int areIdentical(long *node1, long* node2)
{
    int start;
    for (start = 0; start < 6; start++)
        if(identicalLeft(node1, node2, start))
            return 1;
    for (start = 0; start < 6; start++)
        if(identicalRight(node1, node2, start))
            return 1;
    return 0;
}

/// @brief Checks an array of snowflake nodes to determine if any 2+ are identical
/// @param snowflakes the array of snowflake nodes to be iterated through
void identifyIdentical(snowflake_n **snowflakes)
{
    snowflake_n *node1, *node2;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        node1 = snowflakes[i];
        while(node1 != NULL)
        {
            node2 = node1->next;
            while(node2 != NULL)
            {
                if(areIdentical(node1->data, node2->data))
                {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
}

int main()
{
    long N, i, j;
    unsigned long snowflakeCode;

    static snowflake_n* snowflakes[SIZE] = {NULL};
    snowflake_n* snow;
    //Get how many snowlakes we will take in
    scanf("%i", N);
    //Read all the data for our snowflakes into our linked list
    for (i = 0; i < N; i++)
    {
        snow = (snowflake_n*)malloc(sizeof(snowflake_n));
        for(j=0;j<6;j++)
            scanf("%i", snow->data[j]);
        snowflakeCode = oaat((char*)snow, sizeof(snowflake_n), 17);
        snow->next = snowflakes[snowflakeCode];
        snowflakes[snowflakeCode] = snow;
    }
    //Look for identical snowflakes

    return 0;
}