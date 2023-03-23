#pragma once
#include<iostream>
#include<cstring>
using namespace std;

struct player {
	char name[30];
	int point, life;
};

struct position {
	int x, y;
};

struct Box1 {
    int i, j;
    char c;
    bool isValid, isSelected;

    Box1() : c(' '), isValid(true), isSelected(false) {}
    void drawBox();
    void deleteBox();
};

struct Box2 {
	int i, j;
	char c;
	bool isSelected;
	Box2* next;

	Box2() : c(' '), isSelected(false) {}
	void drawBox();
	void deleteBox();
};