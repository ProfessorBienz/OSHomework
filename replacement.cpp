#include "cs_481_hw2_src/src.hpp"

// Delete First Frame in linked list
// Return how many frames you stepped through to find replacement frame
int fifo(FrameList* active_frames, FrameList** frame_to_remove_ptr)
{

}

// Delete Least Recently Used Frame
// frame->idx shows how recently frame has been used
// higher number == more recently used
// Return how many frames you stepped through to find replacement frame
int lru(FrameList* active_frames, FrameList** frame_to_remove_ptr)
{

}

// Step through active frames, starting with first element in linked list (passed as arg)
// Remove first active frame with frame->clock_bit set to zero
// Reset any clock_bit as you traverse over a frame
// Return how many frames you stepped through to find replacement frame
int clock_lru(FrameList* active_frames, FrameList** frame_to_remove_ptr)
{

}
