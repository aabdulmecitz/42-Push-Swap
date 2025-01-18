make update
make compile_libs
make 
make bonus

ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | ./checker_linux $ARG
ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | ./checker $ARG
