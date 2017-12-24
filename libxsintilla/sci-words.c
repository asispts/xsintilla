#include "sci-words.h"


int xsim_wordStartPosition(REALcontrolInstance ctl, int pos, bool onlyWordCharacters)
{
    return xsi_ssm(xsciObj(ctl), SCI_WORDSTARTPOSITION, pos, onlyWordCharacters);
}
