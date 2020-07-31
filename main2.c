// https://www.programmingsimplified.com/c-program-read-file
// https://www.tutorialspoint.com/cprogramming/c_file_io.htm
// https://icecube.wisc.edu/~dglo/c_class/charfunc.html
// https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm
// https://www.geeksforgeeks.org/strings-in-c-2/
// https://www.programiz.com/c-programming/library-function/string.h/strcmp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
typedef struct Context
{
    FILE *fp;
    int iterator;
    int specificCounter;
    int start;
    int end;
} Context;

void *counterThreadFun(void *vargp)
{

    char ch;
    Context *ctx = (Context *)vargp;
    char targetWord[20] = "at";
    printf("\n ++++++++++++++++++++++++++++++++++++++++++++  CTX start:  %d  end  %d  ++++++++++++++++++++++++++++++++++++++++++++\n", ctx->start, ctx->end);
    fseek(ctx->fp, ctx->start, SEEK_SET);

    char word[20];
    int iterator = 0;
    char specificCounter = 0;
    int wordCounter = 0;
    int internal_counter = 0;
    while (internal_counter <= ctx->end)
    {
        ch = fgetc(ctx->fp);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);

        if (isspace(ch))
        {
            if (iterator != 0) // varios espacios juntos
            {
                wordCounter = wordCounter + 1;
                // printf("New Word:  %s \n", word);
                if (!strcmp(targetWord, word))
                {
                    specificCounter = specificCounter + 1;
                }
                iterator = 0;
                memset(word, 0, sizeof word);
            }
        }
        else
        {
            // printf("%c", ch);
            word[iterator] = ch;
            iterator = iterator + 1;
        }
        internal_counter = internal_counter + 1;
    }
    printf("\n Words: %d, occurrences of [ %s ] specific: %d\n", wordCounter, targetWord, specificCounter);

    return NULL;
}

int main()
{
    clock_t start = clock();
    char targetWord[20] = "at";
    char ch;
    FILE *fp;
    char word[20];
    int iterator = 0;
    int wordCounter = 0;

    char specificCounter = 0;

    fp = fopen("test2.txt", "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    long long sz = ftell(fp);
    printf("Size: %lld \n", sz);
    fseek(fp, 0L, SEEK_SET);

    int num_of_threads = 3;
    int ratio = sz / num_of_threads;
    printf("ratio for every thread: %d\n", ratio);

    int start_offset = 0;
    int end_offset = 374;
    pthread_t thread_one;
    Context *ctx_one = malloc(sizeof(struct Context));
    ctx_one->fp = fp;
    ctx_one->iterator = 0;
    ctx_one->specificCounter = 0;
    ctx_one->start = start_offset;
    ctx_one->end = end_offset;
    pthread_create(&thread_one, NULL, counterThreadFun, (void *)ctx_one);
    pthread_join(thread_one, NULL);

    start_offset = 375;
    end_offset = 812;
    pthread_t thread_two;
    Context *ctx_two = malloc(sizeof(struct Context));
    ctx_two->fp = fp;
    ctx_two->iterator = 0;
    ctx_two->specificCounter = 0;
    ctx_two->start = start_offset;
    ctx_two->end = end_offset;
    pthread_create(&thread_two, NULL, counterThreadFun, (void *)ctx_two);
    pthread_join(thread_two, NULL);

    start_offset = 813;
    end_offset = 1303;
    pthread_t thread_three;
    Context *ctx_three = malloc(sizeof(struct Context));
    ctx_three->fp = fp;
    ctx_three->iterator = 0;
    ctx_three->specificCounter = 0;
    ctx_three->start = start_offset;
    ctx_three->end = end_offset;
    pthread_create(&thread_three, NULL, counterThreadFun, (void *)ctx_three);
    pthread_join(thread_three, NULL);

    start_offset = 1304;
    end_offset = 1765;
    pthread_t thread_four;
    Context *ctx_four = malloc(sizeof(struct Context));
    ctx_four->fp = fp;
    ctx_four->iterator = 0;
    ctx_four->specificCounter = 0;
    ctx_four->start = start_offset;
    ctx_four->end = end_offset;
    pthread_create(&thread_four, NULL, counterThreadFun, (void *)ctx_four);
    pthread_join(thread_four, NULL);

    start_offset = 1766;
    end_offset = 2265;
    pthread_t thread_five;
    Context *ctx_five = malloc(sizeof(struct Context));
    ctx_five->fp = fp;
    ctx_five->iterator = 0;
    ctx_five->specificCounter = 0;
    ctx_five->start = start_offset;
    ctx_five->end = end_offset;
    pthread_create(&thread_five, NULL, counterThreadFun, (void *)ctx_five);
    pthread_join(thread_five, NULL);

    fclose(fp);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\n Time  %f \n", seconds);
    return 0;
}