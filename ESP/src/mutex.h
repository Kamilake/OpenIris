// mutex.h
#ifndef MUTEX_H
#define MUTEX_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern SemaphoreHandle_t xMutex;

#endif // MUTEX_H