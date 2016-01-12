/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string.h> 
#include <stdio.h>
#include <cs50.h>
#include "dictionary.h"
#include <ctype.h>

typedef struct node
{
    char* n;
    struct node* next;
    struct node* previous;
}
node;

//global variables
int wordcount = 0;
node* fletter[26];

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

bool load(const char* dictionary)
{
    //define the array of pointers for each letter of the alphabet and initialize.
    //define an array of head pointers for each letter of the alphabet initialize to NULL
     
     node* head[26];
     char* buffer= malloc((LENGTH+1)*sizeof(char));
     
     
     for (int j=0;j<26;j++)
     {
         head[j]=NULL;
         fletter[j]=NULL;
     } 
     
    
    //Open dictionary and check NULL
    
    FILE* inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload(); 
        return 1;
    }
    
    //Start reading dictionary into BUFFER
    
    int i = 0;
    
    
    for (char c = fgetc(inptr); c != EOF; c = fgetc(inptr))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && i > 0))
        {
            // append character to word
            buffer[i] = c;               
            node* next=NULL; 
             int first;
             
         
         if (i==0)
         {   
             node* newword=malloc(sizeof(node));
             if (isupper(buffer[0]))
             {
                first = buffer[0]-'A';
             }
            
             else
             {
                first= buffer[0]-'a';
             }
                
             newword->n= buffer;
             fletter[first]=newword;
             newword -> next = head[first];
             head[first]=newword; 
             if (newword->next==NULL)
             {
                 newword->previous=NULL;
             }
             else
             {
                 next = head[first]->next;
                 next->previous=head[first];
             } 
             wordcount++;                 
        }
    }        
    else if (!isalpha(c))  
    {   
                    
         if (i!=0)
         {   
             buffer[i]='\0';             
             buffer= malloc((LENGTH+1)*sizeof(char));
             i=0;
         }
         continue;
    }
    i++;
}     

fclose(inptr);
                    //if the first letter of Buffer is 'a' than 
 free(buffer);                //pointer array[0] points to what head was pointing to (NULL). Head[0] then points to array[0] 'a'..
 return true;                                        
}            
    //create an array of nodes with the first letter of the alphabet
    
unsigned int size(void)
{
    return (wordcount);       
}




/**
 * Returns true if word is in dictionary else false.
 */
 
bool check(const char* word)
{            
     int fletterc;
     
     if (isupper(word[0]))
     {
         fletterc = (word[0]-'A'); 
     }
     else
     {
         fletterc=(word[0]-'a');
     }
  
                 
     node* spell= NULL;
      
     for (spell = fletter[fletterc]; spell!= NULL; spell=spell->next)
     {
        for (int j=0; spell->n[j]!='\0'; j++) 
        { 
          char letterx = spell->n[j]; 
          char lettery = word[j];
          if (strlen(spell->n)!=strlen(word))
          {
              break;
          }
          if (letterx != lettery && letterx +('a'-'A')!= lettery && letterx-('a'-'A') != lettery)
          {
              break; 
          }
          else if (word[j+1]=='\0')
          {
              return true;
          }
          
      }
   }
       
   return false;     
}  
         //check to see if the two strings are the same strcmp() 
        //if they are return true
     
    
    
     
        
        
        //if they are not follow the link to next compare
        
        //If you hit NULL than the word is not in the dictionary
        //return false

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
 for (int i=0;i<26;i++)
    // go through dictionary until you hit NULL
    { 
       node* deletera= fletter[i];
       while (deletera->next!=NULL)
       {
           deletera=deletera->next;
       }
         
    //go to previous     
       while (deletera!=fletter[i])
       {
       node* deleterb=deletera;
       deletera=deletera->previous;
       char* word=deleterb->n;
       free(word);
       free (deleterb);
       }
       char* worda = deletera->n;
       free(deletera);
       free(worda);
       
   } 
      
    //delete    
    return true;
}   
  
    
