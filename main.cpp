//
// Created by linux on 1/3/23.
//

#include "include/constants.h"
#include "include/solution.h"

GlobalSettings global_settings;
SolutionManage solution_manage;

int main(int argc, char** argv) {
    global_settings.read_global_settings();
    solution_manage.test();
}