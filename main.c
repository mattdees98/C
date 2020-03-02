//
//  main.c
//  Hangman
//
//  Created by Matt Dees on 2/28/20.
//  Copyright © 2020 Matt Dees. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int getWord(char a[])
{
    printf("Enter a word between 5 and 10 characters:\n");
    scanf("%s", a);
    int length = strlen(a);
    return length;
}

int main(int argc, const char * argv[]) {
    
// variable declaration
    char word[9];
    char guess;
    int length = 0, strikes = 0, flag = 0;
    
// have user input word and read input
//getWord(word);
    
    while (length < 5 || length > 10)
    {
        printf("Enter a word between 5 and 10 characters:\n");
        scanf("%s", word);
        length = strlen(word);
        
            if (length < 5 || length > 10)
                printf("Invalid word.\n");
            else
                continue;
            
    }
    
// get length of word
    length = strlen(word);
    char hiddenWord[length - 1];
    
// fill the hidden word array with underscores
    for (int x = 0; x < length; x++)
    {
        hiddenWord[x] = '_';
    }
    
//play hangman until the player has 3 incorrect guesses
        while (strikes != 3)
        {
            if (strikes == 3)
            {
                printf("Sorry, you lose!\n");
                break;
            }
            
            printf("%s\n\n", hiddenWord);
            printf("Enter your guess: \n");
            scanf(" %c", &guess);
            
            
            //loop through the word and find if values match
            for (int x = 0; x < length; x++ )
            {
                if (word[x] == guess)
                {
                    hiddenWord[x] = guess;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 1)
            {
                printf("Your guess was correct!\n");
                continue;
            }
            else
            {
                strikes++;
                printf("Your guess is incorrect. You have %d strike(s).\n", strikes);
                
                if (strikes == 3)
                {
                    printf("Sorry, you lose!\n");
                    break;
                }
                continue;
            }
            
            
        }

    
    return 0;
}
