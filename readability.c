//Implement a program that computes the approximate grade level needed to comprehend some text, using the Coleman-Liau index.


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(void);
int count_words(void);
int count_sentences(void);
float CL_index(void);

int letters, words, sentences;
float index;
string Text;

int main(void)
{
  Text = get_string("Input a text: ");

  count_letters();
  count_words();
  count_sentences();
  CL_index();

  // if the rounded index is less than 1,  then the readability level is less than grade 1
  if (round(index) < 0)
  {
    printf("Before Grade 1\n");
  }
  else if (round(index) >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", (int) round(index));
  }
}


int count_letters(void)
{
  letters = 0;
  //after initializing letters to 0, the for loop parses through the string till ends with the null..
  for (int i = 0; Text[i] != '\0'; i++)
  {
    // the if condition checks if the resulting characters within Text are alphabets, if so, increment letter count.
    if (isalpha(Text[i]) != 0)
    {
      letters++;
    }
  }
  return letters;
}

int count_words(void)
{
  words = 1;
  for (int i = 0; Text[i] != '\0'; i++)
  {
    //the if condition checks if the resulting characters within Text are white spaces,
    //if so, increment word count, since words come before and after the said spaces.
    if (Text[i] == ' ')
    {
      words++;
    }
  }
  return words;
}

int count_sentences(void)
{
  sentences = 0;
  for (int i = 0; Text[i] != '\0'; i++)
  {
    //the if condition checks if the resulting characters within Text are ended by the characters below, if so, increment sentence count.
    if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
    {
      sentences++;
    }
  }
  return sentences;
}

// this is the index function used to calculate the readability level of a text in Grades.
float CL_index(void)
{
  float L = (float) letters/words * 100;
  float S = (float) sentences/words * 100;
  index = 0.0588 * L - 0.296 * S - 15.8;
  return index;
}