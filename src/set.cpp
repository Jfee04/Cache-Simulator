#include "set.h"

bool Set::access(uint32_t tag, bool isWrite, WritePolicy wp, int blockSize, int& bytesFromMem, int& bytesToMem, bool& hit) {
    //look for tag
    for(auto i = blocks.begin(); i != blocks.end(); i++){
        if(i->tag == tag){
            //hit

            blocks.splice(blocks.begin(), blocks, i);

            if(isWrite && wp == WB){
                i->dirty = true;
            } else if(isWrite && wp = WT){
                bytesToMem += blockSize;
            }
        }
    }



}