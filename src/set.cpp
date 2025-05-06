#include "set.h"

bool Set::access(uint32_t tag, bool isWrite, WritePolicy wp, int blockSize, int& bytesFromMem, int& bytesToMem) {
    //look for tag
    for(auto i = blocks.begin(); i != blocks.end(); i++){
        if(i->tag == tag){
            //hit
            //send block to front of list so it is shown to be used
            blocks.splice(blocks.begin(), blocks, i);

            if(isWrite && wp == WB){
                i->dirty = true;
            } else if(isWrite && wp = WT){
                bytesToMem += blockSize;
            }

            return true;
        }
    }

    //miss
    if(blocks.size() >= associativity){
        //evict LRU
        Block& evicted = blocks.back();
        if(evicted.dirty && wp == WB){
            bytesToMem += blockSize;
        }
        blocks.pop_back();
    }

    blocks.emplace_front(Block{tag, true, isWrite && (wp == WB)});
    bytesFromMem += blockSize;

     if (isWrite && wp == WT)
            bytesToMem += blockSize;

    return false;
}