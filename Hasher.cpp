#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int sizeForArray=23;

class hashSlinger
{
public:
    hashSlinger() : cont(sizeForArray)
    {
        for(h=0;h<sizeForArray;h++)
               cont[h]="0";

    }


    void show()
        {
            for (h=0;h<sizeForArray;h++)
                {if (cont[h]=="0")
                    cout<<"Position "<<h<<" is still empty."<<endl;
                 else
                    cout<<"In position "<<h<<" the word "<< cont[h]<<" was placed"<<endl;
                }
        }
    void hashBrowns( string homeFries, char head, char tail )
        {
            has_loc=(tail+head)%23;
            if (cont[has_loc]=="0")
                {cont[has_loc]=homeFries;}

            else if (!(cont[has_loc]=="0"))
            { inc=1;
             while (inc==1)
             {if (has_loc>=(sizeForArray-1))
                 {has_loc=0;}
                 else
                 {has_loc++;}
                 if(cont[has_loc]=="0")
                    {inc=0;
                     cont[has_loc]=homeFries;
                    }
             }
            }
        }
protected:
    int h, compare, has_loc, inc;
    vector <string> cont;
    char head , tail;
    string homeFries;
    };
int main(void)
{
 hashSlinger potato;
 int length_word,j=0;
 char heads, tails;
 string user_word;

 cout<<"Please input 15 words that you want to be hashed:"<<endl;
 for(j=0;j<15;j++)
   {
    cin>>user_word;
    length_word=user_word.length();
    heads=user_word[0];
    tails=user_word[length_word-1];
    potato.hashBrowns(user_word,heads,tails);
    }
   potato.show();

 return(0);
}
