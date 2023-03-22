#pragma once

void checkUserAtLogIn(userList *pHead, user *&curUser);

void startSem();

void endSem();

void anyTime();

void actionsAsStaff();

void actionsAsStudent();

void menuAfterLogin(user *&curUser);