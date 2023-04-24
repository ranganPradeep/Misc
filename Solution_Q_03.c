// # Q3 [C] Find the n most frequent words in the TensorFlow Shakespeare dataset.
// # char **find_frequent_words(const char *path, int32_t n) {
// # // implementation
// # }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   100000



int main()
{
    FILE *fptr;
    char path[100];
    int i, len, index, isUnique;

    // List of distinct words
    char words[MAX_WORDS][50];
    char word[50];

    // Count of distinct words
    int  count[MAX_WORDS];
    int n, j, temp;
    char temp1[50];
    int K;

    /* open file */
    fptr = fopen("shakespeare.txt", "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }

    // Initialize words count to 0
    for (i=0; i<MAX_WORDS; i++)
        count[i] = 0;




    index = 0;
    
    while (fscanf(fptr, "%s", word) != EOF)
    {
        // Convert word to lowercase
        tolower(word);

        // Remove last punctuation character
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';


        // Check if word exits in list of all distinct words
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        // If word is unique then add it to distinct words list
        // and increment index. Otherwise increment occurrence 
        // count of current word.
        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    // Close file
    fclose(fptr);


    /*
     * Print occurrences of all words in file. 
     */
    printf("\nOccurrences of all distinct words in file: \n");
    for (i=0; i<index; i++)
    {
        /*
         * %-15s prints string in 15 character width.
         * - is used to print string left align inside
         * 15 character width space.
         */
        if (count[i]>=200)
        {
            printf("%-15s => %d\n", words[i], count[i]);
        }
    }
    
    
    /*  sorting begins ... */
    n = sizeof(count)/sizeof(count[0]);
    for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j) 
        {
            if (count[i] < count[j]) 
            {
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                
                strcpy(temp1,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],temp1);
                
//                 temp1 = words[i];
//                 words[i] = words[j];
//                 words[j] = temp1;

            }
        }
    }

//     printf("The numbers arranged in descending order are given below\n");
    printf("Enter the top K value for which the histogram needs to be printed\n");
    scanf("%d",&K);

    for (i = 0; i < K; i++) 
    {
        printf("%-15s => %d\n", words[i], count[i]);

    }
    return 0;
}