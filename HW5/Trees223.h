/**
*Francis Troy Kirinhakone
CS223 - Summer 2017
HW5
**/

#ifndef TREES223_H
#define TREES223_H

<template>class BST
{
    public:
        BST();

        virtual ~BST();

        virtual bool Add(const T& value, std::function<int(const T& first, const T& second)> compare);

        int count() const;

        int CountLevels() const;

        int GetLevel(std::function<int(const T& existing)> compare) const;

        void InOrder(std::function<void(const T& value)> visitCallBack) const;

        virtual bool Remove(std::function<int(const T&existing>compare);


    private:

    protected:

}

#endif //TREES223_H
