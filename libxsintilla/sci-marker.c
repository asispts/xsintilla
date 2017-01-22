#include "sci-marker.h"

void xsim_markerDefine(REALcontrolInstance ctl, int markerNumber, int markerSymbol)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERDEFINE, markerNumber, markerSymbol);
}
