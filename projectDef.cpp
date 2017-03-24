// Programmers: David Bippes                              Date: November 2, 2015
//            : Jeremy Schneiderjohn
// File: encryptor.cpp
// Purpose: This file contains the function definitions for the encryptor
//          program

#include "projectHead.h"
using namespace std;

// List of prototypes

void fileInput()
{
  ifstream fin;
  char fileName[25];
  ofstream fout;
  string currentWord;
  int length = 0;
  int connectCounter = 0;
  bool isSelect = false;
  bool inFrom = false;

  // list of attributes
  vector attribute;
  vector tableAbbreviation;
  vector table;

  do
  {
    // connecting to the file
    /*
    fin.clear();
    cout << "Enter the name of the file to connect to:   ";
    cin.ignore(500, '\n');
    cin.getline(fileName, 19);
    */
    strcpy(fileName, "input.dat");
    fin.open(fileName);
    connectCounter++;
  } while (!fin && connectCounter <= 10);

  /*do
  {
    fout.clear();
    fout.open("homerfried.dat");
  } while (!fout);*/

  inSelect = false;
  inFrom = false;

  // fin >> currentWord;
  getline(fin, currentWord, ' ');

  while (!fin.eof())
  {
    length = currentWord.length();

cout << currentWord << " " << length << endl;

    if (currentWord == "AS")
    {

    }

    if (currentWord == "FROM")
    {
      inSelect = false;
      inFrom = true;
    }

    if (inFrom)
    {
      getline(fin, currentWord, ' ');

      table.push_back(currentWord);
    }

    if (inSelect)
    {
      getline(fin, currentWord, ' ');

      if (currentWord.find('.') > 0)
      {
        int dotIndex = currentWord.find('.');

        string attributeName = currentWord.substr(dotIndex, npos);

        attribute.push_back(attributeName);
      }

      else
        attribute.push_back(currentWord);
    }

    if (currentWord == "SELECT")
    {
      inSelect = true;
    }

    cout << currentWord << endl;

    fin >> currentWord;
  }


  fin.close();
  fout.close();

  return;
}