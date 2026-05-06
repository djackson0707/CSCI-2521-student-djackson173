#include "CatsAndCougars.h"


CatsAndCougars::CatsAndCougars()
{
    reset();
}


int CatsAndCougars::getCats()
{
	return cats;
}


int CatsAndCougars::getCougars()
{
    return cougars;
}


void CatsAndCougars::count(string lword, string rword)
{
    reset(); 

    for (int i = 0; i < lword.length(); i++)
    {
        if (lword[i] == rword[i])
        {
            cats++;
        }
    }

    
    for (int i = 0; i < lword.length(); i++)
    {
        for (int j = 0; j < rword.length(); j++)
        {
            if (i != j && lword[i] == rword[j])
            {
                cougars++;
            }
        }
    }

}


void CatsAndCougars::reset()
{
    cats = 0;
    cougars = 0;
}