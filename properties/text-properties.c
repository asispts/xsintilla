#include <stdlib.h>
#include "text-properties.h"

void xsip_setReadonly(REALcontrolInstance ctl, int unused, bool readOnly)
{
    xsiControlData* data = xsi_getControlData(ctl);
    xsi_ssm(data->sci, SCI_SETREADONLY, readOnly, 0);
}

bool xsip_getReadonly(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETREADONLY, 0, 0);
}

REALstring xsip_getText(REALcontrolInstance ctl, int unused)
{
    int length = xsi_ssm(xsciObj(ctl), SCI_GETTEXTLENGTH, 0, 0);
    char* txtBuffer = malloc(length + 1);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_GETTEXT, length + 1, (sptr_t)txtBuffer);
    REALstring txt = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(txt);
    free(txtBuffer);
    return txt;
}

void xsip_setText(REALcontrolInstance ctl, int unused, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETTEXT, 0, (sptr_t)txt);
}
