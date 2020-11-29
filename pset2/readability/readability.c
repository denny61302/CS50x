#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Coleman-Liau index, index = 0.0588 * L - 0.296 * S - 15.8
int count_letters(string test[]);

int main(void)
{
    string test = get_string("Text: ");
    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;
    float index = 0.0;
    int grade = 0;
    
    for (int n = 0; n < strlen(test); n++)
    {
        // count letter using isalpha function
        if (isalpha(test[n]))
        {
            letterCount++;
        }
        
        // count word if there is a space
        if (test[n] == ' ')
        {
            wordCount++;
        }
        
        // count sentence if there is an '!', '?', '.'
        if (test[n] == '!' || test[n] == '?' || test[n] == '.')
        {
            sentenceCount++;
        }
    }
    
    // calculate index = 0.0588 * L - 0.296 * S - 15.8
    index = (0.0588 * (float) letterCount / (float) wordCount * 100.0 - 0.296 * (float) sentenceCount / 
             (float) wordCount * 100.0 - 15.8);
    
    if (index > 1.0)
    {
        grade = (int) round(index);
        printf("Grade %d\n", grade);
        if (grade > 16)
        {
            printf("Grade 16+\n");
        }
    }
    else
    {
        printf("Before Grade 1\n");
    }
    
    // printf("%i letter(s)\n", letterCount);
    // printf("%i word(s)\n", wordCount);
    // printf("%i Sentence(s)\n", sentenceCount);
    
}

