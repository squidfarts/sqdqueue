/***********************************************************************************
 *                                                                                 *
 * NAME: queue.h                                                                   *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * This file contains function prototypes for this project.  It is where all       *
 * queue of prototype functions are defined.                                       *
 *                                                                                 *
 * NOTICES:                                                                        *
 *                                                                                 *
 * MIT License                                                                     *
 *                                                                                 *
 * Copyright (c) 2019 Micheal Brockus                                              *
 *                                                                                 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy    *
 * of this software and associated documentation files (the "Software"), to deal   *
 * in the Software without restriction, including without limitation the rights    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is           *
 * furnished to do so, subject to the following conditions:                        *
 *                                                                                 *
 * The above copyright notice and this permission notice shall be included in all  *
 * copies or substantial portions of the Software.                                 *
 *                                                                                 *
 * DISCLAIMERS:                                                                    *
 *                                                                                 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 * SOFTWARE.                                                                       *
 *                                                                                 *
 ***********************************************************************************/
#ifndef SQUID_QUEUE_H
#define SQUID_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
typedef struct SqdQueueNodeOf_s
{
    void * _data;
    struct SqdQueueNodeOf_s * _nextPtr;
}
SqdQueueNodeOf;

// Structure of a List
typedef struct SqdQueueOf_s
{
    struct SqdQueueNodeOf_s * _rearPtr;
    struct SqdQueueNodeOf_s * _frontPtr;
}
SqdQueueOf;


SqdQueueOf * createQueue(void);
void enQueue(SqdQueueOf * queue, void * data);
SqdQueueNodeOf * deQueue(SqdQueueOf * queue);
void destroyQueue(SqdQueueOf * queue);

#endif /* SQUID_HEADER_H */
