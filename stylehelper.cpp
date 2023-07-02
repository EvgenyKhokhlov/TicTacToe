#include "stylehelper.h"

StyleHelper::StyleHelper()
{

}

QString StyleHelper::getStartButtonsStyle()
{
    return "QPushButton{"
            "color:rgb(255, 255, 255);"
            "font-size:25px;"
            "border-image: url(:/new/prefix1/button_01_unpressed.png);"
            "}"
            "QPushButton::pressed{"
            "border-image: url(:/new/prefix1/button_01_pressed.png);"
            "}";
}

QString StyleHelper::getChooseButtonsStyle()
{
    return "QPushButton{"
            "color:rgb(255, 255, 255);"
            "font-size:20px;"
            "border-image: url(:/new/prefix1/button_02_unpressed_orange.png);"
            "}";
}

QString StyleHelper::getActiveChooseButtonsStyle()
{
    return "QPushButton{"
            "color:rgb(255, 255, 255);"
            "font-size:20px;"
            "border-image: url(:/new/prefix1/button_02_pressed_orange.png);"
            "}";
}

QString StyleHelper::getGameButtonsStyle()
{
    return "QPushButton{"
            "color:rgb(255, 255, 255);"
            "font-size:100px;"
            "border-image: url(:/new/prefix1/button_03_unpressed_pink.png);"
            "}"
            "QPushButton::hover{"
            "border-image: url(:/new/prefix1/button_03_pressed_pink.png);"
            "}";
}

QString StyleHelper::getActiveGameButtonsStyle()
{
    return "QPushButton{"
            "color:rgb(255, 255, 255);"
            "font-size:100px;"
            "border-image: url(:/new/prefix1/button_03_unpressed_pink.png);"
            "}";
}
