//
// Created by JoachimWagner on 28.10.2024.
//

#pragma once


class State {

public :

    virtual ~State()=default;
    virtual void drucken() = 0;
    virtual void changeToA() = 0;
    virtual void changeToB() = 0;

};
