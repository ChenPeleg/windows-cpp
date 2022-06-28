
#ifndef CSTATE_IMP
#define CSTATE_IMP

#include "../headers/app_state.hpp"
#include <time.h>
#include <cmath>
#include "../headers/combat_state.hpp"
#include "../headers/monster.hpp"
#include "../headers/constants.hpp"
State::State(int _initialState)
{
    this->p_level = 1;
    this->animationState = 1;

    this->maxHP = 100;
    this->HP = this->maxHP;

    this->start_time = std::time(&start_time);
    this->start_t = clock();
    this->page = 1;
    this->combat = NULL;
};
State::~State(){};
void State::initFight(content_monsters::MonsterType mnsTyp)
{
    if (mnsTyp == content_monsters::MonsterType ::none)
    {

        return;
    }
    this->combat = new combatController::CombatState((*this), content_monsters::MonsterType::blobhMonster);
}
Page &State::currentPage()
{
    return this->pageObj;
};
void State::setPage(int pageNum)
{
    if (pageNum > 0)
    {
        int _lastPage = page;
        this->page = pageNum;
        this->pageObj = Page::getPages(this->page);
        if (pageObj.isFight)
        {
            this->initFight(pageObj.pageMonster);
        }
        else
        {
            this->combat = NULL;
        }

        for (int i = 0; i < constants::MAX_NUMBER_OF_OPTIONS; i++)
        {
            if (this->pageObj.pageChangesItems[i].itemType != ItemType::NoItem)
            {
                inventory.update(this->pageObj.pageChangesItems[i].itemType, this->pageObj.pageChangesItems[i].amount);
            }
        }
        this->pageObj.updateOptionsFromInventory(inventory);
        if (!pageObj.isFight && pageNum < 10000)
        {
            this->lastStoryPage = pageNum;
        }
    }
};

void State::tik()
{
    clock_t currnetClock = clock();
    this->milisecondsPassed = ((currnetClock - start_t) * 1000) / CLOCKS_PER_SEC;

    time_t current = std::time(nullptr);
    this->secondsPassed = current - this->start_time;
    double justMiliseconds = this->milisecondsPassed;
    this->animationState = ((justMiliseconds / 10000) - std::floor(justMiliseconds / 10000)) * 10000;
    if (this->combat != NULL)
    {
        this->combat->setHighlightPosition(common::getStageClockTicks(animationState, 4, constants::COMBAT_BUTTONS_SPEED));
    }
};
double State::getTimePased()
{
    return secondsPassed;
};
long State::getMiliseconds()
{
    return milisecondsPassed;
};
int State::getSeconds()
{
    return secondsPassed;
}
void State::setMsTimer(int ms)
{
    if (ms < 5 || ms > 10000)
    {
        throw "ms duraion not right";
    }
    msTimerDuration = ms;
    msTimer = milisecondsPassed + msTimerDuration;
};
bool State::isTimerDone()
{
    if (msTimer < milisecondsPassed)
    {
        msTimer = milisecondsPassed + msTimerDuration;
        return true;
    };
    return false;
};
void State::decrementHP(int hpDelta = 1)
{
    this->HP -= hpDelta;
};
void State::combatWon()
{
    Page tempPage = Page::getPages(this->page);

    int nextPageValue = tempPage.choices[0].pageNumber;
    this->setPage(nextPageValue);
}
int State::getPage()
{
    return page;
};
#endif