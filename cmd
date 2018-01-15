python parsenodes.py theta.computenodes location.txt > nodetable
python parsejobnodes.py theta.computenodes location.txt > jobnodetable


CC -std=c++11 -c route.cxx 
CC -o multiroutes route.o multiroutes.cxx 


qsub -n 32 job.sh

