/***********************************************************************************
 *                                                                                 *
 * NAME: queue.c                                                                   *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * This file contains function prototypes for this project.  It is where all       *
 * required functions are defined for later use.                                   *
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
#include "queue.h"

/*
 * A utility function to create a new linked list node.
 *
 */
static SqdQueueNodeOf * createNode(void * key)
{
    SqdQueueNodeOf * temp = malloc(sizeof(* temp));
    temp->_data = key;
    temp->_nextPtr = NULL;
    return temp;
}

/*
 * A function to create an empty queue
 *
 */
SqdQueueOf * createQueue(void)
{
    SqdQueueOf* queue = malloc(sizeof(* queue));
    queue->_frontPtr = queue->_rearPtr = NULL;
    return queue;
}

/*
 * The function to add a key k to q
 *
 */
void enQueue(SqdQueueOf * queue, void * data)
{
    SqdQueueNodeOf * temp = createNode(data);// Create a new LL node
    
    // If queue is empty, then new node is front and rear both
    if (queue->_rearPtr == NULL)
    {
        queue->_frontPtr = queue->_rearPtr = temp;
        return;
    }
    // Add the new node at the end of queue and change rear
    queue->_rearPtr->_nextPtr = temp;
    queue->_rearPtr = temp;
}

/*
 * Function to remove a key from given queue q
 *
 */
SqdQueueNodeOf * deQueue(SqdQueueOf * queue)
{
    // If queue is empty, return NULL.
    if (queue->_frontPtr == NULL) return NULL;
    
    // Store previous front and move front one node ahead
    SqdQueueNodeOf * temp = queue->_frontPtr;
    queue->_frontPtr = queue->_frontPtr->_nextPtr;
    
    // If front becomes NULL, then change rear also as NULL
    return (!queue->_frontPtr)? queue->_rearPtr = NULL : temp;
}

/*
 * A function to destroy the queue.
 *
 */
void destroyQueue(SqdQueueOf * queue)
{
    while (queue->_frontPtr)
    {
        deQueue(queue);
    }
    free(queue);
}
