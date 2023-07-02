#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    StyleHelper();

    static QString getStartButtonsStyle();
    static QString getChooseButtonsStyle();
    static QString getActiveChooseButtonsStyle();
    static QString getGameButtonsStyle();
    static QString getActiveGameButtonsStyle();
};

#endif // STYLEHELPER_H
