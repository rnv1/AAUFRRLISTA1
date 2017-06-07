/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Divide and conquest.c
 * Author: rodri
 *
 * Created on 06 June 2017, 17:06
 */

/* structure is used to return two values from minMax() */
#include<stdio.h>
#include<stdlib.h>

int maxsimum(int a[], int l, int r) {
    if (l == r){  
        return a[l];
    }
    else{
    int m = (l+r)/2;
    int u = maxsimum(a,l,m);
    int v = maxsimum(a,m+1,r);
    if(u>v){
        return u;
    }   
    else{
        return v;
    }
    } 
}

int minimum(int a[], int l, int r) {
    if (l == r){  
        return a[l];
    }
    else{
    int m = (l+r)/2;
    int u = maxsimum(a,l,m);
    int v = maxsimum(a,m+1,r);
    if(u<v){
        return u;
    }   
    else{
        return v;
    }
    } 
}

int main() {
    int a[] = {34,23,45,56,30,31,57,33,55,10};
    int n = sizeof(a)/sizeof(int);
    printf("Esse é o máximo: %d\n", maxsimum(a,0,n));
    
    printf("Esse é o mínimo: %d", minimum(a,0,n));
    return 0;
}