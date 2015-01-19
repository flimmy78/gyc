#!/bin/bash

#./network.gyc.exe .

./network.gyc.exe . --dot --out hehe.dot
neato -Tpng hehe.dot > hehe.png
eog hehe.png

# community
#./network.gyc.exe . --fast_community hehe.fc --fast_community_edges hehe.fc.edges --fast_community_vertices hehe.fc.vertices --fast_community_com_file hehe.fc.files
