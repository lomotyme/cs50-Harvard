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
  for (int i = 0; Text[i] != '\0'; i++)
  {
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
    if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
    {
      sentences++;
    }
  }
  return sentences;
}

float CL_index(void)
{
  float L = (float) letters/words * 100;
  float S = (float) sentences/words * 100;
  index = 0.0588 * L - 0.296 * S - 15.8;
  return index;
}