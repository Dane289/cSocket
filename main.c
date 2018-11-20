/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: stn
 *
 * Created on November 20, 2018, 10:13 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    showMenuContent();
    return (EXIT_SUCCESS);
}

void showMenuContent() {
    printf("1. Connect to socket\n");
    printf("2. Disconnect\n");
    printf("3. GET\n");
    printf("4. Exit");
}

