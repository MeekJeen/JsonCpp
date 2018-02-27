#ifndef _OPERATE_FILE_H
#define _OPERATE_FILE_H

#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include "json.h"

using namespace std;
using namespace Json;

#define MAX_SIZE 7
void parseFile(string &path, Value &root, struct Person info);
void writeJson(string &path, struct Person info);
void readJson(string &path, Value &root);

struct Person{
  string name;
  float ID[MAX_SIZE];
  int age;
};

extern struct Person pinfo;

#endif
