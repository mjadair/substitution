//import functions
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//a global function to check for unique characters
bool uniqueCharacters(string str)
{

  for (int i = 0; i < strlen(str) - 1; i++)
  {
    for (int j = i + 1; j < strlen(str); j++)
    {
      if (str[i] == str[j])
      {
        return false;
      }
    }
  }

  return true;
}

int main(int argc, string argv[])

{

  if (argc != 2)

  {

    return 1;
  }

  //defines the alphabet as an array of
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char userKey[26];
  int substitutor[26];

  //sets userinput as a variable
  // string argv[1] = get_string("Key: ");

  //checks and prints the length of the key input by the user
  int inputLength = strlen(argv[1]);
  //  printf("Inputlength: %i \n", inputLength);

  //ends program if string is more or less than 16 characters
  if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)

  {

    // printf("Invalid key length \n");

    return 1;
  }

  for (int i = 0; i < 26; i++)

  {
    //checks if key input is a letter and a capital
    if (isalpha(argv[1][i]) != 0 && argv[1][i] <= 90)
    {
      //saves the key in lower case
      userKey[i] = (argv[1][i] + 32);
    }
    //checks if key is a letter
    else if (isalpha(argv[1][i]) != 0)
    {
      //saves the key
      userKey[i] = argv[1][i];
    }

    //otherwise ends the program
    else

    {

      // printf("Invalid character \n");

      return 1;
    }
  }

  //runs the unique character function and ends the program if there are duplicates
  if (uniqueCharacters(argv[1]) != true)

  {

    // printf("Duplicate characters not allowed \n");

    return 1;
  }

  for (int i = 0; i < 26; i++)
  {

    substitutor[i] = (userKey[i] - alphabet[i]);
  }

  string userSentence = get_string("plaintext: ");

  char newUserSentence[50] = "\0";

  for (int x = 0; x < strlen(userSentence); x++)

  {

    if (isalpha(userSentence[x]) != 0)

    {

      for (int i = 0; i < 26; i++)

      {

        if (userSentence[x] == alphabet[i])

        {

          newUserSentence[x] = ((alphabet[i] + substitutor[i]));
        }

        else if (userSentence[x] == (alphabet[i] - 32))

        {

          newUserSentence[x] = ((((alphabet[i]) + (substitutor[i])) - 32));
        }
      }
    }

    else

    {

      newUserSentence[x] = userSentence[x];
    }
  }

  printf("ciphertext: %s\n", newUserSentence);

  return 0
}
