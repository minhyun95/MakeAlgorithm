#pragma once

#ifndef __DEFAULT_H__
#define __DEFAULT_H__

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#include <iostream>
#include <time.h>
using namespace std;

#endif