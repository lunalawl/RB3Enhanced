/*
    RB3Enhanced - SetlistHooks.h
    Hooks for modifying the setlist/song selection screen.
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "ports.h"
#include "rb3/BandLabel.h"
#include "rb3/UI/UIPanel.h"
#include "rb3/SortNode.h"

static char *originToIcon[][2] = {
    {"lego", "<alt>A</alt> "},
    {"rb3", "<alt>B</alt> "},
    {"blitz", "<alt>X</alt> "},
    {"rb1", "<alt>Y</alt> "},
    {"rb4_rivals", "<alt>g</alt> "},
    {"rbvr", "<alt>r</alt> "},
    {"beatles", "<alt>b</alt> "},
    {"greenday", "<alt>o</alt> "},
    {"gh", "<alt>R</alt> "},
    {"ghdlc", "<alt>R</alt> "},
    {"rb4dlc", "<alt>S</alt> "},
    {"rb4_dlc", "<alt>S</alt> "},
    {"rb3dlc", "<alt>s</alt> "},
    {"ugc1", "<alt>F</alt> "},
    {"fnfestival", "<alt>G</alt> "},
    {"dlc", "<alt>0</alt> "},
    {"rb1_dlc", "<alt>0</alt> "},
    {"ugc2", "<alt>U</alt> "},
    {"ugc_lost", "<alt>U</alt> "},
    {"rb4", "<alt>1</alt> "},
    {"rb2", "<alt>2</alt> "},
    {"rbtp_acdc", "<alt>O</alt> "},
};
static int numOriginToIcon = sizeof(originToIcon) / sizeof(originToIcon[0]);

void SetSongAndArtistNameHook(BandLabel *label, SortNode *sortNode)
{
    char newLabel[1024] = {0};
    char *originLabel = "<alt>y</alt> "; // default
    int i = 0;

    if (config.GameOriginIcons == 1 && strlen(label->string) < 1000)
    {
        SetSongAndArtistName(label, sortNode);
        for (i = 0; i < numOriginToIcon; i++)
        {
            if (strcmp(sortNode->somethingElse->metaData->gameOrigin, originToIcon[i][0]) == 0)
            {
                originLabel = originToIcon[i][1];
                break;
            }
        }
        strcat(newLabel, originLabel);
        strcat(newLabel, label->string);
        BandLabelSetDisplayText(label, newLabel, 1);
        return;
    }
    SetSongAndArtistName(label, sortNode);
    return;
}

void SetSongNameFromNodeHook(BandLabel *label, SortNode *sortNode)
{
    char newLabel[1024] = {0};
    char *originLabel = "<alt>y</alt> "; // default
    int i = 0;

    RB3E_DEBUG("SetSongNameFromNode: %s", label->string);

    if (config.GameOriginIcons == 1 && strlen(label->string) < 1000)
    {
        SetSongNameFromNode(label, sortNode);
        for (i = 0; i < numOriginToIcon; i++)
        {
            if (strcmp(sortNode->somethingElse->metaData->gameOrigin, originToIcon[i][0]) == 0)
            {
                originLabel = originToIcon[i][1];
                break;
            }
        }
        strcat(newLabel, originLabel);
        strcat(newLabel, label->string);
        BandLabelSetDisplayText(label, newLabel, 1);
        return;
    }
    SetSongNameFromNode(label, sortNode);
    return;
}