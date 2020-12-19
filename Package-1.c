#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{

    //word is the answer,w-len is the length of the word,
    //guess_char is the letter to be guessed in each trial
    // choice is the option for clues

    char word[20],w_len,guess_char,choice;
    printf("\nEnter the word to guess:\n");
    scanf("%s",word);
    w_len=strlen(word);
    float score,hscore;

    //to convert all the letters into small ones if the user has entered any caps
    for(int i=0;i<w_len;i++)
    {
        word[i]=tolower(word[i]);
    }

    //status is the main variable which ends the game if value is 1.
    int w_array[w_len],status=0,attempt=0,clue=0;

    //to hide the answer
    system("cls");

    //initially all words are hidden.
    for(int i=0;i<w_len;i++)
    {
        w_array[i]=0;
    }

    //this runs till the player guesses all words correctly
    while(!status)
    {

        printf("The word to be guessed is:");

        for(int i=0;i<w_len;i++)
        {
            if(w_array[i]!=0)
            {
                printf("%c",word[i]);
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");


        printf("Guess a character:");

        //getting the guess from player
        scanf("%*c%c",&guess_char);
        attempt++;

        //seeding randomly
        srand(time(0));

        //player can have a clue at attempt 4,8,12.
        if((attempt==4) ||(attempt==8)||(attempt==10))
        {


            L:printf("\nDo you want a clue (type y or n):");
            scanf("%*c%c",&choice);
            if(choice=='y'||choice=='Y')
            {
                clue++;

                printf("\nClue is given.\n");


                //clu is the array which holds the undiscoverd letters
                int clu[20],k=0;

                for(int i=0;i<w_len;i++)
                {
                    if(w_array[i]==0)
                    {
                        clu[k]=i;
                        k++;
                    }
                }

                if(k==1)
                {
                       w_array[clu[0]]=1;
                }

                else
                {
                        int t=rand()%k;
                        w_array[clu[t]]=1;
                }


            }
            else if(choice=='n'||choice=='N')
            {
                printf("\nClue is not given.\n");
            }
            else
            {
                printf("\nInvalid Choice,Please Try again\n");
                goto L;
            }
        }
        //if guess is correct then unmasking the numbers
        for(int i=0;i<w_len;i++)
        {
            if(word[i]==guess_char)
            {
                w_array[i]=1;
            }
        }
        status=1;
        for(int i=0;i<w_len;i++)
        {
            if(!w_array[i])
            {
                status=0;
                break;
            }
        }

    }


    printf("\t\t");
    for(int i=0;i<38;i++)
    {
        printf("*");
    }


    score=(((float)w_len/attempt)*100-(clue*5));
    printf("\n\n");
    printf("\t\tNumber of attempts taken = %d\n",attempt);
    printf("\t\tClues availed = %d\n",clue);
    printf("\t\tScore = %.2f\n",score);
    printf("\t\tThe word is \"%s\".\n", word);
    printf("\n\n");

    FILE *f;
    L1:f=fopen("D://hello.txt","r");

    if(f==NULL)
    {
        fclose(f);
        f=fopen("D://hello.txt","w");
        fclose(f);
        goto L1;
    }

    else
    {
        hscore=getw(f);
        if(score>hscore)
        {
            printf("\t\tThis is a new high score!\n");
            printf("\t\tThe high score was %.2f\n",hscore);
            fclose(f);
            f=fopen("D://hello.txt","w");
            putw(score,f);
            fclose(f);
        }
        else
        {
            printf("\t\tHighest score is %.2f\n\n",hscore);
        }
    }

    printf("\t\t");

    for(int i=0;i<38;i++)
    {
        printf("*");
    }

    char opt;
    printf("\nDo You want to play again (if yes enter y) :");
    scanf(" %c",&opt);

    if(opt=='y'||opt=='Y')
    {
        main();
    }

    else
    {
        printf("\n\t\tTHANK YOU FOR PLAYING,COME AGAIN TO PLAY SOMETIME\n\n");
    }

}
