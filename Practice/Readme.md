# Assignment No - 4 : FIFO
* Steps : 
      - Importing iostream, deque
      - Declaring the constants like 
            1. frame_size
            2. reference_string
            3. reference_string_size
            4. page_hits
            5. page_miss
            6. deque<int> current_ueue
            7. deque<int> order_queue
      - Declaring Supportive functions along with main()
            1. printQueue
            2. insertIntoQueue
      - Algorithm for insertIntoQueue
            1.Create flag stating whether given number is present in the current_queue through    iteration.
            2.If exists
                  increase page hits
                  print_queue(current_queue)
            3. Else 
                  increase page misses
                  If current_queue.size equals frame_size then
                        store front element of order_queue
                        drop front element of order_queue
                        push new value to order_queue

                        iterate over current_queue if elementToReplace matches current element in current_queue then replace, printQueue, and return;
                  Else 
                        order_queue.insert_back(value)
                        current_queue.insert_back(value)
                        printQueue